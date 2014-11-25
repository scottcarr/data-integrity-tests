/* The Computer Language Shootout Benchmarks
   http://shootout.alioth.debian.org/

   contributed by Kevin Carson
   compilation:
       gcc -O3 -fomit-frame-pointer -funroll-loops -static binary-trees.c -lm
       icc -O3 -ip -unroll -static binary-trees.c -lm
*/

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../safe_functions.h"


typedef struct tn {
    struct tn*    left;
    struct tn*    right;
    double          item;
} treeNode;

__attribute__((annotate("sensitive"))) treeNode tn;
__attribute__((annotate("sensitive"))) treeNode *tnp;


#ifdef ORIG
treeNode* NewTreeNode(treeNode* left, treeNode* right, double item)
{
    treeNode*    new;

    new = (treeNode*)malloc(sizeof(treeNode));

    new->left = left;
    new->right = right;
    new->item = item;

    return new;
} /* NewTreeNode() */

#else
treeNode* NewTreeNode(treeNode* left, treeNode* right, treeNode *item)
{
    treeNode*    new;

    new = (treeNode*)malloc(sizeof(treeNode));

    new->left = left;
    new->right = right;
    new->item = item->item;

    return new;
} /* NewTreeNode() */
#endif

#ifdef ORIG
double ItemCheck(treeNode* tree)
{
    if (tree->left == NULL)
        return tree->item;
    else
        return tree->item + ItemCheck(tree->left) - ItemCheck(tree->right);
} /* ItemCheck() */
#else
treeNode ItemCheck(treeNode* tree)
{
    treeNode tmp;
    if (tree->left == NULL)
        tmp.item = tree->item;
    else
        tmp.item = tree->item + ItemCheck(tree->left).item - ItemCheck(tree->right).item;

    return tmp;
} /* ItemCheck() */
#endif


#ifdef ORIG
treeNode* BottomUpTree(double item, unsigned depth)
{
    if (depth > 0)
        return NewTreeNode
        (
            BottomUpTree(2 * item - 1, depth - 1),
            BottomUpTree(2 * item, depth - 1),
            item
        );
    else
        return NewTreeNode(NULL, NULL, item);
} /* BottomUpTree() */
#else
treeNode* BottomUpTree(treeNode *item, unsigned depth)
{
    if (depth > 0) {
        treeNode tmp1, tmp2;
        tmp1.item = 2 * item->item - 1;
        tmp2.item = 2 * item->item;
        return NewTreeNode
        (
            BottomUpTree(&tmp1, depth - 1),
            BottomUpTree(&tmp2, depth - 1),
            item
        );
    }
    else
        return NewTreeNode(NULL, NULL, item);
} /* BottomUpTree() */
#endif


//void DeleteTree(treeNode* tree)
//{
//    if (tree->left != NULL)
//    {
//        DeleteTree(tree->left);
//        DeleteTree(tree->right);
//    }
//
//    tree = NULL;
//    free(tree);
//} /* DeleteTree() */


int main(int argc, char* argv[])
{
    unsigned   N, depth, minDepth, maxDepth, stretchDepth;
    treeNode   *stretchTree, *longLivedTree, *tempTree;

    N = atol(argv[1]);

    minDepth = 4;

    if ((minDepth + 2) > N)
        maxDepth = minDepth + 2;
    else
        maxDepth = N;

    stretchDepth = maxDepth + 1;

    treeNode tmp;
    tmp.item = 0;
    stretchTree = BottomUpTree(&tmp, stretchDepth);
    //printf
    //(
    //    "stretch tree of depth %u\t check: %li\n",
    //    stretchDepth,
    //    ItemCheck(stretchTree).item
    //);
    printf
    (
        "stretch tree of depth %u\t check:",
        stretchDepth
    );
    //double d = (double) ItemCheck(stretchTree).item;
    //safe_write_double(&d);
    treeNode tn = ItemCheck(stretchTree);
    safe_write_double(&(tn.item));
    printf("\n");

    //DeleteTree(stretchTree);

    longLivedTree = BottomUpTree(&tmp, maxDepth);

    for (depth = minDepth; depth <= maxDepth; depth += 2)
    {
        //long    i, iterations, check;
        long    i, iterations;

        //iterations = pow(2, maxDepth - depth + minDepth);
        iterations = 2;
        int j;
        for (j = 0; j < (maxDepth - depth + minDepth); ++j) {
          iterations *= 2;
        }

        //check = 0;
        treeNode check; check.item = 0;

        for (i = 1; i <= iterations; i++)
        {
            tmp.item = i;
            tempTree = BottomUpTree(&tmp, depth);
            check.item += ItemCheck(tempTree).item;
            //DeleteTree(tempTree);

            tmp.item = -i;
            tempTree = BottomUpTree(&tmp, depth);
            check.item += ItemCheck(tempTree).item;
            //DeleteTree(tempTree);
        } /* for(i = 1...) */

        printf
        (
            "%li\t trees of depth %u\t check:",
            iterations * 2,
            depth
        );
        safe_write_double(&(check.item));
        printf("\n");
    } /* for(depth = minDepth...) */

    //printf
    //(
    //    "long lived tree of depth %u\t check: %lf\n",
    //    maxDepth,
    //    ItemCheck(longLivedTree).item
    //);

    return 0;
} /* main() */

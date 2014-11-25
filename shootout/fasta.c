/* -*- mode: c -*-
 * $Id: fasta.gcc,v 1.1 2005-03-19 07:50:09 bfulgham Exp $
 * http://shootout.alioth.debian.org/
 *
 * by Paul Hsieh
 */

#include <stdio.h>
#include <stdlib.h>
#include "../safe_functions.h"

#define IM 139968
#define IA   3877
#define IC  29573

double gen_random (double max) {
    static long last = 42;
    return max * (last = (last * IA + IC) % IM) / IM;
}

struct aminoacids {
    char c;
    double p;
};

struct SafeBuf {
  char *buf;
};

__attribute__((annotate("sensitive"))) struct aminoacids aa;
__attribute__((annotate("sensitive"))) struct aminoacids *aap;

__attribute__((annotate("sensitive"))) struct SafeBuf sb;
__attribute__((annotate("sensitive"))) struct SafeBuf *sbp;

void print_genelist(struct aminoacids * genelist, int count) {
    int i;
    for (i=0; i < count; i++) {
      printf("(");
      safe_putchar(&(genelist[i].c));
      printf(",");
      safe_write_double(&(genelist[i].p));
      printf(")");
    }
    printf("\n");
}

/* Weighted selection from alphabet */

void makeCumulative (struct aminoacids * genelist, int count) {
    double cp = 0.0;
    int i;

    for (i=0; i < count; i++) {
        cp += genelist[i].p;
        genelist[i].p = cp;
    }
}

#ifdef ORIG
char selectRandom (const struct aminoacids * genelist, int count) {
#else
int selectRandom (const struct aminoacids * genelist, int count) {
#endif
    double r = gen_random (1);
    int i, lo, hi;

#ifdef ORIG
    if (r < genelist[0].p) return genelist[0].c;
#else
    if (r < genelist[0].p) return 0;
#endif

    lo = 0;
    hi = count-1;

    while (hi > lo+1) {
        i = (hi + lo) / 2;
        if (r < genelist[i].p) hi = i; else lo = i;
    }
#ifdef ORIG
    return genelist[hi].c;
#else
    return hi;
#endif
}

/* Generate and write FASTA format */

#define LINE_LENGTH (60)

void makeRandomFasta (const char * id, const char * desc, const struct 
aminoacids * genelist, int count, int n) {
   int todo = n;
   int i, m;

   printf (">%s %s\n", id, desc);

#ifdef ORIG
   for (; todo > 0; todo -= LINE_LENGTH) {
       char pick[LINE_LENGTH+1];
       if (todo < LINE_LENGTH) m = todo; else m = LINE_LENGTH;
       for (i=0; i < m; i++) pick[i] = selectRandom (genelist, count);
       pick[m] = '\0';
       puts (pick);
   }
#else
   for (; todo > 0; todo -= LINE_LENGTH) {
       struct SafeBuf pick; 
       pick.buf = safe_malloc(LINE_LENGTH+1);
       if (todo < LINE_LENGTH) m = todo; else m = LINE_LENGTH;
       for (i=0; i < m; i++) {
         //struct aminoacids tmp = selectRandom (genelist, count);
         pick.buf[i] = genelist[selectRandom(genelist,count)].c;
       }
       int j;
       for (j = 0; j < i; ++j) {
         safe_putchar(pick.buf + j);
       }
       //free(pick.buf);
   }
#endif
}

void makeRepeatFasta (const char * id, const char * desc, const char * 
s, int n) {
   char * ss;
   int todo = n, k = 0, kn = strlen (s);
   int m;

   ss = (char *) malloc (kn + 1);
   memcpy (ss, s, kn+1);

   printf (">%s %s\n", id, desc);

   for (; todo > 0; todo -= LINE_LENGTH) {
       if (todo < LINE_LENGTH) m = todo; else m = LINE_LENGTH;

       while (m >= kn - k) {
           printf ("%s", s+k);
           m -= kn - k;
           k = 0;
       }

       ss[k + m] = '\0';
       puts (ss+k);
       ss[k + m] = s[m+k];
       k += m;
   }

   free (ss);
}

/* Main -- define alphabets, make 3 fragments */

#ifdef ORIG
struct aminoacids iub[] = {
    { 'a', 0.27 },
    { 'c', 0.12 },
    { 'g', 0.12 },
    { 't', 0.27 },

    { 'B', 0.02 },
    { 'D', 0.02 },
    { 'H', 0.02 },
    { 'K', 0.02 },
    { 'M', 0.02 },
    { 'N', 0.02 },
    { 'R', 0.02 },
    { 'S', 0.02 },
    { 'V', 0.02 },
    { 'W', 0.02 },
    { 'Y', 0.02 }
};

#define IUB_LEN (sizeof (iub) / sizeof (struct aminoacids))

struct aminoacids homosapiens[] = {
    { 'a', 0.3029549426680 },
    { 'c', 0.1979883004921 },
    { 'g', 0.1975473066391 },
    { 't', 0.3015094502008 },
};

#define HOMOSAPIENS_LEN (sizeof (homosapiens) / sizeof (struct aminoacids))

char * alu =
   "GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG" \
   "GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA" \
   "CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT" \
   "ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA" \
   "GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG" \
   "AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC" \
   "AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";
#else 

char * alu =
   "GGCCGGGCGCGGTGGCTCACGCCTGTAATCCCAGCACTTTGG" \
   "GAGGCCGAGGCGGGCGGATCACCTGAGGTCAGGAGTTCGAGA" \
   "CCAGCCTGGCCAACATGGTGAAACCCCGTCTCTACTAAAAAT" \
   "ACAAAAATTAGCCGGGCGTGGTGGCGCGCGCCTGTAATCCCA" \
   "GCTACTCGGGAGGCTGAGGCAGGAGAATCGCTTGAACCCGGG" \
   "AGGCGGAGGTTGCAGTGAGCCGAGATCGCGCCACTGCACTCC" \
   "AGCCTGGGCGACAGAGCGAGACTCCGTCTCAAAAA";

struct aminoacids *iub;
struct aminoacids *homosapiens;

#define IUB_LEN (15)
#define HOMOSAPIENS_LEN (4)

void init_iub() {
  iub = malloc(sizeof(struct aminoacids)*IUB_LEN);
  iub[0].c  =  'a'; iub[0].p  =  .27 ;
  iub[1].c  =  'c'; iub[1].p  =  .12 ;
  iub[2].c  =  'g'; iub[2].p  =  .12 ;
  iub[3].c  =  't'; iub[3].p  =  .27 ;
  iub[4].c  =  'B'; iub[4].p  =  .02 ;
  iub[5].c  =  'D'; iub[5].p  =  .02 ;
  iub[6].c  =  'H'; iub[6].p  =  .02 ;
  iub[7].c  =  'K'; iub[7].p  =  .02 ;
  iub[8].c  =  'M'; iub[8].p  =  .02 ;
  iub[9].c  =  'N'; iub[9].p  =  .02 ;
  iub[10].c =  'R'; iub[10].p =  .02 ;
  iub[11].c =  'S'; iub[11].p =  .02 ;
  iub[12].c =  'V'; iub[12].p =  .02 ;
  iub[13].c =  'W'; iub[13].p =  .02 ;
  iub[14].c =  'Y'; iub[14].p =  .02 ;
}

void init_homosapiens() {
  homosapiens = malloc(sizeof(struct aminoacids)*HOMOSAPIENS_LEN);
  homosapiens[0].c =  'a'; homosapiens[0].p =  0.3029549426680;
  homosapiens[1].c =  'c'; homosapiens[1].p =  0.1979883004921;
  homosapiens[2].c =  'g'; homosapiens[2].p =  0.1975473066391;
  homosapiens[3].c =  't'; homosapiens[3].p =  0.3015094502008;
}

#endif

int main (int argc, char * argv[]) {
    int n = 1000;

    if (argc > 1) sscanf (argv[1], "%d", &n);

    init_iub();
    init_homosapiens();
    makeCumulative (iub, IUB_LEN);
    makeCumulative (homosapiens, HOMOSAPIENS_LEN);

    //print_genelist(iub, IUB_LEN);
    //print_genelist(homosapiens, HOMOSAPIENS_LEN);

    makeRepeatFasta ("ONE", "Homo sapiens alu", alu, n*2);
    makeRandomFasta ("TWO", "IUB ambiguity codes", iub, IUB_LEN, n*3);
    makeRandomFasta ("THREE", "Homo sapiens frequency", homosapiens, HOMOSAPIENS_LEN, n*5);

    return 0;
}


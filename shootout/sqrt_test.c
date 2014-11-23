
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../safe_functions.h"

#define pi 3.141592653589793
#define solar_mass (4 * pi * pi)
#define days_per_year 365.24

struct planet {
  double x, y, z;
  double vx, vy, vz;
  double mass;
};

__attribute__((annotate("sensitive"))) struct planet prot_planet;
__attribute__((annotate("sensitive"))) struct planet *prot_planet_ptr;

// a crazy sqrt implementation I found on the internet so we 
// don't have to use libc
// http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi
double sqrt5(double m) {
   double i=0;
   double x1,x2;
   while( (i*i) <= m )
          i+=0.1f;
   x1=i;
   for(int j=0;j<10;j++)
   {
       x2=m;
      x2/=x1;
      x2+=x1;
      x2/=2;
      x1=x2;
   }
   return x2;
}  

__attribute__((noinline))
void plt_sqrt(struct planet *p) {
   double i=0;
   double x1,x2;
   double m = p->x;
   while( (i*i) <= m )
          i+=0.1f;
   x1=i;
   for(int j=0;j<10;j++)
   {
       x2=m;
      x2/=x1;
      x2+=x1;
      x2/=2;
      x1=x2;
   }
   p->x = x2;
   //return x2;
}

int main(int argc, char ** argv)
{
  //int n = atoi(argv[1]);
  //int i;

  //offset_momentum(NBODIES, bodies);
  //printf ("%.9f\n", energy(NBODIES, bodies));
  //for (i = 1; i <= n; i++)
  //  advance(NBODIES, bodies, 0.01);
  //printf ("%.9f\n", energy(NBODIES, bodies));
  struct planet p;
  struct planet sqrt_p;
  safe_read_double(&(p.x));
  sqrt_p.x = p.x;
  plt_sqrt(&sqrt_p);
  safe_write_double(&(sqrt_p.x));
  printf("\n");
  //printf("%f\n", p.x);
  return 0;
}

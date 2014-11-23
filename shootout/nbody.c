/*
 * The Great Computer Language Shootout
 * http://shootout.alioth.debian.org/
 *
 * contributed by Christoph Bauer
 *  
 */

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

void advance(int nbodies, struct planet * bodies, double dt)
{
  int i, j;

  for (i = 0; i < nbodies; i++) {
    struct planet * b = &(bodies[i]);
    for (j = i + 1; j < nbodies; j++) {
      struct planet * b2 = &(bodies[j]);
      double dx = b->x - b2->x;
      double dy = b->y - b2->y;
      double dz = b->z - b2->z;
#ifdef ORIG
      double distance = sqrt5(dx * dx + dy * dy + dz * dz);
#else
      struct planet tmp;
      tmp.x = dx * dx + dy * dy + dz * dz;
      plt_sqrt(&tmp);
      double distance = tmp.x;
#endif
      double mag = dt / (distance * distance * distance);
      b->vx -= dx * b2->mass * mag;
      b->vy -= dy * b2->mass * mag;
      b->vz -= dz * b2->mass * mag;
      b2->vx += dx * b->mass * mag;
      b2->vy += dy * b->mass * mag;
      b2->vz += dz * b->mass * mag;
    }
  }
  for (i = 0; i < nbodies; i++) {
    struct planet * b = &(bodies[i]);
    b->x += dt * b->vx;
    b->y += dt * b->vy;
    b->z += dt * b->vz;
  }
}

#ifdef ORIG
double energy(int nbodies, struct planet * bodies)
#else
struct planet energy(int nbodies, struct planet * bodies)
#endif
{
  double e;
  int i, j;

  e = 0.0;
  for (i = 0; i < nbodies; i++) {
    struct planet * b = &(bodies[i]);
    e += 0.5 * b->mass * (b->vx * b->vx + b->vy * b->vy + b->vz * b->vz);
    for (j = i + 1; j < nbodies; j++) {
      struct planet * b2 = &(bodies[j]);
      double dx = b->x - b2->x;
      double dy = b->y - b2->y;
      double dz = b->z - b2->z;
#ifdef ORIG
      double distance = sqrt5(dx * dx + dy * dy + dz * dz);
#else
      struct planet tmp;
      tmp.x = dx * dx + dy * dy + dz * dz;
      plt_sqrt(&tmp);
      double distance = tmp.x;
#endif
      e -= (b->mass * b2->mass) / distance;
    }
  }
#ifdef ORIG
  return e;
#else
  struct planet rv;
  rv.x = e;
  return rv;
#endif
}

void offset_momentum(int nbodies, struct planet * bodies)
{
  double px = 0.0, py = 0.0, pz = 0.0;
  int i;
  for (i = 0; i < nbodies; i++) {
    px += bodies[i].vx * bodies[i].mass;
    py += bodies[i].vy * bodies[i].mass;
    pz += bodies[i].vz * bodies[i].mass;
  }
  bodies[0].vx = - px / solar_mass;
  bodies[0].vy = - py / solar_mass;
  bodies[0].vz = - pz / solar_mass;
}

#define NBODIES 5
#ifdef ORIG
__attribute__((annotate("sensitive"))) struct planet bodies[NBODIES] = {
  {                               /* sun */
    0, 0, 0, 0, 0, 0, solar_mass
  },
  {                               /* jupiter */
    4.84143144246472090e+00,
    -1.16032004402742839e+00,
    -1.03622044471123109e-01,
    1.66007664274403694e-03 * days_per_year,
    7.69901118419740425e-03 * days_per_year,
    -6.90460016972063023e-05 * days_per_year,
    9.54791938424326609e-04 * solar_mass
  },
  {                               /* saturn */
    8.34336671824457987e+00,
    4.12479856412430479e+00,
    -4.03523417114321381e-01,
    -2.76742510726862411e-03 * days_per_year,
    4.99852801234917238e-03 * days_per_year,
    2.30417297573763929e-05 * days_per_year,
    2.85885980666130812e-04 * solar_mass
  },
  {                               /* uranus */
    1.28943695621391310e+01,
    -1.51111514016986312e+01,
    -2.23307578892655734e-01,
    2.96460137564761618e-03 * days_per_year,
    2.37847173959480950e-03 * days_per_year,
    -2.96589568540237556e-05 * days_per_year,
    4.36624404335156298e-05 * solar_mass
  },
  {                               /* neptune */
    1.53796971148509165e+01,
    -2.59193146099879641e+01,
    1.79258772950371181e-01,
    2.68067772490389322e-03 * days_per_year,
    1.62824170038242295e-03 * days_per_year,
    -9.51592254519715870e-05 * days_per_year,
    5.15138902046611451e-05 * solar_mass
  }
};
#else
__attribute__((annotate("sensitive"))) struct planet bodies[NBODIES];
void init_bodies() {

  // sun
  bodies[0].x     = 0;
  bodies[0].y     = 0;
  bodies[0].z     = 0;
  bodies[0].vx    = 0;
  bodies[0].vy    = 0;
  bodies[0].vz    = 0;
  bodies[0].mass  = solar_mass;

  // jupiter
  bodies[1].x                  = 4.84143144246472090e+00;
  bodies[1].y                  = -1.16032004402742839e+00;
  bodies[1].z                  = -1.03622044471123109e-01;
  bodies[1].vx                 = 1.66007664274403694e-03 * days_per_year;
  bodies[1].vy                 = 7.69901118419740425e-03 * days_per_year;
  bodies[1].vz                 = -6.90460016972063023e-05 * days_per_year;
  bodies[1].mass               = 9.54791938424326609e-04 * solar_mass;

  // saturn
  bodies[2].x                  = 8.34336671824457987e+00;
  bodies[2].y                  = 4.12479856412430479e+00;
  bodies[2].z                  = -4.03523417114321381e-01;
  bodies[2].vx                 = -2.76742510726862411e-03 * days_per_year;
  bodies[2].vy                 = 4.99852801234917238e-03 * days_per_year;
  bodies[2].vz                 = 2.30417297573763929e-05 * days_per_year;
  bodies[2].mass               = 2.85885980666130812e-04 * solar_mass;

  // uranus
  bodies[3].x                  = 1.28943695621391310e+01;
  bodies[3].y                  = -1.51111514016986312e+01;
  bodies[3].z                  = -2.23307578892655734e-01;
  bodies[3].vx                 = 2.96460137564761618e-03 * days_per_year;
  bodies[3].vy                 = 2.37847173959480950e-03 * days_per_year;
  bodies[3].vz                 = -2.96589568540237556e-05 * days_per_year;
  bodies[3].mass               = 4.36624404335156298e-05 * solar_mass;

  bodies[4].x                  =  1.53796971148509165e+01;
  bodies[4].y                  =  -2.59193146099879641e+01;
  bodies[4].z                  =  1.79258772950371181e-01;
  bodies[4].vx                 =  2.68067772490389322e-03 * days_per_year;
  bodies[4].vy                 =  1.62824170038242295e-03 * days_per_year;
  bodies[4].vz                 =  -9.51592254519715870e-05 * days_per_year;
  bodies[4].mass               =  5.15138902046611451e-05 * solar_mass;

}

#endif

int main(int argc, char ** argv)
{
  int n = atoi(argv[1]);
  int i;

#ifndef ORIG
  init_bodies();
#endif

  offset_momentum(NBODIES, bodies);

  // debugging:
  //for (i = 0; i < NBODIES; i++) {
  //  safe_write_double(&(bodies[i].x));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].y));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].z));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].vx));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].vy));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].vz));
  //  printf("\n");
  //  safe_write_double(&(bodies[i].mass));
  //  printf("\n");
  //}
  
#ifdef ORIG
  printf ("%.9f\n", energy(NBODIES, bodies));
#else
  struct planet tmp = energy(NBODIES, bodies);
  safe_write_double(&(tmp.x));
  printf("\n");
#endif
  for (i = 1; i <= n; i++)
    advance(NBODIES, bodies, 0.01);
#ifdef ORIG
  printf ("%.9f\n", energy(NBODIES, bodies));
#else
  tmp = energy(NBODIES, bodies);
  safe_write_double(&(tmp.x));
  printf("\n");
#endif
  return 0;
}


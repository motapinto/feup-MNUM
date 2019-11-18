#include <stdio.h>
#include <math.h>

double f(double x) {
  return x*x*x -10*sin(x)+2.8;
}

double biss(double a, double b) {
  double m;

   for (int i=0; i<2; i++) {
     m = (a + b) / 2;
     if(f(a)*f(m)<0)
       b = m;
     else
       a = m;

    printf("%f\n", b);
   }
   return 0;
}

int main ()
{
  biss(1.5, 4.2);
}

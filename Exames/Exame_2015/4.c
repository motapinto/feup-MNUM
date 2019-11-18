#include <stdio.h>
#include <math.h>

double f(double x) {
  return exp(x) -4*x*x ;
}

double transf_pic (double x) {
  return 2*log(2*x);
}

double peano (double a) {
  double xn;

  for(int i=0; i<100; i++) {
    xn = transf_pic(a);
    printf("%f\n", xn);
    a = xn;
  }
  return 0;
}


int main () {
  peano(1.1);
}

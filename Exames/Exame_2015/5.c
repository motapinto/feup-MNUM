#include <stdio.h>
#include <math.h>

double f(double x) {
  return sqrt(6.25*exp(5*x) + 1);
}

double simp (double a, double b, double h) {
  double integral=0;
  int p=0, k=1;

  for(double i=a+h; i<=b-h; i+=h) {
    if(k%2 == 0)   p=2;
    else           p=4;
    integral = integral + p*f(i);
    k++;
  }
  integral+=f(a)+f(b);
  return integral*(h/3);
}

double trap (double a, double b, double h) {
  double integral=0;
  int p=0;

  for(double i=a+h; i<=b-h; i+=h) {
    p=2;
    integral = integral + p*f(i);
  }
  integral+=f(a)+f(b);
  return integral*(h/3);
}


int main () {
  double a, b, c, d, e, f;
  a=trap(0, 1, 0.125);
  b=trap(0, 1, 0.125/2);
  c=trap(0, 1, 0.125/4);
  printf("a: %f\nb: %f\nc: %f\n\n", a, b, c);
  printf("qc: %f\nerro: %f\n\n", (b-a)/(c-b), (c-b)/3);

  d=simp(0, 1, 0.125);
  e=simp(0, 1, 0.125/2);
  f=simp(0, 1, 0.125/4);
  printf("a: %f\nb: %f\nc: %f\n\n", d, e, f);
  printf("qc: %f\nerro: %f\n", (e-d)/(f-e), (f-e)/15);
}

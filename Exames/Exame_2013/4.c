#include <stdio.h>
#include <math.h>

double f(double x){
  return exp(1.5*x);
}

double simp(double a, double b, double h) {

  int k=1, p=0;
  double integral = 0;

  
  integral+=f(a)+f(b);
  return integral*(h/3);
}

int main() {
  double s, s1, s2;
  s = simp(1, 1.5, 0.125);
  s1 = simp(1, 1.5, 0.125/2);
  s2 = simp(1, 1.5, 0.125/4);
  printf("%f\n%f\n%f\n\n", s, s1, s2);
  printf("qc: %f\n", (s1-s)/(s2-s1));
  printf("erro: %f\n", (s2-s1)/15);
}

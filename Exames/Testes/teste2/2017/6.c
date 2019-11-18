#include <stdint.h>
#include <stdio.h>
#include <math.h>

double f1(double x, double y, double z){//dydx
  return z;
}

double f2(double x, double y, double z){ //dzdx
  return 2+x*x+x*z;
}

void sist_euler(double x0, double y0, double z0, double h){
    double deltaxn = x0, deltayn = y0, deltazn = z0;
    double xaux, yaux, zaux;

    printf("t: %f\ny: %f\n\n", deltaxn, deltayn);

    for(int i=0; i<=1; i++){
      xaux = deltaxn, yaux=deltayn, zaux = deltazn; //iteracao anterior
      deltaxn += h;
      deltayn += h * f1(deltaxn, deltayn, deltazn);
      deltazn += h * f2(xaux, yaux, deltazn);
      printf("t: %f\ny: %f\n\n", deltaxn, deltayn);
    }
}

void sist_rk4(double x0, double y0, double z0, double h){
  double deltazn=z0, deltayn=y0, deltaxn=x0;
  double xaux, yaux, zaux;
  double k1, k2, k3, k4, d1, d2, d3, d4;

  printf("t: %f\ny: %f\n\n", deltaxn, deltayn);

  for(int i=0; i<2; i++){

    xaux = deltaxn, yaux=deltayn, zaux = deltazn; //iteracao anterior

    d1 = h*f1(xaux, yaux, zaux);
    k1 = h*f2(deltaxn, yaux, zaux);

    d2 = h*f1(xaux+h/2, yaux+d1/2, zaux+k1/2);
    k2 = h*f2(xaux+h/2, yaux+d1/2, zaux+k1/2);

    d3 = h*f1(xaux+h/2, yaux+d2/2, zaux+k2/2);
    k3 = h*f2(xaux+h/2, yaux+d2/2, zaux+k2/2);

    d4 = h*f1(xaux+h, yaux+d3, zaux+k3);
    k4 = h*f2(xaux+h, yaux+d3, zaux+k3);

    deltaxn += h;
    deltayn += d1/6+d2/3+d3/3+d4/6;
    deltazn += k1/6+k2/3+k3/3+k4/6;
    printf("t: %f\ny: %f\n\n", deltaxn, deltayn);
  }
}

int main()
{
  double x0=1, y0=1, z0=0, h=0.25;
  printf("\nEULER\n");
  sist_euler(x0, y0, z0, h);
  printf("\nRK4\n");
  sist_rk4(x0, y0, z0, h);

}

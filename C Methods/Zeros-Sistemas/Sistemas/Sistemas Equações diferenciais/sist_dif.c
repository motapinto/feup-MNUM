#include <stdio.h>
#include <math.h>

double f1(double x, double y, double z){ //dydx
  return x+y+z;
}

double f2(double x, double y, double z){//dzdx
  return x*y-z;
}

void sist_euler(double x0, double y0, double z0, double xf, double h){
    double deltazn=z0, deltayn=y0, deltaxn=x0;

    while(x0<1){
      deltaxn = x0 + h;
      deltayn = y0 + h * f1(x0, y0, z0);
      deltazn = z0 + h * f2(x0, y0, z0);
      x0 = deltaxn, y0 = deltayn, z0 = deltazn;
    }
    printf("x: %f\ny: %f\nz: %f\n\n", deltaxn, deltayn, deltazn);
}

void sist_rk2(double x0, double y0, double z0, double xf, double h){
  double deltazn=z0, deltayn=y0, deltaxn=x0;

  while(deltaxn<1){
    deltaxn = x0 + h;
    deltayn = y0 + h * f1(x0+h/2, (y0+h/2)*f1(x0, y0, z0), (z0+h/2)*f2(x0, y0, z0)); //f1 = y'
    deltazn = z0 + h * f2(x0+h/2, (y0+h/2)*f1(x0, y0, z0), (z0+h/2)*f2(x0, y0, z0)); //f1 = y'
    x0 = deltaxn, y0 = deltayn, z0 = deltazn;
  }
  printf("x: %f\ny: %f\nz: %f\n\n", deltaxn, deltayn, deltazn);
}

void sist_rk4(double x0, double y0, double z0, double xf, double h){
  double deltazn=z0, deltayn=y0, deltaxn=x0;
  double k1, k2, k3, k4, d1, d2, d3, d4;

  while(deltaxn<1){

    d1 = h*f1(x0, y0, z0);
    k1 = h*f2(x0, y0, z0);

    d2 = h*f1(x0+h/2, y0+d1/2, z0+k1/2);
    k2 = h*f2(x0+h/2, y0+d1/2, z0+k1/2);

    d3 = h*f1(x0+h/2, y0+d2/2, z0+k2/2);
    k3 = h*f2(x0+h/2, y0+d2/2, z0+k2/2);

    d4 = h*f1(x0+h, y0+d3, z0+k3);
    k4 = h*f2(x0+h, y0+d3, z0+k3);

    deltaxn = x0 + h;
    deltayn = y0 + d1/6+d2/3+d3/3+d4/6;
    deltazn = z0 + k1/6+k2/3+k3/3+k4/6;
    x0 = deltaxn, y0 = deltayn, z0 = deltazn;
  }
  printf("x: %f\ny: %f\nz: %f\n\n", deltaxn, deltayn, deltazn);
}

int main()
{
  double x0=0, y0=0, z0=0, xn=1, deltax=0.02;
  sist_euler(x0, y0, z0, xn, deltax);
  sist_rk2(x0, y0, z0, xn, deltax);
  sist_rk4(x0, y0, z0, xn, deltax);
}

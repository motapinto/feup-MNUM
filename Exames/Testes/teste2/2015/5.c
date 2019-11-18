#include <stdio.h>
#include <math.h>

double f1(double x, double y, double z){
  return z;
}
double f2(double x, double y, double z){
  return -7/f1(x,y,z) + -2*y;
}

void euler(double x0, double y0, double z0, double h)
{
  double xaux=x0, yaux=y0, zaux = z0;
    for(int i=0; i<2; i++){
      x0 = xaux+h;
      y0 = yaux+h*f1(xaux,yaux, zaux);
      z0 = zaux+h*f2(xaux,yaux, zaux);

      xaux = x0;
      yaux = y0;
      zaux = z0;

      printf("x: %f\ny: %f\nz: %f\n\n", xaux, yaux, zaux);
    }

}

int main()
{
    double h=0.25, x0=1, y0=1, z0=0;
    euler(x0, y0, z0, h);
}

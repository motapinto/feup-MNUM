#include <stdio.h>
#include <math.h>

void jacobi(double x, double y, double z, double w)
{
    double xaux=x, yaux=y, zaux=z, waux=w;
    for(int i=0; i<2; i++){
      x = (1 + yaux + zaux - waux)/4.5;
      y = (-1 + xaux - zaux + waux)/(4.5);
      z = (-1 + xaux -2*yaux + waux)/4.5;
      w = (-2*xaux + yaux + zaux)/4.5;

      xaux = x, yaux = y, zaux = z, waux = w;
      printf("x: %f\ny: %f\nz: %f\nw: %f\n\n", x, y, z, w);
    }
}
int main()
{
    double x=0.25, y=0.25, z=0.25, w=0.25;
    jacobi(x, y, z, w);
}

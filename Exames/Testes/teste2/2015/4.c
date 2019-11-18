#include <stdio.h>
#include <math.h>

double f(double x, double y){
  return -0.25*(y-45);
}

void euler(double x0, double y0, double h)
{
  double xaux=x0, yaux=y0;
    for(int i=0; i<2; i++){
      x0=xaux+h;
      y0=yaux+h*f(xaux,yaux);
      xaux = x0;
      yaux = y0;
      printf("x: %f\ny: %f\n\n", xaux, yaux);
    }

}

int main()
{
    double h=0.4, x0=1, y0=23;
    euler(x0, y0, h);
}

#include <stdio.h>
#include <math.h>

double f(double x, double y){
  return x*(x/2.0+1)*pow(y, 3) + (x+5/2.0)*pow(y, 2);
}

double euler(double x, double y, double h)
{
  double yaux = y;
  double xaux = x;
    while(x<=1.8){
      x = xaux + h;
      y = yaux + h*f(xaux,yaux);
      yaux = y;
      xaux = x;
      printf("x: %f\ny: %f\n\n", x, y);
    }
  return y;
}

int main()
{
  double h = 0.04, y0 = 0.1, x0 = 1, c1,c2, c0;
  c0 = euler(x0, y0, 0.08);
  c1 = euler(x0, y0, 0.04);
  c2 = euler(x0, y0, 0.02);
  printf("Erro: %f\n", c2-c1);
  printf("QC: %f\n", (c1-c0)/(c2-c1));
}

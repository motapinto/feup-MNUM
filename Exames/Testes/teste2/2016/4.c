#include <stdio.h>
#include <math.h>

double dTdt(double x, double t){
    return -0.25*(t-64);
}

void euler(double x, double y, double h)
{
  double deltaxn = x, deltayn = y;
  double xaux=x, yaux=y;
  int i=0;

  printf("t: %f\nT: %f\n\n", deltaxn, deltayn);

  for(i=0; i<2; i++){//iteracao 1 e 2 - primeiro quadro euler
      deltaxn = xaux+h;
      deltayn = yaux + h*dTdt(xaux, yaux);
      printf("t: %f\nT: %f\n\n", deltaxn, deltayn);
      xaux = deltaxn, yaux = deltayn;
    }
}

int main()
{
  double h=0.5, x0=4, t0=0;
  printf("\n\n\nEULER\n");
  euler(x0, t0, h);
}

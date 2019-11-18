#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double dCdt (double x, double c, double t){
  return -pow(exp(1), -0.1/(t+273))*c;
}

double dTdt(double x, double c, double t){
    return -15.0*dCdt(x,c,t) - 0.1*(t-20);
}

void sist_euler(double x, double y, double z, double h)
{
  double deltaxn = x,deltayn = y,deltazn = z;
  double xaux=x, yaux=y, zaux=z;
  double xaux1=x, yaux1=y, zaux1=z;
  double xaux2=x, yaux2=y, zaux2=z;
  double c0, c1, c2;
  int i=0;

  printf("t: %f\nC: %f\nT: %f\n\n", deltaxn, deltayn, deltazn);

  for(i=0; i<=15; i++){
    if(i<2){ //iteracao 1 e 2 - primeiro quadro euler
      deltaxn = xaux+h;
      deltayn = yaux + h*dCdt(xaux, yaux, zaux);
      deltazn = zaux + h*dTdt(xaux, yaux, zaux);
      printf("t: %.4f\nC: %.4f\nT: %.4f\n\n", deltaxn, deltayn, deltazn);
      xaux = deltaxn, yaux = deltayn, zaux = deltazn;
      if(i==1){
        c0 = deltayn;
      }
    }
    else if(i>=2 && i<6){ //iteracao 3, 4, 5, 6 (4 iteracoes para h')
      deltaxn = xaux1+(h/2);
      deltayn = yaux1 + (h/2)*dCdt(xaux1, yaux1, zaux1);
      deltazn = zaux1 + (h/2)*dTdt(xaux1, yaux1, zaux1);
      if(i==5){
        printf("C: %.4f\n\n", deltayn);
        c1 = deltayn;
      }
      xaux1 = deltaxn, yaux1 = deltayn, zaux1 = deltazn;
    }
    else if(i>=6 && i<14){ //8 iteracoes para h''
      deltaxn = xaux2+(h/4);
      deltayn = yaux2 + (h/4)*dCdt(xaux2, yaux2, zaux2);
      deltazn = zaux2 + (h/4)*dTdt(xaux2, yaux2, zaux2);
      if(i==13){
        printf("C: %.4f\n\n", deltayn);
        c2 = deltayn;
      }
      xaux2 = deltaxn, yaux2 = deltayn, zaux2 = deltazn;
    }
    else if(i== 14) {
      printf("QC: %.4f\n", (c1-c0)/(c2-c1));
      printf("Erro: %.4f\n", c2-c1);
    }
  }
}

void sist_rk4(double x, double y, double z, double h)
{
  double deltaxn = x, deltayn = y, deltazn = z;
  double xaux, yaux, zaux;
  double d1,d2,d3,d4,k1,k2,k3,k4;

  printf("t: %f\nC: %f\nT: %f\n\n", deltaxn, deltayn, deltazn);

  for(int i=0; i<2; i++){
    xaux = deltaxn, yaux = deltayn, zaux = deltazn;

    k1=h*dCdt(xaux, yaux, zaux);
    d1=h*dTdt(xaux, yaux, zaux);

    k2=h*dCdt(xaux+h/2, yaux+k1/2, zaux+d1/2);
    d2=h*dTdt(xaux+h/2, yaux+k1/2, zaux+d1/2);

    k3=h*dCdt(xaux+h/2, yaux+k2/2, zaux+d2/2);
    d3=h*dTdt(xaux+h/2, yaux+k2/2, zaux+d2/2);

    k4=h*dCdt(xaux+h, yaux+k3, zaux+d3);
    d4=h*dTdt(xaux+h, yaux+k3, zaux+d3);

    deltaxn = xaux+h;
    deltayn = yaux + k1/6 + k2/3 + k3/3 + k4/6;
    deltazn = zaux + d1/6 + d2/3 + d3/3 + d4/6;

    printf("t: %f\nC: %f\nT: %f\n\n", deltaxn, deltayn, deltazn);
  }
}

int main()
{
  double h=0.25, x0=0.5, c0=2.0, t0=20.0;
  printf("\nRK4\n");
  sist_rk4(x0, c0, t0, h);
  printf("\n\n\nEULER\n");
  sist_euler(x0, c0, t0, h);


}

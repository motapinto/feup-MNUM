#include <stdio.h>
#include <math.h>

double dCdt(double x, double C, double T){//dydx
    return -(pow(exp(1), -0.5/(T+273)) * C);
}
double dTdt(double x, double C, double T){//dzdx
    return 20*pow(exp(1), -0.5/(T+273)) * C  -0.5*(T-20);
}

double euler (double x, double y, double z, double h) {
  double x1=x, y1=y, z1=z;
  while (x<0.5) {
    x1 = x + h; //t
    y1 = y + h*dCdt(x, y, z);
    z1 = z + h*dTdt(x, y, z);
    x = x1; y = y1; z = z1;
    //printf("%f %f %f\n\n", x, y, z);
  }
  return y;
}

double rk4 (double x, double y, double z, double h) {
  double xn=x, yn=y, zn=z;
  double k1,k2,k3,k4,d1,d2,d3,d4;
  while (x<0.5) {

    k1 = h*dCdt(x, y, z);
    d1 = h*dTdt(x, y, z);
    k2 = h*dCdt(x+h/2.0, y+k1/2.0, z+d1/2.0);
    d2 = h*dTdt(x+h/2.0, y+k1/2.0, z+d1/2.0);
    k3 = h*dCdt(x+h/2.0, y+k2/2.0, z+d2/2.0);
    d3 = h*dTdt(x+h/2.0, y+k2/2.0, z+d2/2.0);
    k4 = h*dCdt(x+h, y+k3, z+d3);
    d4 = h*dTdt(x+h, y+k3, z+d3);

    xn = x + h; //t
    yn = y + k1/6 + k2/3 + k3/3 + k4/6;
    zn = z + d1/6 + d2/3 + d3/3 + d4/6;
    x = xn; y = yn; z = zn;
    printf("%f %f %f\n\n", x, y, z);
  }
  return y;
}


int main()
{
  double a = 0;
  double b = 1;
  double c = 15;
  double h = 0.25;
  double s, s1, s2;
  s = euler(a, b, c, h);
  s1 = euler(a, b, c, h/2);
  s2 = euler(a, b, c, h/4);
  rk4(a, b, c, h);
  //printf("%f %f %f\nQC: %f\nErro: %f\n\n", s, s1, s2, (s1-s)/(s2-s1), s2-s1);
}

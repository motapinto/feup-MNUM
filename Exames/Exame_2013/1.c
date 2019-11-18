#include <stdio.h>
#include <math.h>

double dydt(double x, double y, double z) {//y'
  return z;
}
double dzdt(double x, double y, double z) { //y''
  return 0.5 + x*x + x*dydt(x, y, z);
}
double euler(double t, double y, double z, double h) {
  double t1, y1, z1;

  for(double i = t; i<0.5; i+=h) {
    t1 = t + h;
    y1 = y + h*dydt(t, y, z);
    z1 = z + h*dzdt(t, y, z);
    t = t1; y = y1, z = z1;
    printf("%f %f\n", t, y);
  }
  return y;
}
double rk4(double x, double y, double z, double h) {
  double k1,k2,k3,k4,d1,d2,d3,d4;
  double x1, y1, z1;

  for(double i = x; i<0.5; i+=h) {
    k1 = h*dydt(x, y, z);
    d1 = h*dzdt(x, y, z);
    k2 = h*dydt(x+0.5*h, y+k1/2, z+d1/2);
    d2 = h*dzdt(x+0.5*h, y+k1/2, z+d1/2);
    k3 = h*dydt(x+0.5*h, y+k2/2, z+d2/2);
    d3 = h*dzdt(x+0.5*h, y+k2/2, z+d2/2);
    k4 = h*dydt(x+h, y+k3, z+d3);
    d4 = h*dzdt(x+h, y+k3, z+d3);

    x1 = x + h;
    y1 = y + k1/6+k2/3+k3/3+k4/6;
    z1 = z + d1/6+d2/3+d3/3+d4/6;
    x = x1; y = y1, z = z1;
    printf("%f %f\n", x, y);
  }
  return 0;
}


int main () {
  double x0 = 0, y0 = 0, z0 = 1, h=0.25 ;
  euler(x0, y0, z0, h);
  rk4(x0, y0, z0, h);
}

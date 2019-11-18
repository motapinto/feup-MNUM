#include <stdio.h>
#include <math.h>

double f(double x, double y){
  return 3*x*x - x*y + 11*y + y*y - 8*x;
}
double dfdx(double x, double y) {
  return -y+6*x-8;
}
double dfdy(double x, double y) {
  return 2*y-x+11;
}
void gradiente(double x, double y, double h) {
  double x1, y1;
  x1 = x - h*dfdx(x, y);
  y1 = y - h*dfdy(x, y);
  if(f(x1, y1)<f(x, y))  h = 2*h;
  else                   h = h/2;

  x = x1, y = y1;
  printf("%f %f\n", x, y);
  printf("%f %f\n", dfdx(x, y), dfdy(x, y));
  printf("%f\n", f(x, y));
}

int main() {
  printf("%f\n", f(2, 2));
  gradiente(2, 2, 0.5);

}

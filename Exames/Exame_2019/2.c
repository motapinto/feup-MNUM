#include <stdio.h>
#include <math.h>

double f1(double x, double y) {
  return sin(x+y)-pow(exp(1), x-y);
}

double f2 (double x, double y) {
  return cos(x+y)-x*x*y*y;
}

double f1x(double x, double y) {
    return cos(y+x)-pow(exp(1),(x-y));
}

double f1y(double x, double y) {
    return cos(y+x)+pow(exp(1),(x-y));
}

double f2x(double x, double y) {
    return -sin(y+x)-2*x*y*y;
}

double f2y(double x, double y) {
    return -sin(y+x)-2*x*x*y;
}

int main()
{
    double x, xn ,y, yn;
    x = 0.5, y = 0.5;

    for(int i=0; i<2; i++) {
        xn = x - (f1(x, y)*f2y(x, y) - f2(x, y)*f1y(x, y)) / 
         (f1x(x, y)*f2y(x, y)-f2x(x, y)*f1y(x, y));
        yn = y - (f2(x, y)*f1x(x, y) - f1(x, y)*f2x(x, y)) / 
         (f1x(x, y)*f2y(x, y)-f2x(x, y)*f1y(x, y));
        printf("x: %f\ny: %f\n\n", xn, yn);
        x = xn, y = yn;
    }
}


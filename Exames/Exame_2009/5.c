#include <stdio.h>
#include <math.h>

double dxdt(double t, double x) {
    return sin(x)+sin(2*t);
}
void rk4(double t0, double x0, double h) {
    double d1,d2,d3,d4;
    double x, t;

    for (double i=t0; i<1.5; i+=h) {

        d1 = h*dxdt(t0, x0);
        d2 = h*dxdt(t0+h/2, x0+d1/2);
        d3 = h*dxdt(t0+h/2, x0+d2/2);
        d4 = h*dxdt(t0+h, x0+d3);

        t = t0 + h;
        x = x0 + d1/6 + d2/3 + d3/3 + d4/6;
        x0 = x, t0 = t;
        printf("t:%f\nx:%f\n\n", t, x);
    }
}

int main() {
    rk4(1, 1, 0.125);
}
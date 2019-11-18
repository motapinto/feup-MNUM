#include <stdio.h>
#include <math.h>

double dxdt(double x, t) {
    return sin(x)+sin(2*t);
}
void rk4(double x0, double t0, double h) {
    double d1,d2,d3,d4;
    double x, t;

    for (double i=x0; i<=1.5; i+=h) {

        d1 = h*dzdt(x0, t0);
        d2 = h*dzdt(x0+h/2, t0+k1/2);
        d3 = h*dzdt(x0+h/2, t0+k2/2);
        d4 = h*dzdt(x0+h, t0+k3);

        x = x0 + h;
        t = t0 + d1/6 + d2/3 + d3/3 + d4/6;
        x0 = x, t0 = t;
        printf("x:%f\nt:%f\n\n", x, t);
    }
}

int main() {
    rk4(1, 1, 0.25/2);
}
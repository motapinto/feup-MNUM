#include <stdio.h>
#include <math.h>

double dydt(double t, double y) {
    return y/(t-1);
}

void euler(double t0, double y0, double h) {
    double t, y;
    for (int i = 0; i < 2 ; i++) {
        t = t0 + h;
        y = y0 + h*dydt(t0, y0);
        t0 = t;
        y0 = y;
        printf("%f %f \n", t, y);
    }
}

void rk4 (double t0, double y0, double h) {
    double t, y;
    double d1,d2,d3,d4;
    for (int i = 0; i < 2 ; i++) {

        d1 = h*dydt(t0, y0);
        d2 = h*dydt(t0+h/2, y0+d1/2);
        d3 = h*dydt(t0+h/2, y0+d2/2);
        d4 = h*dydt(t0+h, y0+d3);

        t = t0 + h;
        y = y0 + d1/6 + d2/3 + d3/3 + d4/6;
        y0 = y, t0 = t;
       printf("%f %f \n", t, y);
    }
}

int main() {
    euler(2, 2, 0.25);
    printf("\n");
    rk4(2, 2, 0.25);
}
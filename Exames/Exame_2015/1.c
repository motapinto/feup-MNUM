#include <stdio.h>
#include <math.h>

double dTdt(double t, double T) {
    return -0.25*(T-37);
}

void euler (double t0, double T0, double h) {
    double T, t;
    for(int i=0; i<2; i++) {
        t = t0 + h ; 
        T = T0 + h*dTdt(t0, T0);
        printf("%f\n", T);
        t0 = t, T0 = T;
    }
}

int main() {
    euler(5, 3, 0.4);
}
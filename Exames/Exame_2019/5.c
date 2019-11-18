#include <stdio.h>
#include <math.h>

double dydx(double x, double y, double z) {
    return z;
}

double dzdx(double x, double y, double z) {
    return -6*z - 5*y;
}

void euler(double x, double y, double z, double h) {
    double xn,yn,zn;

    for(double i=x; i<=0.3; i+=h) {
        xn = x + h;
        yn = y + h*dydx(x,y,z);
        zn = z + h*dzdx(x,y,z);
        z = zn, y = yn, x = xn;
        printf("%f %f %f\n", xn, yn, zn);
    }
}

int main() {
    euler(0, 2, 1, 0.1);
}
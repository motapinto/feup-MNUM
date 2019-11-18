#include <stdio.h>
#include <math.h>

double f (double x, double y) {
    return -1.7*x*y + 12*y + 7*x*x -8*x;
}
double dfdx (double x, double y) {
    return -1.7*y + 14*x -8;
}
double dfdy (double x, double y) {
    return -1.7*x + 12 ;
}

void gradiente(double x0, double y0, double lambda) {
    double x, y;

    for(int i=0; i<1; i++) {
        x = x0 - lambda*dfdx(x0, y0);
        y = y0 - lambda*dfdy(x0, y0);
        printf("%f \n", f(x, y));
    }
}

int main() {
    gradiente(2.4, 4.3, 0.1);
}
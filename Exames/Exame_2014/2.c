#include <stdio.h>
#include <math.h>

double g(double x) {
    return -x+40*cos(sqrt(x))+3;
}

double dg(double x) {
    return -(20*sin(sqrt(x)))/sqrt(x)-1 ;
}

int main() {
    double x, x0 = 1.7;
    for(int i=0; i<=2; i++) {
        printf("%f %f\n", x0, g(x0));
        x = x0 - g(x0)/dg(x0);
        x0 = x;
    }
}
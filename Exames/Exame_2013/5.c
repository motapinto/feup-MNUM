#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x-3.7)+pow(cos(x+1.2), 2);
}

double df(double x) {
    return 1-2*cos(x+1.2)*sin(x+1.2);
}

double newton(double x0) {
    double x = x0 - f(x0)/df(x0);
    return x;
}

int main() {
    printf("%f\n", newton(3.8));
}
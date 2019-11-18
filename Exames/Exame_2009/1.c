#include <stdio.h>
#include <math.h>

double f (double x) {
    return (x-2.6) + pow(cos((x+1.1)), 3);
}

double df (double x) {
    return 1 - 3 * pow(cos(x+1.1), 2) * sin(x+1.1);
}

int main() {
    double x0 = 1.8, x;
    for(int i=0; i<1; i++) {
        x = x0 - (f(x0)/df(x0));
        x0 = x;
        printf("%f\n", x);
    }
}
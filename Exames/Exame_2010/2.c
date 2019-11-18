#include <stdio.h>
#include <math.h>

double g(double x) {
    return 2*log(2*x);
}

int main() {
    double x = 0.9;
    for (int i=0; i<2; i++) {
        printf("%f\n", x);
        x = g(x);
        printf("Residuo: %f\n", x-0.9);
    }
}
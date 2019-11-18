#include <stdio.h>
#include <math.h>

double g(double x) {
    return pow((4*x*x*x - x + 3), 0.25);
}

void pic(double x0) {

    double x;
    for(int i=0; i<2; i++) {
        x = g(x0);
        printf("%f\n", x);
        x0 = x;
    }
}

int main() {
    pic(3.5);
}
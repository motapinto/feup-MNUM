#include <stdio.h>
#include <math.h>


double f(double x) {
    return pow(x, 7) + x/2 - 0.5;
}

void met_corda(double a, double b) {
    double xn;

    for(int i=0; i<4; i++) {
        printf("xe: %f\n", a);
        printf("xd: %f\n", b);
        xn = (a*f(b)-b*f(a))/(f(b)-f(a));

        if(f(a)*f(xn) < 0) {
            b = xn;
        } else {
            a = xn;
        }

        printf("xn: %f\n", xn);
    }
}

int main () {
    met_corda(0, 0.8);
}
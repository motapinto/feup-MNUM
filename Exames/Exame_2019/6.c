#include <math.h>
#include <stdio.h>

#define B       (sqrt(5)-1)/2
#define A       B*B

double f(double x) {
    return pow((x-5), 2) + x*x*x*x;
}

double df(double x) {
    return 2*(x-5) + 4*x*x*x;
}

void aurea(double x1, double x2) {
    double x3,x4;
    for(int i=0; i<10; i++) {
        x3 = A*(x2-x1) + x1;
        x4 = B*(x2-x1) + x1;
        printf("%f %f %f %f \n", x1,x2,x3,x4);
        if(f(x3) > f(x4))
            x1 = x3;
        else
            x2 = x4;
    }
}

int main() {
    aurea(0.5, 2);
}
#include <stdio.h>
#include <math.h>

#define B       (sqrt(5)-1)/2
#define A       B*B

double f(double x) {
    return 5*cos(x)-sin(x);
}

void aurea(double x1, double x2) {
    double x3, x4;

    for(int i=0; i<=2; i++) {
        printf("%f %f ", x1, x2);
        x3 = A*(x2-x1) + x1;
        x4 = B*(x2-x1) + x1;
        printf("%f %f ", x3, x4);
        printf("%f %f %f %f\n", f(x1), f(x2), f(x3), f(x4));

        if(f(x3)>f(x4))
            x1 = x3;
        else 
            x2 = x4;
    }
     printf("\nComo |x3-x2| = %f entao esse e o amplitude onde se encontra o minimo", x2-x3);
}

int main() {
    aurea (2, 4);
    printf("\nComo na ultima iteracao o valor de f(x3) > f(x4) --->>> o minimo encontra -se entre o intervalo [x3,x2]\n");
}
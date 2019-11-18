#include <stdio.h>
#include <math.h>

#define B (sqrt(5)-1)/2
#define A B*B

double f(double x) {
    return 5*cos(x)-sin(x);
}

void aurea(double x1, double x2) {
    double x3, x4;
    for(int i=0; i<3; i++) {
        printf("x1:%f\nx2:%f\n", x1, x2);

        x3 = x1 + A*(x2-x1);
        x4 = x1 + B*(x2-x1);
        printf("x3:%f\nx4:%f\n\n", x3, x4);
        printf("fx1:%f\nfx2:%f\n", f(x1), f(x2));
        printf("fx3:%f\nfx4:%f\n\n\n", f(x3), f(x4));

        if(f(x3)>f(x4))
            x1 = x3;
        else
            x2 = x4;
    }
}

int main()
{
    aurea(2, 4);
}
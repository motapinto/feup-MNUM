#include <stdio.h>
#include <math.h>

double z(double x, double y) {
    return 6*x*x-x*y+12*y+y*y-8*x;
}
double dfdx(double x, double y) {
    return 12*x-y-8;
}
double dfdy(double x, double y) {
    return -x+12+2*y;
}


void gradiente(double x0, double y0, double h) {
    double x, y;
    for(int i=0; i<2; i++){
        printf("Z: %f\n", z(x0,y0));
        x = x0 - h*dfdx(x0, y0);
        y = y0 - h*dfdy(x0, y0);
        printf("%f\n", dfdx(x0, y0));
        printf("%f\n", dfdy(x0, y0));
        printf("x:%f y:%f\n\n", x, y);
        if(z(x,y)>z(x0,y0))
            h/=2;
        else
            h*=2;
        x0 = x, y0 = y;
    }
}

int main() {
    gradiente(0, 0, 0.25);
}
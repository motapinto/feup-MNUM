#include <stdio.h>
#include <math.h>

int main() {
    double x=0,y=0,z=0;
    double xn=x,yn=y,zn=z;

    for(int i=0; i<50; i++) {
        xn = (1.2  - 61*yn - 41*zn) / 103;
        yn = (-x-3*z) / 5.5;
        zn = (-2*x - 10*y -13 ) / 13;
        printf("%F %f %f \n", xn, yn, zn);
    }
}
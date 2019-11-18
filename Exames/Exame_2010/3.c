#include <stdio.h>
#include <math.h>

double dxdt(double t, double x) {
    return sin(x)+sin(2*t);
}

double rk4(double t0, double x0, double h) {
    double x, t;
    double d1,d2,d3,d4;

    for(double i = t0; i<1.5; i+=h) {
        d1 = h*dxdt(t0, x0);
        d2 = h*dxdt(t0+h/2, x0+d1/2);
        d3 = h*dxdt(t0+h/2, x0+d2/2);
        d4 = h*dxdt(t0+h, x0+d3);

        t = t0 + h;
        x = x0 + d1/6 + d2/3 + d3/3 + d4/6;
        x0 = x, t0 = t;
        //printf("t:%f\nx:%f\n\n", t, x);
    }
    return x;
}

int main() {
    double s,s1,s2;
    s = rk4(1, 0, 0.5);
    s1 = rk4(1, 0, 0.25);
    s2 = rk4(1, 0, 0.25/2);
    printf("%f\n", (s1-s)/(s2-s1));
    printf("Como o Qc esttá longe de 16 voltar a dividr h por 2 = 0.0625")
}
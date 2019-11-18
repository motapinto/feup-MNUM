#include <stdio.h>
#include <math.h>

double f(double x) {
    return sqrt( 1+ pow(1.5*pow(exp(1), 1.5*x), 2) );
}

double trap(double x0, double xn, double h) {
    double sum = f(x0)+f(xn);
    for(double i=x0+h; i<xn; i+=h) {
        sum += 2*f(i);
    }
    return sum*h/2;
}

double simp(double x0, double xn, double h) {
    double sum = f(x0)+f(xn);
    int p=4, k=1;

    for(double i=x0+h; i<xn; i+=h) {
        if(k%2 == 0)
            p = 2;
        else
            p = 4;
        sum += p*f(i);
        k++;
    }
    return sum*h/3;
}

int main()
{
    double s, s1, s2;
    double k1, k2, k3;

    s = trap(0, 2, 0.5);
    s1 = trap(0, 2, 0.25);
    s2 = trap(0, 2, 0.125);

    k1 = simp(0, 2, 0.5);
    k2 = simp(0, 2, 0.25);
    k3 = simp(0, 2, 0.125);

    printf("%f\t%f\t%f\n", s, s1, s2);
    printf("%f\t%f\t%f\n", k1, k2, k3);
    printf("%f \t\t %f\n", ((s1-s)/(s2-s1)), ((k2-k1)/(k3-k2)));
    printf("%f\t%f\n\n", (s2-s1)/3, (k3-k2)/15);
}
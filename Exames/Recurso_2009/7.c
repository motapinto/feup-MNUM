#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(1.5*x);
}

double simp(double a, double b, double h) {
    double sum = f(a) + f(b);
    int p=4, k=1;
    for(double i=a+h; i<b; i+=h) {
        if(k%2 == 0)
            p = 2;
        else
            p = 4;
        sum+=p*f(i);
        k++;
    }
    return sum*h/3;
}

int main() {
    double s, s1, s2;

    s = simp(2.5, 3, 0.125);
    s1 = simp(2.5, 3, 0.125/2);
    s2 = simp(2.5, 3, 0.125/4);
    printf("%f\n%f\n%f\n\n", s, s1, s2);
    printf("qc: %f\n", (s1-s)/(s2-s1));
    printf("erro: %f\n", (s2-s1)/15);
}
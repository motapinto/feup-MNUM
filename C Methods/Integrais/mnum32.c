#include <stdio.h>//metodo trapezio
#include<math.h>

double function(double x)
{
    return sin(x);
}

int main()
{
    double x0 = 0, xn = M_PI;
    double y0 = function(x0), yn = function(xn);
    double S=0, sum;
    int n_int = 8;
    
    double h = (double)(xn-x0)/n_int;

    for(int i=0; i<n_int; i++){
        S+=function(x0);
        x0 = x0 + h;
    }

    sum = (h/2) * (y0+yn+2*S);
    printf("%f\n", sum);

}


//h=pi()/4 (número de steps, isto é, a altura de cada trapézio)
//r (i=1;i<n-1;i++)
//S=2*S+f(x0)+f(xn
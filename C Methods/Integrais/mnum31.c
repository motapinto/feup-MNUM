#include <stdio.h>//metodo trapezio

double function(double x)
{
    return x*x;
}

double integral_val (int low, int n, double dx)
{
    double area_sum = 0;
    int i=0;

    for(i=0; i<n; i++){
        
        double x1 = low + i*dx;
        double x2 = low + (i+1)*dx;
        double f_val1 = function(x1);
        double f_val2 = function(x2);
        double trapezio = (f_val1 + f_val2) * (x2-x1)/2;
        area_sum +=trapezio;
    }
    return area_sum;
}


int main()
{
    double low_bound = 0;
    double up_bound = 2;
    int n_int = 100;
    double dx = (double)(up_bound - low_bound)/n_int; //dx is the difference between x0, x1,x2, ...

    printf("%f\n", integral_val(low_bound, n_int, dx));
}
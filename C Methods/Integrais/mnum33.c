#include <stdio.h>//metodo simpson ajusta com uma parobla e tem mais intervalos intercalares = + precisao
#include <math.h>

double function(double x)
{
    return sin(x);
}

double simpson_method(double x0, double xn, int n_int)
{
    double y0 = function(x0), yn = function(xn);
    double S1=0, S2=0, sum=0;

    double h = (double)(xn-x0)/(2*n_int);//divide pelo dobro dos espacos

    for(int i=2; i<=2*n_int-2; i+=2){//S2= somatorio de i=2,4 ate 2n-2 de f(xi)
        S2+=function(x0+h*i);
    }


    for(int i=1; i<=2*n_int-1; i+=2){ //S1 = somatorio de i=1,3 ate 2n-1 de f(xi)
        S1=S1+function(x0+h*i);
    }

    sum = (h/3) * (y0+yn+4*S1+2*S2);
    printf("%f\n", sum);
    return sum;
}

int main()
{
    double x0 = 0, xn = M_PI, S, S1, S2;
    int n=2;
    S1=simpson_method(x0, xn, n);
    S2=simpson_method(x0, xn, n*n);//S2 = S'
    S3=simpson_method(x0, xn, n*n*n);//S3 = S''

    while((S1-S)/(S2-S1) > 16){

    }

    

}

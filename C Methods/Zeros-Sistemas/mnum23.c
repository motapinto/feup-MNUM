
#include <stdio.h>//newton method/metodo tangente//newton-rhapson
#include <stdlib.h>
#include <math.h>// compile with -lm

double f(double x)
{
    return x-2*log(x)-5;
}
double df (double x)
{
    return -2/x +1;
}


int main()
{
    int i=0;
    double xn, x0=3, erro=5;

    while(erro>=0.00001)
    {
        if(df(x0)==0){
            printf("df(x0) = 0\n");
            break;
        }

        xn = x0 - f(x0)/df(x0);//!!!!!!!!
        erro = fabs(x0-xn);
        x0=xn;
        i++;
    }
    printf("%f em %d iteracoes\n", xn, i);
}
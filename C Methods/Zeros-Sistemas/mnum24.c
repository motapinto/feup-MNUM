//Picard peano method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>// compile with -lm

double f(double x)
{
    return x-2*log(x)-5;
}

double transf_pic(double x)//g(x)=2ln(x)+5
{
    return 2*log(x)+5;
}

double transf_pic2(double x)//g(x)=e^((x-5)/2)
{
    return exp((x-5)/2);
}



int main()//erro = |xn-xn+1|
{
    int i=0;
    double gx0, gxn, xn=1, x0=7.0;
    double erro=2;

    while (erro>= 0.00001)
    {
        gx0 = transf_pic2(x0);
        xn = gx0;
        gxn = transf_pic2(xn);
        erro = fabs(x0-xn);
        x0=xn;
        i++;
    }
    printf("%f in %d iterations\n", gxn, i);
}
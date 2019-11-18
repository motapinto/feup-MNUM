#include <stdio.h>//metodo da corda/falsa posicao
#include <stdlib.h>
#include <math.h>// compile with -lm

int main()
{
    double a1=9, b1=10, xn1, fxn1, xn2, fxn2;
    double fa1 = a1- 2*log(a1)-5;
    double fb1 = b1 - 2*log(b1)-5;
    int i=0;

    xn1 = (a1*fb1 - b1*fa1)/(fb1-fa1);
    fxn1 = xn1 - 2*log(xn1)-5;

    b1 = xn1;
    fb1 = fxn1;

    xn2 = (a1*fb1 - b1*fa1)/(fb1-fa1);
    fxn2 = xn2 - 2*log(xn2)-5;


    b1= xn2;
    fb1 = fxn2;

    i+=2;

    while(fabs(xn1-xn2) >= 0.00001)
    {
        xn1 = (a1*fb1 - b1*fa1)/(fb1-fa1);
        fxn1 = xn1 - 2*log(xn1)-5;

        b1 = xn1;
        fb1 = fxn1;

        xn2 = (a1*fb1 - b1*fa1)/(fb1-fa1);
        fxn2 = xn2 - 2*log(xn2)-5;

        b1= xn2;
        fb1 = fxn2;

        i+=2;
    }

    printf("%f é a primeira raiz em %d iterações\n", xn1, i); 
}

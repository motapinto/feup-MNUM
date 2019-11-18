#include <stdio.h>//metodo da bissecao
#include <stdlib.h>
#include <math.h>// compile with -lm

int main()//abrir maxima e definir um intervalo a1 e b1; definir metodo de paragem; fazer algoritmo
{
    double a1=0.01, b1=0.5, fa1, fb1, xn, fxn;
    int i=0;

    while(fabs(b1-a1) >= (0.000010))
    {

        fa1 = a1- 2*log(a1)-5;
        fb1 = b1 - 2*log(b1)-5;
        xn = (a1+b1)/2;
        fxn = xn - 2*log(xn)-5;

        if(fa1*fxn<0)
        {   
            b1 = xn;
        }

        else 
        {
            a1 = xn;
        }
        ++i;

    }

    printf("%f é a primeira raiz em %d iterações\n", xn, i); 


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    double a2=9.0, b2=10.0, fa2, fb2, xn2, fxn2;
    int i2=0;

    while(fabs(b2-a2) > (0.000010))
    {

        fa2 = a2- 2*log(a2)-5;
        fb2 = b2 - 2*log(b2)-5;
        xn2 = (a2+b2)/2;
        fxn2 = xn2 - 2*log(xn2)-5;

        if(fa2*fxn2<0)
        {   
            b2 = xn2;
        }

        else 
        {
            a2 = xn2;
        }
        i2++;

    }

    printf("%f é a segunda raiz em %d iterações\n", xn2, i2); 

}

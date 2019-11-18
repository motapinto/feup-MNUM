#include <stdio.h> // INtegral DUplo
#include <math.h>

double function(double x, double y)
{
    return sin(x+y);
}

double int_duplo(double a, double b, double A, double B, int n_int)
{
    double S0=0, S1=0, S2=0, sum=0;
    double hx = (A-a)/n_int;
    double hy = (B-b)/n_int;
    double x1=a, y1=b, i=0;

    //pontos dos vertices do retangulo de lados A-a E b-B 
    //S0 = soma dos valores nos vertices da malha,
    S0=function(a, b) + 4*function(a, B)+ function(A, b)+ function(A, B); 

    for(x1 = a; x1 < A; x1 = x1 + i*hx ){ 
        for(y1=b; y1<B; y1=x1+i*hx){ 
            S1+=function(x1,b)+4*function(a,y1)+function(A, y1)+function(x1,B);//S1 = (..) nos pontos medios dos lados da malha
            S2+=function(x1,y1); //calcula valores de f no centro da malha
            i++;
            
        }
    }
    
    sum = (hx*hy/9) * (S0+4*S1+16*S2) ;
    printf("sum = %f\n", sum);              
    return sum;
}

int main()
{
    double x0 = 0, xn = M_PI;
    double y0=0, yn=M_PI;
    double S=0, S1=0, S2=0;
    int n=10;

    int_duplo(x0, y0, xn, yn, n);
    

}
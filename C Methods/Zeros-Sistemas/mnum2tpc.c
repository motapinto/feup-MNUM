//funcao: 2^raiz(x)-10x+1
//funcao: x²-x-12

#include <stdio.h>
#include <math.h>

double f(double x)
{
    //return x*x -x -12;
    return pow(2.0, sqrt(x)) -10*x +1 ;
}

double df(double x)
{
    //return 2*x-1;
    return (log(2)*pow(2, sqrt(x)-1))/(sqrt(x)) -10 ;
}

double transf_pic(double x)
{
    return x*x-12 ;//sqrt(x+12)
}

double transf_pic2(double x)
{
    return sqrt (x+12);
}

double dtransf_pic2(double x)
{
    return 1/(2*sqrt(1+12));
}

double bissection(double xa, double xb, int *i)//recebe o intervalo e apontador do contador
{
    *i = 0;
    double xn, erro=5;
    
    while(erro>0.00001){// metodo de paragem
        xn = (xa+xb)/2;
        if(f(xa)*f(xn)<0){
            erro = fabs(xn -xb);
            xb = xn;
        }
        else{
            erro = fabs(xn -xa);
            xa = xn;
        }
        *i+=1;
    }

    return xn;
}

double falsa_pos(double a, double b, int *i)
{
    double xn, erro=5.0;
    *i=0;

    while(erro>0.00001){
        xn = (a*f(b)-b*f(a))/(f(b)-f(a));

        if(f(a)*f(xn)<0){
            erro = fabs(xn-b);
            b = xn;
        }
        else{
            erro = fabs(xn-a);
            a = xn;
        }
        *i+=1;
    }

    return xn;
}

double newton_method (double x0, int *i)
{
    *i=0;
    double xn, erro=5;

    while(erro>=0.00001)
    {
        if(df(x0)==0){
            printf("df(x0) = 0\n");
            return -1;
        }
        xn = x0 - f(x0)/df(x0);
        erro = fabs(x0-xn); 
        x0=xn;
        *i+=1;
    }
    return xn;
}   

double picard_perno (double x0, int *i)
{
    *i=0;
    double xn, gx0, gxn;
    double erro=5;

    while (erro>= 0.00001)
    {
        if(fabs(dtransf_pic2(x0))>=1){
            break;
            return -1;
        }
        gx0 = transf_pic(x0);
        xn = gx0;
        erro = fabs(x0-xn);
        x0=xn;
        *i+=1;
    }
    return xn;
}

int main()
{
    int contador=0;

    double result_bissection1 = bissection(0.0, 2.0, &contador);
    printf("%f\t Is the first root using the bissection method in %d iterations!\n", result_bissection1, contador);
    //double result_bissection2 = bissection(2.0, 7.0, &contador);
    //printf("%f\t Is the second root using the bissection method in %d iterations!\n\n", result_bissection2, contador);
    
    double result_falsa_pos1 = falsa_pos(0.0, 2.0, &contador);
    printf("%f\t Is the first root using the false position method in %d iterations!\n", result_falsa_pos1, contador);
    //double result_falsa_pos2 = falsa_pos(2.0, 7.0, &contador);
    //printf("%f\t Is the second root using the false postion method in %d iterations!\n\n", result_falsa_pos2, contador);
    
    double newton1 = newton_method(4.0, &contador);
    printf("%f\t Is the first root using the newton method in %d iterations!\n", newton1, contador);
    //double newton2 = newton_method(2.0, &contador);
    //printf("%f\t Is the second root using the newton method in %d iterations!\n\n", newton2, contador);

    double picard1 = picard_perno(0.1, &contador);
    printf("%f\t Is the first root using the picard perno method in %d iterations!\n", picard1, contador);
    double picard2 = picard_perno(0.2, &contador);
    printf("%f\t Is the second root using the picard perno method in %d iterations!\n\n", picard2, contador);
}

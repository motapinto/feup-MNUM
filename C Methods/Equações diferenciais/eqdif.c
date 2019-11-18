#include <math.h>
#include <stdio.h>

double f(double x, double y){
    return pow(x, 2) + pow(y, 2);
}



double rk2(double x0, double y0, double xn, double h){
    double x1, y1;
    int n=(xn-x0)/h;

    while (n>0) { 
     x1 = x0+h;
     y1 = y0+h*f(x0+h/2, y0+(h/2)*f(x0, y0));
   
     x0 = x1;
     y0=y1;
     n--;
    } 
    return y0;
}

double rk4(double x0, double y0, double xn, double h){
    double x1, y1, k1, k2, k3, k4;
    int n=(xn-x0)/h;

    while (n>0) { 
     k1 = h*f(x0, y0);
     k2 = h*f(x0+ (h/2), y0 + (k1/2));
     k3 = h*f(x0+ (h/2), y0 + (k2/2));
     k4 = h*f(x0+h, y0+k3);

     x1 = x0+h;
     y1 = y0+ k1/6 + k2/3 + k3/3 + k4/6;

     x0 = x1;
     y0=y1;
     n--;
    } 
    return y0;
}

double euler(double x0, double y0, double xn, double h){
    double x1, y1;
    int n=(xn-x0)/h;

    while (n>0) { 
     x1 = x0+h;
     y1 = y0+h*f(x0, y0);
  
     x0 = x1;
     y0=y1;
     n--;
    } 
    return y0;
}

double err_rk4(double x0, double y0, double xn, double h, double *erro)
{
    double S=rk4(x0, y0, xn, h); 
    double S1=rk4(x0, y0, xn, h/2);
    double S2=rk4(x0, y0, xn, h/2); 
    *erro = (S2-S1)/15;

    return (S1-S)/(S2-S1);//qc
}

double err_rk2(double x0, double y0, double xn, double h, double *erro)
{
    double S=rk2(x0, y0, xn, h);
    double S1=rk2(x0, y0, xn, h/2);
    double S2=rk2(x0, y0, xn, h/4);
    *erro = (S2-S1)/3;

    return (S1-S)/(S2-S1);//qc
}

double err_euler(double x0, double y0, double xn, double h, double *erro)
{
    double S=euler(x0, y0, xn, h);
    double S1=euler(x0, y0, xn, h/2);
    double S2=euler(x0, y0, xn, h/4);
    *erro = (S2-S1);

    return (S1-S)/(S2-S1);//qc
}

int main()
{
    double x0=0, y0=0, h=0.1, xn=1.4;
    double erro_rk2=0, erro_rk4=0, erro_euler=0;
    int i;

    double rk_2 = rk2(x0, y0, xn, h);
    double rk_4 = rk4(x0, y0, xn, h);
    double euler_e = euler(x0, y0, xn, h);
    
    printf("\nrk2: \t%f\n", rk_2);
    printf("rk4: \t%f\n", rk_4);
    printf("euler: \t%f\n\n", euler_e);

    double qc_euler = err_euler(x0, y0, xn, h, &erro_euler);
    double qc_rk2 = err_rk2(x0, y0, xn, h, &erro_rk2);
    double qc_rk4 = err_rk4(x0, y0, xn, h, &erro_rk4);

    printf("\n EULER-> QC: %f \t ERRO: %f\n", qc_euler, erro_euler);
    printf("\n RK2-> QC: %f \t ERRO: %f\n", qc_rk2, erro_rk2);
    printf("\n RK4-> QC: %f \t ERRO: %f\n\n\n", qc_rk4, erro_rk4);

   


}

  
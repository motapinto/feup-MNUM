#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define PRECISION 0.001

double f1(double x, double y){
    return (y*y - 2*x*y - 6*y + 2*x*x + 12);
}

double f1dx(double x, double y){
    return (4*x - 2*y);
}

double f1dy(double x, double y){
    return (2*y - 2*x - 6);
}

double f2 (double x, double y) {
  return 2*x*y + 2*x -x*x -2*y*y;
}

double f2dx(double x, double y){
    return 2*y - 2*x + 2;
}

double f2dy(double x, double y){
    return 2*x-4*y;
}

int main()
{
    double h = 1, x = 1, y = 1;//x e y sao os x's anteriores
    double xn, yn;
    int counter = 0;
    bool condition = true;

    printf("\n\tMetodo Gradiente:\n\n");

    //EXERCICIO DE MINIMO
    while (condition)
    { 
        xn = x - h * f1dx(x, y);
        yn = y - h * f1dy(x, y);

        if (f1(xn, yn) < f1(x, y))    h = h * 2.0;

        else                          h = h / 2.0;

        if(fabs(yn-y) < PRECISION && fabs(xn-x) < PRECISION)
          condition = false;

        x=xn, y=yn;
        counter++;
    }

    printf("\n Minimo para (%.6f, %.6f):\t\t%.1f\n", x, y, f1(x,y));
    printf(" Contador: \t\t\t\t\t%d\n\n", counter);

    h = 1, x = -1, y = 1;//xt e yt sao os x's anteriores
    counter = 0;
    condition = true;

//EXERCICIO DE MAXIMO
    while (condition)
    {
        xn = x + h * f2dx(x, y);
        yn = y + h * f2dy(x, y);

        if (f2(xn, yn) < f2(x, y))    h = h / 2.0;

        else                          h = h * 2.0;

        if(fabs(yn-y) < PRECISION && fabs(xn-x) < PRECISION)
          condition = false;

        x=xn, y=yn;
        counter++;
    }
  printf("\n Maximo para (%.6f, %.6f):\t\t%.1f\n", x, y, f2(x,y));
  printf(" Contador: \t\t\t\t\t%d\n\n", counter);
}

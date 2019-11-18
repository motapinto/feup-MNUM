#include <stdio.h>
#include <math.h>

double f(double x, double y){ //y=t, x=x
  return sin(2*x)+sin(2*y);
}

void rk4(double x, double y, double h){
  double d1,d2,d3,d4;
  double c0, c1, c2;
  double xn=x, yn=y; 
  int i=0;

  for(int i=0; i<1; i++){
    d1 = h*f(xn, yn);
    d2 = h*f(xn+h/2, yn+d1/2);
    d3 = h*f(xn+h/2, yn+d2/2);
    d4 = h*f(xn+h, yn + d3);

    xn += h;
    yn += d1/6 + d2/3 + d3/3 + d4/6;
    c0=yn;
    printf("S: %f\n", c0);
  }

  h=h/2;
  xn=x, yn=y;

  for(int i=0; i<2; i++){
    d1 = h*f(xn, yn);
    d2 = h*f(xn+h/2, yn+d1/2);
    d3 = h*f(xn+h/2, yn+d2/2);
    d4 = h*f(xn+h, yn+d3);

    xn += h;
    yn += d1/6 + d2/3 + d3/3 + d4/6;
    if(i==1){
      c1=yn;
      printf("S1: %f\n", c1);
    }
  }

  h=h/2;
  xn=x, yn=y;

  for(int i=0; i<4; i++){
    d1 = h*f(xn, yn);
    d2 = h*f(xn+h/2, yn+d1/2);
    d3 = h*f(xn+h/2, yn+d2/2);
    d4 = h*f(xn+h, yn+d3);

    xn += h;
    yn += d1/6 + d2/3 + d3/3 + d4/6;
    //printf("x: %f\ny: %f\n\n", x, y);
    if(i==3){
      c2=yn;
      printf("S2: %f\n", c2);
    }
  }
  printf("QC: %f\n", (c1-c0)/(c2-c1));
}
int main()
{
  double x0=1.0, y0=1.0, h=0.5;
  rk4(x0, y0, h);
//c)O QC no metodo de rk4 tem de variar entre 4-16 para convergir
}

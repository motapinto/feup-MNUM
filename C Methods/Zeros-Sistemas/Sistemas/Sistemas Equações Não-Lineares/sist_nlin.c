#include <stdio.h>
#include <math.h>

double g1(double x, double y){//funcao g em funcao de x : x=g(x)
    return sqrt((5*x+x*y-1)/2);
}
double g2(double x, double y){//funcao g em funcao de y : y=g(x)
    return sqrt(x+3*log(x));
}
double dg1dx(double x, double y){//usada no metodo de newton
  return (y+5)/(pow(2, 1.5)*sqrt(x*y+5*x-1));
}
double dg1dy(double x, double y){//usada no metodo de newton
  return x/(pow(2, 1.5)*sqrt(x*y+5*x-1));
}
double dg2dx(double x, double y){
  return (3/x+1)/(2*sqrt(3*log(x)+x));
}
double dg2dy(double x, double y){
  return 0;
}


double f1(double x, double y){
  return 2*x*x-x*y-5*x+1;
}
double f2(double x, double y){
  return x+3*log(x)-y*y;
}
double df1dx(double x, double y){
  return 4*x-y-5;
}
double df1dy(double x, double y){
  return -1;
}
double df2dx(double x, double y){
  return 1+3/x;
}
double df2dy(double x, double y){
  return -2*y;
}



double sist_newton(double x0, double y0){
  double x1, y1;
  int i=100;

  while(1){
      if(df1dx(x0, y0)*df2dy(x0, y0)-df2dx(x0, y0)*df1dy(x0, y0) == 0){//denominador
        return -1;
      }
      x1 = x0 - (f1(x0, y0)*df2dy(x0, y0)-f2(x0, y0)*df1dy(x0, y0))/(df1dx(x0, y0)*df2dy(x0, y0)-df2dx(x0, y0)*df1dy(x0, y0));
      y1 = y0 - (f2(x0, y0)*df1dx(x0, y0)-f1(x0, y0)*df2dx(x0, y0))/(df1dx(x0, y0)*df2dy(x0, y0)-df2dx(x0, y0)*df1dy(x0, y0));

      if((fabs(x1-x0)<0.00001 && fabs(y1-y0)<0.00001) || i<0){
          break;
      }
      x0=x1;
      y0=y1;
      i--;
  }
  printf("\tSoluçao newton\nx0 = %f e y0= %f\n\n", x0, y0);
  return 0;
}


double sist_peano(double x0, double y0){
  double x1, y1;

  while(1){

      x1 = g1(x0, y0);
      y1 = g2(x0, y0);

      if(fabs(x1-x0)<0.00001 && fabs(y1-y0)<0.00001){
          break;
      }
      x0=x1;
      y0=y1;
  }
  printf("\tSoluçao pic_peano\nx0 = %f e y0= %f\n\n", x0, y0);
  return 0;
}

int main()
{
    double x0 = 4, y0 = 4;//guess inicial
    sist_peano(x0, y0);
    //sist_newton(3, 3);
    sist_newton(x0, y0);
}

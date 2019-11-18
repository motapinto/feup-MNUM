#include <stdio.h>
#include<math.h>

double f(double x)
{
    return sin(x);
}

double simpson_method(double x0, double xn, double h)
{
    double integral=0;
    int p=0, k=0;

    for(double i=x0; i<=xn; i+=h){ //S1 = somatorio de i=1,3 ate 2n-1 de f(xi)

      if(i == x0 || i==xn)    p = 1;
      else if(k % 2 == 0)     p = 2;
      else                    p = 4;

      integral = integral + p*f(i);
      k++;
    }

    integral=(h/3)*integral;
    return integral;
}

double trapezio(double x0, double xn, double h)
{
    double y0 = f(x0), yn = f(xn);
    double sum=0;

    for(double i=x0; i<=xn; i+=h)
        sum += f(i);

    sum = (h/2) * (y0+yn+2*sum);
    return sum;
}

double erro_simpson(double x0, double xn, double h, double *erro) {
  double S, S1, S2;
  S=simpson_method(x0, xn, h);
  S1=simpson_method(x0, xn, h/2);//S1 = S'
  S2=simpson_method(x0, xn, h/4);//S2 = S''
  *erro = fabs((S2-S1)/15);
  return (S1-S)/(S2-S1);
}

double erro_trapezio(double x0, double xn, double h, double *erro) {
  double S, S1, S2;
  S=trapezio(x0, xn, h);
  S1=trapezio(x0, xn, h/2);//S1 = S'
  S2=trapezio(x0, xn, h/4);//S2 = S''
  *erro = fabs((S2-S1)/3);
  return (S1-S)/(S2-S1);
}

int main()
{
  double x0=0.0, xn=M_PI, h=M_PI/8;
  double qc_trap, qc_simp, trap_result, simp_result;
  double erro_trap, erro_simp;

  trap_result = trapezio(x0, xn, h);
  simp_result = simpson_method(x0, xn, h);


  printf("\tTrapezio: %f\n\tSimpson: %f\n\n", trap_result, simp_result);
  qc_trap = erro_trapezio(x0, xn, h, &erro_trap);
  qc_simp = erro_simpson(x0, xn, h, &erro_simp);

  printf("\t\t Método do trapezio\n");
  printf("\tQC:%f\tErro:%f\n", qc_trap, erro_trap);
  printf("\t\t Método de Simpson\n");
  printf("\tQC:%f\tErro:%f\n\n", qc_simp, erro_simp);

}
/*

trapezio-----
Erro = (I''-I') / 3
QC= (I'-I) / (I'' - I' ) ; (qc idela deve ser aproximadamente 4)

simpson_method -----
Erro = (I''-I') / 15
QC= (I'-I) / (I'' - I' ) ; (qc idela deve ser aproximadamente 16)

*/

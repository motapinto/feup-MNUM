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

double f2 (double x, double y){
  return 2*x*y + 2*x -x*x -2*y*y;
}

double f2dx(double x, double y){
    return 2*y - 2*x + 2;
}

double f2dy(double x, double y){
    return 2*x-4*y;
}

// inversa da matriz hessiana de f (determinante)
double invH1(double x, double y) {
	return 0.25;
}

// inversa da matriz hessiana de f2 (determinante)
double invH2(double x, double y) {
	return 0.25;
}

void quadrica_min(double x, double y) {
	double xn, yn;
  int counter = 0;
	bool continua = true;

	while (continua) {
		xn = x - invH1(x,y) * f1dx(x, y);
		yn = y - invH1(x,y) * f1dy(x, y);
		if (fabs(xn - x) < PRECISION && fabs(yn - y) < PRECISION)
			continua = false;
		x = xn , y = yn;
    counter++;
	}

	printf("\n Minimo para (%.6f, %.6f):\t\t%.1f\n", x, y, f1(x,y));
  printf(" Contador: \t\t\t\t\t%d\n\n", counter);

}

void quadrica_max(double x, double y) {
	double xn, yn;
  int counter = 0;
	bool continua = true;
	while (continua) {
		xn = x + invH1(x,y) * f2dx(x, y);
		yn = y + invH1(x,y) * f2dy(x, y);
		if (fabs(xn - x) < PRECISION && fabs(yn - y) < PRECISION)
			continua = false;
		x = xn , y = yn;
    counter++;
	}
	printf("\n Maximo para (%.6f, %.6f):\t\t%.1f\n", x, y, f2(x,y));
  printf(" Contador: \t\t\t\t\t%d\n\n", counter);

}

int main()
{
  quadrica_min(1, 1);
  quadrica_max(-1, 1);
}

#include <stdio.h>
#include <math.h>

#define B 						(sqrt(5) - 1) / 2.0 // golden ratio/aurea ration
#define A 						pow(B, 2) //B^2
#define PRECISION 		0.001

double f(double x){
	return (pow(2*x+1, 2)-5*cos(10*x));
}

double f_max(double x){ //inverte a funcao devido a concavidade
	return -(pow(2*x+1, 2)-5*cos(10*x));
}

int main()
{
	// set interval where minimum is located and pre-compute the function on the extremes
	double x1 = -1, x2 = 0;
	double x3 , x4;

	unsigned int counter = 0;

	while (fabs(x1-x2) > PRECISION)
	{
		x3 = A * (x2 - x1) + x1;
		x4 = B * (x2 - x1) + x1;

		if (f(x3) < f(x4))
			x2 = x4; //x1 = x1
		else
			x1 = x3; //x2 = x2

		counter++;
	}

	printf("\nMinimo em %f: %f\n", x2, f(x2));
	printf("Iterations: %d\n\n", counter);

	 x1 = -1, x2 = 0;
	 counter = 0;

	while (fabs(x2 - x1) > PRECISION)
	{
		x3 = A * (x2 - x1) + x1;
		x4 = B * (x2 - x1) + x1;

		if (f_max(x3) < f_max(x4))
			x2 = x4;
		else
			x1 = x3;

		counter++;
	}

	printf("Maximo em %f: %f\n", x2, -f_max(x2));
	printf("Iterations: %d\n\n", counter);

	printf("OUTRA MANEIRA DE FAZER O MAXIMO:\n\n");

	x1 = -1, x2 = 0;
	counter = 0;

 while (fabs(x2 - x1) > PRECISION)
 {
	 x3 = (A * (x2 - x1)) + x1;
 	 x4 = (B * (x2 - x1)) + x1;

	 if (f(x3) > f(x4))
		 x2 = x4;
	 else
		 x1 = x3;

	 counter++;
 }

 printf("Maximo em %f: %f\n", x2, f(x2));
 printf("Iterations: %d\n\n", counter);
}

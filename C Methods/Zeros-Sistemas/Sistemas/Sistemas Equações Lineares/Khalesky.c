#include <stdint.h>
#include <stdio.h>
#include <math.h>


void Seidel(double l[], double r[]);

int main() {
	/*
	Solving the following system
	* 3x + y + z = 7
	* 1x + 4y + 2z = 4
	* 0x + 2y + 5z = 5
	Notice that the convergence criterium is satisfied (diagonal principal)
	*/

	double l[35], u[35], a[35], r[34];

	a[11] = 3;		a[12] = 1;		a[13] = 1;		r[1] = 7;
	a[21] = 1;		a[22] = 4;		a[23] = 2;		r[2] = 4;
	a[31] = 0;		a[32] = 2;		a[33] = 5;		r[3] = 5;

	l[11] = a[11];
	l[21] = a[21];
	l[31] = a[31];

	u[11] = 1;
	u[12] = 1;
	u[13] = 1;

	l[22] = (a[22] - (l[21] * u[12]));
	u[22] = (a[22] - (l[21] * u[12])) / l[22];
	u[23] = (a[23] - (l[21] * u[13])) / l[22];

	l[32] = (a[32] - (l[31] * u[12]));
	l[33] = (a[33] - (l[31] * u[13] + l[32]*u[23]));
	u[33] = (a[33] - (l[21] * u[13] + l[22] * u[23])) / l[33];


	double y1, y2, y3, y4, x1, x2, x3, x4;

	printf("\nL: \n\n");
	printf("%f\t0\t\t0\n\n", l[11]);
	printf("%f\t%f\t0\n\n", l[21], l[22]);
	printf("%f\t%f\t%f\n\n", l[31], l[32], l[33]);

	printf("\nU: \n\n");
	printf("1\t\t1\t\t1\n\n");
	printf("0\t\t%f\t%f\n\n", u[22], u[23]);
	printf("0\t\t0\t\t%f\n\n", u[33]);

	printf("\n\t\t\t\t[L].Y = R\n\n");
	printf("| %f\t0\t\t0\t|\t|Y1| \t = \t |7|\n\n", l[11]);
	printf("| %f\t%f\t0\t|\t|Y2| \t = \t |4|\n\n", l[21], l[22]);
	printf("| %f\t%f\t%f|\t|Y3| \t = \t |5|\n\n", l[31], l[32], l[33]);

	printf("\nSolving...\n");

	Seidel(l, r);
}

void Seidel(double l[], double r[]) {
    // Initial guess
    double x = 0, y = 0, z = 0;
    double xaux, yaux, zaux; //iteracao anterior
    int count=0;

    for(int i = 0; i < 5; i++) {
				xaux = x, yaux = y, zaux = z;

        x = r[1] / l[11];
        y = (r[2]-l[21]*x) / l[22];
				z = (r[3] - l[31]*x - l[32]*y) / l[33];

        if(fabs(x-xaux)<0.00001 && fabs(y-yaux)<0.00001 && fabs(z-zaux)<0.00001){
          printf("\nCount = %d\n\n", count);
          break;
        }

        printf("x: %.6lf\tResiduo: %.6lf\n", x, fabs(7 - 3*x -y -z));
        printf("y: %.6lf\tResiduo: %.6lf\n", y, fabs(4 - x - 4*y -2*z));
        printf("z: %.6lf\tResiduo: %.6lf\n\n", z, fabs(5 - 2*y - 5*z));
        count++;
    }
}

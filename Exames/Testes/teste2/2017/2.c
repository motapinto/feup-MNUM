#include <stdio.h>
#include <math.h>

int main() {
    /*
    Solving the following system
    * 6x + 0.5y + 3z +0.25w = 25
    * 1.2x + 3y + 0.25z + 0.2w = 10
    * -1x + 0.25y + 4z + 2w = 7
    * 2x + 4y + z 8w = -12
    Notice that the convergence criterium is satisfied (diagonal principal)
    */

    // Initial guess
    double x = 2.12687, y = 2.39858, z = 3.99517, w=-3.73040;
    double xaux= x, yaux = y, zaux = z, waux = w; //iteracao anterior
    int count=0;

    for(int i = 0; i < 1; i++) {
        x = (25-0.5*y-3*z-0.25*w)/6;
        y = (10-1.2*x-0.25*z-0.2*w)/3;
        z = (7+x-0.25*y-2*w)/4;
        w = (-12-2*x-4*y-z)/8;

        printf("x: %.6lf\tResiduo: %.6lf\n", x, fabs(25-6*x-0.5*y-3*z-0.25*w));
        printf("y: %.6lf\tResiduo: %.6lf\n", y, fabs(10-3*y-1.2*x-0.25*z-0.2*w));
        printf("z: %.6lf\tResiduo: %.6lf\n", z, fabs(7+x-0.25*y-4*z-2*w));
        printf("w: %.6lf\tResiduo: %.6lf\n\n", w, fabs(-12-2*x-4*y-z-8*w));
        count++;
    }
}

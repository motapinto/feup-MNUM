#include <stdio.h>
#include <math.h>

int main() {
    /*
    Solving the following system
    * 3x + y + z = 7
    * 1x + 4y + 2z = 4
    * 0x + 2y + 5z = 5
    Notice that the convergence criterium is satisfied (diagonal principal)
    */

    // Initial guess
    double x = 0, y = 0, z = 0;
    double xaux=0, yaux=0, zaux=0; //iteracao anterior
    int count=0;

    for(int i = 0; i < 20; i++) {
        x = (7-y-z)/3;
        y = (4-x-2*z)/4;
        z = (5-2*y)/5;

        if(fabs(x-xaux)<0.00001 && fabs(y-yaux)<0.00001 && fabs(z-zaux)<0.00001){
          printf("\nCount = %d\n\n", count);
          break;
        }

        xaux = x;
        yaux = y;
        zaux = z;

        printf("x: %.6lf\tResiduo: %.6lf\n", x, fabs(7 - 3*x -y -z));
        printf("y: %.6lf\tResiduo: %.6lf\n", y, fabs(4 - x - 4*y -2*z));
        printf("z: %.6lf\tResiduo: %.6lf\n\n", z, fabs(5 - 2*y - 5*z));
        count++;
    }
}

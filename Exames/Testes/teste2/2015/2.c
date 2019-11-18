#include <stdio.h>
#include <math.h>

/*
Solving the following system
* 4.5x + -y - z +w = 1
* -x + 4.5y + z - w = -1
* -x + 2y + 4.5z + -w = -1
* 2x + -y - z + 4.5w = 0
Notice that the convergence criterium is satisfied (diagonal principal)
*/

void jacobi(double x, double y, double z, double w)
{
  double xaux=x, yaux=y, zaux=z, waux=w;

  for(int i=0; i<2; i++){
    x = (1 + yaux +zaux -waux)/4.5;
    y = (-1 + xaux -zaux + waux)/4.5;
    z = (-1 + xaux - 2*yaux +waux)/4.5;
    w = (-2*xaux + yaux + zaux)/4.5;

    xaux = x, yaux = y, zaux = z, waux = w;

    printf("x: %f\ny: %f\nz: %f\nw: %f\n\n", x, y, z, w);
  }
}

int main()
{
  double x0=0.25, y0=0.25, z0=0.25, w0=0.25;
  jacobi(x0, y0, z0, w0);
  printf("O metodo converge visto que em cada linha da matriz A o modulo do elemento da diagonalo principal é superior ao modulo  dos restantes elementosdessa linha\n");
}

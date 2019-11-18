#include <stdio.h>
#include <math.h>
/*
6x + 0.5y + 3z + 0.25w = 25
1.2x + 3y + 0.25z + 0.2w = 10
-x + 0.25y + 4z + 2w = 7
2x + 4y + 1z + 8w = -12
*/

void seidel(double x, double y, double z, double w){
  double xaux=x, yaux=y, zaux=z, waux=w; // atualiza durante a iteracao
  int count = 0;
  while(count<1)
  {
    x = (25-0.5*y-3*z-0.25*w)/6;
    y = (10-1.2*x-0.25*z-0.2*w)/3;
    z = (7+x-0.25*y-2*w)/4;
    w = (-12-2*x-4*y-z)/8;

    xaux = x;
    yaux = y;
    zaux = z;
    waux = w;
    count++;
  }
  printf("x: %.6f\ny: %.6f\nz: %.6f\n2: %.6f\n\n", x, y, z, w);
  printf("Count: %d\n", count);
}

int main()
{
  // Initial guess
  double x = 2.83865, y = 2.22131, z = 4.17630, w = -3.84236;
  seidel(x, y, z, w);
}

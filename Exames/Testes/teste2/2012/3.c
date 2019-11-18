#include <stdio.h>

void rowOp(float m[3][4], int r1, int r2, float coef) {
    for(int j = 0; j < 4; j++) { // iterate throw rows elements
        m[r1][j] = m[r1][j] - coef*m[r2][j];
    }
}


void gauss(float m[3][4]) {
    for(int i = 0; i < 3; i++) { //for each row
        rowOp(m, i, i, 1-1/m[i][i]); //put 1 on each diagonal element
        for(int j = 0; j < 3; j++) {
            if(j == i) continue;
            rowOp(m, j, i, m[j][i]); //put zeros above or below
        }
    }
    printf("[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n\n", m[0][0], m[0][1], m[0][2], m[0][3], m[1][0], m[1][1], m[1][2], m[1][3], m[2][0], m[2][1], m[2][2], m[2][3]);
}


int main()
{
    float m1[3][4] = {
            {0.70, 8.0, 3.0, 12.00},
            {-6.0, 0.45, -0.25, 15.0},
            {8.0, -3.10, 1.05, 23.0}
        };

    gauss(m1);
}


/*
  Estabilidade externa:
    Resolvida num ficheiro a aprte 3_est_ext - maxima
*/

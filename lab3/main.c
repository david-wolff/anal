#include "sistlinear.h"
#include "matriz.h"
#include "vetor.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    double** A = create_matrix(n);
    A[0][0] = 1;  A[0][1] = -1; A[0][2] = 0;
    A[1][0] = -1; A[1][1] = 2;  A[1][2] = 1;
    A[2][0] = 0;  A[2][1] = 1;  A[2][2] = 2;
    
    double b[] = {0, 2, 3};
    double* x = create_vector(n);

    gauss(n, A, b, x);

    printf("Solution for the first system:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }

    free_matrix(A, n);
    free_vector(x);

    int m = 6;
    double** B = create_matrix(m);
    B[0][0] = 3;  B[0][1] = -1; B[0][2] = 0;  B[0][3] = 0;  B[0][4] = 0; B[0][5] = 0.5;
    B[1][0] = -1; B[1][1] = 3;  B[1][2] = -1; B[1][3] = 0;  B[1][4] = 0.5; B[1][5] = 0;
    B[2][0] = 0;  B[2][1] = -1; B[2][2] = 3;  B[2][3] = -1; B[2][4] = 0; B[2][5] = 0;
    B[3][0] = 0;  B[3][1] = 0;  B[3][2] = -1; B[3][3] = 3;  B[3][4] = -1; B[3][5] = 0;
    B[4][0] = 0;  B[4][1] = 0.5; B[4][2] = 0; B[4][3] = -1; B[4][4] = 3; B[4][5] = -1;
    B[5][0] = 0.5; B[5][1] = 0;  B[5][2] = 0; B[5][3] = 0;  B[5][4] = -1; B[5][5] = 3;
    
    double c[] = {2.5, 1.5, 1, 1, 1.5, 2.5};
    double* y = create_vector(m);

    gauss(m, B, c, y);

    printf("\nSolution for the second system:\n");
    for (int i = 0; i < m; i++) {
        printf("x[%d] = %f\n", i, y[i]);
    }

    free_matrix(B, m);
    free_vector(y);

    return 0;
}

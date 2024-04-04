#include "sistlinear.h"
#include <stdio.h>
#include <math.h>


static void pivot(int n, double** A, double* b, int col) {
    int maxIndex = col;
    double maxValue = fabs(A[col][col]);
    for (int i = col + 1; i < n; i++) {
        if (fabs(A[i][col]) > maxValue) {
            maxValue = fabs(A[i][col]);
            maxIndex = i;
        }
    }
    if (maxIndex != col) { // Swap rows in A and b
        double* tempA = A[col];
        A[col] = A[maxIndex];
        A[maxIndex] = tempA;
        
        double tempB = b[col];
        b[col] = b[maxIndex];
        b[maxIndex] = tempB;
    }
}

void gauss(int n, double** A, double* b, double* x) {
    for (int i = 0; i < n; i++) {
        pivot(n, A, b, i);
        if (fabs(A[i][i]) < 1e-10) {
            printf("Matrix is singular or nearly singular.\n");
            return;
        }
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

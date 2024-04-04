#include "vetor.h"
#include <stdlib.h>

double* create_vector(int n) {
    return (double*)malloc(n * sizeof(double));
}

void free_vector(double* v) {
    free(v);
}

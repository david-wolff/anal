#include "interp.h"
#include <math.h>

void reg_samples(int n, double start, double end, double* x) {
    for (int i = 0; i < n; ++i) {
        x[i] = start + i * (end - start) / (n - 1);
    }
}

void cheby_samples(int n, double start, double end, double* x) {
    for (int i = 0; i < n; ++i) {
        x[i] = (start + end) / 2 + (end - start) / 2 * cos((2 * i + 1) * M_PI / (2 * n));
    }
}

void calc_coeffs(int n, double* x, double (*f)(double), double* coeffs) {
    for (int i = 0; i < n; i++) {
        coeffs[i] = f(x[i]);
        for (int j = i - 1; j >= 0; j--) {
            coeffs[j] = (coeffs[j + 1] - coeffs[j]) / (x[i] - x[j]);
        }
    }
}

double eval_poly(int n, double* x, double* coeffs, double pt) {
    double sum = 0;
    double prod;
    for (int i = n - 1; i >= 0; --i) {
        prod = coeffs[i];
        for (int j = 0; j < i; ++j) {
            prod *= (pt - x[j]);
        }
        sum += prod;
    }
    return sum;
}

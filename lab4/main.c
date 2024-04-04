#include "interp.h"
#include <stdio.h>
#include <math.h>

double norm_dist(double x) {
    double mu = 0.0, sigma = 0.5;
    return (1 / (sigma * sqrt(2 * M_PI))) * exp(-pow(x - mu, 2) / (2 * pow(sigma, 2)));
}

int main() {
    int n = 5;
    double a = -2, b = 2;
    double x[n], coeffs[n];

    reg_samples(n, a, b, x);
    calc_coeffs(n, x, norm_dist, coeffs);
    printf("Regular:\n");
    for (double pt = a; pt <= b; pt += 0.1) {
        printf("x = %f, P(x) = %f\n", pt, eval_poly(n, x, coeffs, pt));
    }

    cheby_samples(n, a, b, x);
    calc_coeffs(n, x, norm_dist, coeffs);
    printf("\nCheby:\n");
    for (double pt = a; pt <= b; pt += 0.1) {
        printf("x = %f, P(x) = %f\n", pt, eval_poly(n, x, coeffs, pt));
    }

    return 0;
}

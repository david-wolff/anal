#include <stdio.h>
#include <math.h>

// Function prototypes
double lagrange_interpolate(double x, double x_points[], double y_points[], int n);
double f(double x); // Replace with the actual function you wish to interpolate
void newton_divided_difference(double x[], double y[], int n, double dd[][10]);
double evaluate_newton_polynomial(double x[], double dd[][10], int n, double t);
double simpsons_rule(double (*func)(double), double a, double b, int n);

// Function definitions

double f(double x) {
    // Example function: cos(x)
    return cos(x);
}

double lagrange_interpolate(double x, double x_points[], double y_points[], int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y_points[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - x_points[j]) / (x_points[i] - x_points[j]);
            }
        }
        result += term;
    }
    return result;
}

void newton_divided_difference(double x[], double y[], int n, double dd[][10]) {
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}

double evaluate_newton_polynomial(double x[], double dd[][10], int n, double t) {
    double result = dd[0][n-1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * (t - x[i]) + dd[0][i];
    }
    return result;
}

double simpsons_rule(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * func(x);
    }
    
    return sum * (h / 3);
}

// Main program to demonstrate the interpolation and integration methods
int main() {
    // Demonstrate Lagrange Interpolation
    double x_points[] = {0, M_PI / 2, M_PI, 3 * M_PI / 2, 2 * M_PI};
    double y_points[] = {1, 0, -1, 0, 1}; // cos(x) at the given x_points
    int n_points = sizeof(x_points) / sizeof(x_points[0]);

    printf("Lagrange Interpolation at PI/4: %f\n", lagrange_interpolate(M_PI / 4, x_points, y_points, n_points));

    // Demonstrate Newton's Divided Differences Interpolation
    double dd[10][10] = {0}; // Adjust size based on the maximum number of points
    newton_divided_difference(x_points, y_points, n_points, dd);
    printf("Newton Interpolation at PI/4: %f\n", evaluate_newton_polynomial(x_points, dd, n_points, M_PI / 4));

    // Demonstrate Numerical Integration using Simpson's Rule
    double integral = simpsons_rule(f, 0, M_PI, 10); // 10 intervals in [0, PI]
    printf("Integral of cos(x) from 0 to PI using Simpson's Rule: %f\n", integral);

    return 0;
}

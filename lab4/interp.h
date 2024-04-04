#define INTERP_H

void reg_samples(int n, double a, double b, double* x);
void cheby_samples(int n, double a, double b, double* x);
void calc_coeffs(int n, double* x, double (*f)(double), double* coeffs);
double eval_poly(int n, double* x, double* coeffs, double pt);



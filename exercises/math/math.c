#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(void){
	double Gamma_5 = tgamma(5);
	printf("Gamma(5) = %g\n", Gamma_5);

	double J_1_half = j1(0.5);
	printf("J_1(1/2) = %g\n", J_1_half);

	printf("sqrt(-2) = %g + %gi\n", creal(csqrt(-2)), cimag(csqrt(-2)));
	printf("exp(i*pi) = %g + %gi\n", creal(cexp(I*M_PI)), cimag(cexp(I*M_PI)));
	printf("exp(i) = %g + %gi\n", creal(cexp(I)), cimag(cexp(I)));
	printf("i^e = %g + %gi\n", creal(cpow(I, M_E)), cimag(cpow(I, M_E)));
	printf("i^i = %g + %gi\n", creal(cpow(I, I)), cimag(cpow(I, I)));

	
	float x_float = 1.f/9;
	double x_double = 1./9;
	long double x_long_double = 1.L/9;
	printf("float %.25g\n", x_float);
	printf("double %.25lg\n", x_double);
	printf("long double %.25Lg\n", x_long_double);

	return 0;
}

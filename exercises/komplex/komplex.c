#include <stdio.h>
#include <math.h>
#include "komplex.h"

void komplex_print (char *s, komplex a) {
	printf("%s(%g, %g)\n", s, a.re, a.im);
}

void komplex_set (komplex* z, double x, double y) {
	(*z).re = x;
	(*z).im = y;
}

komplex komplex_new (double x, double y) {
	komplex z = { x, y };
	return z;
}

komplex komplex_add (komplex a, komplex b) {
	komplex result = { a.re + b.re , a.im + b.im };
	return result;
}

komplex komplex_sub (komplex a, komplex b) {
	komplex result = { a.re - b.re , a.im - b.im };
	return result;
}

komplex komplex_mul (komplex a, komplex b) {
	komplex result = { a.re * b.re - a.im * b.im, a.re * b.im + a.im + b.re };
	return result;
}

komplex komplex_div (komplex a, komplex b) {
	komplex result = {(a.re * b.re + a.im * b.im)/(pow(b.re, 2) + pow(b.im, 2)), 
	                  (a.im * b.re - a.re * b.im)/(pow(b.re, 2) + pow(b.im, 2))};
	return result;
}

komplex komplex_conjugate (komplex z) {
	komplex result = { z.re, -z.im };
	return result;
}

double komplex_abs (komplex z) {
	double result = pow(z.re, 2) + pow(z.im, 2);
	return result;
}

int komplex_equal (komplex a, komplex b, double acc, double eps) {
	if ( komplex_abs(komplex_sub(a, b)) < acc || komplex_abs(komplex_sub(a, b))/(komplex_abs(a) + komplex_abs(b)) < eps/2 ) {
		return 1;
	}
	else {
		return 0;
	}
}

komplex komplex_exp (komplex z) {
	komplex result = { exp(z.re)*cos(z.im), exp(z.re)*sin(z.im) };
	return result;
}

komplex komplex_cos (komplex z) {
	komplex result = { 0.5 * cos(z.im) * (exp(z.re) + exp(-z.re)), 0.5 * sin(z.im) * (exp(z.re) - exp(-z.re)) };
	return result;
}

komplex komplex_sin (komplex z) {
	komplex result = { 0.5 * sin(z.im) * (exp(z.re) + exp(-z.re)), 0.5 * cos(z.im) * (exp(-z.re) - exp(z.re)) };
	return result;
}

komplex komplex_sqrt (komplex z) {
	if ( z.im == 0 ) {
		komplex result = { sqrt(z.re), 0 };
		return result;
	}
	else if ( z.im > 0 ){
		komplex result = { 0.5 * sqrt(z.re + sqrt(pow(z.re, 2) + pow(z.im, 2))),
		                   0.5 * sqrt(-z.re + sqrt(pow(z.re, 2) + pow(z.im, 2))) };
		return result;
	}
	else if ( z.im < 0 ) {
		komplex result = { 0.5 * sqrt(z.re + sqrt(pow(z.re, 2) + pow(z.im, 2))),
		                   0.5 * sqrt(-z.re + sqrt(pow(z.re, 2) + pow(z.im, 2))) };
		return result;
	}
}


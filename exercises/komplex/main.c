#include "komplex.h"
#include "stdio.h"
#include <math.h>
#define TINY 1e-6

void test_komplex_print(void){
	printf("\nTesting komplex_print\n");
	komplex z = {3, 2};
	printf("komplex_print should print    (3, 2)\n");
	komplex_print("komplex_print actually prints ", z);
}

void test_komplex_add(void){
	printf("\nTesting komplex_add\n");
	komplex a = {1, 2}, b = {3, 4};
	komplex r = komplex_add(a, b);
	komplex R = {4, 6};
	komplex_print("a = ", a);
	komplex_print("b = ", b);
	komplex_print("a + b should   = ", R);
	komplex_print("a + b actually = ", r);
}

void test_komplex_sub(void){
	printf("\nTesting komplex_sub\n");
	komplex a = {1, 2}, b = {3, 4};
	komplex r = komplex_sub(a, b);
	komplex R = {-2, -2};
	komplex_print("a = ", a);
	komplex_print("b = ", b);
	komplex_print("a - b should   = ", R);
	komplex_print("a - b actually = ", r);
}

void test_komplex_mul(void){
	printf("\nTesting komplex_mul\n");
	komplex a = {1, 2}, b = {3, 4};
	komplex r = komplex_mul(a, b);
	komplex R = {-5, 10};
	komplex_print("a = ", a);
	komplex_print("b = ", b);
	komplex_print("a * b should   = ", R);
	komplex_print("a * b actually = ", r);
}

void test_komplex_div(void){
	printf("\nTesting komplex_div\n");
	komplex a = {1, 2}, b = {3, 4};
	komplex r = komplex_div(a, b);
	komplex R = {11.0/25, 2.0/25};
	komplex_print("a = ", a);
	komplex_print("b = ", b);
	komplex_print("a / b should   = ", R);
	komplex_print("a / b actually = ", r);
}

void test_komplex_conjugate(void){
	printf("\nTesting komplex_conjugate\n");
	komplex z = {1, 2};
	komplex r = komplex_conjugate(z);
	komplex R = {1, -2};
	komplex_print("z = ", z);
	komplex_print("a* should   = ", R);
	komplex_print("a* actually = ", r);
}

void test_komplex_abs(void){
	printf("\nTesting komplex_abs\n");
	komplex z = {3, 4};
	double r = komplex_abs(z);
	double R = 5;
	komplex_print("z = ", z);
	printf("abs(z) should   = %f\n", R);
	printf("abs(z) actually = %f\n", r);
}

void test_komplex_equal(void){
	printf("\nTesting komplex_equal\n");
	komplex a = {1, 2}, b = {3, 4}, c = {1.0001, 2.0001};
	int equal_ab_low_tolerance = komplex_equal(a, b, TINY, TINY);
	int equal_ac_low_tolerance = komplex_equal(a, c, TINY, TINY);
	int equal_ac_high_tolerance = komplex_equal(a, c, 0.01, 0.01);
	komplex_print("a = ", a);
	komplex_print("b = ", b);
	komplex_print("c = ", c);
	printf("komplex_equal(a, b, 1e-6, 1e-6) should   = 0\n");
	printf("komplex_equal(a, b, 1e-6, 1e-6) actually = %i\n", equal_ab_low_tolerance);
	printf("komplex_equal(a, c, 1e-6, 1e-6) should   = 0\n");
	printf("komplex_equal(a, c, 1e-6, 1e-6) actually = %i\n", equal_ac_low_tolerance);
	printf("komplex_equal(a, c, 0.01, 0.01) should   = 1\n");
	printf("komplex_equal(a, c, 0.01, 0.01) actually = %i\n", equal_ac_high_tolerance);
}

void test_komplex_exp(void){
	printf("\nTesting komplex_exp\n");
	komplex z = {3, 4}, i_pi = {0, M_PI}, one = {1, 0}, zero = {0, 0};
	komplex r = komplex_exp(z);
	komplex R = {-13.12878308, -15.20078446};
	komplex_print("z = ", z);
	komplex_print("exp(z) should   = ", R);
	komplex_print("exp(z) actually = ", r);
	if (komplex_equal(komplex_add(komplex_exp(i_pi), one), zero, TINY, TINY)) {
		printf("Euler's formula, exp(i*pi) + 1 = 0 is true.\n");
	}
	else {
		printf("Euler's formula, exp(i*pi) + 1 = 0 is false.\n");
	}
}

void test_komplex_cos(void){
	printf("\nTesting komplex_cos\n");
	komplex z = {3, 4};
	komplex r = komplex_cos(z);
	komplex R = {-27.03494560, -3.851153345};
	komplex_print("z = ", z);
	komplex_print("cos(z) should   = ", R);
	komplex_print("cos(z) actually = ", r);
}

void test_komplex_sin(void){
	printf("\nTesting komplex_sin\n");
	komplex z = {3, 4};
	komplex r = komplex_sin(z);
	komplex R = {3.8537380, -27.016813258};
	komplex_print("z = ", z);
	komplex_print("sin(z) should   = ", R);
	komplex_print("sin(z) actually = ", r);
}

void test_komplex_sqrt(void){
	printf("\nTesting komplex_sqrt\n");
	komplex w = {3, 4}, x = {3, -4}, y = {-3, 4}, z = {-3, -4}, a = {-4, 0}, i = {0, 1}, sqrt_i = {1.0/sqrt(2), 1.0/sqrt(2)};
	komplex r_a = komplex_sqrt(a);
	komplex R_a = {0, 2};
	komplex r_w = komplex_sqrt(w);
	komplex R_w = {2, 1};
	komplex r_x = komplex_sqrt(x);
	komplex R_x = {2, -1};
	komplex r_y = komplex_sqrt(y);
	komplex R_y = {1, 2};
	komplex r_z = komplex_sqrt(z);
	komplex R_z = {1, -2};
	komplex_print("a = ", a);
	komplex_print("w = ", w);
	komplex_print("x = ", x);
	komplex_print("y = ", y);
	komplex_print("z = ", z);
	komplex_print("sqrt(a) should   = ", R_a);
	komplex_print("sqrt(a) actually = ", r_a);
	komplex_print("sqrt(w) should   = ", R_w);
	komplex_print("sqrt(w) actually = ", r_w);
	komplex_print("sqrt(x) should   = ", R_x);
	komplex_print("sqrt(x) actually = ", r_x);
	komplex_print("sqrt(y) should   = ", R_y);
	komplex_print("sqrt(y) actually = ", r_y);
	komplex_print("sqrt(z) should   = ", R_z);
	komplex_print("sqrt(z) actually = ", r_z);
	komplex_print("sqrt(i) should   = ", sqrt_i);
	komplex_print("sqrt(i) actually = ", komplex_sqrt(i));
}

int main(void){
	test_komplex_print();
	test_komplex_add();
	test_komplex_sub();
	test_komplex_mul();
	test_komplex_div();
	test_komplex_conjugate();
	test_komplex_abs();
	test_komplex_equal();
	test_komplex_exp();
	test_komplex_cos();
	test_komplex_sin();
	test_komplex_sqrt();

	return 0;
}


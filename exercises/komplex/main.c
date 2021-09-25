#include "komplex.h"
#include "stdio.h"
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
	komplex_print("a + b should   = ", R);
	komplex_print("a + b actually = ", r);
}


int main(void){
	test_komplex_print();
	test_komplex_add();
	test_komplex_sub();

	return 0;
}


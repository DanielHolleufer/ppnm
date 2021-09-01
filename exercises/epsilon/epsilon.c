#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	// EXERCISE 1
	printf("Exercise 1\n");

	// Part i
	int i = 1;
	while(i + 1 > i){i++;}
	printf("My max int with while loop = %i\n", i);

	i = 1;
	do{i++;}
	while(i + 1 > i);
	printf("My max int with do while loop = %i\n", i);

	for(i = 1; i + 1 > i; ++i){}
	printf("My max int with for loop = %i\n", i);
	printf("INT_MAX = %i\n\n", INT_MAX);


	// Part ii
	i = 1;
	while(i - 1 < i){i--;}
	printf("My min int with while loop = %i\n", i);

	i = 1;
	do{i--;}
	while(i - 1 < i);
	printf("My min int with do while loop = %i\n", i);

	for(i = 1; i - 1 < i; i--){}
	printf("My min int with for loop = %i\n", i);
	printf("MIN_INT = %i\n\n", INT_MIN);


	// Part iii
	float x = 1;
	while(1 + x != 1){x/=2;}
	x*=2;
	printf("My float machine epsilon with while loop = %.25g\n", x);
	
	x = 1;
	do{x/=2;}
	while(1 + x != 1);
	printf("My float machine epsilon with do while loop = %.25g\n", x);

	for(x = 1; 1 + x != 1; x/=2){}
	printf("My float machine epsilon with for loop = %.25g\n", x);
	printf("FLT_EPSILON = %.25g\n\n", FLT_EPSILON);


	double y = 1;
	while(1 + y != 1){y/=2;}
	y*=2;
	printf("My double machine epsilon with while loop = %.25lg\n", y);
	
	y = 1;
	do{y/=2;}
	while(1 + y != 1);
	printf("My double machine epsilon with do while loop = %.25lg\n", y);

	for(y = 1; 1 + y != 1; y/=2){}
	printf("My float machine epsilon with for loop = %.25g\n", y);
	printf("DBL_EPSILON = %.25g\n\n", DBL_EPSILON);

	
	long double z = 1;
	while(1 + z != 1){z/=2;}
	z*=2;
	printf("My long double machine epsilon with while loop = %.25Lg\n", z);

	z = 1;
	do{z/=2;}
	while(1 + z != 1);
	printf("My long double machine epsilon with do while loop = %.25Lg\n", z);

	for(z = 1; 1 + z != 1; z/=2){}
	printf("My long double machine epsilon with for loop = %.25Lg\n", z);
	printf("LDBL_EPSILON = %.25Lg\n\n", LDBL_EPSILON);
	
	return 0;
}


#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "equal.h"

void exercise_1(void){
	printf("\nExercise 1\n");

	// Part i)
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


	// Part ii)
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


	// Part iii)
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
}	


void exercise_2(void){
	printf("\nExercise 2\n");

	// Part i)
	int max = INT_MAX/2;
	int i = 1;
	float sum_up_float = 0.0f;
	float sum_down_float = 0.0f;
	while(i <= max){
		sum_up_float = sum_up_float + 1.0f/i;
		sum_down_float = sum_down_float + 1.0f/(max + 1 - i);
		i++;
	}
	printf("sum_up_float = %g\n", sum_up_float);
	printf("sum_down_float = %g\n", sum_down_float);

	// Part ii)
	printf("It seems that you get a higher result by summing down instead of up.\n");

	// Part iii)
	printf("The sum is the harmonic series, which is divergent.\n");

	// Part iv)
	i = 1;
	double sum_up_double = 0;
	double sum_down_double = 0;
	while(i <= max){
		sum_up_double = sum_up_double + 1.0f/i;
		sum_down_double = sum_down_double + 1.0f/(max + 1 - i);
		i++;
	}
	printf("sum_up_double = %g\n", sum_up_double);
	printf("sum_down_double = %g\n", sum_down_double);
	printf("With doubles you get the same result whether you sum up or down. This result is also higher and thus more correct.\n");
}


void exercise_3(void){
	double a = 5;
	double b = 5.1;
	double tau = 1;
	double epsilon = 1;
	int answer = equal(a, b, tau, epsilon);	
	printf("answer = %i\n", answer);
}


void name_digit(int i){
	switch(i){
		case 0:
			printf("Zero\n");
			break;

		case 1:
			printf("One\n");
			break;

		case 2:
			printf("Two\n");
			break;

		case 3:
			printf("Three\n");
			break;

		case 4:
			printf("Four\n");
			break;

		case 5:
			printf("Five\n");
			break;
			
		case 6:
			printf("Six\n");
			break;

		case 7:
			printf("Seven\n");
			break;

		case 8:
			printf("Eight\n");
			break;

		case 9:
			printf("Nine\n");
			break;
	}
}


void exercise_4(void){
	int i = 4;
	name_digit(i);
}


int main(void){
	exercise_4();
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int equal(double a, double b, double tau, double epsilon){
	if (abs(a - b) < tau || abs(a - b)/(abs(a) + abs(b)) < epsilon/2){
		return 1;
	}
	else{
		return 0;
	}
}

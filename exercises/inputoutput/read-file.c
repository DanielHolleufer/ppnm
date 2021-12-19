#include<stdio.h>
#include<math.h>

int main(void) {
	printf("\nRead from input file\n");

	FILE* input_file = fopen("input.txt", "r");
	double x[5];
	fscanf(input_file, "%lf%lf%lf%lf%lf", &x[0], &x[1], &x[2], &x[3], &x[4]);
	printf("%-8s%-10lf%-10lf%-10lf%-10lf%-10lf\n", "x:", x[0], x[1], x[2], x[3], x[4]);
	printf("%-8s%-10lf%-10lf%-10lf%-10lf%-10lf\n", "cos(x):", cos(x[0]), cos(x[1]), cos(x[2]), cos(x[3]), cos(x[4]));
	printf("%-8s%-10lf%-10lf%-10lf%-10lf%-10lf\n", "sin(x):", sin(x[0]), sin(x[1]), sin(x[2]), sin(x[3]), sin(x[4]));
}

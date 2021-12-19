#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
	printf("\nRead from command line.\n");
	
	if (argc == 1) {
		printf("No inputs were given.\n");
	}
	else {
		printf("%-8s%-10s%-10s%-10s%-10s%-10s\n", "x:", argv[1], argv[2], argv[3], argv[4], argv[5]);
		printf("%-8s%-10f%-10f%-10f%-10f%-10f\n", "cos(x):", cos(atof(argv[1])), cos(atof(argv[2])), cos(atof(argv[3])), cos(atof(argv[4])), cos(atof(argv[5])));
		printf("%-8s%-10f%-10f%-10f%-10f%-10f\n", "sin(x):", sin(atof(argv[1])), sin(atof(argv[2])), sin(atof(argv[3])), sin(atof(argv[4])), sin(atof(argv[5])));
	}
}


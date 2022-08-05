#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include<gsl/gsl_linalg.h>
#include<gsl/gsl_eigen.h>


void linearsolve(void) {
    printf("\nLinear System Solver\n");

    // Memory allocation
    int n = 3;
    gsl_matrix * a = gsl_matrix_alloc(n, n);
    gsl_matrix * a_copy = gsl_matrix_alloc(n, n);
    gsl_vector * b = gsl_vector_alloc(n);
    gsl_vector * x = gsl_vector_alloc(n);
    gsl_vector * y = gsl_vector_alloc(n);
    
    // Encoding vectors and matrices
    int i, j;
    double a_data[3][3] = {{6.13, -2.90, 5.86}, {8.08, -6.31, -3.89}, {-4.36, 1.00, 0.19}};
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            gsl_matrix_set(a, i, j, a_data[i][j]);
        }
    }
    gsl_matrix_memcpy(a_copy, a);

    double b_data[3] = {6.23, 5.37, 2.29};
    for (i = 0; i < n; i++) {
        gsl_vector_set(b, i, b_data[i]);
    }

    // Solve ax = b
    gsl_linalg_HH_solve(a_copy, b, x);
    gsl_blas_dgemv(CblasNoTrans, 1.0, a, x, 0.0, y);
    printf("Solution is\n");
    gsl_vector_fprintf(stdout, x, "%g");
    printf("Checking solution a*x = \n");
    gsl_vector_fprintf(stdout, y, "%g");
    printf("Correct answer is = \n");
    gsl_vector_fprintf(stdout, y, "%g");

    // Free memory
    gsl_matrix_free(a);
    gsl_matrix_free(a_copy);
    gsl_vector_free(b);
    gsl_vector_free(x);
    gsl_vector_free(y);
}


void hilbert(void) {
    printf("\nEigenvalues and eigenvectors of 4th order Hilbert matrix.\n");

    // Memory allocation
    int n = 4;
    gsl_matrix * H = gsl_matrix_alloc(n, n);
    gsl_matrix * H_copy = gsl_matrix_alloc(n, n);
    gsl_vector * b = gsl_vector_alloc(n);
    gsl_vector * x = gsl_vector_alloc(n);
    gsl_vector * y = gsl_vector_alloc(n);

    // Encoding vectors and matrices
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            gsl_matrix_set(H, i, j, (double) 1.0/((i + 1) + (j + 1) - 1));
        }
    }

    gsl_eigen_symmv_workspace * w= gsl_eigen_symmv_alloc(n);
    gsl_eigen_symmv(H, x, H_copy, w);
    gsl_eigen_symmv_free(w);
    gsl_eigen_symmv_sort(x, H_copy, GSL_EIGEN_SORT_ABS_ASC);

    // Find eigenvectors and eigenvalues.
    for (i = 0; i < n; i++) {
        double x_i=gsl_vector_get (x, i);
        gsl_vector_view evec_i = gsl_matrix_column (H_copy, i);

        printf("Eigenval = %g \n", x_i);
        printf("Eigenvector = \n");
        gsl_vector_fprintf(stdout, &evec_i.vector, "%g");
        printf("\n");
    }

    // Free memory
    gsl_matrix_free(H);
    gsl_matrix_free(H_copy);
    gsl_vector_free(b);
    gsl_vector_free(x);
    gsl_vector_free(y);
}


int main(void) {
    linearsolve();
    hilbert();
    return 0;
}

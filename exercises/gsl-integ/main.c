// Code for integration sqrt(x)/x is taken directly from the gsl documentation.
// https://www.gnu.org/software/gsl/doc/html/integration.html#qags-adaptive-integration-with-singularities
// Implementation of the error function and the Bessel function of first kind is my own.

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f(double x, void * params) {
  double alpha = *(double *) params;
  double f = log(alpha*x) / sqrt(x);
  return f;
}


double gauss(double t, void * params) {
    return 2.0 / sqrt(M_PI) * exp(- t * t);
}


double myerf(double z){
    gsl_integration_workspace * w = gsl_integration_workspace_alloc (1000);

    double myerfresult, myerferror;
    gsl_function F;
    F.function = &gauss;

    gsl_integration_qags (&F, 0, z, 1e-7, 1e-7, 1000, w, &myerfresult, &myerferror);
    gsl_integration_workspace_free (w);
    return myerfresult;
}


double besselintegrand(double t, void * params) {
    double x = *(double *) params;
    return 1.0 / M_PI * cos(t - x*sin(t));
}


double mybessel(double x){
    gsl_integration_workspace * w = gsl_integration_workspace_alloc (1000);

    double mybesselresult, mybesselerror;
    gsl_function F;
    F.function = &besselintegrand;
    F.params = &x;

    gsl_integration_qags (&F, 0, M_PI, 1e-7, 1e-7, 1000, w, &mybesselresult, &mybesselerror);
    gsl_integration_workspace_free (w);
    return mybesselresult;
}


int main(void) {
    // Integration of log(x) / sqrt(x).
    gsl_integration_workspace * w = gsl_integration_workspace_alloc (1000);

    double result, error;
    double expected = -4.0;
    double alpha = 1.0;

    gsl_function F;
    F.function = &f;
    F.params = &alpha;

    gsl_integration_qags (&F, 0, 1, 0, 1e-7, 1000, w, &result, &error);

    printf ("\nresult          = % .18f\n", result);
    printf ("exact result    = % .18f\n", expected);
    printf ("estimated error = % .18f\n", error);
    printf ("actual error    = % .18f\n", result - expected);
    printf ("intervals       = %zu\n", w->size);

    gsl_integration_workspace_free (w);


    // Error function.
    FILE * fperror = fopen("errordata.txt", "w");
    double x[32];
    int i;
    for (i = 0; i < 5; i++) {
        x[i] = (double) i / 50;
    }
    for (i = 5; i < 30; i++) {
        x[i] = (double) (i - 4) / 10;
    }
    x[30] = 3.0;
    x[31] = 3.5;
    printf("\n\nError function\n");
    printf("%10s %10s\n", "z", "erf(z)");
    for (i = 0; i <= 31; i++) {
        printf("%10g %10g\n", x[i], myerf(x[i]));
        fprintf(fperror, "%10g %10g\n", x[i], myerf(x[i]));
    }
    printf("\n");
    fclose(fperror);

    // Bessel function.
    double y[100];
    for (i = 0; i < 100; i++) {
        y[i] = (double) i/10;
    }
    FILE * fpbessel = fopen("besseldata.txt", "w");
    printf("\n\nError function\n");
    printf("%10s %10s\n", "z", "J_1(z)");
    for (i = 0; i < 100; i++) {
        printf("%10g %10g\n", y[i], mybessel(y[i]));
        fprintf(fpbessel, "%10g %10g\n", y[i], mybessel(y[i]));
    }
    printf("\n");
    fclose(fpbessel);
    return 0;
}

#include<stdio.h>
#include<math.h>
#include<gsl/gsl_sf_erf.h>
#include<gsl/gsl_sf_gamma.h>


double myerf(double x){
    // Single precision error function (Abramowitz and Stegun, from Wikipedia)
    if(x < 0) return -myerf(-x);
    double a[] = {0.254829592, -0.284496736, 1.421413741, -1.453152027, 1.061405429};
    double t = 1/(1 + 0.3275911*x);
    double sum = t*(a[0] + t*(a[1] + t*(a[2] + t*(a[3] + t*a[4])))); // the right thing
    return 1 - sum*exp(-x*x);
}


double mygamma(double x){
    // Single precision gamma function (Gergo Nemes, from Wikipedia)
    if(x < 0) return M_PI/sin(M_PI*x)/mygamma(1 - x);
    if(x < 9) return mygamma(x + 1)/x;
    double lnmygamma = x*log(x + 1/(12*x - 1/x/10)) - x + log(2*M_PI/x)/2;
    return exp(lnmygamma);
}


int main(void){
    // Error function.
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
    printf("Error function\n");
    printf("%10s %10s %10s %10s\n", "Input", "math.h", "gsl", "custom");
    for (i = 0; i <= 31; i++) {
        printf("%10g %10g %10g %10g\n", x[i], erf(x[i]), gsl_sf_erf(x[i]), myerf(x[i]));
    }
    printf("\n");

    // Gamma function.
    double y[10] = {-1.5, -0.5, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    printf("Gamma function\n");
    printf("%10s %10s %10s %10s\n", "Input", "math.h", "gsl", "custom");
    for (i = 0; i < 10; i++) {
        printf("%10g %10g %10g %10g\n", y[i], tgamma(y[i]), gsl_sf_gamma(y[i]), mygamma(y[i]));
    }
    printf("\n");

    // Logarithm of Gamma function.
    printf("Logarithm of Gamma function\n");
    printf("%10s %10s %10s\n", "Input", "math.h", "gsl");
    for (i = 0; i < 10; i++) {
        printf("%10g %10g %10g\n", y[i], lgamma(y[i]), gsl_sf_lngamma(y[i]));
    }
    return 0;
}

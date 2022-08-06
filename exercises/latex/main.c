#include<stdio.h>
#include<math.h>


double ex(double x) {
    if (x<0) return 1/ex(-x);
    if (x>1./8) return pow(ex(x/2), 2);
    return 1 + x * (1 + x/2 * (1 + x/3 * (1 + x/4 * (1 + x/5 * (1 + x/6 * (1 + x/7 * (1 + x/8 * (1 + x/9 * (1 + x/10)))))))));
}


int main(void) {
    FILE * fp = fopen("data.txt", "w");
    int n = 1000;
    double x[n];
    double exp_x[n];
    double x_min = -3.0;
    double x_max = 3.0;
    for (int i = 0; i < n; i++) {
        x[i] = x_min + i*(x_max - x_min) / n;
        exp_x[i] = ex(x[i]);
        fprintf(fp, "%10g %10g \n", x[i], exp_x[i]);
    }
    fclose(fp);
    return 0;
}

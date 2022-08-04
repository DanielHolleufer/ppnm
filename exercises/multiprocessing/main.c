#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#define ITERATIONS 1e7


void* pi_sim(void * arg) {
    double x, y, r;
    int * count = (int *) arg;
    unsigned int SEED;
    for (int i = 0; i <= ITERATIONS; i++) {
        x = (double) rand_r(&SEED)/RAND_MAX;
        y = (double) rand_r(&SEED)/RAND_MAX;
        r = sqrt(pow(x, 2) + pow(y, 2));
        if (r <= 1) {
            *count = *count + 1;
        }
    }
    return NULL;
}


int main(void) {
    int count1 = 0;
    int count2 = 0;
    pthread_t thread1;
    pthread_create(&thread1, NULL, pi_sim, (void*) &count1);
    pi_sim((void*)&count2);
    void* returnval = NULL;
    pthread_join(thread1, returnval);
    int count_tot = count1 + count2;
    double pi = (double) 2*count_tot/ITERATIONS;
    printf("pi = %f\n", pi);
    return 0;
}

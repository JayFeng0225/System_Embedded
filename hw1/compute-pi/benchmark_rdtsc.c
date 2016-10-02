#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

inline __attribute__((always_inline)) unsigned long long int rdtsc()
{
    unsigned long long int x;
    asm   volatile ("rdtsc" : "=A" (x));
    return x;
}

int main(int argc, char const *argv[])
{
	unsigned long long int begin;
	unsigned long long int end;
	unsigned long long int total = 0;
    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    int i, loop = 25;

    // Baseline
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_baseline(N);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/ONE_SEC/10);
	
	//Leibniz
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_leibniz(N);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/1024/1024/1024/10);
	
	//Euler
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_euler(N);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/1024/1024/1024/10);

	//OpenMP_2
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_openmp(N,2);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/1024/1024/1024/10);
	
	//OpenMP_4
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_openmp(N,4);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/1024/1024/1024/10);

	//AVX
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_avx(N);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf ", (double)23*total/1024/1024/1024/10);

	//AVX_Unroll
	total = 0;
    for(i = 0; i < loop; i++) {
		begin = rdtsc();
        compute_pi_avx_unroll(N);
		end = rdtsc();
		total += end-begin;
    }
	total /= 25;
    printf("%.9lf\n", (double)23*total/1024/1024/1024/10);

    return 0;
}

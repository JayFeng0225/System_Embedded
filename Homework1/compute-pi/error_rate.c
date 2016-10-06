#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "computepi.h"


int main(int argc, char const *argv[])
{
    //__attribute__((unused)) int N = 400000000;
	//FILE *f = fopen("error_rate.txt","a");
    double pi = 0.0;
	double error = 0.0;
	double diff = 0.0;
    int N = atoi(argv[1]);

    pi = compute_pi_baseline(N);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf ",error);

	pi = compute_pi_leibniz(N);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf ",error);

	pi = compute_pi_euler(N);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf\n",error);
	printf("%.15lf ",error);

    pi = compute_pi_openmp(N, 2);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf ",error);

    pi = compute_pi_openmp(N, 4);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf ",error);

    pi = compute_pi_avx(N);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf ",error);

    pi = compute_pi_avx_unroll(N);
	diff = pi - M_PI > 0 ? pi - M_PI : M_PI - pi;
	error = diff / M_PI;
	//fprintf(f,"%.15lf ",error);
	printf("%.15lf\n",error);
    
	return 0;
}

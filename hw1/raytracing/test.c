#include <stdio.h>
#include <omp.h>

int main(){
	#pragma omp parallel
	{
		printf("Hello");
	}

	return 0;
}

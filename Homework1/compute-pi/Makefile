CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall -fopenmp -mavx
EXECUTABLE = \
	time_test_baseline time_test_openmp_2 time_test_openmp_4 \
	time_test_avx time_test_avxunroll time_test_leibniz time_test_euler\
	error_test benchmark_rdtsc\
	benchmark_clock_gettime

default: computepi.o
	$(CC) $(CFLAGS) computepi.o time_test.c -DBASELINE -o time_test_baseline -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DOPENMP_2 -o time_test_openmp_2 -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DOPENMP_4 -o time_test_openmp_4 -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVX -o time_test_avx -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DAVXUNROLL -o time_test_avxunroll -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DLEIBNIZ -o time_test_leibniz -lm
	$(CC) $(CFLAGS) computepi.o time_test.c -DEULER -o time_test_euler -lm
	$(CC) $(CFLAGS) computepi.o benchmark_clock_gettime.c -o benchmark_clock_gettime -lm
	$(CC) $(CFLAGS) computepi.o error_rate.c -o error_test -lm
	$(CC) $(CFLAGS) computepi.o benchmark_rdtsc.c -o benchmark_rdtsc -lm

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time -p ./time_test_baseline
	time -p ./time_test_openmp_2
	time -p ./time_test_openmp_4
	time -p ./time_test_avx
	time -p ./time_test_avxunroll
	time -p ./time_test_leibniz
	time -p ./time_test_euler

gencsv: default
	for i in `seq 1000 5000 1000000`; do \
		printf "%d " $$i;\
		./benchmark_clock_gettime $$i; \
	done > result_clock_gettime.csv	

genrdtsc: default
	for i in `seq 1000 2000 100000`; do \
		printf "%d " $$i;\
		./benchmark_rdtsc $$i; \
	done > result_rdtsc.csv	

plot: result_clock_gettime.csv
	gnuplot scripts/runtime.gp

error: default 
	for i in `seq 1000 5000 1000000`; do \
		printf "%d " $$i;\
		./error_test $$i; \
	done > error_rate.csv	
	gnuplot scripts/errortime.gp
clean:
	rm -f $(EXECUTABLE) *.o *.s result_clock_gettime.csv error_rate.csv result_rdtsc.csv runtime.png errorrate.png cputime.png

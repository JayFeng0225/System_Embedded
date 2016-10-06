reset
set logscale x
set xlabel 'N'
set ylabel 'Time (sec)'
set title 'Wall-clock time - using clock\_gettime()'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot[:][0:] 'result_clock_gettime.csv' using 1:2 smooth csplines title 'Baseline', \
'' using 1:3 smooth csplines title 'Leibniz', \
'' using 1:4 smooth csplines title 'Euler', \
'' using 1:5 smooth csplines title 'OpenMP\_2', \
'' using 1:6 smooth csplines title 'OpenMP\_4', \
'' using 1:7 smooth csplines title 'AVX', \
'' using 1:8 smooth csplines title 'AVX + unroll looping',\


reset
set logscale x
set xlabel 'N'
set ylabel 'Time (sec)'
set title 'CPU time - using rdtsc()'
set term png enhanced font 'Verdana,10'
set output 'cputime.png'

plot[:][0:] 'result_rdtsc.csv' using 1:2 smooth csplines title 'Baseline', \
'' using 1:3 smooth csplines title 'Leibniz', \
'' using 1:4 smooth csplines title 'Euler', \
'' using 1:5 smooth csplines title 'OpenMP\_2', \
'' using 1:6 smooth csplines title 'OpenMP\_4', \
'' using 1:7 smooth csplines title 'AVX', \
'' using 1:8 smooth csplines title 'AVX + unroll looping',\

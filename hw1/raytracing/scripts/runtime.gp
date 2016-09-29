reset
set ylabel 'time(sec)'
set style fill solid
set title 'execution time comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.15):($2+0.001):2 with labels title ' ' , \
'' using 3:xtic(1) with histogram title 'loop unrolling'  , \
'' using ($0):($3+0.0015):3 with labels title ' ' , \
'' using 4:xtic(1) with histogram title 'OpenMP'  , \
'' using ($0+0.17):($4+0.05):4 with labels title ' ' , \
'' using 5:xtic(1) with histogram title 'inline'  , \
'' using ($0+0.34):($5+0.0015):5 with labels title ' ' , \

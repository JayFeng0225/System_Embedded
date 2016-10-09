reset
set ylabel 'time(sec)'
set xlabel '# of threads'
set style fill solid
set title 'perfomance with # of threads'
set term png enhanced font 'Verdana,10'
set output 'thread.png'

plot [:][0:]'compare.txt' using 2:xticlabel(1) with histogram title '',\
'' using ($0):($2+0.001):2 with labels title '',\

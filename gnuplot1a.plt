!#/usr/bin/gnuplot -persist 
#Here -persist is used for to create executable file 

reset
set terminal png
set out "cmplx_num_1a_omp.png"

set xrange [0:10]
set yrange [-1:1]

set style line 1 linetype 1 linewidth 0.5 pointtype 1 
set style line 2 linetype 2 linewidth 0.5 pointtype 2
set style line 3 linetype 3 linewidth 0.5 pointtype 3


plot "data_1a_with_omp.txt" u 1:2 title "{/Symbol F} vs Re(exp(i{/Symbol F}))" w linespoints linestyle 1, "" u 1:3 title "{/Symbol F} vs Com(exp(i{/Symbol F}))" w linespoints linestyle 2, "" u 1:4 title "{/Symbol F} vs abs(exp(i{/Symbol F}))" w linespoints linestyle 3


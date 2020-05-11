reset session

set term gif animate delay 24 optimize
set output "../cm.gif"
unset xtics
unset ytics
unset ztics


do for [i= 1:10000]{
    splot "../dat/cm.dat" u 2:3:4 w lp lt 1 lw 0.09 pt 7 ps 0.1 lc rgb "blue" t"", \
          '../dat/cm.dat' u 2:3:4 every ::i::i w  p pt 7 ps 1.42 lc rgb "red" t""
}
set output
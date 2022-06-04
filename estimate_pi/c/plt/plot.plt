set terminal pdfcairo
set output "../pi.pdf"

unset tics
set size ratio 1
set xrange [-1:1]
set yrange [-1:1]
set object circle at 0,0 size 1

plot "../dat/pi.dat" u 1:2 w p pt 7 ps 0.24 t""
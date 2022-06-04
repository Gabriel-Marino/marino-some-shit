set terminal pngcairo size 1024,576
set output "lv-sol.png"

unset size
set xrange[0:30]
set xtics 5
set xlabel "tempo"
set yrange[0:3.0]
set ytics 0.5
set ylabel "densidade de x, y" rotate by 90
set key maxrows 1 reverse Left samplen 0.5 center top

plot	"lv.dat" u 1:2 w l ls 2 lc rgb "#ff0000" t "presa (x)",\
        "lv.dat" u 1:3 w l ls 3 lc rgb "#0000ff" t "predador (y)"

unset output
unset terminal
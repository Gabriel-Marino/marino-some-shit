#set terminal pngcairo size 1080,1080
set terminal gif animate delay 10 optimize
set output "../wave.gif"

set size ratio -1
set xrange [-5:5]
set xtics 1
set yrange [-2:2]
set ytics 1

#do for [t= 1:10]{
#	set output sprintf ("square-%d.png", t)
#	plot sprintf ("../dat/serie-%d.dat", t) u 1:2 w l lt 1 lw 0.5 lc rgb "#0F0F0F" t""
#	unset output
#}

set print

do for [t= 1:10]{
	plot sprintf("../dat/serie-%d.dat", t) u 1:2 w l lt 1 lw 0.5 lc rgb "#0F0F0F" t""
}
t= 10
while (t> 0){
	plot sprintf("../dat/serie-%d.dat", t) u 1:2 w l lt 1 lw 0.5 lc rgb "#0F0F0F" t""
	t= t-1
}

unset output
unset terminal
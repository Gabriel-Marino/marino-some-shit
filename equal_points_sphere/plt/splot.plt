set terminal pdfcairo
set output "../sphere.pdf"

set view equal xyz
set hidden3d
set xrange [-1:1]
set yrange [-1:1]
set zrange [-1:1]
set xtics 1
set ytics 1
set ztics 1
set multiplot layout 1,2

#parametros da esfera - começo
set parametric
set isosamples 50,50
set hidden3d
R= 1		#radius of sphere
set urange [-pi/2:pi/2]
set vrange [0:2*pi]
#parametros da esfera - fim

splot	R*cos(u)*cos(v), R*cos(u)*sin(v), R*sin(u) w l lc rgb "#FF0000" t"" ,\
		"../dat/pontos.dat" u 2:3:4 w p pt 7 ps 0.0690 lc rgb "#0000FF" t""

splot "../dat/cm.dat" u 2:3:4 w lp lt 1 lw 0.09 pt 7 ps 0.1 lc rgb "#000000" t""

unset terminal
unset output

set terminal pngcairo size 1080,1080

#	system pega tudo e executa no terminal
#	sed pega o valor na linha p
#	cut seleciona a coluna "-f#" separada por um espaço em branco "-d' '"
#	-n no sed pega só a linha %d

set view equal xyz
fx(t)= system(sprintf("sed -n '%d p' ../dat/cm.dat | cut -f2 -d' '", t))
fy(t)= system(sprintf("sed -n '%d p' ../dat/cm.dat | cut -f3 -d' '", t))
fz(t)= system(sprintf("sed -n '%d p' ../dat/cm.dat | cut -f4 -d' '", t))
set hidden3d
set xrange [-1:1]
set yrange [-1:1]
set zrange [-1:1]
unset xtics
unset ytics
unset ztics

i= 1
while(i <= 10000){
	set output sprintf("%d.png", i/10)
	set object circle at fx(i), fy(i), fz(i) size 0.05 fc rgb "#000000" fillstyle solid 1.0
	splot	"../dat/cm.dat" u 2:3:4 w l lw 5 lc rgb "#FFFFFF" t""
#	splot	"../dat/cm.dat" u 2:3:4 every ::i::i w p pt 7 ps 2.4  lc rgb "#000000" t"",\
#			"../dat/cm.dat" u 2:3:4 w l lw 2 lc rgb "#FFFFFF" t""
	unset object
	i= i+10
}

#um roxo bem bonito: 7E00A3

unset terminal
unset output
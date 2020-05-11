set terminal pdfcairo
set output "../surface.pdf"

set parametric
set isosamples 50,50
set hidden3d
set cntrparam levels 10
set view equal xyz
set hidden3d
set xrange [-1:1]
set yrange [-1:1]
set zrange [-1:1]
set xtics 1
set ytics 1
set ztics 1
set pm3d

R = 1.   # radius of sphere
set urange [-pi/2:pi/2]
set vrange [0:2*pi]
splot R*cos(u)*cos(v),R*cos(u)*sin(v),R*sin(u) w l lc rgb "#C0FFEE" t""

unset terminal
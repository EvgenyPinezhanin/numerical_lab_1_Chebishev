datafile_v0='./data/points_v0_test.txt'
datafile_vn='./data/points_vn_test.txt'
datafile_u_vn='./data/points_u_vn_test.txt'

set xlabel "X"
set ylabel "Y"
set zlabel "Z"

set pm3d

set xrange [-1.0:1.0]
set yrange [-1.0:1.0]

if (ARG1 == 1) {
	set title 'U(x, y)'
	splot exp(1.0 - x**2 - y**2) with pm3d title 'U(x, y)'
}

if (ARG1 == 2) {
	set title 'V^{(0)}(x, y)'
	splot datafile_v0 matrix nonuniform with pm3d title 'V^{(0)}(x, y)'
}

if (ARG1 == 3) {
	set title 'V^{(N)}(x, y)'
	splot datafile_vn matrix nonuniform with pm3d title 'V^{(N)}(x, y)'
}

if (ARG1 == 4) {
	set title 'U(x, y) - V^{(N)}(x, y)'
	splot datafile_u_vn matrix nonuniform with pm3d title 'U(x, y) - V^{(N)}(x, y)'
}

bind all "alt-End" "exit gnuplot"
pause mouse close

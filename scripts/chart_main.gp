datafile_v0='./data/points_v0_main.txt'
datafile_v02='./data/points_v02_main.txt'
datafile_vn='./data/points_vn_main.txt'
datafile_vn2='./data/points_vn2_main.txt'
datafile_vn2_vn='./data/points_vn2_vn_main.txt'

set xlabel "X"
set ylabel "Y"
set zlabel "Z"

set pm3d

set xrange [-1.0:1.0]
set yrange [-1.0:1.0]

if (ARG1 == 1) {
	set title 'V^{(0)}(x, y)'
	splot datafile_v0 matrix nonuniform with pm3d title 'V^{(0)}(x, y)'
}

if (ARG1 == 2) {
	set title 'V2^{(0)}(x, y)'
	splot datafile_v02 matrix nonuniform with pm3d title 'V2^{(0)}(x, y)'
}

if (ARG1 == 3) {
	set title 'V^{(N)}(x, y)'
	splot datafile_vn matrix nonuniform with pm3d title 'V^{(N)}(x, y)'
}

if (ARG1 == 4) {
	set title 'V2^{(N2)}(x, y)'
	splot datafile_vn2 matrix nonuniform with pm3d title 'V2^{(N2)}(x, y)'
}

if (ARG1 == 5) {
	set title 'V2^{(N2)}(x, y) - V^{(N)}(x, y)'
	splot datafile_vn2_vn matrix nonuniform with pm3d title 'V2^{(N2)}(x, y) - V^{(N)}(x, y)'
}

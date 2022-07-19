datafile_v0='./data/points_v0_test.txt'
datafile_vn='./data/points_vn_test.txt'
datafile_u_vn='./data/points_u_vn_test.txt'

set terminal png size 1280, 720

set xlabel "X"
set ylabel "Y"
set zlabel "Z"

set pm3d

set xrange [-1.0:1.0]
set yrange [-1.0:1.0]

set output 'images/test_u.png'
set title 'U(x, y)'
splot exp(1.0 - x**2 - y**2) with pm3d title 'U(x, y)'

set output 'images/test_v0.png'
set title 'V^{(0)}(x, y)'
splot datafile_v0 matrix nonuniform with pm3d title 'V^{(0)}(x, y)'

set output 'images/test_vn.png'
set title 'V^{(N)}(x, y)'
splot datafile_vn matrix nonuniform with pm3d title 'V^{(N)}(x, y)'

set output 'images/test_u_vn.png'
set title 'U(x, y) - V^{(N)}(x, y)'
splot datafile_u_vn matrix nonuniform with pm3d title 'U(x, y) - V^{(N)}(x, y)'
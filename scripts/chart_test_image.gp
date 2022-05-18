set terminal png size 1280, 720

set xlabel "X"
set ylabel "Y"
set zlabel "Z"

set pm3d scansbackward

set xrange [-1.0:1.0]
set yrange [-1.0:1.0]

set output 'images/test_u.png'
set title 'U(x, y)'
splot exp(1.0 - x**2 - y**2) title 'U(x, y)'

set output 'images/test_v0.png'
set title 'V^{(0)}(x, y)'
splot exp(1.0 - x**2 - y**2) title 'U(x, y)'

set output 'images/test_vn.png'
set title 'U(x, y)'
splot exp(1.0 - x**2 - y**2) title 'U(x, y)'

set output 'images/test_u_vn.png'
set title 'U(x, y)'
splot exp(1.0 - x**2 - y**2) title 'U(x, y)'
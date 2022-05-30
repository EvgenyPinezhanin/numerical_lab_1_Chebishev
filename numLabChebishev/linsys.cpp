#include "linsys.h"
#include <omp.h>

VectorV::VectorV(int _n, int _m, double _a, double _b, double _c, double _d)
	: v_data(new vector<vector<double>>(_n + 1)), n(_n), m(_m), a(_a), b(_b), c(_c), d(_d) {
	for (int i = 0; i < n + 1; i++) {
		(*v_data)[i].resize(m + 1);
	}
}

VectorV::VectorV(const VectorV& V)
	: v_data(new vector<vector<double>>(V.n + 1)), n(V.n), m(V.m), a(V.a), b(V.b), c(V.c), d(V.d) {
	for (int i = 0; i < n + 1; i++) {
		(*v_data)[i].resize(m + 1);
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			(*v_data)[i][j] = V[i][j];
		}
	}
}

VectorV::~VectorV() {
	delete v_data;
}

VectorV& VectorV::operator=(const VectorV& V) {
	if (v_data != V.v_data) {
		n = V.n; m = V.m; 
		a = V.a; b = V.b; c = V.c; d = V.d;
		v_data->resize(n + 1);
		for (int i = 0; i < n + 1; i++) {
			(*v_data)[i].resize(m + 1);
		}
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				(*v_data)[i][j] = V[i][j];
			}
		}
	}
	return *this;
}

vector<double>& VectorV::operator[](size_t index) {
	return (*v_data)[index];
}

const vector<double>& VectorV::operator[](size_t index) const {
	return (*v_data)[index];
}

void VectorV::setBorder(double (*mu)(double, int)) {
	double h = (b - a) / n;
	double k = (d - c) / m;
	for (int i = 0; i < n + 1; i++) {
		(*v_data)[i][0] = mu(a + i * h, 3);
		(*v_data)[i][m] = mu(a + i * h, 4);
	}
	for (int i = 0; i < m + 1; i++) {
		(*v_data)[0][i] = mu(c + i * k, 1);
		(*v_data)[n][i] = mu(c + i * k, 2);
	}
}

void VectorV::setInterval(double _a, double _b, double _c, double _d) {
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}

void VectorV::setSize(int _n, int _m) {
	n = _n;
	m = _m;
	v_data->resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		(*v_data)[i].resize(m + 1);
	}
}

void VectorV::getInterval(double& _a, double& _b, double& _c, double& _d) const {
	_a = a;
	_b = b;
	_c = c;
	_d = d;
}

void VectorV::getSize(int& _n, int& _m) const {
	_n = n;
	_m = m;
}

double VectorV::norm_vector_max() {
	double max_tmp = (*v_data)[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			max_tmp = max(max_tmp, abs((*v_data)[i][j]));
		}
	}
	return max_tmp;
}

double VectorV::norm_vector_euclid() {
	double sum = 0.0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			sum += pow((*v_data)[i][j], 2);
		}
	}
	return sqrt(sum);
}

VectorV operator-(const VectorV& V1, const VectorV& V2) {
	VectorV v_tmp(V1);
	size_t n = V1.n;
	size_t m = V1.m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			v_tmp[i][j] -= V2[i][j];
		}
	}
	return v_tmp;
}

VectorV operator*(double a, const VectorV& V) {
	VectorV v_tmp(V);
	size_t n = V.n;
	size_t m = V.m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			v_tmp[i][j] *= a;
		}
	}
	return v_tmp;
}

void MatrixA::getLamdMinMax(double& Mmin, double& Mmax) const {
	Mmin = 4.0 / (h * h) * pow(sin(M_PI / (2.0 * n)), 2) + 4.0 / (k * k) * pow(sin(M_PI / (2.0 * m)), 2);
	Mmax = 4.0 / (h * h) * pow(sin(M_PI * (n - 1.0) / (2.0 * n)), 2) + 4.0 / (k * k) * pow(sin(M_PI * (m - 1.0) / (2.0 * m)), 2);
}

VectorV MatrixA::residual(const VectorV& V) {
	VectorV tmp(V);
	double _h_2 = -1.0 / (h * h);
	double _k_2 = -1.0 / (k * k);
	double _A = -2.0 * (_h_2 + _k_2);
	double a, b, c, d;
	V.getInterval(a, b, c, d);

#pragma omp parallel for num_threads(2)
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			tmp[i][j] = (V[i][j + 1] + V[i][j - 1]) * _k_2 + (V[i - 1][j] + V[i + 1][j]) * _h_2 + V[i][j] * _A - f(a + i * h, c + j * k);
		}
	}
	return tmp;
}

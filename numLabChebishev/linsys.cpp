#include "linsys.h"
#include <iostream>

MatrixA::MatrixA(int _n, int _m, double _h, double _k) 
	: n(_n), m(_m), h(_h), k(_k) {}

vector<double> MatrixA::operator*(const vector<double>& vec) {
	// if ((n - 1) * (m - 1) != vec.size()) throw "Different matrix size and vector size";
	vector<double> tmp(vec.size());
	double _h_2 = -1.0 / (h * h);
	double _k_2 = -1.0 / (k * k);
	double _A = -2.0 * (_h_2 + _k_2);
	size_t size = vec.size();

	tmp[0] = vec[0] * _A + vec[1] * _h_2 + vec[n - 1] * _k_2;
	tmp[n - 2] = vec[n - 3] * _h_2 + vec[n - 2] * _A + vec[(n - 2) + (n - 1)] * _k_2;
	tmp[size - 1 - (n - 2)] = vec[size - 1 - (n - 2) - (n - 1)] * _k_2 + vec[size - 1 - (n - 2)] * _A + vec[size - (n - 2)] * _h_2;
	tmp[size - 1] = vec[size - 1 - (n - 1)] * _k_2 + vec[size - 2] * _h_2 + vec[size - 1] * _A;

	for (size_t i = 1; i < n - 2; i++) {
		tmp[i] = vec[i - 1] * _h_2 + vec[i] * _A + vec[i + 1] * _h_2 + vec[i + n - 1] * _k_2;
	}

	for (size_t i = size - (n - 2); i < size - 1; i++) {
		tmp[i] = vec[i - (n - 1)] * _k_2 + vec[i - 1] * _h_2 + vec[i] * _A + vec[i + 1] * _h_2;
	}

	for (size_t i = n - 1; i < size + 1 - 2 * (n - 1); i += (n - 1)) {
		tmp[i] = vec[i - (n - 1)] * _k_2 + vec[i] * _A + vec[i + 1] * _h_2 + vec[i + (n - 1)] * _k_2;
	}

	for (size_t i = 2 * (n - 1) - 1; i < size - (n - 1); i += (n - 1)) {
		tmp[i] = vec[i - (n - 1)] * _k_2 + vec[i - 1] * _h_2 + vec[i] * _A + vec[i + (n - 1)] * _k_2;
	}
	int lb, rb;
	for (int i = 1; i < m - 2; i++) {
		lb = 1 + i * (n - 1);
		rb = (i + 1) * (n - 1) - 1;
		for (int j = lb; j < rb; j++) {
			tmp[j] = vec[j - (n - 1)] * _k_2 + vec[j - 1] * _h_2 + vec[j] * _A + vec[j + 1] * _h_2 + vec[j + (n - 1)] * _k_2;
		}
	}
	return tmp;
}

void MatrixA::setN(int _n) {
	n = _n;
}

void MatrixA::setM(int _m) {
	m = _m;
}

void MatrixA::setH(double _h) {
	h = _h;
}

void MatrixA::setK(double _k) {
	k = _k;
}

void MatrixA::setParam(int _n, int _m, double _h, double _k) {
	n = _n;
	m = _m;
	h = _h;
	k = _k;
}

void MatrixA::getLamdMinMax(double& Mmin, double& Mmax) const {
	Mmin = 4.0 / (h * h) * pow(sin(M_PI / (2.0 * n)), 2) + 4.0 / (k * k) * pow(sin(M_PI / (2.0 * m)), 2);
	Mmax = 4.0 / (h * h) * pow(sin(M_PI * (n - 1.0) / (2.0 * n)), 2) + 4.0 / (k * k) * pow(sin(M_PI * (m - 1.0) / (2.0 * m)), 2);
}

void VectorB::getVectorB(vector<double>& vec, int n, int m, double h, double k, double (*f)(double, double), 
						 double (*mu)(double, int), double a, double b, double c, double d) {
	vec.clear();
	vec.resize((n - 1) * (m - 1));

	for (size_t i = 0; i < vec.size(); i++) {
		vec[i] = f(a + (i % (n - 1) + 1) * h, c + (i / (n - 1) + 1) * k);
		if (i / (n - 1) == 0) {
			vec[i] += mu(a + (i % (n - 1) + 1) * h, 3)  / (k * k);
		}
		if (i / (n - 1) == m - 2) {
			vec[i] += mu(a + (i % (n - 1) + 1) * h, 4) / (k * k);
		}
		if (i % (n - 1) == 0) {
			vec[i] += mu(c + (i / (n - 1) + 1) * k, 1) / (h * h);
		}
		if (i % (n - 1) == n - 2) {
			vec[i] += mu(c + (i / (n - 1) + 1) * k, 2) / (h * h);
		}
	}
}

vector<double> operator+(const vector<double>& v1, const vector<double>& v2) {
	vector<double> v_tmp(v1);
	for (size_t i = 0; i < v1.size(); i++) {
		v_tmp[i] += v2[i];
	}
	return v_tmp;
}

vector<double> operator-(const vector<double>& v1, const vector<double>& v2) {
	vector<double> v_tmp(v1);
	int size = (int)v1.size();
	for (int i = 0; i < size; i++) {
		v_tmp[i] -= v2[i];
	}
	return v_tmp;
}

vector<double> operator*(double a, const vector<double>& v) {
	vector<double> v_tmp(v);
	int size = (int)v.size();
	for (int i = 0; i < size; i++) {
		v_tmp[i] *= a;
	}
	return v_tmp;
}

double norm_vector_max(vector<double> vec) {
	double max_tmp = vec[0];
	for (size_t i = 1; i < vec.size(); i++) {
		max_tmp = max(max_tmp, abs(vec[i]));
	}
	return max_tmp;
}
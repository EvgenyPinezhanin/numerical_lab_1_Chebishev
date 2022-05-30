#include "chebishev.h"
#include <cmath>
#include <iostream>
#include <fstream>

ofstream ofstr;

int check_pow_2(int k) {
	int count = 0;
	while (k % 2 == 0) {
		k /= 2;
		count++;
	}
	if (k != 1) {
		return -1;
	}
	else
	{
		return count;
	}
}

void iter_chebishev::calc_index_tau(int pow) {
	if (pow < 1) {
		index_tau.resize(k);
		for (int i = 0; i < k; i++) {
			index_tau[i] = i;
		}
	}
	else
	{
		index_tau.resize(2);
		index_tau[0] = 0;
		index_tau[1] = 1;
		for (int i = 1; i < pow; i++) {
			int l = (int)std::pow(2, i + 1);
			index_tau.resize(l);
			for (int j = (index_tau.size() - 2) / 2; j >= 0; j--) {
				index_tau[2 * j] = index_tau[j];
			}
			for (int j = 1; j < index_tau.size(); j += 2) {
				index_tau[j] = l - 1 - index_tau[j - 1];
			}
		}
	}
}

void iter_chebishev::calc_tau() {
	calc_index_tau(check_pow_2(k));
	tau.resize(k);
	for (size_t i = 0; i < tau.size(); i++) {
		tau[i] = 1.0 / ((Mmin + Mmax) / 2.0 + (Mmax - Mmin) / 2.0 * cos(M_PI / (2.0 * k) * (1.0 + 2.0 * i)));
	}
}

double iter_chebishev::calc_eps_current(const VectorV& V_prev, const VectorV &V_curr) {
	double eps_tmp = 0.0;
	int n, m;
	V_prev.getSize(n, m);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			eps_tmp = max(eps_tmp, abs(V_prev[i][j] - V_curr[i][j]));
		}
	}
	return eps_tmp;
}

iter_chebishev::iter_chebishev() 
	: A(MatrixA()), k(1), epsMet(0.0), Nmax(0), Mmin(0), Mmax(0), tau(vector<double>()) { }

iter_chebishev::iter_chebishev(const MatrixA& _A, int _k, double _epsMet, int _Nmax)
	: A(_A), k(_k), epsMet(_epsMet), Nmax(_Nmax), Mmin(0), Mmax(0), tau(vector<double>()) { }

void iter_chebishev::setA(const MatrixA& _A) {
	A = _A;
}

void iter_chebishev::setK(int _k) {
	k = _k;
}

void iter_chebishev::setEpsMet(double _epsMet) {
	epsMet = _epsMet;
}

void iter_chebishev::setNmax(int _Nmax) {
	Nmax = _Nmax;
}

double u(double x, double y) {
	return exp(1 - x * x - y * y);
}

double iter_chebishev::calc_eps_1(const VectorV& V) {
	double eps_curr;
	double eps1 = 0.0;
	int n, m;
	V.getSize(n, m);
	double h = 2.0 / n;
	double k = 2.0 / m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			eps_curr = abs(u(-1.0 + i * h, -1.0 + j * k) - V[i][j]);
			if (eps_curr > eps1) {
				eps1 = eps_curr;
			}
		}
	}
	return eps1;
}

void iter_chebishev::solve(VectorV& V, double& eps, int& N) {
	A.getLamdMinMax(Mmin, Mmax);
	calc_tau();
	VectorV V_tmp(V);
	int Nmax_correct = Nmax - (Nmax % k);
	double eps1, RN;
	VectorV R;
	// cout.setf(ios::scientific);
	// ofstr.open("data.txt");
	for (int i = 0; i < Nmax_correct / k; i++) {
		for (int j = 0; j < k; j++) {
			R = A.residual(V);
			V = V - tau[index_tau[j]] * R;
		}
		eps = calc_eps_current(V_tmp, V);
		// eps1 = calc_eps_1(V);
		// RN = A.residual(V).norm_vector_euclid();
		// cout << "N = " << (i + 1) * k << " eps1 = " << eps1 << " eps = " << eps << " RN = " << RN << "\n";
		// ofstr << "N = " << (i + 1) * k << " eps1 = " << eps1 << " eps = " << eps << " RN = " << RN << "\n";
		if (eps <= epsMet) {
			N = (i + 1) * k;
			return;
		} 
		V_tmp = V;
	}
	ofstr.close();
	N = Nmax_correct;
}
#include "chebishev.h"

void iter_chebishev::initial_approximation(vector<double>& V) {
	V.resize(B.size());
	switch (approx) {
	case APPROX::ZERO:
		for (int i = 0; i < V.size(); i++) {
			V[i] = 0.0;
		}
		break;
	case APPROX::AVERAGE:
		break;
	case APPROX::LINEARX:
		break;
	case APPROX::LINEARY:
		break;
	default:
		break;
	}
}

void iter_chebishev::calc_tau() {
	tau.resize(k);
	for (int i = 0; i < tau.size(); i++) {
		tau[i] = 1.0 / ((Mmin + Mmax) / 2.0 + (Mmax - Mmin) / 2.0 * cos(M_PI / (2.0 * k) * (1.0 + 2.0 * i)));
	}
}

double iter_chebishev::calc_eps_current(const vector<double>& V_prev, const vector<double> &V_curr) {
	double eps_tmp = 0.0;
	for (int i = 0; i < V_prev.size(); i++) {
		eps_tmp = max(eps_tmp, abs(V_prev[i] - V_curr[i]));
	}
	return eps_tmp;
}

iter_chebishev::iter_chebishev() 
	: A(MatrixA()), B(vector<double>()), k(1), approx(APPROX::ZERO), epsMet(0.0), Nmax(0), Mmin(0), Mmax(0), tau(vector<double>()) { }

iter_chebishev::iter_chebishev(const MatrixA& _A, const vector<double>& _B, int _k, APPROX _approx, double _epsMet, int _Nmax)
	: A(_A), B(_B), k(_k), approx(_approx), epsMet(_epsMet), Nmax(_Nmax), Mmin(0), Mmax(0), tau(vector<double>()) { }

void iter_chebishev::setA(const MatrixA& _A) {
	A = _A;
}

void iter_chebishev::setB(const vector<double>& _B) {
	B = _B;
}

void iter_chebishev::setK(int _k) {
	k = _k;
}

void iter_chebishev::setApprox(APPROX _approx) {
	approx = _approx;
}

void iter_chebishev::setEpsMet(double _epsMet) {
	epsMet = _epsMet;
}

void iter_chebishev::setNmax(int _Nmax) {
	Nmax = _Nmax;
}

void iter_chebishev::solve(vector<double>& V, vector<double>& V0, double& eps, int& N) {
	initial_approximation(V);
	A.getLamdMinMax(Mmin, Mmax);
	calc_tau();
	V0 = V;
	vector<double> V_tmp(V.size());
	int Nmax_correct = Nmax - (Nmax % k);
	int count = 0;
	for (int i = 0; i < Nmax_correct / k; i++) {
		for (int j = 0; j < k; j++) {
			vector<double> v1 = A * V;
			V = V + tau[j] * (B - A * V);
		}
		eps = calc_eps_current(V_tmp, V);
		if (eps <= epsMet) {
			N = (i + 1) * k;
			return;
		}
		V_tmp = V;
	}
	N = Nmax_correct;
}
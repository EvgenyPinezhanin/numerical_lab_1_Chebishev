#pragma once

#include <vector>
#define USE_MATH_DEFINES
#include <math.h>

#include "linsys.h"
#include "info.h"

using std::vector;

class iter_chebishev {
private:
	MatrixA A;
	int k;
	double epsMet;
	int Nmax;

	double Mmin, Mmax;
	vector<double> tau;
	vector<int> index_tau;

	void calc_index_tau(int pow);
	void calc_tau();
	double calc_eps_current(const VectorV &V_prev, const VectorV &V_curr);
	double calc_eps_1(const VectorV& V);

public:
	iter_chebishev();
	iter_chebishev(const MatrixA &_A, int _k, double _epsMet, int _Nmax);

	void setA(const MatrixA &_A);
	void setK(int _k);
	void setEpsMet(double _epsMet);
	void setNmax(int _Nmax);

	void solve(VectorV &V, double &eps, int &N);
};
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
	vector<double> B;
	int k;
	double epsMet;
	int Nmax;

	double Mmin, Mmax;
	vector<double> tau;

	void calc_tau();
	double calc_eps_current(const vector<double> &V_prev, const vector<double> &V_curr);

public:
	iter_chebishev();
	iter_chebishev(const MatrixA &_A, const vector<double> &_B, int _k, double _epsMet, int _Nmax);

	void setA(const MatrixA &_A);
	void setB(const vector<double> &_B);
	void setK(int _k);
	void setEpsMet(double _epsMet);
	void setNmax(int _Nmax);

	void solve(vector<double> &V, double &eps, int &N);
};
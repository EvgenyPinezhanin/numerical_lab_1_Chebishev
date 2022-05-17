#pragma once

#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class MatrixA {
private:
	int n, m;
	double h, k;

public:
	MatrixA(int _n = 0, int _m = 0, double _h = 0.1, double _k = 0.1);

	vector<double> operator*(const vector<double>& vec);

	void setN(int _n);
	void setM(int _m);
	void setH(double _h);
	void setK(double _k);
	void setParam(int _n, int _m, double _h, double _k);

	void getLamdMinMax(double &Mmin, double &Mmax) const;
};

class VectorB {
public:
	static void getVectorB(vector<double> &vec, int n, int m, double h, double k, double (*f)(double, double), 
						   double (*mu)(double, int), double a, double b, double c, double d);
};

vector<double> operator+(const vector<double> &v1, const vector<double> &v2);
vector<double> operator-(const vector<double>& v1, const vector<double>& v2);
vector<double> operator*(double a, const vector<double>& v);

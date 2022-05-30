#pragma once

#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class VectorV {
private:
	vector<vector<double>> *v_data;
	double a, b, c, d;
	int n, m;

public:
	VectorV() : v_data(new vector<vector<double>>()) {};
	VectorV(int _n, int _m, double _a, double _b, double _c, double _d);
	VectorV(const VectorV &V);
	~VectorV();

	VectorV& operator=(const VectorV& V);

	vector<double>& operator[](size_t index);
	const vector<double>& operator[](size_t index) const;
	
	void setBorder(double (*mu)(double, int));
	void setInterval(double _a, double _b, double _c, double _d);
	void setSize(int _n, int _m);

	void getInterval(double& _a, double& _b, double& _c, double& _d) const;
	void getSize(int& _n, int& _m) const;

	double norm_vector_max();
	double norm_vector_euclid();

	friend VectorV operator-(const VectorV& V1, const VectorV& V2);
	friend VectorV operator*(double a, const VectorV& V);
};

class MatrixA {
public:
	MatrixA(int _n = 0, int _m = 0, double _h = 0.0, double _k = 0.0, double (*_f)(double, double) = nullptr)
		: n(_n), m(_m), h(_h), k(_k), f(_f) {};

	double (*f)(double, double);

	int n, m;
	double h, k;

	void getLamdMinMax(double& Mmin, double& Mmax) const;

	VectorV residual(const VectorV& V);
};

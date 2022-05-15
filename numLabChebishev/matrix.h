#pragma once

#include <vector>

using namespace std;

class MatrixA {
private:
	int width, height;
	double h, k;

public:
	MatrixA(int _width = 0, int _height = 0, double _h = 0.1, double _k = 0.1);

	void setWidth(int _width);
	void setHeight(int _height);
	void setH(double _h);
	void setK(double _k);
	void setParam(int _width, int _height, double _h, double _k);

	void getLamdMinMax(double &Mmin, double &Mmax) const;
};

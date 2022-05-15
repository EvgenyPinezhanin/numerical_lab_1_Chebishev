#include "matrix.h"

MatrixA::MatrixA(int _width, int _height, double _h, double _k) 
	: width(_width), height(_height), h(_h), k(_k) {}

void MatrixA::setWidth(int _width) {
	width = _width;
}

void MatrixA::setHeight(int _height) {
	height = _height;
}

void MatrixA::setH(double _h) {
	h = _h;
}

void MatrixA::setK(double _k) {
	k = _k;
}

void MatrixA::setParam(int _width, int _height, double _h, double _k) {
	width = _width;
	height = _height;
	h = _h;
	k = _k;
}

void MatrixA::getLamdMinMax(double& Mmin, double& Mmax) const {
	Mmin = 0.0001;
	Mmax = 4.0 * (1.0 / (h * h) + 1.0 / (k * k));
}
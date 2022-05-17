#pragma once

enum class TASK { MAIN, TEST };
enum class APPROX { LINEARX, LINEARY, AVERAGE, ZERO };

// Структура для хранения информации об испытании
struct Info {
	TASK task;
	int n, m;
	int k;
	double epsMet, epsN, eps1;
	int Nmax, N;
	double norm_RN, norm_R0;
	double max_x1, max_y1;
	APPROX approx;

	double epsN2, eps2;
	int N2;
	double norm_RN2, norm_R02;
	double max_x2, max_y2;

	double time;

	Info(TASK _task = TASK::TEST, int _n = 0, int _m = 0, int _k = 0, double _epsMet = 0.0, int _Nmax = 0, double _epsN = 0.0, int _N = 0, double _norm_RN = 0.0,
		 double _max_x1 = 0.0, double _max_y1 = 0.0, APPROX _approx = APPROX::ZERO, double _norm_R0 = 0.0, double _epsN2 = 0.0, double _eps2 = 0.0, int _N2 = 0,
		 double _norm_RN2 = 0.0, double _norm_R02 = 0.0, double _max_x2 = 0.0, double _max_y2 = 0.0, double _time = 0.0) 
		: task(_task), n(_n), m(_m), k(_k), epsMet(_epsMet), Nmax(_Nmax), epsN(_epsN), N(_N), norm_RN(_norm_RN), max_x1(_max_x1), max_y1(_max_y1), approx(_approx), 
		norm_R0(_norm_R0), epsN2(_epsN2), eps2(_eps2), N2(_N2), norm_RN2(_norm_RN2), norm_R02(_norm_R02), max_x2(_max_x2), max_y2(_max_y2), time(_time) {};
};
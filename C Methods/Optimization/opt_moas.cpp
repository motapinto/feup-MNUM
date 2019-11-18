#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double WOAH_NUM = (sqrt(5) - 1) / 2.0;

double f(double x) {
	return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

double nf(double x) {
	return -f(x);
}

double aurea(double f(double), double x1, double x2, double absError) {
	double B = WOAH_NUM;
	double A = B * B;
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);
	while (fabs(x2 - x1) > absError) {
		if (f(x3) < f(x4))
			x2 = x4;
		else x1 = x3;
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
	}
	return x3;
}


struct point {
	point(double x, double y) : x(x), y(y) {}
	double x, y;
};

double f1(double x, double y) {
	return y * y - 2 * x*y - 6 * y + 2 * x*x + 12;
}


double df1x(double x, double y) {
	return -2 * y + 4 * x;
}

double df1y(double x, double y) {
	return 2 * y - 2 * x - 6;
}

double f2(double x, double y) {
	return -(2 * x*y + 2 * x - x * x - 2 * y * y);
}

double df2x(double x, double y) {
	return -(2 * y + 2 - 2 * x);
}

double df2y(double x, double y) {
	return -(2 * x - 4*y);
}

point gradiente(double f(double, double), double dfx(double, double), double dfy(double, double), double x0, double y0, double h0, double absError) {
	double x = x0, y = y0, h = h0;
	double xNext, yNext;
	bool continua = true;
	while (continua) {
		xNext = x - h * dfx(x, y);
		yNext = y - h * dfy(x, y);
		if (f(xNext, yNext) < f(x, y))
			h = h * 2.0;
		else h = h / 2.0;
		if (fabs(xNext - x) < absError && fabs(yNext - y) < absError)
			continua = false;
		x = xNext, y = yNext;
	}
	return point(x, y);
}

// Pode-se trocar o sinal da funcao e derivadas em vez disto.
point gradienteMax(double f(double, double), double dfx(double, double), double dfy(double, double), double x0, double y0, double h0, double absError) {
	double x = x0, y = y0, h = h0;
	double xNext, yNext;
	bool continua = true;
	while (continua) {
		xNext = x + h * dfx(x, y);
		yNext = y + h * dfy(x, y);
		if (f(xNext, yNext) > f(x, y))
			h = h * 2.0;
		else h = h / 2.0;
		if (fabs(xNext - x) < absError && fabs(yNext - y) < absError)
			continua = false;
		x = xNext, y = yNext;
	}
	return point(x, y);
}

// inversa da matriz hessiana de f
double invH1(double x, double y) {
	return 0.25;
}

// inversa da matriz hessiana de f2
double invH2(double x, double y) {
	return 0.25;
}

point quadrica(double f(double, double), double dfx(double, double), double dfy(double, double), double x0, double y0, double invH(double, double), double absError) {
	double x = x0, y = y0;
	double xNext, yNext;
	bool continua = true;
	while (continua) {
		xNext = x - invH(x,y) * dfx(x, y);
		yNext = y - invH(x,y) * dfy(x, y);
		if (fabs(xNext - x) < absError && fabs(yNext - y) < absError)
			continua = false;
		x = xNext, y = yNext;
	}
	return point(x, y);
}
int main() {
	double min = aurea(f, -1, 0, 0.001);
	double max = aurea(nf, -1, 0, 0.001);
	cout << "aurea min: " << f(min) << " | x = " << min << endl;
	cout << "aurea max: " << f(max) << " | x = " << max << endl;
	point minimo = gradiente(f1, df1x, df1y, 1, 1, 1, 0.001);
	point maximo = gradiente(f2, df2x, df2y, -1, 1, 1, 0.001);
	cout << "gradiente min: " << f1(minimo.x, minimo.y) << " | x = " << minimo.x << " | y = " << minimo.y << endl;
	cout << "gradiente max: " << f2(maximo.x, maximo.y) << " | x = " << maximo.x << " | y = " << maximo.y << endl;
	minimo = quadrica(f1, df1x, df1y, 1, 1, invH1, 0.001);
	maximo = quadrica(f2, df2x, df2y, 1, 1, invH2, 0.001);
	cout << "quadrica min: " << f1(minimo.x, minimo.y) << " | x = " << minimo.x << " | y = " << minimo.y << endl;
	cout << "quadrica max: " << f2(maximo.x, maximo.y) << " | x = " << maximo.x << " | y = " << maximo.y << endl;
}

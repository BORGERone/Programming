#include <iostream>
using namespace std;

double x(double x0, double v0, double a, double t) {
	return x0 + v0 * t - (a * t * t) / 2;
}

	int main()
{
	setlocale(LC_ALL, "Russian");
	double x0;
	double v0;
	double t;
	double g = 9.8;

	cout << "Введите x0, v0 и t через пробел\n" ;
	cin >> x0 >> v0 >> t;
	double xt = abs(x0 - x(x0, v0, g, t));
	cout << "xt = " << xt;
}

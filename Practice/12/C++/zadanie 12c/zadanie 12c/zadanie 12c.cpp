#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	long a;
	long long b = 1;
	cout << "Этот калькулятор вычисляет факториал числа\n Введите число для расчёта факториала:\n";
	cin >> a;

	for (int c = 2; c <= a; c++) {
		b *= c;
	}
	cout << b;
}
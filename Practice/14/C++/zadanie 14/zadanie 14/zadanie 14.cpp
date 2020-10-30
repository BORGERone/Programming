#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	long long a;
	int x = 0;
	cout << "Введите целое число:\n";
    cin >> a;

	if (a >= 1) {
		x++;
	}
		while (a > 1) {
			a /= 2;
			x++;
		}

	cout << x;
}
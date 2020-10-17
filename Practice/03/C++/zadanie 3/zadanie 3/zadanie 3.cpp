#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double d;
	double c;
	int a;
	int b;

	cout << "Введите 2 целых числа\n";
		cin >> a;
		cin >> b;
		cout << "Введите 2 не целых числа\n";
		cin >> c;
		cin >> d;

		cout << "a + b = " << a + b << endl;
		cout << "a - b = " << a - b << endl;
		cout << "a * b = " << a * b << endl;
		cout << "a / b = " << a / b << endl;
		//целые числа
		cout << "c + d = " << c + d << endl;
		cout << "c - d = " << c - d << endl;
		cout << "c * d = " << c * d << endl;
		cout << "c / d = " << c / d << endl;
		//дробные числа
		cout << "c + b = " << c + b << endl;
		cout << "c - b = " << c - b << endl;
		cout << "c * b = " << c * b << endl;
		cout << "c / b = " << c / b << endl;
		//дробные с целыми
		cout << "a + d = " << a + d << endl;
		cout << "a - d = " << a - d << endl;
		cout << "a * d = " << a * d << endl;
		cout << "a / d = " << a / d << endl;
		//целые с дробными

		//С++ выдает целые числа при переменной типа int, но если есть хотя бы одна переменная типа double - получается дробное число
}
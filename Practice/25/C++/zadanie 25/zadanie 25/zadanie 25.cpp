#include <iostream>
using namespace std;

int main()
{
	double n;
	setlocale(LC_ALL, "RU");
	cout << "Сколько чисел нужно отсортировать?\n";
	cin >> n;
	if (4 >= n) {
		cout << "Эта программа сортирует минимум 5 цифр";
	}
	else if (n <= 100) {
		cout << "Введите числа через пробел";
	}
	else {
		cout << "Эта программа способна отсортировать не более 100 чисел";
	}
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
	double n, a;
	setlocale(LC_ALL, "RU");
	vector<int>num;

	cout << "Сколько чисел нужно отсортировать?\n";
	cin >> n;
	if (4 >= n) {
		cout << "Эта программа сортирует минимум 5 цифр";
	}
	else if (n <= 100) {
		for (int range = 1; range <= n; range++) {
			num.push_back(0);
			cout << range << endl;
		}
		//заполнили диапазон нулями
		for(int m = 0; m < n; m++) {
			cout << "Введите число "<< m+1 <<"\n";
			cin >> a;
			num[m] = a;
		}
		//ниже код для просмотра того, что находится в диапозоне
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << "\n";
		}
	}
	else {
		cout << "Эта программа способна отсортировать не более 100 чисел";
	}
}

﻿#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int p, r, x;
	bool win, retry;
	cout << "<====================================>\n Приветствую вас в игре под названием\n  \\                                /\n  || |]|[|]|[УГАДАЙ ЧИСЛО]|[|]|[| ||\n  /                                \\ \n<====================================>\n  Компьютер загадал случайное число\n    в диапазоне от [1] до [100]\nУ Вас есть 5 попыток чтобы его угадать\n    Какое число загадал компьютер?\n";

	do {
		retry = false;
		win = false;
		r = rand() % 101;
		for (int c = 0; c < 5; c++) {
			cin >> p;
			if (p < r) {
				cout << "===============================\n       [Загаданное число больше]\n";
			}
			else if (p > r) {
				cout << "===============================\n       [Загаданное число меньше]\n";
			}
			else {
				cout << "===============================\n       [Поздравляю! Вы угадали]\n";
				win = true;
				break;
			}
		}
		if (win == false) {
			cout << "[Вы проиграли. Было загадано: " << r << "]\n";
		}
		cout << "[Хотите начать сначала?] (1 - ДА)\n";
		cin >> x;
		if (x == 1) {
			cout << "<============ТОГДА ПРИСТУПИМ============>\n  Компьютер загадал случайное число\n     в диапазоне от [1] до [100]\nУ Вас есть 5 попыток чтобы его угадать\n     Какое число загадал компьютер?\n";
			retry = true;
		}
	} while (retry);
}
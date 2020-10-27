#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	double b;
	char c;
	double x;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число, символ и еще одно число через пробел:\n";
cin >> a;
cin >> c;
cin >> b;

switch (c) 
{
case '-':
	x = (a - b);
	break;

case '+':
	x = (a + b);
	break;

case '*':
	x = (a * b);
	break;

case '/':
	if (b == 0)
        {
			cout << "Делить на ноль нельзя";
			break;
		}
	x = (a / b);
	break;	
default:
	cout << "[ОШИБКА]////////////////////////////////\n В одной строке, через пробел вводятся: \n     вещественное число \n     затем символ - знак операции \n     и вещественное число\n============ПОВТОРИТЕ ПОПЫТКУ============";
}
cout << x;
}
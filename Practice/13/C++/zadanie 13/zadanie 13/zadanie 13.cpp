#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
    int a;
    cout << "Введите число:\n ";
    cin >> a;
    if (a == 1 || a % 2 == 0 && a / 2 != 0)
        cout << "Составное " << endl;
    else
        cout << "Простое\n" << endl;
}

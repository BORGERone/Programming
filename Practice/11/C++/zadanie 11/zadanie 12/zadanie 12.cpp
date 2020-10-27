#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    double b;
    double c;
    double d = 1;
    double e;
    cout << "Этот калькулятор вычисляет степень числа \n Введите число которое нужно возвести в степень:\n";
    cin >> a;
    cout << " Введите саму степень:\n";
        cin >> c;
        e = a;
        if (c == 0) {
            cout << "0";
        }
        else {
            while (c != d) {
                a = (e * a);
                d++;
            }
            cout << a;
        }
    return 0;
}
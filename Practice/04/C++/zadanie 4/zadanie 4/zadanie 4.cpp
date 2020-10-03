#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    double b;

    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;

    swap(a, b);

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    (a, b = b, a);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
}
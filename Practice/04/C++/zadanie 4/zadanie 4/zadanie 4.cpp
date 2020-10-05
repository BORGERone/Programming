#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a;
    double b;
    double c;

        cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;

    swap(a, b);

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    

        (c = a);
        (a = b);
        (b = c);
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
}
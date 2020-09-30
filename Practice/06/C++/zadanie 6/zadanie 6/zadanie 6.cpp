#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double a;
	double b;
	double c;
	double x;

    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    cout << "Введите значение c: ";
    cin >> c;

    if ((a + b + c) == 0)
    {
        cout << "Бесконечно корней  ＼(º □ º *)/" << endl;
    }

    if (a == 0)
        if (b != 0)
            if (c != 0)
    {
        x = (b / -c);
        cout << "x1 = " << x << endl;
    }
    
        if ((b * b - 4 * a * c) > 0)
            if (a != 0)
        {
            x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "x1 = " << x << endl;
            x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "x2 = " << x << endl;
        }
   
        if ((b * b - 4 * a * c) < 0)
        {
            x = (b * b - 4 * a * c);
            cout << "x 1 = " << x << endl;
        }
        if ((b * b - 4 * a * c) == 0)
            if (a != 0)
        {
            x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "x1 = " << x << endl;
        }
}
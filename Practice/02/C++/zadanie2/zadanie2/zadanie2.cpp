#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    double c;
    double d;
    (a = 3);
    (b = 3.14); //Будет выводится "3", т.к. это целочисленная переменная
    (c = 3);
    (d = 3.14);
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
   cout << d << endl;
}

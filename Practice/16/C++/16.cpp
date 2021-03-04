#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int a, b, f = 0;
    cout << "¬ведите количество билетов\n";
    cin >> a;
    cout << "¬ведите билеты через пробел\n";
    string str{};
    for (int c = 1; c <= a; c++) {
        cin >> str;
        if (str[0] == 'a' && str[4] == '5' && str[5] == '5' && str[6] == '6' && str[7] == '6' && str[8] == '1') {
            cout << str << " ";
        }
        else {
            f++;
        }
    }
    if (f == a) {
        cout << "-1";
    }
}

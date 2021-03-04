#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "¬ведите стоп слово\n";
	string word;
	cin >> word;
	double bukvi[26] = {};
	double chanse_proiznesti = 1;
	char alf[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'x' };
	vector<string> s1 = { "hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen" };
	int dlinna = 0;

	for (int c = 0; c < s1.size(); c++) {
		for (int j = 0; j < s1[c].size(); j++) {
			dlinna++;
			for (int k = 0; k < 26; k++) {
				if (s1[c][j] == alf[k])
				{
					bukvi[k]++;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		bukvi[i] = bukvi[i] / dlinna;
	}

	for (int i = 0; i < word.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (word[i] == alf[j]) {
				chanse_proiznesti = chanse_proiznesti * bukvi[j];
			}
		}
	}
	cout.precision(16);
	cout << chanse_proiznesti << endl;
}
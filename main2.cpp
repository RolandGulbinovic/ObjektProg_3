#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
using std::sort;
using std::setw;
using std::setprecision;
using std::fixed;

struct studentas {
	string Vardas;
	string Pav;
	int nd[15];
	int egz;
	float GP;
	float Med;
};



int main()
{
	vector<studentas> Eiles;
	studentas laik;
	int n;
	int sk;
	int l = 0;
	cout << "Norite gauti studentu mediana(1) ar Galutini pazymi(2)" << endl;
	cin >> sk;


	cout << "Iveskite studentu skaiciu" << endl;
	cin >> l;
	Eiles.reserve(l);

	for (int i = 0; i < l; i++) {

		laik.GP = 0;
		laik.Med = 0;

		cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
		cin >> laik.Vardas >> laik.Pav;
		cout << "Iveskite namu darbu skaiciu" << endl;
		cin >> n;
		cout << "Prasome ivesti visus namu darbu pazymius" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> laik.nd[j];
			laik.GP = laik.nd[j] + laik.GP;
		}
		cout << "Iveskite egzamino rez." << endl;
		cin >> laik.egz;

		if (sk == 2)
		{
			laik.GP = laik.GP / (float)n;
			laik.GP = 0.4 * laik.GP + 0.6 * (float)laik.egz; //GP skaiciavumas
		}
		else {
			laik.nd[n] = laik.egz;
			sort(laik.nd, laik.nd + (n + 1));
			if (n + 1 % 2 != 0)
				laik.Med = (float)laik.nd[(n + 1) / 2];

			laik.Med = (float)(laik.nd[n / 2] + laik.nd[(n + 1) / 2]) / 2.0;
		}
		Eiles.push_back(laik);

	}

	for (auto tt: Eiles) {
		if (sk == 2)
		{
			cout << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis Paz" << endl;
			cout << tt.Vardas << setw(15) << tt.Pav << setw(15) << fixed << setprecision(2) << tt.GP; ; //Isvedimas
			cout << endl;
		}
		else {
			cout << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis Paz" << setw(20) << endl;
			cout << tt.Vardas << setw(15) << tt.Pav << setw(15) << fixed << setprecision(2) << tt.Med; //Isvedimas
			cout << endl;
		}
	}
}

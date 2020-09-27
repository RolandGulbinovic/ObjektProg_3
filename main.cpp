#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>


using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
using std::sort;

struct studentas {
	string Vardas[10];
	string Pav[10];
	int nd[10][15];
	int egz[10];
	float GP[10];
	float Med[10];
};



int main()
{

	studentas Eil; studentas Eil_mas[5];
	vector<studentas> Eiles;
	int n;
	int sk;
	int l;
	cout << "norite medianas(1) ar GP(2)" << endl;
	cin >> sk;

	for (int i = 0; i < 10; i++) {
		Eil.GP[i] = 0;
		Eil.Med[i] = 0;
	}

	
	cout << "Iveskite studentu skaiciu" << endl;
	cin >> l;
	for (int i = 0; i < l; i++) {

		cout << "Iveskite studenta varda ir pavarde" << endl;
		cin >> Eil.Vardas[i] >> Eil.Pav[i];
		cout << "Iveskite namu darbu skaiciu" << endl;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> Eil.nd[i][j];
			Eil.GP[i] = Eil.nd[i][j] + Eil.GP[i];
		}
		cout << "Iveskite egzamino rez." << endl;
		cin >> Eil.egz[i];

		if (sk == 2)
		{
			Eil.GP[i] = Eil.GP[i] / (float)n;
			Eil.GP[i] = 0.4 * Eil.GP[i] + 0.6 * (float)Eil.egz[i]; //GP skaiciavumas
		}
		else {
			Eil.nd[i][n] = Eil.egz[i];
			sort(Eil.nd[i], Eil.nd[i] + (n + 1));
			if (n + 1 % 2 != 0)
				Eil.Med[i] = (float)Eil.nd[i][(n + 1) / 2];

			Eil.Med[i] = (float)(Eil.nd[i][n / 2] + Eil.nd[i][(n + 1) / 2]) / 2.0;
		}
	}



	for(int i=0;i<l;i++){
		if (sk == 2)
		{
			cout << Eil.Vardas[i] << " " << Eil.Pav[i] << " "; //Isvedimas
			printf("%.2f", Eil.GP[i]);
			cout << endl;
		}
		else {
			cout << Eil.Vardas[i] << " " << Eil.Pav[i] << " "; //Isvedimas
			printf("%.2f", Eil.Med[i]);
			cout << endl;
		}
	}
}

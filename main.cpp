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

struct studentas {  //Sukuriu struktura
	string Vardas;
	string Pav;
	int* nd;
	int egz;
	float GP;
	float Med;
};

// VERSIJA SU MASYVAIS 
// Man lietuvių kalba terminale nerašo, tai viska (cout << ) parašyta nelietuviškomis raidėmis.

int main()
{
	int n = 0;
	int sk; // sk - Mediana arba Galutinis pažymis
	int l = 0; // l - Norimas studentų kiekis
	int t; // t - Ar norite užpildyti automatiškai duomenis apie namu darbus

	cout << "Norite gauti studentu Mediana(1) ar Galutini pazymi(2)" << endl;

	while (!(cin >> sk))
	{

		cout << "error: ne skaicius ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	}



	cout << "Iveskite studentu skaiciu" << endl;

	while (!(cin >> l))
	{
		cout << "error: ne skaicius ";

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	studentas* Eil = new studentas[l];
	for(int i=1;i<l;i++)
		Eil[i].nd = new int[n];

	for (int i = 0; i < l; i++) {
		// pildau duomenis
		
		int n = 0;
		Eil[i].nd = new int[n];
		
		Eil[i].GP = 0;
		Eil[i].Med = 0;

		studentas* temp = new studentas[l];
		temp[i].nd = new int[n + 1];

		cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
		cin >> Eil[i].Vardas >> Eil[i].Pav;


		cout << "Uzpildyti automatiskai? (random) 1- Taip || 2 - NE" << endl;

		while (!(cin >> t))
		{
			cout << "error: ne skaicius ";

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if (t == 1) {
			cout << "Kiek norite sugeneruoti pazymiu" << endl;
			cin >> n;
			for (int j = 0; j < n; j++) {
				Eil[i].nd[j] = rand() % 11; // (% 11) kad sugeneruotas skaičius butu tarp 0 iki 10
				Eil[i].GP = Eil[i].nd[j] + Eil[i].GP;
			}
		}
		else {
			cout << "Prasome ivesti visus namu darbu pazymius" << endl;
			
			
			while (true)
			{
				cin >> temp[i].nd[n];
				if (temp[i].nd[n] > 0) {
					Eil[i].GP = temp[i].nd[n] + Eil[i].GP;
					for (int j = 0; j < l; j++)
						temp[j] = Eil[j];

					delete[] Eil;
					
					n++;
					Eil = new studentas[l];
					Eil[i].nd = new int[n];
					
					
					for(int j=0;j<l;j++)
						Eil[j] = temp[j];

					delete[] temp;

					temp = new studentas[l];
					temp[i].nd = new int[n + 1];
				}
				else if(temp[i].nd[n] == 0) {
					cin.clear();
					cin.ignore(10, '\n');
					break;
				}

			}
		}
		delete[] temp;
		cout << Eil[i].GP / (float)(n - 1) << endl;
		cout << "Iveskite egzamino rez." << endl;

		while (!(cin >> Eil[i].egz))
		{
			cout << "ERROR: ne skaicius " << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}



		if (sk == 2)
		{
			Eil[i].GP = Eil[i].GP / (float)(n);
			Eil[i].GP = 0.4 * Eil[i].GP + 0.6 * (float)Eil[i].egz; //skaičiuojamas galutinis pažymis
		}
		else {

			Eil[i].nd[n+1] = Eil[i].egz; // Pridedu egz rezultata į nd masyva kaip paskutini elementa
			sort(Eil[i].nd, Eil[i].nd + (n + 1));  //rušiuoju
			//skaičiuoju mediana

			if (n + 1 % 2 != 0)
				Eil[i].Med = (float)Eil[i].nd[(n + 1) / 2];

			Eil[i].Med = (float)(Eil[i].nd[n / 2] + (float)Eil[i].nd[(n + 1) / 2]) / (float)2.0;
		}
		
	}

	//Spausdinimas i terminala rezultatu

	if (sk == 2) cout << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis Paz(vid.)" << endl;

	else cout << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis Paz(med.)" << endl;

	for (int i = 0; i < l; i++) {
		if (sk == 2)
		{
			cout << Eil[i].Vardas << setw(15) << Eil[i].Pav << setw(15) << fixed << setprecision(2) << Eil[i].GP; ; //Isvedimas
			cout << endl;
		}
		else {
			cout << Eil[i].Vardas << setw(15) << Eil[i].Pav << setw(15) << fixed << setprecision(2) << Eil[i].Med; //Isvedimas
			cout << endl;
		}
	}
}

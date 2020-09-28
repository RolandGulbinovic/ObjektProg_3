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
	int *nd;
	int egz;
	float GP;
	float Med;
};

// VERSIJA SU MASYVAIS 
// Man lietuvių kalba terminale nerašo, tai viska (cout << ) parašyta nelietuviškomis raidėmis.

int main()
{

	int n; // n - Namų darbų skaičius
	int sk; // sk - Mediana arba Galutinis pažymis
	int l=0; // l - Norimas studentų kiekis
	int t; // t - Ar norite užpildyti automatiškai duomenis apie namu darbus

	cout << "Norite gauti studentu Mediana(1) ar Galutini pazymi(2)" << endl;
	cin >> sk;
	
	
	cout << "Iveskite studentu skaiciu" << endl;
	cin >> l; 



	studentas* Eil = new studentas [l];
	

	for (int i = 0; i < l; i++) { // Pasidarau tusčius masyvus
		Eil[i].GP = 0;
		Eil[i].Med = 0;
	}

	for (int i = 0; i < l; i++) {
		// pildau duomenis
		cout << "Iveskite "<< i+1 <<"-ojo studento varda ir pavarde" << endl;
		cin >> Eil[i].Vardas >> Eil[i].Pav;
		cout << "Iveskite namu darbu skaiciu" << endl;
		cin >> n;
		Eil[i].nd = new int[n];
		cout << "Uzpildyti automatiskai? (random) 1- Taip || 2 - NE" << endl;
		cin >> t;
		if (t == 1) {
			for (int j = 0; j < n; j++) {
				Eil[i].nd[j] = rand() % 11; // (% 11) kad sugeneruotas skaičius butu tarp 0 iki 10
				Eil[i].GP = Eil[i].nd[j] + Eil[i].GP;
			}
		}
		else {
			cout << "Prasome ivesti visus namu darbu pazymius" << endl;
			for (int j = 0; j < n; j++)
			{
				cin >> Eil[i].nd[j];
				Eil[i].GP = Eil[i].nd[j] + Eil[i].GP;
			}
		}
		cout << "Iveskite egzamino rez." << endl;
		cin >> Eil[i].egz;

		if (sk == 2)
		{
			Eil[i].GP = Eil[i].GP / (float)n;
			Eil[i].GP = 0.4 * Eil[i].GP + 0.6 * (float)Eil[i].egz; //skaičiuojamas galutinis pažymis
		}
		else {
			Eil[i].nd[n] = Eil[i].egz; // Pridedu egz rezultata į nd masyva kaip paskutini elementa
			sort(Eil[i].nd, Eil[i].nd + (n + 1));  //rušiuoju
			//skaičiuoju mediana
			if (n + 1 % 2 != 0)
				Eil[i].Med = (float)Eil[i].nd[(n + 1) / 2];	

			Eil[i].Med = (float)(Eil[i].nd[n / 2] + (float)Eil[i].nd[(n + 1) / 2]) / (float) 2.0;
		}

	}

	//Spausdinimas i terminala rezultatu
	
	if (sk == 2) cout << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis Paz(vid.)" << endl;

	else cout << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis Paz(med.)" << endl;

	for(int i=0;i<l;i++){
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

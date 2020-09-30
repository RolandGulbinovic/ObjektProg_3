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
	int* nd{};
	int egz{};
	float GP{};
	float Med{};
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

	while (cin >> sk && sk !=1 && sk!=2)
	{

		cout << "ERROR: Ivestas klaidingas skaicius "<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	}



	cout << "Iveskite studentu skaiciu" << endl;

	while (cin >> l && l<=0)
	{
		cout << "ERROR: Ivestas klaidingas skaicius "<<endl;

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	studentas* Eil = new studentas[l];		// sukuriu dynamiška masyva Eil
	for(int i=0;i<l;i++)
		Eil[i].nd = new int[n];

	for (int i = 0; i < l; i++) {
		// pildau duomenis
		
		int n = 0;
		Eil[i].nd = new int[n];
		
		Eil[i].GP = 0;
		Eil[i].Med = 0;

		studentas* temp = new studentas[l]; //sukuriu laikina masyva temp
		temp[i].nd = new int[n + 1]; //namu darbus turi (n+1)

		cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
		cin >> Eil[i].Vardas >> Eil[i].Pav;


		cout << "Uzpildyti automatiskai? (random) 1- Taip || 2 - NE" << endl;
		
		while (cin>>t && t != 1 && t!=2)
		{
			cout << "error: ne skaicius ";

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if (t == 1) {
			cout << "Kiek norite sugeneruoti pazymiu" << endl;
			cin >> n;
			for (int j = 0; j < n; j++) {

				for (int k = 0; k < l;k++) //kopijuoju duomenys iš Eil į laikina masyva temp
					temp[k] = Eil[k];

				delete[] Eil;	//ištrinų masyva Eil
				
				Eil = new studentas[l];	//sukuriu nauja masyva Eil su Eil[i].nd[n+1]
				Eil[i].nd = new int[n+1];

				for (int k = 0; k < l; k++)	// atgal keliu duomenys iš temp į Eil
					Eil[k] = temp[k];

				Eil[i].nd[j] = rand() % 11; // (% 11) kad sugeneruotas skaičius butu tarp 0 iki 10
				Eil[i].GP = Eil[i].nd[j] + Eil[i].GP;
			}
		}
		else {
			cout << "Prasome ivesti visus namu darbu pazymius kai uzbaigete pildyti parasykite (-1)" << endl;
			
			while (true)
			{
				for (int j = 0; j < l; j++)	//kopijuoju duomenys iš Eil į laikina masyva temp
					temp[j] = Eil[j];

				cin >> temp[i].nd[n];
				if (temp[i].nd[n] > 0) {
					
					delete[] Eil;	//ištrinų masyva Eil
					
					n++;

					Eil = new studentas[l];
					Eil[i].nd = new int[n];	//sukuriu nauja masyva Eil su Eil[i].nd[n] kur n++ kiekviena karta kai ivedu duomenys
					
					
					for(int j=0;j<l;j++)	// atgal keliu duomenys iš temp į Eil
						Eil[j] = temp[j];

					Eil[i].GP = Eil[i].nd[(n-1)] + Eil[i].GP;

					delete[] temp;	//ištrinų masyva temp

					temp = new studentas[l];
					temp[i].nd = new int[n + 1];//sukuriu nauja masyva temp su temp[i].nd[n+1] kur n++ kiekviena karta kai ivedu duomenys
				}
				else if (temp[i].nd[n] == -1){
					cin.clear();
					cin.ignore(10, '\n');
					break;
				}

			}
			
		}
		cout << "Iveskite egzamino rez." << endl;

		while (cin >> Eil[i].egz && Eil[i].egz <= 0)
		{
			cout << "ERROR: ne skaicius " << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		

		if (sk == 2)
		{	
			if (n == 0) {
				Eil[i].GP = 0; // kad nebutu dalybos iš 0, kai namu darbu 0
			}
			else {
				Eil[i].GP = Eil[i].GP / (float)(n);
				Eil[i].GP = (float)0.4 * Eil[i].GP + (float)0.6 * (float)Eil[i].egz; //skaičiuojamas galutinis pažymis
			}
		}
		else {
			if (n == 0) {
				Eil[i].Med = (float)Eil[i].egz;	// Prielaida tokia kad, egzamino pažymis turi visada buti, tai jeigu namu darbu nera mediana yra iš vieno skaičio(egzamino paž.)
			}
			else {
				for (int j = 0; j < l; j++)
					temp[j] = Eil[j];
				delete[] Eil;

				Eil = new studentas[l];
				Eil[i].nd = new int[(n + 1)];

				for (int j = 0; j < l; j++)
					Eil[j] = temp[j];


				Eil[i].nd[n] = Eil[i].egz; // Pridedu egz rezultata į nd masyva kaip paskutini elementa
				sort(Eil[i].nd, Eil[i].nd + (n + 1));  //rušiuoju
				//skaičiuoju mediana

				if ((n + 1) % 2 != 0)
					Eil[i].Med = (float)Eil[i].nd[(n + 1) / 2];

				Eil[i].Med = (float)(Eil[i].nd[n / 2] + (float)Eil[i].nd[(n + 1) / 2]) / (float)2.0;
			}
		}
		delete[] temp;
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

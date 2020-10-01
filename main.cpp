
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <iomanip>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
using std::sort;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::ifstream;
using std::left;

struct studentas {
	string Vardas;
	string Pav;
	int nd;
	int egz;
	float GP;
	float Med;
};


// VERSIJA SU VEKTORIAIS

bool compareByName(const studentas& a, const studentas& b);

int main()
{
	vector<studentas> Eiles;
	vector<int> ndf;// Vektorius
	ifstream inFile;
	studentas laik;
	int sk;
	int f;
	int l = 0;
	int t;
	int n = 0;
	string failas;
	string header;

	cout << "Norite gauti studentu mediana(1) ar Galutini pazymi(2)" << endl;

	while (!(cin >> sk) || (sk != 1 && sk != 2))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "ERORR: Ivesti galima tik 1 arba 2" << endl;

	}
	cout << "Nuskaityti is failo(1) ar ivedineti asmeniskai(2)?" << endl;
	cin >> f;
	if (f == 1)
	{
		cout << "Kiek namu darbu jusu faile(testavimo failuose - 15; Kursiokai.txt - 5)" << endl;
		cin >> n;
		cout << "Iveskite failo vieta (C:/... .txt" << endl;
		cin >> failas;
		inFile.open(failas);
		getline(inFile, header); //paima pirma eilute "Vardas Pavarde nd1 nd2 nd3...."

		if (inFile.is_open()) {
			while (inFile >> laik.Vardas >> laik.Pav)
			{
				laik.GP = 0;
				laik.Med = 0;
				l++;
				Eiles.reserve(l);
				for (int i = 0; i < n; i++)
				{
					inFile >> laik.nd;
					laik.GP = laik.nd + laik.GP;
					ndf.reserve(n);
					ndf.push_back(laik.nd);
				}
				inFile >> laik.egz;
				if (sk == 2)
				{
					if (n == 0)
						laik.GP = 0; //jei n=0 tai kad nedalintu is 0
					else {
						laik.GP = laik.GP / (float)n;
						laik.GP = 0.4 * laik.GP + 0.6 * (float)laik.egz; //GP skaiciavumas
					}

				}
				else {
					ndf.push_back(laik.egz);
					
					sort(ndf.begin(), ndf.end());
					
					if (ndf.size() % 2 != 0)
						laik.Med = (float)ndf[(ndf.size()) / 2];

					laik.Med = (float)(ndf[(ndf.size()-1) / 2] + ndf[ndf.size() / 2]) / (float)2.0;
				}
				ndf.clear();
				Eiles.push_back(laik);
			}
				
		}
	}
	else {
		cout << "Iveskite studentu skaiciu" << endl;
		while (!(cin >> l) || l <= 0)
		{
			cout << "ERROR: Ivestas klaidingas skaicius " << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		Eiles.reserve(l);


		for (int i = 0; i < l; i++) {
			int n = 0;
			vector<int> nd; //sukuriu dar viena vektoriu kur saugosiu namu darbus, kad galima butu skaiciuoti mediana ir vidurkius


			nd.reserve(n); //rezervuoju n vietos vektoriui nd

			laik.GP = 0;
			laik.Med = 0;

			cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde" << endl;
			cin >> laik.Vardas >> laik.Pav;
			cout << "Uzpildyti automatiskai? (random) 1- Taip/2 - NE" << endl;
			while (!(cin >> t) || (t != 1 && t != 2))
			{
				cout << "ERROR: Ivesti galima tik 1 arba 2 " << endl;

				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			if (t == 1) {
				cout << "Kiek norite sugeneruoti skaiciu" << endl;
				while (!(cin >> n) || n < 0)
				{
					cout << "ERROR:Ivestas klaidingas skaicius " << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				for (int j = 0; j < n; j++) {

					laik.nd = rand() % 11;

					laik.GP = laik.nd + laik.GP;
					nd.push_back(rand() % 11);

				}
			}
			else {
				cout << "Prasome ivesti visus namu darbu pazymius kai uzbaigete pildyti parasykite (-1)" << endl;

				while (true)
				{

					while (!(cin >> laik.nd) || (laik.nd < 0 && laik.nd != -1))
					{
						cout << "ERROR:Ivesta klaidingai " << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					if (laik.nd > 0) {

						n++;

						nd.reserve(n);	// Kiekviena karta kai pridedu elementa rezervuoju n++ vietos
						laik.GP = laik.nd + laik.GP;
						nd.push_back(laik.nd);

					}
					else if (laik.nd == -1) {
						cin.clear();
						cin.ignore(10, '\n');
						break;
					}

				}
			}

			cout << "Iveskite egzamino rez." << endl;
			while (!(cin >> laik.egz) || laik.egz <= 0)
			{
				cout << "ERROR: ne skaicius " << endl;

				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}

			if (sk == 2)
			{
				if (n == 0)
					laik.GP = 0; //jei n=0 tai kad nedalintu is 0
				else {
					laik.GP = laik.GP / (float)n;
					laik.GP = 0.4 * laik.GP + 0.6 * (float)laik.egz; //GP skaiciavumas
				}

			}
			else {

				nd.reserve(n + 1); // rezervuoju daugiau vietos nes kaip paskutini elementa pridedu egz
				
				nd.push_back(laik.egz);

				sort(nd.begin(), nd.end());

				if (nd.size() % 2 != 0)
					laik.Med = (float)nd[(nd.size()) / 2];

				laik.Med = (float)(nd[(nd.size()-1) / 2] + nd[(nd.size() / 2)]) / (float)2.0;
			}
			Eiles.push_back(laik); //Viska idedu i vektoriu
		}
	}
	if (sk == 2) cout << setw(15)<< "Vardas" << setw(15) << "Pavarde" << setw(25) << "Galutinis Paz(vid.)" << endl;

	else cout << setw(15)<< "Vardas" << setw(15) << "Pavarde" << setw(25) << "Galutinis Paz(med.)" << endl;

	sort(Eiles.begin(), Eiles.end(), compareByName);
	for (auto tt : Eiles) {
		if (sk == 2)
		{
			cout <<setw(15)<< tt.Vardas << setw(15) << tt.Pav << setw(25) << fixed << setprecision(2) << tt.GP; ; //Isvedimas
			cout << endl;
		}
		else {
			cout << setw(15) << tt.Vardas << setw(15) << tt.Pav << setw(25) << fixed << setprecision(2) << tt.Med; //Isvedimas
			cout << endl;
		}
	}
	Eiles.clear();
}
bool compareByName(const studentas &a, const studentas &b)
{
	if (a.Vardas != b.Vardas)
		return a.Vardas < b.Vardas;
	else
		return a.Pav < b.Pav;
}

/*#include <fstream>
#include <iomanip>

#include <iostream>

using namespace std;

struct studentas{
	string Vardas;
	string Pavarde;
	int *nd;
	int egz;

};

int main() {
	ifstream inFile;

	studentas* Eil = new studentas[2];
	for (int i = 0; i < 2; i++)
		Eil[i].nd = new int[5];
	

	inFile.open("C:/Users/rolan/Desktop/0.2v/Kursiokai.txt");
	
	for (int i = 0; i < 2; i++) {
		inFile >> Eil[i].Vardas >> Eil[i].Pavarde;
		for (int j = 0; j < 5; j++)
			inFile >> Eil[i].nd[j];
	
		inFile >> Eil[i].egz;
	}

	for (int i = 0; i < 2; i++) {
		cout<<Eil[i].Vardas <<" "<< Eil[i].Pavarde << " ";
		for (int j = 0; j < 5; j++)
			cout << Eil[i].nd[j] << " ";
		cout << Eil[i].egz << endl;
			
	}

}
*/
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

struct studentas {
	string Vardas;
	string Pav;
	int nd;
	int egz;
	float GP;
	float Med;
};


// VERSIJA SU VEKTORIAIS

int main()
{
	vector<studentas> Eiles;
	vector<int> ndf;// Vektorius
	ifstream inFile;
	studentas laik;
	int sk;
	int f;
	int l = 1;
	int t;
	int n = 0;
	string failas;


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

		inFile.open("C:/Users/rolan/Desktop/0.2v/Kursiokai.txt");
		n = 5;
		Eiles.reserve(2);
		ndf.reserve(10);
		if (inFile.is_open()) {
			while (inFile >> laik.Vardas >> laik.Pav)
			{
				laik.GP = 0;
				laik.Med = 0;
				for (int i = 0; i < 5; i++)
				{
					inFile >> laik.nd;

					laik.GP = laik.nd + laik.GP;
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
 // rezervuoju daugiau vietos nes kaip paskutini elementa pridedu egz
					ndf[ndf.size()-1] = laik.egz;
					cout << ndf.size() << endl;
					cout <<ndf[0]<<ndf[1]<<ndf[2]<<ndf[3] <<ndf[4] << endl;
					sort(ndf.begin(), ndf.end());

					
					if (ndf.size() % 2 != 0)
						laik.Med = (float)ndf[(ndf.size()) / 2];

					laik.Med = (float)(ndf[ndf.size() / 2] + ndf[(ndf.size() + 1) / 2]) / (float)2.0;
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

				nd[nd.size() - 1] = laik.egz;

				sort(nd.begin(), nd.end());

				if (nd.size() % 2 != 0)
					laik.Med = (float)nd[(nd.size()) / 2];

				laik.Med = (float)(nd[nd.size() / 2] + nd[(nd.size() + 1) / 2]) / (float)2.0;
			}
			Eiles.push_back(laik); //Viska idedu i vektoriu
		}
	}
	if (sk == 2) cout << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis Paz(vid.)" << endl;

	else cout << "Vardas" << setw(20) << "Pavarde" << setw(25) << "Galutinis Paz(med.)" << endl;

	for (auto tt : Eiles) {
		if (sk == 2)
		{
			cout << tt.Vardas << setw(15) << tt.Pav << setw(15) << fixed << setprecision(2) << tt.GP; ; //Isvedimas
			cout << endl;
		}
		else {
			cout << tt.Vardas << setw(15) << tt.Pav << setw(15) << fixed << setprecision(2) << tt.Med; //Isvedimas
			cout << endl;
		}
	}
	Eiles.clear();
}
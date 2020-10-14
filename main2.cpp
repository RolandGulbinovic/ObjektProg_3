#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <iomanip>
#include <fstream>
#include <chrono>

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
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::to_string;
using namespace std::chrono;

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
	vector<studentas> Eiles; // Vektorius
	studentas laik;
	vector<int> ndf;
	int sk;
	int l = 0;
	int t;
	int f;
	int s;
	int n = 0;
	

	cout << "norite atlikti failo greicio testavima?" << endl;
	cin >> f;
	if (f == 1) {
		ifstream file1;
		ofstream file;

		for (int i = 0; i < 5; i++) {
			cout << "kokio dydzio faila" << endl;
			cin >> s;

			auto start = steady_clock::now();
			string  ss = to_string(s);
			string fileName = "file" + ss;


			file.open(fileName + ".txt");
			for (int i = 0; i < s; i++) {
				file << "Vardas" + to_string(i) << " " << "Pavarde" +to_string(i);
				for (int i = 0; i < 15; i++)
					file << " " << rand() % 11;
				file << " " << rand() % 11;
				file << "\n";
			}

			auto stop = steady_clock::now();
			duration<double> elapsed_seconds = stop - start;
			cout << " Kurimas failo uztruko: " << elapsed_seconds.count() << endl;
			file.close();
			auto start1 = steady_clock::now();


			
			file1.open("C:/Users/rolan/Desktop/0.1.2/" + fileName + ".txt");

			if (file1.is_open()) {
				while (file1 >> laik.Vardas >> laik.Pav)
				{
					laik.GP = 0;
					laik.Med = 0;
					l++;
					Eiles.reserve(l);
					for (int i = 0; i < 15; i++)
					{
						n++;
						file1 >> laik.nd;
						laik.GP = laik.nd + laik.GP;
						ndf.reserve(n);
						ndf.push_back(laik.nd);
					}
					file1 >> laik.egz;
					if (n == 0)
						laik.GP = 0; //jei n=0 tai kad nedalintu is 0
					else {
						laik.GP = laik.GP / (float)n;
						laik.GP = 0.4 * laik.GP + 0.6 * (float)laik.egz; //GP skaiciavumas
					}
					ndf.clear();
					Eiles.push_back(laik);
				}
				auto stop1 = steady_clock::now();
				duration<double> elapsed_seconds1 = stop1 - start1;

				cout << "Nuskaitymas nuo " << fileName << " Uztruko: " << elapsed_seconds1.count() << endl;

				auto start2 = steady_clock::now();
				ofstream blogas, geras;
				blogas.open("blogi.txt");
				geras.open("geras.txt");
				for (auto tt : Eiles) {
					if (tt.GP < 5.0) {
						blogas << tt.Vardas << " " << tt.Pav << " " << fixed << setprecision(2) << tt.GP;
						blogas << '\n';
					}
					else if (tt.GP >= 5.0)
					{
						geras << setw(15) << tt.Vardas << setw(15) << tt.Pav << setw(25) << fixed << setprecision(2) << tt.GP;
						geras << '\n';
					}
				}
				auto stop2 = steady_clock::now();
				duration<double> elapsed_seconds2 = stop2 - start2;

				cout << "Duoemnu isvedimui i 2 failus uztruko " << elapsed_seconds2.count() << endl;
				blogas.close();
				geras.close();
			}
			file1.close();

		}
	}
	else {
		cout << "Norite gauti studentu mediana(1) ar Galutini pazymi(2)" << endl;

		while (!(cin >> sk) || (sk != 1 && sk != 2))
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "ERORR: Ivesti galima tik 1 arba 2" << endl;

		}


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
			studentas laik;
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
}
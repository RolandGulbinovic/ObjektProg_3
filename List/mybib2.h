#include "mybib.h"

void KurtiFaila(int, int);
void nuskaitymas(int, int, list<studentas>&, int);
void isvedimas(list<studentas>&, list<studentas>&, list<studentas>&, int);
void rusiavimas(list<studentas>&, list<studentas>&, list<studentas>&, int);

void KurtiFaila(int nd, int studentai) {

	string  ss = to_string(studentai);
	string fileName = "file" + ss;

	ofstream file;
	file.open(fileName + ".txt");
	for (int i = 0; i < studentai; i++) {
		file << "Vardas" + to_string(i) << " " << "Pavarde" + to_string(i);
		for (int i = 0; i < nd; i++)
			file << " " << rand() % 11;
		file << " " << rand() % 11;
		file << "\n";
	}
	file.close();

}


void nuskaitymas(int studentai, int sk, list<studentas>& Eiles, int n)
{
	auto start = high_resolution_clock::now();
	ifstream file;
	list<int> ndf;
	
	string  ss = to_string(studentai);
	string fileName = "file" + ss;

	file.open(fileName + ".txt");

	studentas laik;

	while (file >> laik.Vardas >> laik.Pav)
	{
		laik.GP = 0;
		laik.Med = 0;
		for (int i = 0; i < n; i++) {
			file >> laik.nd;
			laik.GP = laik.nd + laik.GP;
			ndf.push_back(laik.nd);
		}
		file >> laik.egz;

		if (sk == 2) {
			if (n == 0)
				laik.GP = 0; //jei n=0 tai kad nedalintu is 0
			else {
				laik.GP = laik.GP / (float)n;
				laik.GP = 0.4 * laik.GP + 0.6 * (float)laik.egz; //GP skaiciavumas
			}
		}
		else {
			laik.GP = 0;
			int c = ndf.size();
			ndf.push_front(laik.egz);

			ndf.sort();
			list<int>::iterator it = ndf.begin();
			std::advance(it, ((ndf.size() - 1) / 2));


			if (ndf.size() % 2 != 0)
				laik.GP = (float)*it;

			laik.GP = ((float)*it + (float)*it++) / (float)2.0;

		}

		Eiles.push_back(laik);
		ndf.clear();
	}

	duration<double> elapsed_seconds = high_resolution_clock::now() - start;
	cout << "Skaitymas nuo failo uztruko: " << elapsed_seconds.count() << "s." << endl;
}

void rusiavimas(list<studentas>& Eiles, list<studentas>& geri_paz, int studentai)
{
	auto start = high_resolution_clock::now();

	for (auto tt : Eiles)
	{
		if (tt.GP < 5)
			geri_paz.push_back(tt);
	}
	
	auto result = std::remove_if(Eiles.begin(), Eiles.end(), [](const studentas& p)
		{
			return p.GP < 5;
		});

	Eiles.erase(result, Eiles.end());

	
	duration<double> elapsed_seconds = high_resolution_clock::now() - start;
	cout << "Rusiavimas i 2 list'us uztruko: " << elapsed_seconds.count() << "s." << endl;
}

void isvedimas(list<studentas>& Eiles, list<studentas>& geri_paz, int studentai) {
	auto start = high_resolution_clock::now();
	ofstream blogas, geras;
	blogas.open("blogas_paz.txt");
	for (auto tt : geri_paz) { //isvedu du naujus vektorius i failus
		blogas << tt.Vardas << " " << tt.Pav << " " << fixed << setprecision(2) << tt.GP;
		blogas << '\n';
	}
	blogas.close();

	geras.open("geras_paz.txt");
	for (auto tt : Eiles) { //isvedu du naujus vektorius i failus
		geras << tt.Vardas << " " << tt.Pav << " " << fixed << setprecision(2) << tt.GP;
		geras << '\n';
	}
	geras.close();
	duration<double> elapsed_seconds = high_resolution_clock::now() - start;
	cout << "Isvedimas i failus uztruko: " << elapsed_seconds.count() << "s" << endl;
	
}
bool compareByGalut(const studentas& pirmas, const studentas& antras) {
	return pirmas.GP > antras.GP;
}

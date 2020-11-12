#include "mybib.h"
#include "mybib2.h"
int main()
{
	int k;
	int studentai;
	int sk = 0;
	list<studentas> Eiles, blogi_paz, geri_paz;

	cout << "Norite gauti studentu mediana(1) ar Galutini pazymi(2)" << endl;

	while (!(cin >> sk) || (sk != 1 && sk != 2))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "ERORR: Ivesti galima tik 1 arba 2" << endl;

	}


	for (int i = 0; i < 5; i++) {
		cout << "--------------------------" << endl;
		cout << "kiek norite eiluciu faile?" << endl;
		cin >> k;

		nuskaitymas(k, sk, Eiles, 5);
		rusiavimas(Eiles, geri_paz, blogi_paz, k);

		Eiles.clear();
		blogi_paz.clear();
		geri_paz.clear();
	}
	

}

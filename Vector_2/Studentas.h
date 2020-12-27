#pragma once
#include "Zmogus.h"

class Studentas : public Zmogus {
private:

	int nd;
	int egz;
	float GP;
	
public:
	Studentas() {};
	Studentas(string Vardas, string pav, int nd, int egz)
	{
		Vardas = Vardas;
		Pav = pav;
		egz = egz;
		nd = nd;
	}
	~Studentas() {}; //destructor

	Studentas(const Studentas& other) { //copy constructor
		Vardas = other.Vardas;
		Pav = other.Pav;
		nd = other.nd;
		egz = other.egz;
		GP = other.GP;
	}

	Studentas& operator=(const Studentas& p) //Copy assignment operator
	{
		(this->Vardas) = p.Vardas;
		(this->Pav) = p.Pav;
		(this->nd) = p.nd;
		(this->egz) = p.egz;
		(this->GP) = p.GP;
		return *this;
	}
	void setVardas(string a) {
		Vardas = a;
	}

	void setPav(string a) {
		Pav = a;
	}

	string getVardas() {
		return Vardas;
	}
	string getPav() {
		return Pav;
	}

	void setGp(double a) {
		GP = a;
	}
	float getGp() {
		return GP;
	}

	void setEgz(int a) {
		egz = a;
	}
	int getEgz() {
		return egz;
	}
	void KurtiFaila(int, int);
	void nuskaitymas(int, int, vector<Studentas>&, int);
	void rusiavimas(vector<Studentas>&, vector<Studentas>&, int);
	void isvedimas(vector<Studentas>&, vector<Studentas>&, int);
};
bool compareByGalut(Studentas&, Studentas&);

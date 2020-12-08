#pragma once
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
using std::istream;
using namespace std::chrono;

class Studentas {
private:
	string Vardas;
	string Pav;
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

	void setGp(double a) {
		GP = a;
	}
	float getGp() {
		return GP;
	}
	void setVardas(string a) {
		Vardas = a;
	}
	string getVardas() {
		return Vardas;
	}
	void setPavarde(string a) {
		Pav = a;
	}
	string getPav() {
		return Pav;
	}
	void setEgz(int a) {
		egz = a;
	}
	int getEgz() {
		return egz;
	}
	void KurtiFaila(int , int );
	void nuskaitymas(int, int, vector<Studentas>&, int);
	void rusiavimas(vector<Studentas>&, vector<Studentas>&, int);
	void isvedimas(vector<Studentas>&, vector<Studentas>&, int);
};
bool compareByGalut(Studentas&, Studentas&);

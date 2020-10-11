#pragma once
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

bool compareByName(const studentas&, const studentas&);
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
using namespace std::chrono;

struct studentas {
	string Vardas;
	string Pav;
	int nd;
	int egz;
	float GP;
	float Med;
};

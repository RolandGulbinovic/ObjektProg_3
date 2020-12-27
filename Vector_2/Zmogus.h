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

class Zmogus {
public:

    string Vardas;
    string Pav;

    virtual void setVardas(string a) = 0;

    virtual void setPav(string a) = 0;

    virtual string getVardas() = 0;
    virtual string getPav() = 0;

};

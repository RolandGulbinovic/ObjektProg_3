#include "mybib.h"

bool compareByName(const studentas& a, const studentas& b)
{
if (a.Vardas != b.Vardas)
return a.Vardas < b.Vardas;
else
return a.Pav < b.Pav;
}
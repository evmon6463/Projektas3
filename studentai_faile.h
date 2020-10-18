#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "studentas.h"
#include "random.h"
#include "studento_sukurimas.h"
#include "skaiciavimai.h"
#include "rusiavimas.h"
#include "studentai.h"
#include <chrono>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::to_string;
using std::ofstream;


vector<studentas> generuojami_studentai_faile(int failo_dydis, int pazymiu_kiekis);
void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output, int i, string pavadinimas);
void issurusiuoti_failai(int kelintas_failas, const vector<studentas> &studentai);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H

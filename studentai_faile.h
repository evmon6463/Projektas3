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

void issurusiuoti_failai_v(int kelintas_failas, const vector<Studentas> &studentai, Studentas studentas);
vector<Studentas> generuojami_studentai_faile(int failo_dydis, int pazymiu_kiekis, Studentas studentas);
void failu_uzpildymas(const vector<Studentas> &studentai, ofstream& output, int i, string pavadinimas);
void issurusiuoti_failai_vektorius(int kelintas_failas, vector<Studentas> &studentai, Studentas studentas);
void isvedimas_list(const std::list<Studentas> &studentai, ofstream& output);
void failu_uzpildymas_list(const std::list<Studentas> &studentai, ofstream& output, int i, string pavadinimas);
void issurusiuoti_failai(int kelintas_failas, const vector<Studentas> &studentai, Studentas studentas);
void issurusiuoti_failai_listai(int kelintas_failas, vector<Studentas> &studentai, Studentas studentas);
/*vector<studentas> generuojami_studentai_faile(int failo_dydis, int pazymiu_kiekis);
void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output, int i, string pavadinimas);
void issurusiuoti_failai(int kelintas_failas, const vector<studentas> &studentai);
void isvedimas_list(const std::list<studentas> &studentai, ofstream& output);
void failu_uzpildymas_list(const std::list<studentas> &studentai, ofstream& output, int i, string pavadinimas);
void grazina_studenta_list(ofstream &output, studentas st);
void issurusiuoti_failai_v(int kelintas_failas, const vector<studentas> &studentai);
void issurusiuoti_failai_vektorius(int kelintas_failas, vector<studentas> &studentai);
void issurusiuoti_failai_listai(int kelintas_failas, vector<studentas> &studentai);*/



#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H

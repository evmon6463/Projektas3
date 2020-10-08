//
// Created by eveli on 10/6/2020.
//

#ifndef PROJEKTAS_SU_VEKTORIAIS_NUSKAITYTI_DUOMENYS_H
#define PROJEKTAS_SU_VEKTORIAIS_NUSKAITYTI_DUOMENYS_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> isskaidyk_String(const string &str);
void prideti_prie_vektoriaus(vector<string> &zodziai, const string &word);
bool yra_skaicius(vector<string> studento_irasas, int ilgis);
bool ar_atitinka_intervala(vector<string> studento_irasas, int ilgis);

#endif //PROJEKTAS_SU_VEKTORIAIS_NUSKAITYTI_DUOMENYS_H

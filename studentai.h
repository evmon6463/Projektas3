//
// Created by eveli on 10/6/2020.
//

#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H

#include <fstream>
#include <sstream>
#include "random.h"
#include "klausimai.h"
#include "studentas.h"
#include "skaiciavimai.h"
#include "pazymiai.h"
#include "studento_sukurimas.h"
#include "rusiavimas.h"
#include "isvedimas.h"
#include "nuskaityti_duomenys.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

vector<studentas> ivesti_studentai();
void nuskaityto_studento_duomenys(std::ifstream &myfile, string line);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H

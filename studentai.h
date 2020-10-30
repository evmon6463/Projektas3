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
#pragma once
#include <chrono>
#include <list>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

vector<studentas> ivesti_studentai();
void nuskaityti_studentai(std::ifstream &myfile, string line);
void studentai_is_sukurto_failo(std::ifstream &myfile, string line);
std::list<struct studentas> studentai_is_sukurto_failo_list(std::ifstream &myfile, string line);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H

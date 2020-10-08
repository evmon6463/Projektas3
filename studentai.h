//
// Created by eveli on 10/6/2020.
//

#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H

#include "studentas.h"
#include <string>

vector<studentas> ivesti_studentai();
void nuskaityto_studento_duomenys(std::ifstream &myfile, string line);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_H

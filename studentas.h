//
// Created by eveli on 10/6/2020.
//

#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct studentas {
    string Vardas;
    string Pavarde;
    int egzamino_rezultatas;
    float galutinis_rezultatas = 0;
    vector<int> nd_rezultatai;
    float mediana;
};

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H

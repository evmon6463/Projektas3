#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTO_SUKURIMAS_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTO_SUKURIMAS_H

#include "studentas.h"

studentas sukurti_nuskaityta_studenta(vector<string> studento_irasas, int ilgis);
vector<studentas> sukurti_ivesta_studenta(vector<studentas> studentai, struct studentas students);
studentas sukurti_studenta_is_failo(vector<string> studento_irasas);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTO_SUKURIMAS_H

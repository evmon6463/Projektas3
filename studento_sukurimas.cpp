#include "studento_sukurimas.h"

studentas sukurti_nuskaityta_studenta(vector<string> studento_irasas, int ilgis) {
    studentas studentas;
    studentas.Vardas = studento_irasas.at(0);
    studentas.Pavarde = studento_irasas.at(1);
    studentas.nd_rezultatai.reserve(100);
    for (int i = 2; i < ilgis - 1; i++) {
        studentas.nd_rezultatai.push_back(stoi(studento_irasas.at(i)));
    }
    studentas.egzamino_rezultatas = stoi(studento_irasas.at(ilgis - 1));
    return studentas;
}

studentas sukurti_studenta(vector<string> studento_irasas, int ilgis){
    studentas studentas;
    studentas.Vardas = studento_irasas.at(0);
    studentas.Pavarde = studento_irasas.at(1);
    //studentas.galutinis_rezultatas = studento_irasas.at(2);
    //studentas.mediana = studento_irasas.at(ilgis);
    return studentas;
}

vector<studentas> sukurti_ivesta_studenta(vector<studentas> studentai, struct studentas students) {
    studentai.push_back(students);
    return studentai;
}
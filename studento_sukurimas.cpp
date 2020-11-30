#include "studento_sukurimas.h"

Studentas sukurti_nuskaityta_studenta(vector<string> studento_irasas, int ilgis, Studentas studentas) {
    vector<int> pazymiai;
    studentas.setVardas(studento_irasas.at(0));
    studentas.setPavarde(studento_irasas.at(1));
    for (int i = 2; i < ilgis - 1; i++) {
        pazymiai.push_back(stoi(studento_irasas.at(i)));
    }
    studentas.setNdRezultatus(pazymiai);
    studentas.setEgzaminoRezultata(stoi(studento_irasas.at(ilgis - 1)));
    return studentas;
}

Studentas sukurti_studenta_is_failo(vector<string> studento_irasas, Studentas studentas){
    studentas.setVardas(studento_irasas.at(0));
    studentas.setPavarde(studento_irasas.at(1));
    studentas.setGalutinisRezultatas(stof(studento_irasas.at(2)));
    studentas.setMediana(stof(studento_irasas.at(3)));
    studentas.getNdRezultatus().clear();
    studentas.setEgzaminoRezultata(0);
    return studentas;
}
#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    double egzamino_rezultatai;
    std::vector<int> nd_rezultatai;
    float galutinis_rezultatas = 0;
    float mediana;
public:
    void ivesti_studenta(Studentas studentas);
    float galutinisRezultatas(Studentas studentas);
    float medianosRezultatas(Studentas studentas);

    void nuskaityto_studento_duomenys(std::ifstream &myfile, string line, Studentas studentas);
    void rusiavimas_pagal_galutini_pazymi(vector<Studentas> &studentai);

    string getVardas(){
        return vardas_;
    }
    void setVardas(string vardas) {
        vardas_ = vardas;
    }
    string getPavarde(){
        return pavarde_;
    }
    void setPavarde(string pavarde) {
        pavarde_ = pavarde;
    }
    double getEgzaminoRezultata(){
        return egzamino_rezultatai;
    }
    void setEgzaminoRezultata(double egzaminas) {
        egzamino_rezultatai = egzaminas;
    }
    vector<int> getNdRezultatus(){
        return nd_rezultatai;
    }
    void setNdRezultatus(vector<int> nd) {
        nd_rezultatai = nd;
    }
    float getGalutinisRezultatas(){
        return galutinis_rezultatas;
    }
    void setGalutinisRezultatas(float  galutinis) {
        galutinis_rezultatas = galutinis;
    }
    float getMediana(){
        return mediana;
    }
    void setMediana(float median) {
        mediana = median;
    }

    Studentas();
};
#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H

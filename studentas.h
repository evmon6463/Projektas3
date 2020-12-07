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
    Studentas();

     Studentas(string vardas, string pavarde, float galutinis_rez, float median, std::vector<int> nd, double egzaminas) //copy constructor
    {
        vardas_ = vardas;
        pavarde_ = pavarde;
        galutinis_rezultatas = galutinis_rez;
        mediana = median;
        nd_rezultatai = nd;
        egzamino_rezultatai = egzaminas;

    }
    void string_rusiavimas(vector<Studentas> &studentai);
    void ivesti_studenta(Studentas studentas);
    float galutinisRezultatas(Studentas studentas);
    float medianosRezultatas(Studentas studentas);

    void nuskaityto_studento_duomenys(std::ifstream &myfile, string line, Studentas studentas);
    void rusiavimas_pagal_galutini_pazymi(vector<Studentas> &studentai);

    string getVardas() const {
        return vardas_;
    }
    void setVardas(string vardas) {
        vardas_ = vardas;
    }
    string getPavarde() const {
        return pavarde_;
    }
    void setPavarde(string pavarde) {
        pavarde_ = pavarde;
    }
    double getEgzaminoRezultata() const {
        return egzamino_rezultatai;
    }
    void setEgzaminoRezultata(double egzaminas) {
        egzamino_rezultatai = egzaminas;
    }
    vector<int> getNdRezultatus() const {
        return nd_rezultatai;
    }
    void setNdRezultatus(vector<int> nd) {
        nd_rezultatai = nd;
    }
    float getGalutinisRezultatas() const {
        return galutinis_rezultatas;
    }
    void setGalutinisRezultatas(float  galutinis) {
        galutinis_rezultatas = galutinis;
    }
    float getMediana() const {
        return mediana;
    }
    void setMediana(float median) {
        mediana = median;
    }
    ~Studentas(){ }//destruktorius

    Studentas(const Studentas &stu):Studentas(stu.vardas_, stu.pavarde_,
                                              stu.galutinis_rezultatas, stu.mediana, stu.nd_rezultatai, stu.egzamino_rezultatai){}//copy konstruktorius

    friend std::ostream& operator<<(std::ostream &output, const Studentas &stu); //copy priskyrimas
};

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAS_H

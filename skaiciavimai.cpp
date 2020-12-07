#include "skaiciavimai.h"

float Studentas::galutinisRezultatas(Studentas studentas) {
    float galutinis_rezultatas = 0;
    float suma = 0;
    float vidurkis = 0;
    int nd_skaicius = studentas.getNdRezultatus().size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + studentas.getNdRezultatus()[i];
    }
    vidurkis = suma / nd_skaicius;
    galutinis_rezultatas = vidurkis * (float) 0.4 + studentas.getEgzaminoRezultata() * (float) 0.6;
    return galutinis_rezultatas;
}

float Studentas::medianosRezultatas(Studentas studentas) {
    float mediana = 0;
    int size = this->nd_rezultatai.size();
    sort(this->nd_rezultatai.begin(), this->nd_rezultatai.end());
    if (size % 2 == 0) {
        mediana = ((this->nd_rezultatai[size / 2 - 1] + this->nd_rezultatai[size / 2]) / 2.0);
        return mediana;
    } else {
        mediana = this->nd_rezultatai[size / 2];
        return mediana;
    }
}
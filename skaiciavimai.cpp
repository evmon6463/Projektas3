#include "skaiciavimai.h"

float galutinisRezultatas(studentas st) {
    float galutinis_rezultatas = 0;
    float suma = 0;
    float vidurkis = 0;
    int nd_skaicius = st.nd_rezultatai.size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + st.nd_rezultatai[i];
    }
    vidurkis = suma / nd_skaicius;
    galutinis_rezultatas = vidurkis * (float) 0.4 + st.egzamino_rezultatas * (float) 0.6;
    return galutinis_rezultatas;
}

float mediana(studentas st) {
    float mediana = 0;
    int size = st.nd_rezultatai.size();
    sort(st.nd_rezultatai.begin(), st.nd_rezultatai.end());
    int s1 = (size/2)-1;
    int s2 = (size/2);
    if (size % 2 == 0) {
        float m1 = st.nd_rezultatai[s1];
        float m2 = st.nd_rezultatai[s2];
        mediana = ( m1+ m2) / 2;
    } else {
        mediana = st.nd_rezultatai[s2];
    }
    return mediana;

}

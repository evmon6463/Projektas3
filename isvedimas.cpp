#include "isvedimas.h"

void informacijos_isvedimas(vector<Studentas> studentai) {
    cout.width(20);
    cout << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis vidurkis"
         << setw(20) << "Galutine mediana" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        st.setGalutinisRezultatas(st.galutinisRezultatas(st));
        st.setMediana(st.medianosRezultatas(st));
        cout.width(20);
        cout << st.getVardas() << std::setw(20) << st.getPavarde() << std::setw(20) << std::setprecision(2) << std::fixed
             << std::left << std::setw(20) <<
             st.getGalutinisRezultatas() << std::setw(20) << std::setprecision(2)
             << std::fixed
             << st.getMediana()
             << endl;
    }
}


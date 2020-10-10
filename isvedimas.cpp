#include "isvedimas.h"

void informacijos_isvedimas(const vector<studentas> &studentai) {
    cout.width(20);
    cout << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis vidurkis"
         << setw(20) << "Galutine mediana" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        st.galutinis_rezultatas = galutinisRezultatas(st);
        st.mediana = mediana(st);
        cout.width(20);
        cout << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
             << std::left << std::setw(20) <<
             st.galutinis_rezultatas << std::setw(20) << std::setprecision(2)
             << std::fixed
             << st.mediana << endl;
    }
}


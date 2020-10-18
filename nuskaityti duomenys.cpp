#include "nuskaityti_duomenys.h"
vector<string> isskaidyk_String(const string &str) {
    vector<string> zodziai;
    string zodis;
    for (auto x : str) {
        if (x == ' ') {
            prideti_prie_vektoriaus(zodziai, zodis);
            zodis = "";
        } else {
            zodis += x;
        }
    }
    prideti_prie_vektoriaus(zodziai, zodis);
    return zodziai;
}

void prideti_prie_vektoriaus(vector<string> &zodziai, const string &word) {
    if (!word.empty()) {
        zodziai.reserve(100);
        zodziai.push_back(word);
    }
}

bool yra_skaicius(vector<string> studento_irasas, int ilgis) {
    for (int i = 2; i < ilgis; i++) {
        if (!studento_irasas.at(i).find_first_not_of("0123456789")) {
            return true;
        }
    }
    return false;
}

bool ar_atitinka_intervala(vector<string> studento_irasas, int ilgis) {
    for (int i = 2; i < ilgis; i++) {
        if (stoi(studento_irasas.at(i)) < 0 || stoi(studento_irasas.at(i)) > 10)
            return true;
    }
    return false;
}

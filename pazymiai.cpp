#include "pazymiai.h"

int patikrink_egzamino_pazymi(string skaicius_string) {
    while (true) {
        try {
            int ivestas_skaicius = stoi(skaicius_string);
            if (ivestas_skaicius > 0 & ivestas_skaicius <= 10) {
                return ivestas_skaicius;
            } else {
                cout << "Klaida! Skaicius nera tarp 1 ir 10. Pabandykite dar karta!" << endl;
                cin >> skaicius_string;
                continue;
            }
        }
        catch (invalid_argument &e) {
            cout << "Klaida! Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
            cin >> skaicius_string;
            continue;
        }
    }
}

bool konvertuok_pazymius(string token) {
    bool tesk = false;
    int skaicius;
    try {
        skaicius = stoi(token);
        if (skaicius <= 0 | skaicius > 10) {
            cout << "Klaida pazymys  turi buti nuo 0 iki 10" << endl;
            tesk = true;
        }
    } catch (invalid_argument &e) {
        cout << "Klaida. Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
        tesk = true;
    }
    return tesk;
}

vector<int> pazymiu_nuskaitymas() {
    vector<int> pazymiai;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string pazymiai_string;
    while (true) {
        int kiek = 0;
        bool tesk = true;
        cout << "Iveskite studento namu darbu rezultatus:" << endl;
        getline(cin >> std::ws, pazymiai_string);
        if (pazymiai_string.size() == 1) {
            cout << "Turi buti ivestas bent du pazymiai" << endl;
        } else {
            while ((pos = pazymiai_string.find(delimiter)) != string::npos) {
                token = pazymiai_string.substr(0, pos);
                tesk = konvertuok_pazymius(token);
                if (tesk) {
                    break;
                }
                pazymiai.push_back(stoi(token));
                pazymiai_string.erase(0, pos + delimiter.length());
                kiek++;
            }
            if (!tesk) {
                pazymiai.push_back(stoi(token));
                if (!konvertuok_pazymius(token)) {
                    return pazymiai;
                }
            }
        }
    }
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;
using std::invalid_argument;
using std::getline;
using std::to_string;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;

struct studentas {
    string Vardas;
    string Pavarde;
    int egzamino_rezultatas;
    float galutinis_rezultatas = 0;
    vector<int> nd_rezultatai;
    float mediana;
};

int random() {
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}

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

vector<int> pazymiu_nuskaitymas(studentas *students, int i) {
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
                students[i].nd_rezultatai.push_back(stoi(token));
                pazymiai_string.erase(0, pos + delimiter.length());
                kiek++;
            }
            if (!tesk) {
                if (!konvertuok_pazymius(token)) {
                    return pazymiai;
                }
            }
        }
    }
}

float galutinisRezultatas(vector<int> nd_rezultatas, string skaicius_string) {
    float suma = 0;
    int nd_skaicius = nd_rezultatas.size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + nd_rezultatas.at(i);
    }
    float vidurkis = suma / nd_skaicius;
    int egzaminas = patikrink_egzamino_pazymi(skaicius_string);
    float galutinis_pazymys = vidurkis * (float) 0.4 +
                              egzaminas * (float) 0.6;
    return galutinis_pazymys;
}

float mediana(vector<int> pazymiai) {
    int size = pazymiai.size();
    float mediana;
    sort(pazymiai.begin(), pazymiai.end());
    if (size % 2 == 0) {
        mediana = ((pazymiai.at(size / 2 - 1) + pazymiai.at((size / 2))) / 2.0);
        return mediana;
    } else {
        mediana = pazymiai.at(size / 2);
        return mediana;
    }
}

string generavimo_klausimas() {
    string klausimas;
    cout << "Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai?" << endl
         << "(Iveskite taip arba ne)";
    cin >> klausimas;
    return klausimas;
}

int studento_ivedimo_klausimas() {
    string atsakymas;
    cout << "Ar ivesti nauja studenta?Iveskite taip arba ne" << endl;
    while (true) {
        cin >> atsakymas;
        if (atsakymas == "Taip" || atsakymas == "taip" || atsakymas == "TAIP")
            return 1;
        else if (atsakymas == "ne" || atsakymas == "Ne" || atsakymas == "NE")
            return 0;
        else {
            cout << "Klaida. Iveskite taip arba ne." << endl;
            continue;
        }
    }
}

int sugeneruotu_pazymiu_kiekis() {
    string kiek;
    cout << "Kiek pazymiu sugeneruoti?";
    while (true) {
        cin >> kiek;
        try {
            if (!kiek.find_first_not_of(" 0123456789")) {
                cout << "Klaida. Ivedete ne skaicius" << endl;
                continue;
            } else {
                int skaicius = stoi(kiek);
                return skaicius;
            }
        } catch (invalid_argument &e) {
            cout << "Klaida. Ivedete ne skaicius. Pabandykite dar karta!" << endl;
        }
    }
}

vector<int> generuojami_skaiciai() {
    vector<int> nd_rezultatai;
    int kiek;
    while (true) {
        kiek = sugeneruotu_pazymiu_kiekis();
        if (kiek > 0 & kiek < 100) {
            srand(time(NULL));
            for (int i = 0; i < kiek; i++) {
                nd_rezultatai.push_back(random());
            }
            srand(time(NULL));
            return nd_rezultatai;
        } else {
            cout << "Skaicius turi buti didesnis uz 0 ir mazesnis nei 100" << endl;
        }
    }
}
studentas sukurti_studenta(studentas *students, int kiek, int nd_kiek) {
    studentas studentas;
    studentas.Vardas = students[kiek].Vardas;
    studentas.Pavarde = students[kiek].Pavarde;
    return studentas;
}
int studento_duomenys(studentas *students, vector<int> pazymiai, string &skaicius_string, int i) {
    vector<studentas> studentai;
    while (studento_ivedimo_klausimas() == 1) {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> students[i].Vardas >> students[i].Pavarde;
        while (true) {
            string klausimas = generavimo_klausimas();
            if (klausimas == "ne" || klausimas == "Ne" || klausimas == "NE") {
                string egzaminas;
                pazymiai = pazymiu_nuskaitymas(students, i);

                cout << "Iveskite egzamino rezultata: " << endl;
                cin >> skaicius_string;
                students[i].galutinis_rezultatas = galutinisRezultatas(pazymiai, skaicius_string);
                students[i].mediana = mediana(pazymiai);
                i++;
                break;
            } else if (klausimas == "taip" || klausimas == "Taip" || klausimas == "TAIP") {
                pazymiai = generuojami_skaiciai();
                students[i].egzamino_rezultatas = random();
                students[i].galutinis_rezultatas = galutinisRezultatas(pazymiai,
                                                                       to_string(students[i].egzamino_rezultatas));
                students[i].mediana = mediana(pazymiai);
                i++;
                break;
            } else {
                cout << "Klaida. " << endl;
                continue;
            }
        }
        studentai.push_back(sukurti_studenta(students, i, 8));
    }
    return i;
}



void informacijos_isvedimas(studentas *students, int i) {
    cout.width(20);
    cout << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis vidurkis"
         << setw(20) << "Galutine mediana" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    ofstream myfile;
    myfile.open("example.txt");
    myfile.width(20);
    myfile << left << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis vidurkis"
           << setw(20) << "Galutine mediana" << endl;
    myfile << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (int j = 0; j < i; j++) {
        cout.width(20);
        cout << students[j].Vardas << setw(20) << students[j].Pavarde
             << setw(20) << setprecision(2) << fixed
             << left << setw(20) << students[j].galutinis_rezultatas << setw(20)
             << setprecision(2) << fixed
             << students[j].mediana
             << endl;
        myfile.width(20);
        myfile << students[j].Vardas << setw(20) << students[j].Pavarde
               << setw(20) << setprecision(2) << fixed
               << left << setw(20) << students[j].galutinis_rezultatas << setw(20)
               << setprecision(2) << fixed
               << students[j].mediana
               << endl;
    }
    myfile.close();
}

int main() {
    studentas students[5];
    vector<studentas> studentai;
    vector<int> pazymiai;
    pazymiai.reserve(100);
    string skaicius_string;
    int i = 0;

    i = studento_duomenys(students, pazymiai, skaicius_string, i);

    informacijos_isvedimas(students, i);

}
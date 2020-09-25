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

struct studentas {
    string Vardas;
    string Pavarde;
    int egzamino_rezultatas;
    float galutinis_rezultatas = 0;
    string nd_rezultatai;
    float mediana;
};
int random() {
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}
int nuskaityti_pazymi(string skaicius_string) {
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
        catch (std::invalid_argument &e) {
            cout << "Klaida! Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
            cin >> skaicius_string;
            continue;
        }
    }
}
int pradinis_klausimas() {
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
string klausimai() {
    string klausimas;
    cout << "Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai?" << endl
         << "(Iveskite taip arba ne)";
    cin >> klausimas;
    return klausimas;
}
float galutinisRezultatas(vector<int> nd_rezultatas, string skaicius_string) {
    float suma = 0;
    int nd_skaicius = nd_rezultatas.size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + nd_rezultatas.at(i);
    }
    float vidurkis = suma / nd_skaicius;
    int egzaminas = nuskaityti_pazymi(skaicius_string);
    float galutinis_pazymys = vidurkis * (float) 0.4 +
                        egzaminas * (float) 0.6;
    return galutinis_pazymys;
}
float mediana(vector<int> pazymiai){
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
bool konvertuot(string token) {
    bool tesk = false;
    int skaicius;
    try {
        skaicius = stoi(token);
        if (skaicius <= 0 | skaicius > 10) {
            cout << "Klaida pazymys  turi buti nuo 0 iki 10" << endl;
            tesk = true;
        }
    } catch (std::invalid_argument &e) {
        cout << "Klaida. Jus ivedete ne skaiciu. Pabandykite dar karta!" << endl;
        tesk = true;
    }

    return tesk;
}

vector<int> eilutes_nuskaitymas() {
    vector<int> pazymiai;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string pazymiai_string;
    while (true) {
        int kiek = 0;
        bool tesk = true;
        cout << "Iveskite studento namu darbu rezultatus:" << endl;
        std::getline(std::cin >> std::ws, pazymiai_string);
        while ((pos = pazymiai_string.find(delimiter)) != std::string::npos) {
            token = pazymiai_string.substr(0, pos);
            tesk = konvertuot(token);

            if (tesk) {
                break;
            }
            pazymiai.push_back(stoi(token));
            pazymiai_string.erase(0, pos + delimiter.length());
            kiek++;
        }

        if (!tesk) {
            if (!konvertuot(token)) {
                return pazymiai;
            }
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
        } catch (std::invalid_argument &e) {
            cout << "Klaida. Ivedete ne skaicius. Pabandykite dar karta!" << endl;
        }

    }
}

vector<int> generuojamas_kiekis() {
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


int studento_duomenys(studentas *students, vector<int> pazymiai, string &skaicius_string, int i) {
    while (pradinis_klausimas() == 1) {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> students[i].Vardas >> students[i].Pavarde;
        while (true) {
            string klausimas = klausimai();
            if (klausimas == "ne" || klausimas == "Ne" || klausimas == "NE") {
                string egzaminas;
                pazymiai = eilutes_nuskaitymas();
                cout << "Iveskite egzamino rezultata: " << endl;
                cin >> skaicius_string;
                students[i].galutinis_rezultatas = galutinisRezultatas(pazymiai, skaicius_string);
                students[i].mediana = mediana(pazymiai);
                i++;
                break;
            } else if (klausimas == "taip" || klausimas == "Taip" || klausimas == "TAIP") {
                pazymiai = generuojamas_kiekis();
                students[i].egzamino_rezultatas = random();
                students[i].galutinis_rezultatas = galutinisRezultatas(pazymiai,
                                                                      std::to_string(students[i].egzamino_rezultatas));
                students[i].mediana = mediana(pazymiai);
                i++;
                break;
            } else {
                cout << "Klaida. " << endl;
                continue;
            }
        }
    }
    return i;
}

void grazina(studentas students[], int i) {
    cout.width(20);
    cout << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
         << std::setw(20) << "Galutine mediana" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    ofstream myfile;
    myfile.open("example.txt");
    myfile.width(20);
    myfile << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    myfile << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (int j = 0; j < i; j++) {
        cout.width(20);
        cout << students[j].Vardas << std::setw(20) << students[j].Pavarde
             << std::setw(20) << std::setprecision(2) << std::fixed
             << std::left << std::setw(20) << students[j].galutinis_rezultatas << std::setw(20)
             << std::setprecision(2) << std::fixed
             << students[j].mediana
             << endl;
        myfile.width(20);
        myfile << students[j].Vardas << std::setw(20) << students[j].Pavarde
               << std::setw(20) << std::setprecision(2) << std::fixed
               << std::left << std::setw(20) << students[j].galutinis_rezultatas << std::setw(20)
               << std::setprecision(2) << std::fixed
               << students[j].mediana
               << endl;
    }
    myfile.close();
}
int main() {
    studentas students[5];
    vector<int> pazymiai;
    pazymiai.reserve(100);
    string skaicius_string;
    int i = 0;
    i = studento_duomenys(students, pazymiai, skaicius_string, i);
    grazina(students, i);
}
        /*std::getline(cin, studentas->nd_rezultatai);
        std::istringstream is(studentas->nd_rezultatai);
        vector<int> pazymiai((std::istream_iterator<int>(is)), std::istream_iterator<int>());
        cout << "Iveskite egzamino rezultata: " << endl;
        cin >> studentas[j].egzamino_rezultatas;
        galutinisRezultatas(j, studentas, pazymiai);
        mediana(pazymiai, studentas, j);*/




/*nd_skaicius = pazymiai.size();
for (int i = 0; i < nd_skaicius; i++) {
    suma = suma + pazymiai[i];
}
vidurkis = suma / nd_skaicius;
cout << "Iveskite egzamino rezultata: " << endl;
cin >> studentas[j].egzamino_rezultatas;
studentas[j].galutinis_rezultatas = vidurkis * (float) 0.4 +
                                    studentas[j].egzamino_rezultatas * (float) 0.6;
int size = pazymiai.size();

sort(pazymiai.begin(), pazymiai.end());
if (size % 2 == 0) {
    studentas[j].mediana = ((pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2.0);
} else {
    studentas[j].mediana = pazymiai[size / 2];
}

}
cout << "Vardas:\t" << "Pavarde:\t" << "Galutinis vidurkis/Galutine mediana:\t" << endl;
cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
for (int g = 0; g < 2; g++) {
cout << studentas[g].Vardas << "\t" << studentas[g].Pavarde << "\t\t" << std::setprecision(2) << std::fixed
     << studentas[g].galutinis_rezultatas << "\t\t" << std::setprecision(2) << std::fixed
     << studentas[g].mediana
     << endl;
}

ofstream myfile;
myfile.open("example.txt");
myfile << "Vardas:\t" << "Pavarde:\t" << "Galutinis rezultatas/Galutine mediana:\t" << endl;
myfile << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
for (int g = 0; g < 2; g++)
myfile << studentas[g].Vardas << "\t" << studentas[g].Pavarde << "\t\t" << std::setprecision(2) << std::fixed
       << studentas[g].galutinis_rezultatas << "\t\t" << std::setprecision(2) << std::fixed
       << studentas[g].mediana
       << endl;
myfile.close();
}*/
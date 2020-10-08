#include <fstream>
#include <sstream>
#include "random.h"
#include "klausimai.h"
#include "studentas.h"
#include "skaiciavimai.h"
#include "pazymiai.h"
#include "studento_sukurimas.h"
#include "rusiavimas.h"
#include "isvedimas.h"
#include "nuskaityti_duomenys.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

vector<studentas> ivesti_studentai() {
    vector<studentas> studentai;
    studentai.reserve(1000000);
    studentas student;
    string skaicius_string;
    while (ivesti_nauja_studenta() == 1) {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> student.Vardas >> student.Pavarde;
        while (true) {
            string klausimas = ar_generuoti();
            if (klausimas == "ne" || klausimas == "Ne" || klausimas == "NE") {
                string egzaminas;
                student.nd_rezultatai = pazymiu_nuskaitymas();
                cout << "Iveskite egzamino rezultata: " << endl;
                cin >> skaicius_string;
                student.egzamino_rezultatas = patikrink_egzamino_pazymi(skaicius_string);
                student.galutinis_rezultatas = galutinisRezultatas(student);
                student.mediana = mediana(student);
                studentai = sukurti_ivesta_studenta(studentai, student);
                break;
            } else if (klausimas == "taip" || klausimas == "Taip" || klausimas == "TAIP") {
                student.nd_rezultatai = generuojami_skaiciai();
                student.egzamino_rezultatas = random();
                student.galutinis_rezultatas = galutinisRezultatas(student);
                student.mediana = mediana(student);
                studentai = sukurti_ivesta_studenta(studentai, student);
                break;
            } else {
                cout << "Klaida. " << endl;
                continue;
            }
        }
    }
    return studentai;
}



void nuskaityto_studento_duomenys(std::ifstream &myfile, string line) {
    vector<studentas> studentai;
    vector<string> nuskaityta_eilute;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::stringstream lineStream(line);
            string eilute;
            std::getline(lineStream, eilute);
            nuskaityta_eilute = isskaidyk_String(eilute);
            int ilgis = nuskaityta_eilute.size();
            if (yra_skaicius(nuskaityta_eilute, ilgis) || ar_atitinka_intervala(nuskaityta_eilute, ilgis)) {
                cout << "Klaidingai ivesti pazymiai";
                exit(0);
            }
            studentai.push_back(sukurti_nuskaityta_studenta(nuskaityta_eilute, ilgis));
        }
        rusiavimas(studentai);

        informacijos_isvedimas(studentai);
    } else cout << "Unable to open file";
    myfile.close();
}
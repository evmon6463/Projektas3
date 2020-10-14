#include "studentai.h"

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
    std::chrono::duration<double> diff;
    auto start = std::chrono::high_resolution_clock::now();
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
            auto end = std::chrono::high_resolution_clock::now();
            diff = end-start;
            studentai.push_back(sukurti_nuskaityta_studenta(nuskaityta_eilute, ilgis));
        }
        string_rusiavimas(studentai);
        informacijos_isvedimas(studentai);

        std::cout << "Failu nuskaitymas uztrunka "<< diff.count() <<endl;

    } else cout << "Unable to open file";
    myfile.close();
}

void studentai_is_sukurto_failo(std::ifstream &myfile, string line) {
    vector<studentas> studentai;
    vector<string> nuskaityta_eilute;
    if (myfile.is_open()) {
        std::stringstream lineStream(line);
        string eilute;
        std::getline(lineStream, eilute);
        while (getline(myfile, line)) {
            std::stringstream lineStream(line);
            std::getline(lineStream, eilute);
            nuskaityta_eilute = isskaidyk_String(eilute);
            int ilgis = nuskaityta_eilute.size();
            studentai.push_back(sukurti_studenta(nuskaityta_eilute, ilgis));
        }
    } else {cout<< "Unable to open file";}
    myfile.close();
}
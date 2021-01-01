
#include "studentai.h"

void Studentas::ivesti_studenta(Studentas studentas) {
    vector<Studentas> studentai;
    studentai.reserve(100);
    string x;
    string y;
    string skaicius_string;
    while (ar_ivesti_nauja_studenta() == 1) {
        cout << "Iveskite varda: " << endl;
        cin >> x;
        cout << "Iveskite pavarde: " << endl;
        cin >> y;
        studentas.setVardas(x);
        studentas.setPavarde(y);
        while (true) {
            string klausimas = ar_generuoti();
            if (klausimas == "ne" || klausimas == "Ne" || klausimas == "NE") {
                string egzaminas;
                studentas.setNdRezultatus(pazymiu_nuskaitymas());
                cout << "Iveskite egzamino rezultata: " << endl;
                cin >> skaicius_string;
                studentas.setEgzaminoRezultata(patikrink_egzamino_pazymi(skaicius_string));
                studentas.setGalutinisRezultatas(galutinisRezultatas(studentas));
                studentas.setMediana(medianosRezultatas(studentas));
                studentai.push_back(studentas);
                break;
            }
            else if (klausimas == "taip" || klausimas == "Taip" || klausimas == "TAIP") {
                studentas.setNdRezultatus(generuojami_skaiciai());
                studentas.setEgzaminoRezultata(random());
                studentas.setGalutinisRezultatas(galutinisRezultatas(studentas));
                studentas.setMediana(medianosRezultatas(studentas));
                studentai.push_back(studentas);
                break;
            } else {
                cout << "Klaida. " << endl;
                continue;
            }
        }
    }
    informacijos_isvedimas(studentai);
}



void Studentas::nuskaityto_studento_duomenys(std::ifstream &myfile, string line, Studentas studentas) {
    vector<Studentas> studentai;
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
            studentai.push_back(sukurti_nuskaityta_studenta(nuskaityta_eilute, ilgis, studentas));
        }
        string_rusiavimas(studentai);
        informacijos_isvedimas(studentai);
    } else cout << "Unable to open file";
    myfile.close();
}

void studentai_is_sukurto_failo(std::ifstream &myfile, string line, Studentas studentas) {
    vector<Studentas> studentai;
    studentai.reserve(1000010);
    studentai.clear();
    vector<string> nuskaityta_eilute;
    nuskaityta_eilute.reserve(1000000);
    nuskaityta_eilute.clear();
    if (myfile.is_open()) {
        std::stringstream lineStream(line);
        string eilute;
        while (getline(myfile, line)) {
            std::stringstream lineStream(line);
            std::getline(lineStream, eilute);
            nuskaityta_eilute = isskaidyk_String(eilute);
            studentai.push_back(sukurti_studenta_is_failo(nuskaityta_eilute, studentas));
        }
    } else {std::cout<< "Unable to open file";}
    myfile.close();
}

std::list<Studentas> studentai_is_sukurto_failo_list(std::ifstream &myfile, string line, Studentas studentas) {
    std::list<Studentas> studentai;
    vector<string> nuskaityta_eilute;
    nuskaityta_eilute.reserve(1000000);
    nuskaityta_eilute.clear();

    if (myfile.is_open()) {
        std::stringstream lineStream(line);
        string eilute;
        while (getline(myfile, line)) {
            std::stringstream lineStream(line);
            std::getline(lineStream, eilute);
            nuskaityta_eilute = isskaidyk_String(eilute);
            studentai.push_back(sukurti_studenta_is_failo(nuskaityta_eilute, studentas));
        }
        return studentai;
    } else {std::cout<< "Unable to open file";}
    myfile.close();
}
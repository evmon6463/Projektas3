#include <iostream>
#include "studentas.h"
#include "studentai.h"
#include "studentai_faile.h"

using std::cout;
using std::endl;
using std::cin;

Studentas::Studentas() {
}

std::ostream& operator<<(std::ostream &output, const Studentas &stu) { //priskyrimas
    output.width(20);
    output << std::left << stu.getVardas() <<  std::setw(20) << stu.getPavarde() << std::left << std::setw(20) << std::setprecision(2) << std::fixed
         << std::left << std::setw(20) <<
         stu.getGalutinisRezultatas() << std::setw(20) << std::setprecision(2)
         << std::fixed
         << stu.getMediana()
         << endl;
    return output;
}

int main() {
    char atsakymas;
    string line;
    cout << "Iveskite kaip norite sukurti duomenis" << endl
         << "Jeigu norite ivesti patys I, Sukurti faila S,"
            " Nuskaityti is failo N" << endl;
    bool ar = true;
    Studentas studentas;
    while(ar) {
        cin >> atsakymas;
        switch (atsakymas) {
            case 'I': {
                studentas.ivesti_studenta(studentas);
                ar=false;
                break;
            }
            case 'S': {
                int failo_dydis=1000;
                int pazymiu_kiekis;
                vector<Studentas> studentai;
                studentai.reserve(10000010);
                ofstream output;
                output.clear();
                pazymiu_kiekis = sugeneruotu_pazymiu_kiekis();
                for (int kelintas_failas = 1; kelintas_failas < 5; kelintas_failas++){
                    studentai = generuojami_studentai_faile(failo_dydis, pazymiu_kiekis, studentas);
                    studentas.rusiavimas_pagal_galutini_pazymi(studentai);
                    failu_uzpildymas(studentai,output, kelintas_failas,"rezultatai");
                    std::cout <<failo_dydis<<" failas su vektoriais 1 strategija"<<endl;
                    output.close();

                    issurusiuoti_failai_v(kelintas_failas, studentai, studentas);
                    cout<<failo_dydis<<" failas su listais 1 strategija"<<endl;
                    issurusiuoti_failai(kelintas_failas, studentai, studentas);

                    std::cout <<failo_dydis<<" failas su vektoriais 2 strategija"<<endl;
                    issurusiuoti_failai_vektorius(kelintas_failas, studentai, studentas);

                    std::cout <<failo_dydis<<" failas su listais 2 strategija"<<endl;
                    issurusiuoti_failai_listai(kelintas_failas, studentai, studentas);
                    failo_dydis=failo_dydis*10;
                }
                ar = false;
                break;
            }
            case 'N': {
                std::ifstream myfile("kursiokai1.txt");
                std::getline(myfile, line);
                studentas.nuskaityto_studento_duomenys(myfile, line, studentas);
                ar = false;
                break;
            }
            default:
                cout << "Klaida" << endl;
        }
    }
}


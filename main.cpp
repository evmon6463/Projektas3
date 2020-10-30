#include <iostream>
#include "studentas.h"
#include "isvedimas.h"
#include "studentai.h"
#include "studentai_faile.h"
#include <chrono>
#include <list>


using std::cout;
using std::endl;
using std::cin;

int main() {
    char atsakymas;
    string line;
    cout << "Iveskite kaip norite sukurti duomenis" << endl
         << "Jeigu norite ivesti patys I, Sukurti faila S,"
            " Nuskaityti is failo N" << endl;
    bool ar = true;
    while(ar) {
        cin >> atsakymas;
        switch (atsakymas) {
            case 'I': {
                vector<studentas> studentai = ivesti_studentai();
                informacijos_isvedimas(studentai);
                ar=false;
                break;
            }
            case 'S': {
                int failo_dydis=1000;
                int pazymiu_kiekis;
                vector<studentas> studentai;

                studentai.reserve(10000010);
                ofstream output;
                output.clear();
                pazymiu_kiekis = sugeneruotu_pazymiu_kiekis();
                for (int kelintas_failas = 1; kelintas_failas < 6; kelintas_failas++){
                    auto start = std::chrono::high_resolution_clock::now();
                    studentai = generuojami_studentai_faile(failo_dydis, pazymiu_kiekis);
                    rusiavimas_pagal_galutini_pazymi(studentai);
                    failu_uzpildymas(studentai,output, kelintas_failas,"rezultatai");
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diff = end-start;
                    std::cout <<failo_dydis<< " Failu kurimas uztrunka "<< diff.count() <<endl;
                    output.close();

                    issurusiuoti_failai(kelintas_failas, studentai);
                    issurusiuoti_failai_v(kelintas_failas, studentai);

                    failo_dydis=failo_dydis*10;
                }
                ar = false;
                break;
            }
            case 'N': {
                std::ifstream myfile("kursiokai.txt");
                std::getline(myfile, line);
                nuskaityti_studentai(myfile, line);
                ar=false;
                break;
            }
            default:
                cout << "Klaida" << endl;
        }
    }
}


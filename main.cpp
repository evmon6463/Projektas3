#include <iostream>
#include "studentas.h"
#include "isvedimas.h"
#include "studentai.h"
#include "studentai_faile.h"
#pragma once
#include <chrono>


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
                int failo_dydis=10;
                vector<studentas> studentai;
                ofstream output;
                for (int kelintas_failas = 1; kelintas_failas < 6; kelintas_failas++){
                    studentai = generuojami_studentai_faile(failo_dydis, kelintas_failas);
                    rusiavimas_pagal_galutini_pazymi(studentai);
                    auto start = std::chrono::high_resolution_clock::now();
                    failu_uzpildymas(studentai,output, kelintas_failas,"rezultatai");
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diff = end-start;
                    std::cout << "Failu kurimas uztrunka "<< diff.count()*1000000 <<endl;
                    issurusiuoti_failai(kelintas_failas, studentai);
                    failo_dydis=failo_dydis*10;
                }
                ar = false;
                break;
            }
            case 'N': {
                std::ifstream myfile("kursiokai.txt");
                std::getline(myfile, line);
                nuskaityto_studento_duomenys(myfile, line);
                ar=false;
                break;
            }
            default:
                cout << "Klaida" << endl;
        }
    }
}


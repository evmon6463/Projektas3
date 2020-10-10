#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "studentas.h"
#include "random.h"
#include "studento_sukurimas.h"
#include "skaiciavimai.h"
#include <time.h>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::to_string;
using std::ofstream;

void grazina_studenta(ofstream &output, studentas st) {
    output.width(20);
    output << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
           << std::left << std::setw(20) << galutinisRezultatas(st) << std::setw(20) << std::setprecision(2)
           << std::fixed
           << mediana(st) << endl;
}

void isvedimas(const vector<studentas> &studentai, ofstream& output,ofstream& vargseliai, ofstream& galvociai){
    output << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    vargseliai << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
               << std::setw(20) << "Galutine mediana" << endl;
    vargseliai << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    galvociai << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
              << std::setw(20) << "Galutine mediana" << endl;
    galvociai << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        grazina_studenta(output, st);
        if(st.galutinis_rezultatas<5){
            grazina_studenta(vargseliai, st);
        }
        else{
            grazina_studenta(galvociai, st);
        }
    }
    output.close();
    vargseliai.close();
    galvociai.close();
}

void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output,ofstream& vargseliai, ofstream& galvociai, int i) {
    galvociai.width(20);
    vargseliai.width(20);
    output.width(20);
    string j = to_string(i);
    output.open("rezultatas"+j+".txt");
    vargseliai.open("vargseliai"+j+".txt");
    galvociai.open("galvociai"+j+".txt");
    isvedimas(studentai, output, vargseliai, galvociai);

}

void generuojami_studentai_faile(int failo_dydis, int k) {
    ofstream output;
    ofstream vargseliai;
    ofstream galvociai;
    studentas studenta;
    std::vector<studentas> studentai;
    srand(time(NULL));
    for (int i=1; i<failo_dydis+1; i++) {
        string j = to_string(i);
        studenta.Vardas = "Vardas" + j;
        studenta.Pavarde = "Pavarde" + j;
        for (int k = 0; k < 10; k++) {
            studenta.nd_rezultatai.push_back(random());
        }
        studenta.egzamino_rezultatas = random();
        studenta.galutinis_rezultatas = galutinisRezultatas(studenta);
        studenta.mediana = mediana(studenta);
        studentai = sukurti_ivesta_studenta(studentai, studenta);
        studenta.nd_rezultatai.clear();
    }
    failu_uzpildymas(studentai, output, vargseliai, galvociai, k);
}

#include <iostream>
#include <fstream>

#include "studentas.h"
#include "isvedimas.h"
#include "studentai.h"
#include "studentai_faile.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    char atsakymas;
    string line;
    cout << "Iveskite kaip norite sukurti duomenis" << endl
         << "Jeigu norite ivesti patys I, nuskaityti is failo N,"
            " sugeneruotu kompiuteris G" << endl;
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
            case 'N': {
                int failo_dydis;
                for (int i = 1; i < 6; i++){
                    cout << "Kokio dydzio faila norite sugeneruoti?" << endl;
                cin >> failo_dydis;
                generuojami_studentai_faile(failo_dydis, i);
            }
                ar = false;
                break;
            }
            case 'G': {
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


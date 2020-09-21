#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

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

float galutinisRezultatas(int j, studentas studentas[], vector<int> pazymiai) {
    float suma = 0;
    float vidurkis = 0;
    int nd_skaicius = pazymiai.size();
    for (int i = 0; i < nd_skaicius; i++) {
        suma = suma + pazymiai[i];
    }
    vidurkis = suma / nd_skaicius;
    studentas[j].galutinis_rezultatas = vidurkis * (float) 0.4 +
                                        studentas[j].egzamino_rezultatas * (float) 0.6;
    return studentas[j].galutinis_rezultatas;
}
float mediana(vector<int> pazymiai, studentas studentas[], int j){
    int size = pazymiai.size();

    sort(pazymiai.begin(), pazymiai.end());
    if (size % 2 == 0) {
        studentas[j].mediana = ((pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2.0);
        return studentas[j].mediana;
    } else {
        studentas[j].mediana = pazymiai[size / 2];
        return studentas[j].mediana;
    }
}

int main() {
    studentas studentas[5];
    string klausimas;
    int kiek;
    for (int j = 0; j < 2; j++) {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> studentas[j].Vardas >> studentas[j].Pavarde;
        cout << "Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai?" << endl
             << "(Iveskite taip arba ne)";
        cin >> klausimas;
        if (klausimas == "ne" || klausimas == "Ne") {
            cout << "Iveskite studento namu darbu rezultatus: "<<endl;
            std::getline(cin >> std::ws, studentas->nd_rezultatai);
            std::istringstream is(studentas->nd_rezultatai); //brake vector
            vector<int> pazymiai((std::istream_iterator<int>(is)), std::istream_iterator<int>());
            cout << "Iveskite egzamino rezultata: "<<endl;
            cin >> studentas[j].egzamino_rezultatas;
            galutinisRezultatas(j, studentas, pazymiai);
            mediana(pazymiai, studentas, j);
        }
        else if (klausimas == "taip" || klausimas == "Taip") {
            cout << "Kiek pazymiu sugeneruoti?";
            cin >> kiek;
            vector<int> pazymiai;
            srand(time(NULL));
            for (int i = 0; i < kiek; i++) {
                pazymiai.push_back(random());
            }
            srand(time(NULL));
            studentas[j].egzamino_rezultatas = random();
            galutinisRezultatas(j, studentas, pazymiai);
            mediana(pazymiai, studentas, j);
        } else {
            cout << "Blogai ivestas rezultatas. Iveskite taip arba ne." << endl;
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
        }*/

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
}


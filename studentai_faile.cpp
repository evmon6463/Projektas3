#include "studentai_faile.h"

void grazina_studenta(ofstream &output, studentas st) {
    output.width(20);
    output << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
           << std::left << std::setw(20) << galutinisRezultatas(st) << std::setw(20) << std::setprecision(2)
           << std::fixed
           << mediana(st) << endl;
}

void isvedimas(const vector<studentas> &studentai, ofstream& output){
    output << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        grazina_studenta(output, st);
    }
    output.close();
}

void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output, int i, string pavadinimas) {
    output.width(20);
    string j = to_string(i);
    output.open(pavadinimas+j+".txt");
    isvedimas(studentai, output);
}

vector<studentas> generuojami_studentai_faile(int failo_dydis, int pazymiu_kiekis) {
    studentas studenta;
    std::vector<studentas> studentai;
    srand(time(NULL));
    for (int i=1; i<failo_dydis+1; i++) {
        string j = to_string(i);
        studenta.Vardas = "Vardas" + j;
        studenta.Pavarde = "Pavarde" + j;
        for (auto k = 0; k < pazymiu_kiekis; k++) {
            studenta.nd_rezultatai.push_back(random());
        }
        studenta.egzamino_rezultatas = random();
        studenta.galutinis_rezultatas = galutinisRezultatas(studenta);
        studenta.mediana = mediana(studenta);
        studentai.push_back(studenta);
        studenta.nd_rezultatai.clear();
    }
    return studentai;
}

void issurusiuoti_failai(int kelintas_failas, const vector<studentas> &studentai) {
    ofstream gudruciai;
    ofstream vargseliai;
    vector<studentas> vargsai;
    vargsai.reserve(10000010);
    vargsai.clear();
    vector<studentas> gudruoliai;
    gudruoliai.reserve(10000010);
    gudruoliai.clear();

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    auto start1 = std::chrono::high_resolution_clock::now();
    std::getline(myfile, line);
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_is_sukurto_failo(myfile, line);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    std::cout << "Failo nuskaitymas " << diff1.count()<< endl;
    auto start = std::chrono::high_resolution_clock::now();

    for(auto st:studentai){
        if(st.galutinis_rezultatas>=5){
            gudruoliai.push_back(st);
        }
        else{
            vargsai.push_back(st);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "Failu isrusiavimas uztrunka "<< diff.count() <<endl;
    auto start_1 = std::chrono::high_resolution_clock::now();
    failu_uzpildymas(gudruoliai, gudruciai, kelintas_failas, "gudruciai");
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Gudruoliu failo isvedimas "<< diff_1.count() <<endl;
    auto start_2 = std::chrono::high_resolution_clock::now();
    failu_uzpildymas(vargsai, vargseliai, kelintas_failas, "vargseliai");
    auto end_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_2 = end_2-start_2;
    std::cout << "Vargseliu failo isvedimas "<< diff_2.count() <<endl;
    std::cout<<endl;
}


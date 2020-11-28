#include "studentai_faile.h"



void grazina_studenta_list(ofstream &output, studentas st) {
    output.width(20);
    output << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
           << std::left << std::setw(20) << st.galutinis_rezultatas << std::setw(20) << std::setprecision(2)
           << std::fixed
           << st.mediana << endl;
}

void isvedimas(const vector<studentas> &studentai, ofstream& output){

    output << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        output.width(20);
        output << st.Vardas << std::setw(20) << st.Pavarde << std::setw(20) << std::setprecision(2) << std::fixed
               << std::left << std::setw(20) << galutinisRezultatas(st) << std::setw(20) << std::setprecision(2)
               << std::fixed
               << mediana(st);
        if (st.Pavarde == studentai.back().Pavarde && st.Vardas == studentai.back().Vardas &&
            st.galutinis_rezultatas == studentai.back().galutinis_rezultatas) {
            break;
        } else {
            output <<endl;
        }
    }
    output.close();
}

void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output, int i, string pavadinimas) {
    output.width(20);
    string j = to_string(i);
    output.open(pavadinimas+j+".txt");
    isvedimas(studentai, output);
}

void isvedimas_list(const std::list<studentas> &studentai, ofstream& output){
    output << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        grazina_studenta_list(output, st);
    }
    output.close();
}

void failu_uzpildymas_list(const std::list<studentas> &studentai, ofstream& output, int i, string pavadinimas) {
    output.width(20);
    string j = to_string(i);
    output.open(pavadinimas+j+".txt");
    isvedimas_list(studentai, output);
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
    std::list<studentas> vargsai;
    std::list<studentas> gudruoliai;
    std::list<studentas> studentai_list;

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_list = studentai_is_sukurto_failo_list(myfile, line);
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai_list){
        if(st.galutinis_rezultatas>=5){
            gudruoliai.push_back(st);
        }
        else{
            vargsai.push_back(st);
        }
    }
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo dalinimas "<< diff_1.count() <<endl<<endl;
#ifdef LIST
    std::list<studentas>::iterator it = std::find_if (studentai_list.begin(), studentai_list.end(),5.0);
    vargsai.splice(vargsai.begin(), studentai_list, studentai_list.begin(), it);
    gudruoliai.splice(gudruoliai.begin(), studentai_list, it, studentai_list.end());
#endif //LIST


    failu_uzpildymas_list(gudruoliai, gudruciai, kelintas_failas, "gudruciai_l");
    failu_uzpildymas_list(vargsai, vargseliai, kelintas_failas, "vargseliai_l");
}

void issurusiuoti_failai_v(int kelintas_failas, const vector<studentas> &studentai) {
    ofstream gudruciai1;
    ofstream vargseliai1;
    vector<studentas> vargsai;
    vargsai.reserve(10000010);
    vargsai.clear();
    vector<studentas> gudruoliai;
    gudruoliai.reserve(10000010);
    gudruoliai.clear();

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_is_sukurto_failo(myfile, line);
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai){
        if(st.galutinis_rezultatas>=5){
            gudruoliai.push_back(st);
        }
        else{
            vargsai.push_back(st);
        }
    }
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo dalinimas "<< diff_1.count() <<endl<<endl;
    failu_uzpildymas(gudruoliai, gudruciai1, kelintas_failas, "gudruciai_v");
    failu_uzpildymas(vargsai, vargseliai1, kelintas_failas, "vargseliai_v");
}

void issurusiuoti_failai_vektorius(int kelintas_failas, vector<studentas> &studentai) {
    ofstream gudruciai1;
    ofstream vargseliai1;
    vector<studentas> vargsai;
    vargsai.reserve(10000010);
    vargsai.clear();

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_is_sukurto_failo(myfile, line);
    int kelintas = 0;
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai){
        if(st.galutinis_rezultatas<5){
            vargsai.push_back(st);
            kelintas++;
        }
    }

    vector<studentas>::iterator it;
    it = studentai.begin();
    studentai.erase(it, it+kelintas);

    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo dalinimas "<< diff_1.count() <<endl<<endl;





    failu_uzpildymas(studentai, gudruciai1, kelintas_failas, "gudruciai_vektorius");
    failu_uzpildymas(vargsai, vargseliai1, kelintas_failas, "vargseliai_vektorius");
}

void issurusiuoti_failai_listai(int kelintas_failas, vector<studentas> &studentai) {
    ofstream gudruciai;
    ofstream vargseliai;
    std::list<studentas> vargsai;
    std::list<studentas> studentai_list;

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_list = studentai_is_sukurto_failo_list(myfile, line);
    int kelintas = 0;
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai_list){
        if(st.galutinis_rezultatas<5){
            vargsai.push_back(st);
            kelintas++;
        }
    }
    std::list<studentas>::iterator it1;

    for (int i=0; i<kelintas; i++){
        it1 = studentai_list.begin();
        studentai_list.erase(it1);
    }
    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo dalinimas "<< diff_1.count() <<endl<<endl;
#ifdef LIST
    std::list<studentas>::iterator it = std::find_if (studentai_list.begin(), studentai_list.end(),5.0);
    vargsai.splice(vargsai.begin(), studentai_list, studentai_list.begin(), it);
    gudruoliai.splice(gudruoliai.begin(), studentai_list, it, studentai_list.end());
#endif //LIST


    failu_uzpildymas_list(studentai_list, gudruciai, kelintas_failas, "gudruciai_list");
    failu_uzpildymas_list(vargsai, vargseliai, kelintas_failas, "vargseliai_list");

}


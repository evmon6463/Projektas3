#include "studentai_faile.h"



void grazina_studenta_list(ofstream &output, Studentas st) {
    output.width(20);
    output << st.getVardas() << std::setw(20) << st.getPavarde() << std::setw(20) << std::setprecision(2) << std::fixed
           << std::left << std::setw(20) << st.getGalutinisRezultatas() << std::setw(20) << std::setprecision(2)
           << std::fixed
           << st.getMediana() << endl;
}

void isvedimas(const vector<Studentas> &studentai, ofstream& output){

    output << std::left << "Vardas" << std::setw(20) << "Pavardess" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        st.setGalutinisRezultatas(st.galutinisRezultatas(st));
        st.setMediana(st.medianosRezultatas(st));
        Studentas stu(st.getVardas(), st.getPavarde(), st.getGalutinisRezultatas(), st.getMediana(), st.getNdRezultatus(), st.getEgzaminoRezultata()); //call copy constructor
        output<<stu;
    }

    output.close();
}

void failu_uzpildymas(const vector<Studentas> &studentai, ofstream& output, int i, string pavadinimas) {
    output.width(20);
    string j = to_string(i);
    output.open(pavadinimas+j+".txt");
    isvedimas(studentai, output);
}

void isvedimas_list(const std::list<Studentas> &studentai, ofstream& output){
    output << std::left << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis vidurkis"
           << std::setw(20) << "Galutine mediana" << endl;
    output << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    for (auto st : studentai) {
        grazina_studenta_list(output, st);
    }
    output.close();
}

void failu_uzpildymas_list(const std::list<Studentas> &studentai, ofstream& output, int i, string pavadinimas) {
    output.width(20);
    string j = to_string(i);
    output.open(pavadinimas+j+".txt");
    isvedimas_list(studentai, output);
}

vector<Studentas> generuojami_studentai_faile(int failo_dydis, int pazymiu_kiekis, Studentas studentas) {
    std::vector<Studentas> studentai;
    srand(time(NULL));
    vector<int> pazymiai;
    for (int i=1; i<failo_dydis+1; i++) {
        string j = to_string(i);
        studentas.setVardas("Vardas" + j);
        studentas.setPavarde("Pavarde" + j);
        for (auto k = 0; k < pazymiu_kiekis; k++) {
            pazymiai.push_back(random());
        }
        studentas.setNdRezultatus(pazymiai);
        studentas.setEgzaminoRezultata(random());
        studentas.setGalutinisRezultatas(studentas.galutinisRezultatas(studentas));
        studentas.setMediana(studentas.medianosRezultatas(studentas));
        studentai.push_back(studentas);
        pazymiai.clear();
    }
    return studentai;
}

void issurusiuoti_failai(int kelintas_failas, const vector<Studentas> &studentai, Studentas studentas) {
    ofstream gudruciai;
    ofstream vargseliai;
    std::list<Studentas> vargsai;
    std::list<Studentas> gudruoliai;
    std::list<Studentas> studentai_list;

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_list = studentai_is_sukurto_failo_list(myfile, line, studentas);
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai_list){
        if(st.getGalutinisRezultatas()>=5){
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

void issurusiuoti_failai_v(int kelintas_failas, const vector<Studentas> &studentai, Studentas studentas) {
    ofstream gudruciai1;
    ofstream vargseliai1;
    vector<Studentas> vargsai;
    vargsai.reserve(1000010);
    vargsai.clear();
    vector<Studentas> gudruoliai;
    gudruoliai.reserve(1000010);
    gudruoliai.clear();

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_is_sukurto_failo(myfile, line, studentas);
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai){
        if(st.getGalutinisRezultatas()>=5){
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

void issurusiuoti_failai_vektorius(int kelintas_failas, vector<Studentas> &studentai, Studentas studentas) {
    ofstream gudruciai1;
    ofstream vargseliai1;
    vector<Studentas> vargsai;
    vargsai.reserve(1000010);
    vargsai.clear();

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_is_sukurto_failo(myfile, line, studentas);
    int kelintas = 0;
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai){
        if(st.getGalutinisRezultatas()<5){
            vargsai.push_back(st);
            kelintas++;
        }
    }

    vector<Studentas>::iterator it;
    it = studentai.begin();
    studentai.erase(it, it+kelintas);

    auto end_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo dalinimas "<< diff_1.count() <<endl<<endl;

    failu_uzpildymas(studentai, gudruciai1, kelintas_failas, "gudruciai_vektorius");
    failu_uzpildymas(vargsai, vargseliai1, kelintas_failas, "vargseliai_vektorius");
}

void issurusiuoti_failai_listai(int kelintas_failas, vector<Studentas> &studentai, Studentas studentas) {
    ofstream gudruciai;
    ofstream vargseliai;
    std::list<Studentas> vargsai;
    std::list<Studentas> studentai_list;

    string line;
    std::ifstream myfile("rezultatai" + to_string(kelintas_failas) + ".txt");
    std::getline(myfile, line);
    std::getline(myfile, line);
    studentai_list = studentai_is_sukurto_failo_list(myfile, line, studentas);
    int kelintas = 0;
    auto start_1 = std::chrono::high_resolution_clock::now();
    for(auto st:studentai_list){
        if(st.getGalutinisRezultatas()<5){
            vargsai.push_back(st);
            kelintas++;
        }
    }
    std::list<Studentas>::iterator it1;

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


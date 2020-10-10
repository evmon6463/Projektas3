#ifndef PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H
#define PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H

using std::ofstream;

void grazina_studenta(ofstream &output, studentas st);
void isvedimas(const vector<studentas> &studentai, ofstream& output,ofstream& vargseliai, ofstream& galvociai);
void failu_uzpildymas(const vector<studentas> &studentai, ofstream& output,ofstream& vargseliai, ofstream& galvociai, int i);
void generuojami_studentai_faile(int failo_dydis, int i);

#endif //PROJEKTAS_SU_VEKTORIAIS_STUDENTAI_FAILE_H

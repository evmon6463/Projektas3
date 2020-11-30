#include "rusiavimas.h"

/*void string_rusiavimas(vector<Studentas> &studentai) {
    sort(studentai.begin(), studentai.end(), [](const Studentas &s1, const Studentas &s2) {
             if (s1.vardas_.find("0123456789")) {
                 if (s1.vardas_.size() != s2.vardas_.size()) {
                     return (s1.vardas_.length() < s2.vardas_.length());
                 }
             }
             return (s1.vardas_ < s2.vardas_);
         }
    );
}*/

void Studentas::rusiavimas_pagal_galutini_pazymi(vector<Studentas> &studentai)
{
    vector<Studentas> surusiuoti_studentai;
    surusiuoti_studentai.reserve(10000010);
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &left, const Studentas &right)
    {return (left.galutinis_rezultatas < right.galutinis_rezultatas);});
}

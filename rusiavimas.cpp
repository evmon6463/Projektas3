#include "rusiavimas.h"

void Studentas::string_rusiavimas(vector<Studentas> &studentai) {
    sort(studentai.begin(), studentai.end(), [](const Studentas &s1, const Studentas &s2) {
             if (s1.getVardas().find("0123456789")) {
                 if (s1.getVardas().size() != s2.getVardas().size()) {
                     return (s1.getVardas().length() < s2.getVardas().length());
                 }
             }
             return (s1.getVardas() < s2.getVardas());
         }
    );
}

void Studentas::rusiavimas_pagal_galutini_pazymi(vector<Studentas> &studentai)
{
    vector<Studentas> surusiuoti_studentai;
    surusiuoti_studentai.reserve(10000010);
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &left, const Studentas &right)
    {return (left.galutinis_rezultatas < right.galutinis_rezultatas);});
}

#include "studentas.h"
#include <algorithm>

void rusiavimas(vector<studentas> &studentai) {
    sort(studentai.begin(), studentai.end(), [](const studentas &s1, const studentas &s2) {
             if (s1.Vardas.find("0123456789")) {
                 if (s1.Vardas.size() != s2.Vardas.size()) {
                     return (s1.Vardas.length() < s2.Vardas.length());
                 }
             }
             return (s1.Vardas < s2.Vardas);
         }
    );
}

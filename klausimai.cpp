#include "klausimai.h"

string ar_generuoti() {
    string klausimas;
    cout << "Ar norite, kad pazymiai ir egzamino rezultatas butu sugeneruotas atsitiktinai?" << endl
         << "(Iveskite taip arba ne)";
    cin >> klausimas;
    return klausimas;
}

int ar_ivesti_nauja_studenta() {
    string atsakymas;
    cout << "Ar ivesti nauja studenta?Iveskite taip arba ne" << endl;
    while (true) {
        cin >> atsakymas;
        if (atsakymas == "Taip" || atsakymas == "taip" || atsakymas == "TAIP")
            return 1;
        else if (atsakymas == "ne" || atsakymas == "Ne" || atsakymas == "NE")
            return 0;
        else {
            cout << "Klaida. Iveskite taip arba ne." << endl;
            continue;
        }
    }
}

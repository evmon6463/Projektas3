#include "random.h"

int random() {
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}

int sugeneruotu_pazymiu_kiekis() {
    string pazymiu_kiekis;
    cout << "Kiek pazymiu sugeneruoti?";
    while (true) {
        cin >> pazymiu_kiekis;
        try {
            if (!pazymiu_kiekis.find_first_not_of(" 0123456789")) {
                cout << "Klaida. Ivedete ne skaicius" << endl;
                continue;
            } else {
                int skaicius = stoi(pazymiu_kiekis);
                return skaicius;
            }
        } catch (invalid_argument &e) {
            cout << "Klaida. Ivedete ne skaicius. Pabandykite dar karta!" << endl;
        }
    }
}
vector<int> generuojami_skaiciai() {
    vector<int> nd_rezultatai;
    int pazymiu_kiekis = 0;
    while (true) {
        pazymiu_kiekis = sugeneruotu_pazymiu_kiekis();
        if (pazymiu_kiekis > 0 & pazymiu_kiekis < 100) {
            srand(time(NULL));
            for (int i = 0; i < pazymiu_kiekis; i++) {
                nd_rezultatai.push_back(random());
            }
            srand(time(NULL));
            return nd_rezultatai;
        } else {
            cout << "Skaicius turi buti didesnis uz 0 ir mazesnis nei 100" << endl;
        }
    }
}
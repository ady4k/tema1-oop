//
// Created by 4K-PC on 26/02/2021.
//

#include "BazaDeDate.h"

// constructori & destructor
BazaDeDate::BazaDeDate() {
    nrPersoane = 0;
    dimensiune = 0;
}

BazaDeDate::BazaDeDate(int dimensiune_) {
    nrPersoane = 0;
    persoane = new Persoana[dimensiune_];
    initializare(nrPersoane);
}

BazaDeDate::BazaDeDate(const BazaDeDate &other) {
    nrPersoane = other.dimensiune;
    if (dimensiune < 1) {
        persoane = nullptr;
    } else {
        persoane = new Persoana[dimensiune];
        for(int i = 0; i < dimensiune; i++) {
            persoane[i] = other.persoane[i];
        }
    }
}

BazaDeDate::~BazaDeDate() {
    delete [] persoane;
}

// metode
void BazaDeDate::initializare(int nrPersoane_) {
    for(int i = nrPersoane_; i < dimensiune; i++) {
        persoane[i].seteazaValori("",NULL,'\0');
    }
}

void BazaDeDate::extindere() {
    dimensiune++;
    if (dimensiune > 1) {
        Persoana *temp = new Persoana[dimensiune];
        for(int i = 0; i < dimensiune; i++) {
            temp[i] = persoane[i];
        }
        delete [] persoane;
        persoane = temp;
        initializare(nrPersoane);
    } else {
        persoane = new Persoana[dimensiune];
        initializare(nrPersoane);
    }
}

void BazaDeDate::micsorare() {
    dimensiune--;
    Persoana *temp = new Persoana[dimensiune];
    for(int i = 0; i < dimensiune; i++) {
        temp[i] = persoane[i];
    }
    delete [] persoane;
    persoane = temp;
}

void BazaDeDate::stergere(int nrPers) {
    for (int i = nrPers; i < nrPersoane; i++) {
        persoane[i] = persoane[i + 1];
    }
    nrPersoane--;
    micsorare();
}


void BazaDeDate::adaugaPersoana(string nume_, int anNastere_, char sex_) {
    if (nrPersoane == dimensiune) {
        extindere();
        persoane[nrPersoane++].seteazaValori(nume_, anNastere_, sex_);
    } else {
        persoane[nrPersoane++].seteazaValori(nume_, anNastere_, sex_);
    }
}

void BazaDeDate::stergePersoana(string nume_) {
    for(int i = 0; i <= nrPersoane; i++) {
        if (persoane[i].getNume() == nume_) {
            stergere(i);
        }
    }
}

void BazaDeDate::stergePersoana(int anNastere_) {
    for(int i = 0; i <= nrPersoane; i++) {
        if (persoane[i].getAnNastere() == anNastere_) {
            stergere(i);
        }
    }
}

void BazaDeDate::stergePersoana(char sex_) {
    for(int i = 0; i <= nrPersoane; i++) {
        if (persoane[i].getSex() == sex_) {
            stergere(i);
        }
    }
}

void BazaDeDate::sortare(bool optiune) {
    if (optiune) {
        bool ok;
        for(int i = 0; i < nrPersoane; i++) {
            ok = false;
            for(int j = 0; j < nrPersoane - 1; j++) {
                string nume1 = persoane[j].getNume();
                string nume2 = persoane[j + 1].getNume();
                if (nume1.compare(nume2) < 0) {
                    Persoana aux = persoane[j];
                    persoane[j] = persoane[j + 1];
                    persoane[j + 1] = aux;
                    ok = true;
                }
            }
            if (!ok) {
                break;
            }
        }
    } else {
        bool ok;
        for(int i = 0; i < nrPersoane; i++) {
            ok = false;
            for(int j = 0; j < nrPersoane - 1; j++) {
                if (persoane[j].getAnNastere() < persoane[j + 1].getAnNastere()) {
                    Persoana aux = persoane[j];
                    persoane[j] = persoane[j + 1];
                    persoane[j + 1] = aux;
                    ok = true;
                }
            }
            if (!ok) {
                break;
            }
        }
    }
}

void BazaDeDate::afisare() {
    for (int i = 0; i <= nrPersoane; i++) {
        cout << "Persoana " << i << " se numeste " << persoane[i].getNume() << ", este nascuta in " << persoane[i].getAnNastere() << " si este de sex " << persoane[i].getSex() << "\n";
    }
}

void BazaDeDate::afisareAlfabetic() {
    sortare(true);
    afisare();
}

void BazaDeDate::afisareVarsta() {
    sortare(false);
    afisare();
}

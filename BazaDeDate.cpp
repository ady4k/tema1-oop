//
// Created by 4K-PC on 26/02/2021.
//

#include "BazaDeDate.h"

// constructor & destructor
BazaDeDate::BazaDeDate() {
    nrPersoane = 0;
    persoane = new Persoana[nrPersoane];
    initializare(nrPersoane);
}

BazaDeDate::~BazaDeDate() {
    delete [] persoane;
}

// metode
void BazaDeDate::initializare(int nrPersoane_) {
    for(int i = nrPersoane_; i < nrPersoane; i++) {
        persoane[i].setNume(nullptr);
        persoane[i].setAnNastere(NULL);
        persoane[i].setSex(NULL);
    }
}

void BazaDeDate::seteazaValori(string nume_, int anNastere_, char sex_) {

}

void BazaDeDate::adaugaPersoana(string nume_, int anNastere_, char sex_) {
    nrPersoane++;
    Persoana *tempPersoane = new Persoana[nrPersoane];
    for (int i = 0; i < nrPersoane; i++) {
        tempPersoane[i] = persoane[i];
    }
    delete [] persoane;
    persoane = tempPersoane;
    delete [] tempPersoane;

}
//
// Created by 4K-PC on 26/02/2021.
//

#ifndef TEMA1_OOP_BAZADEDATE_H
#define TEMA1_OOP_BAZADEDATE_H

#include "Persoana.h"

class BazaDeDate {
private:
    Persoana *persoane;
    int nrPersoane;
    int dimensiune;

public:
    // constructor & destructor
    BazaDeDate();
    BazaDeDate(int dimensiune_);
    BazaDeDate(const BazaDeDate &other);
    ~BazaDeDate();

    // metode
    void initializare(int nrPersoane_);
    void extindere();
    void micsorare();
    void stergere(int nrPers);
    void adaugaPersoana(string nume_, int anNastere_, char sex_);
    void stergePersoana(string nume_);
    void stergePersoana(int anNastere_);
    void stergePersoana(char sex_);
    void modificaPersoana(int nrPers, string nume_);
    void modificaPersoana(int nrPers, int anNastere_);
    void modificaPersoana(int nrPers, char sex_);
    void sortare(bool optiune);
    void afisare();
    void afisareAlfabetic();
    void afisareVarsta();
};


#endif //TEMA1_OOP_BAZADEDATE_H

//
// Created by 4K-PC on 26/02/2021.
//

#ifndef TEMA1_OOP_BAZADEDATE_H
#define TEMA1_OOP_BAZADEDATE_H

#include "Persoana.cpp"

class BazaDeDate {
private:
    Persoana *persoane;
    static int nrPersoane;

public:
    // constructor & destructor
    BazaDeDate();
    ~BazaDeDate();

    // metode
    void initializare(int nrPersoane_);
    void seteazaValori(string nume_, int anNastere_, char sex_);
    void adaugaPersoana(string nume_, int anNastere_, char sex_);
    void stergePersoana(string nume_);
    void stergePersoana(int anNastere_);
    void stergePersoana(char sex_);
    void afisareAlfabetic();
    void afisareVarsta();
};


#endif //TEMA1_OOP_BAZADEDATE_H

//
// Created by 4K-PC on 26/02/2021.
//

#include "Persoana.h"
#include <iostream>

// constructori & destructori
Persoana::Persoana() {

}

Persoana::Persoana(string nume_, int anNastere_, char sex_) {
    nume = nume_;
    anNastere = anNastere_;
    sex = sex_;
}

Persoana::~Persoana() {

}

// setteri
void Persoana::setNume(string nume_) {
    nume = nume_;
}

void Persoana::setAnNastere(int anNastere_) {
    anNastere = anNastere_;
}

void Persoana::setSex(char sex_) {
    if (sex_ == 'M' || sex_ == 'F') {
        sex = sex_;
    } else {
        sex = '\0';
        cout << "Valoare introdusa incorecta, a fost aplicata valoarea NULL";
    }
}

// getteri
string Persoana::getNume() {
    return nume;
}

int Persoana::getAnNastere() {
    return anNastere;
}

char Persoana::getSex() {
    return sex;
}

// metode
void Persoana::seteazaValori(string nume_, int anNastere_, char sex_) {
    this->setNume(nume_);
    this->setAnNastere(anNastere_);
    this->setSex(sex_);
}
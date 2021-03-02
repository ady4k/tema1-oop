//
// Created by 4K-PC on 26/02/2021.
//

#include "Persoana.h"

// constructori & destructori
Persoana::Persoana() {
    nume = "";
    anNastere = NULL;
    sex = '\0';
}

Persoana::Persoana(string nume_, int anNastere_, char sex_) {
    nume = nume_;
    anNastere = anNastere_;
    sex = sex_;
}

Persoana::~Persoana() = default;

// setteri
void Persoana::setNume(string nume_) {
    nume = nume_;
}

void Persoana::setAnNastere(int anNastere_) {
    anNastere = anNastere_;
}

void Persoana::setSex(char sex_) {
    if (sex_ == 'M' || sex_ == 'F' || sex_ == '\0') {
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

// supraincarcare
istream& operator>>(istream &in, Persoana &persoana) {
    string nume_;
    int anNastere_;
    char sex_;
    in >> nume_ >> anNastere_ >> sex_;
    persoana.seteazaValori(nume_, anNastere_, sex_);
    return in;
}

ostream& operator<<(ostream &out, Persoana &persoana) {
    out << " se numeste " << persoana.getNume() << " este nascuta in anul " << persoana.getAnNastere() << " si este de sexul " << persoana.getSex() << '\n';
    return out;
}
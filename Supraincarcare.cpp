//
// Created by Ady on 01/03/2021.
//

#include "Persoana.h"
using namespace std;

istream& operator>>(istream &in, Persoana &persoana) {
    string nume_;
    int anNastere_;
    char sex_;
    in >> nume_ >> anNastere_ >> sex_;
    persoana.seteazaValori(nume_, anNastere_, sex_);
    return in;
}

ostream& operator<<(ostream &out, Persoana &persoana) {
    out << persoana.getNume() << ' ' << persoana.getAnNastere() << ' ' << persoana.getSex() << '\n';
    return out;
}
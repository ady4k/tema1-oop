//
// Created by 4K-PC on 26/02/2021.
//

#ifndef TEMA1_OOP_PERSOANA_H
#define TEMA1_OOP_PERSOANA_H

#include <string>
using namespace std;

class Persoana {
private:
    string nume;
    int anNastere;
    char sex;

public:
    // constructori & destructor
    Persoana();
    Persoana(string nume_, int anNastere_, char sex_);
    ~Persoana();

    // setteri
    void setNume(string nume_);
    void setAnNastere(int anNastere_);
    void setSex(char sex_);

    // getteri
    string getNume();
    int getAnNastere();
    char getSex();

};


#endif //TEMA1_OOP_PERSOANA_H

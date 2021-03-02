#include "BazaDeDate.h"
#include "ctime"
#include <cstdlib>

bool iesire();

int main() {

    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    bool exit = false;
    int i;
    BazaDeDate bazaDeDate;
    bazaDeDate.adaugaPersoana("Ben Dover", 1955, 'M');
    bazaDeDate.adaugaPersoana("Paris", 1967, 'F');
    do {
        cout << "1. Afiseaza toate persoanele in ordine alfabetica\n"
                "2. Afiseaza toate persoanele in ordinea crescatoare a varstelor\n"
                "3. Adauga o persoana\n"
                "4. Elimina persoanele dupa nume\n"
                "5. Elimina persoanele dupa varsta\n"
                "6. Elimina persoanele dupa sex\n"
                "7. Modifica o persoana\n"
                "8. Iesire\n";
        cin >> i;
        switch (i) {
            case 1: {
                system("CLS");
                bazaDeDate.afisareAlfabetic();
                system("pause");
                exit = iesire();
                break;
            }
            case 2: {
                system("CLS");
                bazaDeDate.afisareVarsta();
                system("pause");
                exit = iesire();
                break;
            }
            case 3: {
                system("CLS");
                Persoana temp;
                cin >> temp;
                bazaDeDate.adaugaPersoana(temp.getNume(), temp.getAnNastere(), temp.getSex());
                system("pause");
                exit = iesire();
                break;
            }
            case 4: {
                system("CLS");
                cout << "Introduceti numele al caror persoane vor fi sterse:";
                string nume;
                cin >> nume;
                bazaDeDate.stergePersoana(nume);
                cout << "Persoanele cu numele introdus au fost sterse.\n\n";
                system("pause");
                exit = iesire();
                break;
            }
            case 5: {
                system("CLS");
                cout << "Introduceti varsta persoanelor care vor fi sterse:";
                int varsta;
                cin >> varsta;
                bazaDeDate.stergePersoana(timePtr->tm_year + 1900 - varsta);
                cout << "Persoanele cu numele introdus au fost sterse.\n\n";
                system("pause");
                exit = iesire();
                break;
            }
            case 6: {
                system("CLS");
                cout << "Introduceti sexul persoanelor care vor fi sterse:";
                char sex;
                cin >> sex;
                bazaDeDate.stergePersoana(sex);
                cout << "Persoanele cu numele introdus au fost sterse.\n\n";
                system("pause");
                exit = iesire();
                break;
            }
            case 7: {
                system("CLS");
                cout << "Alegeti persoana pe care doriti sa o modificati:\n";
                bazaDeDate.afisareAlfabetic();
                int numarul, modificare;
                cin >> numarul;
                cout << "Alegeti modificarea dorita:\n"
                        "1. Numele\n"
                        "2. Anul nasterii\n"
                        "3. Sexul\n";
                cin >> modificare;
                switch (modificare) {
                    case 1:{
                        string nume_;
                        cout << "Introduceti numele dorit:\n";
                        cin >> nume_;
                        bazaDeDate.modificaPersoana(numarul, nume_);
                        break;
                    }
                    case 2:{
                        int anNastere_;
                        cout << "Introduceti anul de nastere dorit:\n";
                        cin >> anNastere_;
                        bazaDeDate.modificaPersoana(numarul, anNastere_);
                        break;
                    }
                    case 3:{
                        char sex_;
                        cout << "Introduceti sexul dorit:\n";
                        cin >> sex_;
                        bazaDeDate.modificaPersoana(numarul, sex_);
                        break;
                    }
                    default: {
                        cout << "Valoare introdusa invalida!";
                        break;
                    }
                }
                system("CLS");
                system("pause");
                exit = iesire();
                break;
            }
            case 8: {
                system("CLS");
                exit = true;
                break;
            }
            default: {
                system("CLS");
                cout << "Introduceti un numar de la 1 la 8!";
                break;
            }
        }
    system("CLS");
    } while(!exit);
    return 0;
}

bool iesire() {
    bool exit = false;
    cout << "\n\nDoriti sa iesiti din program? (Y/n)";
    char acord;
    bool iesit = false;
    do {
        cin >> acord;
        if (acord == 'Y' || acord == 'y') {
            system("CLS");
            exit = true;
            iesit = true;
        } else if (acord == 'N' || acord == 'n') {
            system("CLS");
            iesit = true;
        } else {
            system("cls");
            cout << "Valoare invalida!\nIntroduceti Y (da) sau n (nu).";
        }
    } while (!iesit);
    return exit;
}

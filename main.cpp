#include "BazaDeDate.h"
#include "ctime"

bool iesire();

int main() {

    time_t t = time(nullptr);
    tm *timePtr = localtime(&t);

    bool exit = false;
    int i;
    BazaDeDate bazaDeDate;
    bazaDeDate.adaugaPersoana("Penis", 1955, 'M');
    bazaDeDate.adaugaPersoana("Paris", 1967, 'F');
    do {
        cout << "1. Afiseaza toate persoanele in ordine alfabetica\n"
                "2. Afiseaza toate persoanele in ordinea crescatoare a varstelor\n"
                "3. Adauga o persoana\n"
                "4. Elimina persoanele dupa nume\n"
                "5. Elimina persoanele dupa varsta\n"
                "6. Elimina persoanele dupa sex\n"
                "7. Iesire\n";
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
                //bazaDeDate.adaugaPersoana();
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
                system("pause");
                exit = iesire();
                break;
            }
            case 7: {
                system("CLS");
                system("pause");
                exit = iesire();
                break;
            }
            default: {
                system("CLS");
                cout << "Introduceti un numar de la 1 la 7!";
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
    cin >> acord;
    do {
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

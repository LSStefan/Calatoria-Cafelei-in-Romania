#include "angajat.h"
#include <iostream>
#include <fstream>

using namespace std;

//mostenire
class Manager : public Angajat{
    public:
        Manager(){
            nume = "";
            functie = "";
            inceputMunca = "";
            sfarsitMunca = "";
        }
        void addEmployee(){
            string oras,nume, functie, inceputMunca, sfarsitMunca;
            cout << "Introduceti orasul: ";
            cin >> oras;
            cout << "Introduceti numele angajatului: ";
            getline(cin >> ws, nume);
            cout << "Introduceti functia angajatului: ";
            cin >> functie;
            cout << "Introduceti ora de inceput a muncii: ";
            cin >> inceputMunca;
            cout << "Introduceti ora de sfarsit a muncii: ";
            cin >> sfarsitMunca;

            ofstream file;
            file.open("angajati.csv", ios::app);
            file << oras << "," << nume << "," << functie << "," << inceputMunca << "," << sfarsitMunca << endl;
            file.close();
        }
};
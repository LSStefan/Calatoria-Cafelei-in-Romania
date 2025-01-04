#include <iostream>
#include <fstream>
#include <sstream>
#include "angajat.h"

using namespace std;

class Cafenea{
    public:
        Angajat angajati[20];
        int nrAngajati = 0;
        string locatie;

    public:
        Cafenea(){
            locatie = "";
        }
        Cafenea(string locatie){
            this->locatie = locatie;
        }
        void angajeaza(Angajat angajat){
            angajati[nrAngajati] = angajat;
            nrAngajati++;
        }

        void displayEmployees(Angajat angajati[],int nrAngajati){
            for (int i = 0; i < nrAngajati; i++){
                cout << angajati[i].nume << "," << angajati[i].functie << "," << angajati[i].inceputMunca << "," << angajati[i].sfarsitMunca << endl;
            }
        }

        void displayProducts(string locatie){
            ifstream file;
            file.open("produse.csv");
            string line;
            while (getline(file, line))
            {
                string oras = line.substr(0, line.find(","));
                
                if (oras == locatie) {
                    stringstream ss(line);
                    string oras, nume, pret, cantitate;

                    getline(ss, oras, ',');
                    getline(ss, nume, ',');
                    getline(ss, pret, ',');
                    getline(ss, cantitate, ',');

                    cout << nume << "," << pret << "," << cantitate << endl;
                }
            }
        }

};
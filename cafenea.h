#include <iostream>
#include <fstream>
#include <sstream>
#include "angajat.h"
#include "produs.h"

using namespace std;

class Cafenea{
    public:
        Angajat angajati[20];
        Produs produse[20];
        int nrAngajati = 0;
        int nrProduse = 0;
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

        void adaugaProdus(Produs produs){
            produse[nrProduse] = produs;
            nrProduse++;
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
            int i = 1;
            while (getline(file, line))
            {
                string oras = line.substr(0, line.find(","));
                
                if (oras == locatie) {
                    stringstream ss(line);
                    string oras,tip,nume,pret;

                    getline(ss, oras, ',');
                    getline(ss, tip, ',');
                    getline(ss, nume, ',');
                    getline(ss, pret, ',');

                    cout <<  i << "." <<  oras << "," << tip << "," << nume << "," << pret << endl;
                    i++;
                }
            }
        }

};
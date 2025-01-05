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

        void displayEmployees(){
            for (int i = 0; i < nrAngajati; i++){
                cout << angajati[i].nume << "," << angajati[i].functie << "," << angajati[i].inceputMunca << "," << angajati[i].sfarsitMunca << endl;
            }
        }

        void displayProducts(){
            for (int i = 0; i < nrProduse; i++){
                cout << i+1  << "," << produse[i].nume << "," << produse[i].pret << endl;
            }
        }

        void placeorder(){
            displayProducts();
            cout << "Comanda:numarul produsului/cantitate" << endl;
            cout << "Introduceti numarul produsului si cantitatea: ";
            int numar,cantitate;
            cin >> numar >> cantitate;

            int total = 0;
            for (int i = 0; i < nrProduse; i++){
                if (numar == i+1){
                    total = stoi(produse[i].pret) * cantitate;
                    cout << "Total: " << total << endl;
                }
            }

            ofstream file;
            file.open("comenzi.csv", ios::app);
            string line = locatie + "," + produse[numar-1].nume + "," + to_string(cantitate) + "," + to_string(total);
            file << line << endl;
        }

        void clear(){
            nrAngajati = 0;
            nrProduse = 0;
        }

};
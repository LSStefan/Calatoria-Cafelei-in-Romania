#include <iostream>
#include <fstream>
#include <sstream>
#include "angajat.h"
#include "produs.h"
#include <vector>

using namespace std;

class Cafenea{
    public:
        Angajat angajati[20];
        Produs produse[20];
        int nrAngajati = 0;
        int nrProduse = 0;
        string locatie;
        vector<string> evenimente;

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
                cout << i+1  << "." << produse[i].nume << "," << produse[i].pret << endl;
            }
        }

       float placeorder(string name) {
            displayProducts();
            cout << "Comanda: Introduceti numarul produsului si cantitatea sau 'x' pentru iesire." << endl;

            int numar, cantitate;
            int total = 0;
            string fullOrder = name + ","; // Inițializare linie completă cu numele clientului

            while (true) {
                cout << "Numar produs si cantitate: ";
                string input;
                cin >> input;

                if (input == "x") {
                    break; // Iesire din buclă
                }

                try {
                    // Parsează numărul produsului și cantitatea
                    numar = stoi(input);
                    cin >> cantitate;

                    // Validare intrări
                    if (numar < 1 || numar > nrProduse) {
                        cout << "Numar produs invalid. Incercati din nou." << endl;
                        continue;
                    }
                    if (cantitate <= 0) {
                        cout << "Cantitate invalida. Incercati din nou." << endl;
                        continue;
                    }

                    // Calculează totalul pentru produsul selectat
                    int subtotal = stoi(produse[numar - 1].pret) * cantitate;
                    total += subtotal;

                    // Adaugă detaliile produsului în linia completă
                    fullOrder += produse[numar - 1].nume + ":" + to_string(cantitate) + ":" + to_string(subtotal) + ";";

                    cout << "Produs adaugat: " << produse[numar - 1].nume << ", Cantitate: " << cantitate 
                        << ", Subtotal: " << subtotal << endl;
                } catch (const invalid_argument&) {
                    cout << "Intrare invalida. Incercati din nou." << endl;
                }
            }

            // Adaugă totalul comenzii la finalul liniei
            fullOrder += "Total:" + to_string(total);

            // Scrie comanda întreagă în fișier
            if (total > 0) {
                ofstream file("comenzi.csv", ios::app);
                file << fullOrder << endl;
                file.close();
            }

            cout << "Total comanda: " << total << endl;
            return total;
        }


        void clear(){
            nrAngajati = 0;
            nrProduse = 0;
        }

        void addSpecialEvent(){
            string event;
            cout << "Introduceti evenimentul special: ";
            getline(cin >> ws, event);
            evenimente.push_back(event);
            ofstream file;
            file.open("evenimente.csv", ios::app);
            file << this->locatie << "," << event << endl;
            file.close();
        }

};
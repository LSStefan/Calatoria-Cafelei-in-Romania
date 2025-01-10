#include <iostream>
#include <fstream>
#include <sstream>
#include "angajat.h"
#include "produs.h"
#include "utilizator.h"
#include <vector>

using namespace std;

class Cafenea{
    public:
        Angajat angajati[20];
        Produs produse[20];
        int nrAngajati = 0;
        int nrManageri = 0;
        int nrOspatari = 0;
        int nrBarista = 0;
        int nrProduse = 0;
        string locatie;
        vector<string> evenimente;

    private :
        static Cafenea *instance;  // Singleton
        Cafenea(){  //constructor privat
        }


    public:
    // Singleton design pattern
        static Cafenea* getInstance(){
            if (!instance){
                instance = new Cafenea();
            }
            return instance;
        }
        Cafenea(string locatie){
            this->locatie = locatie;
        }
        void angajeaza(Angajat angajat){
            angajati[nrAngajati] = angajat;
            nrAngajati++;
            if(angajat.functie == "Manager"){
                nrManageri++;
            } else if(angajat.functie == "Ospatar"){
                nrOspatari++;
            } else if(angajat.functie == "Barista"){
                nrBarista++;
            }
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

       float placeorder(Utilizator user) {
            displayProducts();
            cout << "Comanda: Introduceti numarul produsului si cantitatea sau 'x' pentru iesire." << endl;

            int numar, cantitate;
            float total = 0.0f;
            string fullOrder = user.getNume() + ","; 

            while (true) {
                cout << "Numar produs si cantitate: ";
                string input;
                cin >> input;

                if (input == "x") {
                    break;
                }

                try {
                    // Parseaza numarul si cantitatea
                    numar = stoi(input);
                    cin >> cantitate;

                    if (numar < 1 || numar > nrProduse) {
                        cout << "Numar produs invalid. Incercati din nou." << endl;
                        continue;
                    }
                    if (cantitate <= 0 || cantitate > produse[numar - 1].cantitate) {
                        cout << "Cantitate invalida. Incercati din nou." << endl;
                        continue;
                    }

                    float subtotal = stof(produse[numar - 1].pret) * cantitate;
                    total += subtotal;

                    fullOrder += produse[numar - 1].nume + ":" + to_string(cantitate) + ":" + to_string(subtotal) + ";";

                    // Actualizeaza cantitatea produsului
                    produse[numar - 1].cantitate -= cantitate;

                    cout << "Produs adaugat: " << produse[numar - 1].nume << ", Cantitate: " << cantitate
                        << ", Subtotal: " << subtotal << endl;
                } catch (const invalid_argument&) {
                    cout << "Intrare invalida. Incercati din nou." << endl;
                }
            }

            fullOrder += "Total:" + to_string(total);

            // Scrie comanda întreaga în fisier
            if (total > 0) {
                ofstream file("comenzi.csv", ios::app);
                file << fullOrder << endl;
                file.close();
            }

            //reducere client fidel
            if (user.returneazaNrComenzi() > 3) {
                cout << "Felicitari! Ai primit un voucher de 10% reducere pentru ca esti client fidel." << endl;
                total -= total * 0.1;
            }
             //actualizare stoc
            ifstream file("produse.csv");
            ofstream tempFile("temp.csv");

            if (!file.is_open() || !tempFile.is_open()) {
                cerr << "Eroare la deschiderea fisierului pentru actualizare." << endl;
                return total;
            }

            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string oras, tip, numeProdus, pret;
                int cantitateDisponibila;

                getline(ss, oras, ',');
                getline(ss, tip, ',');
                getline(ss, numeProdus, ',');
                getline(ss, pret, ',');
                ss >> cantitateDisponibila;

                if (oras == this->locatie && numeProdus == produse[numar - 1].nume) {
                    tempFile << oras << "," << tip << "," << numeProdus << "," << pret << "," << produse[numar - 1].cantitate << endl;
                } else {
                    tempFile << oras << "," << tip << "," << numeProdus << "," << pret << "," << cantitateDisponibila << endl;
                }
            }

            file.close();
            tempFile.close();

            remove("produse.csv");
            rename("temp.csv", "produse.csv");

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

        void addProduct(){
            string nume, pret,categorie;
            int cantitate;
            cout << "Introduceti categoria produsului:(Cafea, Ceai, Dulciuri, Sandwichuri) ";
            cin >> categorie;
            cout << "Introduceti numele produsului: ";
            getline(cin >> ws, nume);
            cout << "Introduceti pretul produsului: ";
            cin >> pret;
            cout << "Introduceti cantitatea produsului: ";
            cin >> cantitate;
            Produs produs(this->locatie, nume, pret,cantitate);
            adaugaProdus(produs);
            ofstream file;
            file.open("produse.csv", ios::app);
            file << this->locatie << "," << categorie << "," << nume << "," << pret << "," << cantitate <<  endl;
            file.close();
        }

        void removeProduct() {
            string nume;
            cout << "Introduceti numele produsului pe care doriti sa il stergeti: ";
            getline(cin >> ws, nume);

            ifstream file("produse.csv");
            ofstream tempFile("temp.csv");

            if (!file.is_open() || !tempFile.is_open()) {
                cerr << "Eroare la deschiderea fisierului!" << endl;
                return;
            }

            string line;
            bool found = false;

            while (getline(file, line)) {
                stringstream ss(line);
                string oras, tip, numeFisier, pret, cantitate;

                getline(ss, oras, ',');
                getline(ss, tip, ',');
                getline(ss, numeFisier, ',');
                getline(ss, pret, ',');
                getline(ss, cantitate, ',');

                if (!(numeFisier == nume && oras == this->locatie)) {
                    tempFile << oras << "," << tip << "," << numeFisier << "," << pret << "," << cantitate << endl;
                } else {
                    found = true;
                }
            }

            file.close();
            tempFile.close();

            // Suprascriem fisierul original
            if (found) {
                remove("produse.csv");
                rename("temp.csv", "produse.csv");
                cout << "Produsul a fost sters cu succes." << endl;
            } else {
                cout << "Produsul nu a fost gasit in locatie." << endl;
                remove("temp.csv");
            }
        }

         //destructor
        ~Cafenea(){
            delete this;
        }

};
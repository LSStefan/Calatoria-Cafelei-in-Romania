#include <iostream>
#include <fstream>
#include <sstream>
#include "angajat.h"

using namespace std;

class Cafenea{
    private:
        Angajat angajati[3];
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

        void displayEmployees(string locatie){
            ifstream file;
            file.open("angajati.csv");
            string line;
            while (getline(file, line))
            {
                string oras = line.substr(0, line.find(","));
                
                if (oras == locatie) {
                    stringstream ss(line);
                    string oras, nume, functie, inceputMunca, sfarsitMunca;

                    getline(ss, oras, ',');           // Extrage orașul
                    getline(ss, nume, ',');          // Extrage numele
                    getline(ss, functie, ',');       // Extrage funcția
                    getline(ss, inceputMunca, ',');  // Extrage ora de început
                    getline(ss, sfarsitMunca, ',');  // Extrage ora de sfârșit

                    cout << nume << "," << functie << "," << inceputMunca << "," << sfarsitMunca << endl;
                }
            }
        }
};
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

        void removeEmployee(){
            string nume;
            cout << "Introduceti numele angajatului pe care doriti sa il stergeti: ";
            getline(cin >> ws, nume);
            ifstream file;
            ofstream tempFile;
            file.open("angajati.csv");
            tempFile.open("temp.csv");
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string oras, numeFisier, functie, inceputMunca, sfarsitMunca;
                getline(ss, oras, ',');      
                getline(ss, numeFisier, ',');       
                getline(ss, functie, ',');   
                getline(ss, inceputMunca, ','); 
                getline(ss, sfarsitMunca, ',');  
                if (numeFisier != nume){
                    tempFile << oras << "," << numeFisier << "," << functie << "," << inceputMunca << "," << sfarsitMunca << endl;
                }
            
            }
            file.close();
            tempFile.close();
            remove("angajati.csv");
            rename("temp.csv", "angajati.csv");
        }

};
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>

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
                    getline(ss, oras, ',');        
                    getline(ss, nume, ',');         
                    getline(ss, functie, ',');
                    getline(ss, inceputMunca, ','); 
                    getline(ss, sfarsitMunca, ',');

                    cout << nume << "," << functie << "," << inceputMunca << "," << sfarsitMunca << endl;
                }
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
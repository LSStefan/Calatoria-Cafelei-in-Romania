#include <iostream>
using namespace std;

#ifndef ANGAJAT_H
#define ANGAJAT_H
class Angajat{
    public:
        string nume;
        string functie;
        string inceputMunca;
        string sfarsitMunca;

    public:
        Angajat(){
            nume = "";
            functie = "";
            inceputMunca = "";
            sfarsitMunca = "";
        }
        //encapsulare
        Angajat(string nume, string functie, string inceputMunca, string sfarsitMunca){
            this->nume = nume;
            this->functie = functie;
            this->inceputMunca = inceputMunca;
            this->sfarsitMunca = sfarsitMunca;
        }
};
#endif
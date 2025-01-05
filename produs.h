#include <iostream>

using namespace std;

#ifndef PRODUS_H
#define PRODUS_H
class Produs{
    public:
        string oras;
        string nume;
        string pret;
        int cantitate = 0;

    public:
        Produs(){
            oras = "";
            nume = "";
            pret = "";
        }
        Produs(string oras, string nume, string pret, int cantitate){
            this->oras = oras;
            this->nume = nume;
            this->pret = pret;
            this->cantitate = cantitate;
        }
        
};

#endif
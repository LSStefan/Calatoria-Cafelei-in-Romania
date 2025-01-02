#include <iostream>
using namespace std;

class Angajat{
    private:
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
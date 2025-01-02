#include <iostream>
#include "angajat.h"

using namespace std;

class Cafenea{
    private:
        Angajat angajati[3];
        int nrAngajati = 0;
        string locatie;

    public:
        Cafenea(string locatie){
            this->locatie = locatie;
        }
        void angajeaza(Angajat angajat){
            angajati[nrAngajati] = angajat;
            nrAngajati++;
        }

        void prezintaAngajatii(){
            for(int i = 0; i < nrAngajati; i++){
                angajati[i].hello();
            }
        }
};
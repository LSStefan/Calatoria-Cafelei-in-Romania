#include <iostream>
#include "angajat.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

int choose_language(int &choice){
    cout << "Alege limba / Choose language: " << endl;
    cout << "1. Romana" << endl;
    cout << "2. English" << endl;

    cin >> choice;
    return choice;
}


void menu(int isRomanian) {
    system("clear"); 
    switch(isRomanian){
        case 1:
           cout << 'Alege cafeneaua dorita: ' << endl;
              cout << "1.Bucuresti" << endl;
                cout << "2.Cluj" << endl;
                cout << "3.Iasi" << endl;
                cout << "4.Timisoara" << endl;
                cout << "5.Brasov" << endl;

        case 2:
            cout << "Choose the desired coffee shop: " << endl;
            cout << "1.Bucuresti" << endl;
            cout << "2.Cluj" << endl;
            cout << "3.Iasi" << endl;
            cout << "4.Timisoara" << endl;
            cout << "5.Brasov" << endl;
    }

    int oras;
    cin >> oras;

    switch(isRomanian){
        case 1:
            cout << "1.Adauga angajat" << endl;
            cout << "2.Afiseaza angajatii" << endl;
            cout << "3.Afiseaza produsele" << endl;
            cout << "4.Iesire" << endl;
        
        case 2:
            cout << "1.Add employee" << endl;
            cout << "2.Display employees" << endl;
            cout << "3.Display products" << endl;
            cout << "4.Exit" << endl;
    }
    


}


int main(){

    int choice;
    choose_language(choice);
    menu(choice);

    return 0;
}
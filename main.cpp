#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "cafenea.h"
#include "manager.h"
#include "utilizator.h"

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

    // Selectarea rolului
    if(isRomanian == 1){
        cout << "==================================" << endl;
        cout << "          Selectati rolul          " << endl;
        cout << "==================================" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Angajat" << endl;
    } else {
        cout << "==================================" << endl;
        cout << "          Select the role          " << endl;
        cout << "==================================" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Employee" << endl;
    }

    int role;
    cin >> role;

    if(role == 1){
        system("clear");
        cout << "==================================" << endl;
        if(isRomanian == 1){
            cout << "          Autentificare            " << endl;
            cout << "==================================" << endl;
            cout << "Introduceti numele de utilizator: ";
        } else {
            cout << "==================================" << endl;
            cout << "          Authentication          " << endl;
            cout << "==================================" << endl;
            cout << "Enter the username: ";
        }
        string username;
        cin >> username;

        cout << "Introduceti parola: ";
        string password;
        cin >> password;

        if (username != "admin" || password != "admin") {
            cout << "Autentificare esuata! Incercati din nou." << endl;
            return;
        }

        system("clear");
    }else{
        Utilizator user;
        cout << "==================================" << endl;
        cout << "          Autentificare            " << endl;
        cout << "==================================" << endl;
        cout << "1.Sign up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Select an option: ";

        int optiune;
        cin >> optiune;

        switch(optiune){
            case 1:
                user.createAccount();
                break;
            case 2:  //Exceptions
                try{
                    user.login();
                } catch (const char* msg){
                    cout << msg << endl;
                    return;
                }
                break;
        }

    }

    // Selectarea orasului
    cout << "==================================" << endl;
    if (isRomanian == 1) {
        cout << "        Alege cafeneaua dorita     " << endl;
        cout << "==================================" << endl;
        cout << "1. Bucuresti" << endl;
        cout << "2. Cluj-Napoca" << endl;
        cout << "3. Iasi" << endl;
        cout << "4. Timisoara" << endl;
        cout << "5. Brasov" << endl;
    } else {
        cout << "    Choose the desired coffee shop " << endl;
        cout << "==================================" << endl;
        cout << "1. Bucuresti" << endl;
        cout << "2. Cluj-Napoca" << endl;
        cout << "3. Iasi" << endl;
        cout << "4. Timisoara" << endl;
        cout << "5. Brasov" << endl;
    }
    cout << "==================================" << endl;
    cout << "Selectati o optiune: ";

    int oras;
    cin >> oras;

    string nume_oras;
    switch (oras) {
        case 1: nume_oras = "Bucuresti"; break;
        case 2: nume_oras = "Cluj-Napoca"; break;
        case 3: nume_oras = "Iasi"; break;
        case 4: nume_oras = "Timisoara"; break;
        case 5: nume_oras = "Brasov"; break;
        default:
            cout << "Optiune invalida! Incercati din nou." << endl;
            return;
    }

    system("clear");

    // Meniu principal
    cout << "==================================" << endl;
    if (isRomanian == 1) {
        cout << "          Meniu principal          " << endl;
        cout << "==================================" << endl;
        cout << "1. Adauga angajat" << endl;
        cout << "2. Afiseaza angajatii" << endl;
        cout << "3. Afiseaza produsele" << endl;
        cout << "4. Iesire" << endl;
        cout << "5. Inapoi" << endl;
    } else {
        cout << "          Main Menu                " << endl;
        cout << "==================================" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Display employees" << endl;
        cout << "3. Display products" << endl;
        cout << "4. Exit" << endl;
        cout << "5. Back" << endl;
    }
    cout << "==================================" << endl;
    cout << "Select an option: ";

    int optiune;
    cin >> optiune;

    // Gestionarea optiunilor
    switch (optiune) {
        case 1:
            if(role == 1){
            Manager manager;
            manager.addEmployee();
            } else {
                cout << "Utilizatorul nu are permisiunea de a adauga angajati." << endl;
            }
            break;
        case 2: {
            Cafenea cafenea;
            cafenea.displayEmployees(nume_oras);
            break;
        }
        case 3:
            cout << "Functionalitatea pentru a afisa produsele nu este implementata inca." << endl;
            break;
        case 4:
            cout << "Iesire din aplicatie. La revedere!" << endl;
            return;
        case 5:
            menu(isRomanian);
            break;
        default:
            cout << "Optiune invalida! Incercati din nou." << endl;
    }
}




int main(){

    int choice;
    choose_language(choice);
    menu(choice);

    return 0;
}
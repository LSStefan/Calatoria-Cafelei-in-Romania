#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "cafenea.h"
#include "manager.h"
#include "utilizator.h"

using namespace std;


Cafenea bucuresti("Bucuresti");
Cafenea cluj("Cluj-Napoca");
Cafenea iasi("Iasi");
Cafenea timisoara("Timisoara");
Cafenea brasov("Brasov");


void startup(){
    ifstream file;
    file.open("angajati.csv");
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string oras;
        getline(ss, oras, ',');
        string nume, functie, inceputMunca, sfarsitMunca;
        getline(ss, nume, ',');
        getline(ss, functie, ',');
        getline(ss, inceputMunca, ',');
        getline(ss, sfarsitMunca, ',');
        if(oras == "Bucuresti"){
            Angajat angajat(nume, functie, inceputMunca, sfarsitMunca);
            bucuresti.angajeaza(angajat);
        } else if(oras == "Cluj-Napoca"){
            Angajat angajat(nume, functie, inceputMunca, sfarsitMunca);
            cluj.angajeaza(angajat);
        } else if(oras == "Iasi"){
            Angajat angajat(nume, functie, inceputMunca, sfarsitMunca);
            iasi.angajeaza(angajat);
        } else if(oras == "Timisoara"){
            Angajat angajat(nume, functie, inceputMunca, sfarsitMunca);
            timisoara.angajeaza(angajat);
        } else if(oras == "Brasov"){
            Angajat angajat(nume, functie, inceputMunca, sfarsitMunca);
            brasov.angajeaza(angajat);
        }
    }
}


int choose_language(int &choice){
    cout << "Alege limba / Choose language: " << endl;
    cout << "1. Romanian" << endl;
    cout << "2. English" << endl;
    cout << "Select an option: ";

    cin >> choice;
    return choice;
}


Cafenea cafenea;

void menu(int isRomanian) {
    system("clear");

    // Selectarea rolului
    if(isRomanian == 1){
        cout << "==================================" << endl;
        cout << "          Selectati rolul          " << endl;
        cout << "==================================" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Utilizator" << endl;
        cout << "Selectati un rol: ";
    } else {
        cout << "==================================" << endl;
        cout << "          Select the role          " << endl;
        cout << "==================================" << endl;
        cout << "1. Manager" << endl;
        cout << "2. User" << endl;  
        cout << "Select a role: ";
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
        system("clear");
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
                try{
                    user.createAccount();
                } catch (const char* msg){
                    cout << msg << endl;
                    return;
                }
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
        
        system("clear");
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
        cout << "4. Sterge angajat" << endl;
        cout << "5. Iesire" << endl;
        cout << "6. Inapoi" << endl;
    } else {
        cout << "          Main Menu                " << endl;
        cout << "==================================" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Display employees" << endl;
        cout << "3. Display products" << endl;
        cout << "4. Remove employee" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Back" << endl;
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
        case 2: 
            if(nume_oras == "Bucuresti"){
                bucuresti.displayEmployees(bucuresti.angajati, bucuresti.nrAngajati);
            } else if(nume_oras == "Cluj-Napoca"){
                cluj.displayEmployees(cluj.angajati, cluj.nrAngajati);
            } else if(nume_oras == "Iasi"){
                iasi.displayEmployees(iasi.angajati, iasi.nrAngajati);
            } else if(nume_oras == "Timisoara"){
                timisoara.displayEmployees(timisoara.angajati, timisoara.nrAngajati);
            } else if(nume_oras == "Brasov"){
                brasov.displayEmployees(brasov.angajati, brasov.nrAngajati);
            }
            break;
        case 3:
            cafenea.displayProducts(nume_oras);
            break;
        case 4:
            if(role == 1){
                Manager manager;
                manager.removeEmployee(nume_oras);
            }else{
                cout << "Utilizatorul nu are permisiunea de a sterge angajati." << endl;
            }
            break;
        case 5:
            menu(isRomanian);
            break;
        default:
            cout << "Optiune invalida! Incercati din nou." << endl;
    }
}




int main(){

    startup();
    int choice;
    choose_language(choice);
    menu(choice);

    


    return 0;
}
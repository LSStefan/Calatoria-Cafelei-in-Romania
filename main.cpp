#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "headere/cafenea.h"
#include "headere/manager.h"
#include "headere/utilizator.h"
#include "headere/produs.h"

using namespace std;

//instantierea obiectelor de tip cafenea folosind Singleton
Cafenea bucuresti("Bucuresti");
Cafenea cluj("Cluj-Napoca");
Cafenea iasi("Iasi");
Cafenea timisoara("Timisoara");
Cafenea brasov("Brasov");

Utilizator user;


int profit_zilnic = 0;

// Generarea raportului



void generareRaport(){
    int isRomanian;
    cout << "Alege limba in care vrei sa exportezi raportul/ Choose the language in which you want to export the report: " << endl;
    cout << "1. Romanian" << endl;
    cout << "2. English" << endl;
    cout << "Select an option: ";
    cin >> isRomanian;
    if(isRomanian == 1){
        ofstream file;
        file.open("raport.csv", ios::app);
        file << "Profit zilnic: " << profit_zilnic << endl;
        int salariiangajati;
        if(bucuresti.nrAngajati > 0){
            salariiangajati = bucuresti.nrManageri * 4000  + bucuresti.nrOspatari * 2500 + bucuresti.nrBarista * 2500;
            file << "Salarii angajati Bucuresti: " << salariiangajati << endl;
        }
        if(cluj.nrAngajati > 0){
            salariiangajati = cluj.nrManageri * 3200 + cluj.nrOspatari * 2500 + cluj.nrBarista * 2500;
            file << "Salarii angajati Cluj-Napoca: " << salariiangajati << endl;
        }
        if(iasi.nrAngajati > 0){
            salariiangajati = iasi.nrManageri * 3500 + iasi.nrOspatari * 2500 + iasi.nrBarista * 2500;
            file << "Salarii angajati Iasi: " << salariiangajati << endl;
        }
        if(timisoara.nrAngajati > 0){
            salariiangajati = timisoara.nrManageri * 3000 + timisoara.nrOspatari * 2500 + timisoara.nrBarista * 2500;
            file << "Salarii angajati Timisoara: " << salariiangajati << endl;
        }
        if(brasov.nrAngajati > 0){
            salariiangajati = brasov.nrManageri * 3500 + brasov.nrOspatari * 2500 + brasov.nrBarista * 2500;
            file << "Salarii angajati Brasov: " << salariiangajati << endl;
        }
        file << "\n \n";
        file.close();
    }else{
        ofstream file;
        file.open("raport.csv", ios::app);
        file << "Daily profit: " << profit_zilnic << endl;
        int salariiangajati;
        if(bucuresti.nrAngajati > 0){
            salariiangajati = bucuresti.nrManageri * 4000  + bucuresti.nrOspatari * 2500 + bucuresti.nrBarista * 2500;
            file << "Salaries Bucuresti: " << salariiangajati << endl;
        }
        if(cluj.nrAngajati > 0){
            salariiangajati = cluj.nrManageri * 3200 + cluj.nrOspatari * 2500 + cluj.nrBarista * 2500;
            file << "Salaries Cluj-Napoca: " << salariiangajati << endl;
        }
        if(iasi.nrAngajati > 0){
            salariiangajati = iasi.nrManageri * 3500 + iasi.nrOspatari * 2500 + iasi.nrBarista * 2500;
            file << "Salaries Iasi: " << salariiangajati << endl;
        }
        if(timisoara.nrAngajati > 0){
            salariiangajati = timisoara.nrManageri * 3000 + timisoara.nrOspatari * 2500 + timisoara.nrBarista * 2500;
            file << "Salaries Timisoara: " << salariiangajati << endl;
        }
        if(brasov.nrAngajati > 0){
            salariiangajati = brasov.nrManageri * 3500 + brasov.nrOspatari * 2500 + brasov.nrBarista * 2500;
            file << "Salaries Brasov: " << salariiangajati << endl;
        }
        file << "\n \n";
        file.close();
    }
    
}

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
    file.close();
    ifstream file2;
    file2.open("produse.csv");
    while(getline(file2,line)){
        stringstream ss(line);
        string oras, tip, nume, pret;
        getline(ss, oras, ',');
        getline(ss, tip, ',');
        getline(ss, nume, ',');
        getline(ss, pret, ',');
        Produs produs(oras, nume, pret,10);
        if(oras == "Bucuresti"){
            bucuresti.adaugaProdus(produs);
        } else if(oras == "Cluj-Napoca"){
            cluj.adaugaProdus(produs);
        } else if(oras == "Iasi"){
            iasi.adaugaProdus(produs);
        } else if(oras == "Timisoara"){
            timisoara.adaugaProdus(produs);
        } else if(oras == "Brasov"){
            brasov.adaugaProdus(produs);
        }
    }

    file2.close();
}



int choose_language(int &choice){
    cout << "Alege limba / Choose language: " << endl;
    cout << "1. Romanian" << endl;
    cout << "2. English" << endl;
    cout << "Select an option: ";

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
        cout << "==================================" << endl;
        cout << "          Autentificare            " << endl;
        cout << "==================================" << endl;
        cout << "1. Sign up" << endl;
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
    while(true){
        cout << "==================================" << endl;
        if (isRomanian == 1) {
            cout << "          Meniu principal          " << endl;
            cout << "==================================" << endl;
            cout << "1. Adauga angajat" << endl;
            cout << "2. Afiseaza angajatii" << endl;
            cout << "3. Afiseaza produsele" << endl;
            cout << "4. Sterge angajat" << endl;
            cout << "5. Comanda" << endl;
            cout << "6. Adauga eveniment special" << endl;
            cout << "7. Iesire si generare raport" << endl;
            cout << "8. Inapoi" << endl;
            cout << "9.Adauga produs" << endl;
            cout << "10. Sterge produs" << endl;

            
        } else {
            cout << "          Main Menu                " << endl;
            cout << "==================================" << endl;
            cout << "1. Add employee" << endl;
            cout << "2. Display employees" << endl;
            cout << "3. Display products" << endl;
            cout << "4. Remove employee" << endl;
            cout << "5. Order" << endl;
            cout << "6. Add special event" << endl;
            cout << "7. Exit and generate daily raport" << endl;
            cout << "8. Back" << endl;
            cout << "9. Add product" << endl;
            cout << "10. Remove product" << endl;
            
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
                startup();
                } else {
                    cout << "Utilizatorul nu are permisiunea de a adauga angajati." << endl;
                }
                break;
            case 2: 
                if(nume_oras == "Bucuresti"){
                    bucuresti.displayEmployees();
                } else if(nume_oras == "Cluj-Napoca"){
                    cluj.displayEmployees();
                } else if(nume_oras == "Iasi"){
                    iasi.displayEmployees();
                } else if(nume_oras == "Timisoara"){
                    timisoara.displayEmployees();
                } else if(nume_oras == "Brasov"){
                    brasov.displayEmployees();
                }
                break;
            case 3:
                if(nume_oras == "Bucuresti"){
                    bucuresti.displayProducts();
                } else if(nume_oras == "Cluj-Napoca"){
                    cluj.displayProducts();
                } else if(nume_oras == "Iasi"){
                    iasi.displayProducts();
                } else if(nume_oras == "Timisoara"){
                    timisoara.displayProducts();
                } else if(nume_oras == "Brasov"){
                    brasov.displayProducts();
                }
                break;
            case 4:
                if(role == 1){
                    Manager manager;
                    manager.removeEmployee();
                }else{
                    cout << "Utilizatorul nu are permisiunea de a sterge angajati." << endl;
                }
                break;
            case 5:
                if(nume_oras == "Bucuresti"){
                    profit_zilnic += bucuresti.placeorder(user);
                } else if(nume_oras == "Cluj-Napoca"){
                    profit_zilnic += cluj.placeorder(user);
                } else if(nume_oras == "Iasi"){
                    profit_zilnic += iasi.placeorder(user);
                } else if(nume_oras == "Timisoara"){
                    profit_zilnic += timisoara.placeorder(user);
                } else if(nume_oras == "Brasov"){
                    profit_zilnic += brasov.placeorder(user);
                }
                user.comenziPlus();
                break;
            case 6:
                if(role == 1){
                    if(nume_oras == "Bucuresti"){
                        bucuresti.addSpecialEvent();
                    } else if(nume_oras == "Cluj-Napoca"){
                        cluj.addSpecialEvent();
                    } else if(nume_oras == "Iasi"){
                        iasi.addSpecialEvent();
                    } else if(nume_oras == "Timisoara"){
                        timisoara.addSpecialEvent();
                    } else if(nume_oras == "Brasov"){
                        brasov.addSpecialEvent();
                    }
                } else {
                    cout << "Utilizatorul nu are permisiunea de a adauga evenimente speciale." << endl;
                }
                return;
            case 7:
                cout << "Profitul zilnic este: " << profit_zilnic << endl;
                generareRaport();
                return;
            case 8:
                system("clear");
                menu(isRomanian);
                break;
            case 9:
                if(role == 1){
                    if(nume_oras == "Bucuresti"){
                        bucuresti.addProduct();
                    } else if(nume_oras == "Cluj-Napoca"){
                        cluj.addProduct();
                    } else if(nume_oras == "Iasi"){
                        iasi.addProduct();
                    } else if(nume_oras == "Timisoara"){
                        timisoara.addProduct();
                    } else if(nume_oras == "Brasov"){
                        brasov.addProduct();
                    }
                } else {
                    cout << "Utilizatorul nu are permisiunea de a adauga produse." << endl;
                }
                break;
            case 10:
                if(role == 1){
                    if(nume_oras == "Bucuresti"){
                        bucuresti.removeProduct();
                    } else if(nume_oras == "Cluj-Napoca"){
                        cluj.removeProduct();
                    } else if(nume_oras == "Iasi"){
                        iasi.removeProduct();
                    } else if(nume_oras == "Timisoara"){
                        timisoara.removeProduct();
                    } else if(nume_oras == "Brasov"){
                        brasov.removeProduct();
                    }
                    startup();
                } else {
                    cout << "Utilizatorul nu are permisiunea de a sterge produse." << endl;
                }
                break;
            default:
                cout << "Optiune invalida! Incercati din nou." << endl;
        }
    }
    
    
}




int main(){

    startup();
    int choice;
    choose_language(choice);
    menu(choice);

    return 0;
}
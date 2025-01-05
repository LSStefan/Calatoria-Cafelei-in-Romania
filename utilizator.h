#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;


string passwordStrength(string password){
    int n = password.length();
    bool hasLower = false, hasUpper = false, hasDigit = false, specialChar = false;
    string specialChars = "!@#$%^&*()-+";
    for (int i = 0; i < n; i++){
        if (islower(password[i])){
            hasLower = true;
        }
        if (isupper(password[i])){
            hasUpper = true;
        }
        if (isdigit(password[i])){
            hasDigit = true;
        }
        if (specialChars.find(password[i]) != string::npos){
            specialChar = true;
        }
    }
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8)){
        return "Strong";
    }
    if ((hasLower || hasUpper) && hasDigit && (n >= 6)){
        return "Moderate";
    }
    return "Weak";
}


string key = "NWLRB";


string encrypt(string str, string key)
{
    string cipher_text;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        char x = (str[i] + key[i]) % 26;

        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}



class Utilizator{
    private:
        string nume;
        string parola;
        int nrComenzi = 0;

    public:

        void createAccount(){
            ofstream passwordFile;
            ifstream passwordFileCheck;
            ofstream keyFile;
            passwordFile.open("passwords.csv",ios::app);
            passwordFileCheck.open("passwords.csv");
            cout << "Introduceti numele de utilizator: ";
            cin >> nume;
            this->nume = nume;
            string line;

            while(getline(passwordFileCheck, line)){
                stringstream ss(line);
                string numeFisier;
                ss >> numeFisier;
                if (numeFisier == nume){
                    throw "Utilizatorul exista deja!";
                }
            }

            cout << "Introduceti parola: ";
            cin >> parola;
            string strength = passwordStrength(parola);  //verific daca parola e puternica
            if (strength == "Weak"){
                throw "Parola prea slaba!";
            }
            parola = encrypt(parola, key);
            passwordFile << nume << " " << parola << endl;
            passwordFile.close();
            this->nume = nume;
            this->parola = parola;
            cout << "Cont creat cu succes!" << endl;
        }

        void login(){
            ifstream passWordFile;
            ifstream keyFile;
            passWordFile.open("passwords.csv");

            string nume, parola;
            cout << "Introduceti numele de utilizator: ";
            cin >> nume;
            cout << "Introduceti parola: ";
            cin >> parola;
            parola = encrypt(parola, key);

            
            string line, fileName, filePassword;


            while (getline(passWordFile, line)) {
                stringstream ss(line); 
                getline(ss, fileName, ' '); 
                getline(ss, filePassword, ' ');

                if (fileName == nume){
                    if (filePassword == parola){
                        cout << "Logare reusita!" << endl;
                        return;
                    }
                    throw "Parola incorecta!";
                }
            }
            throw "Utilizatorul nu exista!";
        }
        //absractization
        virtual string getNume();

        void nrComenziPlus(){
            nrComenzi++;
        }
        int returneazaNrComenzi(){
            return nrComenzi;
        }

};

string Utilizator::getNume(){
    return nume;
}
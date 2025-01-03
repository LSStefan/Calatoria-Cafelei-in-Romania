#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayEmployees(string locatie)
{
    ifstream file;
    file.open("angajati.csv");
    string line;
    while (getline(file, line))
    {
        string oras = line.substr(0, line.find(","));
        
        if(oras == locatie)
        {
            cout << line << endl;
        }
    }
}

int main()
{
    displayEmployees("Cluj-Napoca");
    return 0;
}
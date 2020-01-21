#include <iostream>
using namespace std;

struct Address{
    int homeNumber;
    string city, state;
};

struct personalInfo{
    string name;
    int age;
    Address pAdress;
};

void printInfo(personalInfo* pI, int size, int pos);

int main(void){
    personalInfo* pData;
    int size = 0;

    cout << "Cantidad de datos a ingresar: ", cin >> size;
    pData = new personalInfo[size];

    for (int i = 0; i < size; i++){
        cout << "Nombre: "; cin >> pData[i].name;
        cout << "Edad: "; cin >> (pData + i)->age;
        cout << "No. casa: "; cin >> pData[i].pAdress.homeNumber;
        cin.ignore();
        cout << "Ciudad: "; cin >> (pData + i)->pAdress.city;
        cout << "Estado: "; cin >> (pData + i)->pAdress.state;
    }

    printInfo(pData, size, 0);

    return 0;
}

void printInfo(personalInfo* pI, int size, int pos){
    if(pos == size){
        return;
    }
    else{
        printInfo(pI, size, pos + 1);
        cout << "Nombre: " << pI[pos].name << endl;
        cout << "Edad: " << pI[pos].age << endl;
        cout << "No. casa: " << pI[pos].pAdress.homeNumber << endl;
        cout << "Ciudad: " << pI[pos].pAdress.city << endl;
        cout << "Estado: " << pI[pos].pAdress.state << endl;
    }
}
#include <iostream>
#include <string>
using namespace std;

struct datastudents{
    string name, report;
    float grade;
};

void fillArray(datastudents* array, int size, int aux);
void printArray(datastudents* array, int size, int aux);

int main(void){
    int size = 0;
    cin >> size;

    datastudents* students;
    students = new datastudents[size];

    fillArray(students, size, 0);
    fillArray(students,  size, 0);

    return 0;
}

void fillArray(datastudents* array, int size, int aux){
    if(size == aux){
        return;
    }
    else{
        cout << "Nombre: "; getline (cin, array[aux].name);
        cin.ignore();
        cout << "Comentarios: "; getline (cin, array[aux].report);
        cout << "Nota: "; cin >> array[aux].grade;
        cin.ignore();

        fillArray(array, size, aux + 1);
    }
}

void printArray(datastudents* array, int size, int aux){
    if(size == aux){
        return;
    }
    else{
        cout << "Nombre: " << array[aux].name;
        cout << "Comentarios: " << array[aux].report;
        cout << "Nota: " << array[aux].grade;
        cin.ignore();

        printArray(array, size, aux + 1);
    }
}
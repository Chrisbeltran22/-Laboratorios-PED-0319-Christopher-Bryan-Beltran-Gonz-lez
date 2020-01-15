#include <iostream>
#include <string>
using namespace std;

//Main function
int main(void){
	//Varible declarations
	string Company;
	string customersName;
	int customers = 0;
	
	//Pointer
	int *array;
	
	//Printing 
	cout << "Ingrese el nombre de la compania: "; 
	getline (cin, Company);
	cout << "Cuantos clientes desea agregar:\t";
	cin >> customers;
	
	//Creating new memory spaces
	array = new int[customers];
	
	//Running FOR cycle
	for (int i = 0; i < customers; i++){
		cout << "Cliente N." << (i + 1) << "\t";
		getline(cin, customersName);
		cin.ignore();
	}
	return 0;	
}


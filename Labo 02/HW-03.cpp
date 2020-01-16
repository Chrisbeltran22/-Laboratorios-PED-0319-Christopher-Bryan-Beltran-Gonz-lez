//
#include <iostream>
//
#include <string>
using namespace std;

//Struct
struct person{
	int DUI;
	string name;
	int hired;
	float monthlySalary;	
};

int salary(int size);
float proccess(int year, float salary);

//Main funtion
int main(){
	person total;
	int size = 0;
	
	//Printinfg on screen
	cout << "Determine a cuantos empleados ingresara al sistema: ";
	cin >> size;
	cin.ignore();
	
	//Initializing function 
	salary(size);
	return 0;
}

//Personal information function
int salary(int customers){
	person total;
	
	//Pointer
	int *array;
	
	//Creating new memory spaces
	array = new int[customers];
	
	//Running FOR cycle personal information
	for (int i = 0; i < customers; i++){
		cout << "Ingrese el nombre del empleado/a " << (i + 1) << ":\t";
		getline (cin, total.name);
		cout << "Ingrese el numero de DUI:\t";
		cin >> total.DUI;
		cout << "Ingrese el anio en el que fue contratado:\t";
		cin >> total.hired;
		cout << "Ingrese el salario mensual que recibe: $";
		cin >> total.monthlySalary;
		cin.ignore();
		
		//Initializing function
		proccess(total.hired, total.monthlySalary);
		
	}
	
	return 0;	
}

//Salary estimation function
float proccess(int year, float salary){
	float estimation = 0;
	int present = 0;
	int months = 0;
	
	//Subtraction of the present year with the year when the employee was hired 
	present = (2020 - year);
	
	//Multiplication of total of years working with number of the months of the year
	months = (12 * present);
	
	//Multiplication of total of months worked with the salary per month
	estimation = (months * salary);
	
	//Printing
	cout << "La estimacion del salario devengado en todos los anios que lleva trabajando es de $: " << endl;
	cout << estimation << endl;
	
	return 0;
}

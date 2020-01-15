#include <iostream>
#include <string>
using namespace std;

//Struct
struct person{
	string name, gender;
	float salary;
	int age;
	int workingLife;
	
};

int proccess(int age);

//Main funtion
int main(){	
	person information;
	int option = 0;
	
	cout << "Digite su nombre:\t";
	getline (cin, information.name);
	cout << "Ingrese su salario:\t";
	cin >> information.salary;
	cout << "Digite su edad:\t";
	cin >> information.age;
	cout << "Digite los anios que ha laborado:\t";
	cin >> information.workingLife;
	
	proccess(information.age);
	
	return 0;
}

int proccess( int age){
	int sexMale = 60;
	int sexFemale = 55;
	
	if(age >= 60){
		cout << "Si usted es hombre debe estar jubilado" << endl;;
	}
	else{
		cout << "Si usted es hombre aun no debe estar jubilado" << endl;
	}
	
	if(age >= 55){
		cout << "Si usted es Mujer Debe estar jubilada" << endl;;
	}
	else{
		cout << "Si usted es mujer un no debe estar jubilada" << endl;
	}
	
}



#include <iostream>
#include <string>
using namespace std;

//Struct
struct person{
	string name;
	int gender;
	float salary;
	int age;
	int workingLife;
	
};

//Prototipes
int proccessMale(int age, int workingLife);
int proccessFemale( int age, int workingLife);

//Main funtion
int main(){	
	person information;
	int option = 0;
	
	//Printing on screen
	cout << "Digite su nombre:\t";
	getline (cin, information.name);
	cout << "Genero:\n1- Masculino\n2- Femenino\n";
	cin >> information.gender;
	cout << "Ingrese su salario:\t";
	cin >> information.salary;
	cout << "Digite su edad:\t";
	cin >> information.age;
	cout << "Digite los anios que ha laborado:\t";
	cin >> information.workingLife;
	
	//Function to determinate retirement  
	if (information.gender == 1){
		proccessMale(information.age , information.workingLife);
	}
	else{
		proccessFemale(information.age, information.workingLife);
	}
	return 0;
}

//Proccess function
int proccessMale( int age, int workingLife){
	int sexMale = 60;
	int workingTime = 25;
	
	//Determinating men retirement
	if(age >= 60 && workingTime >= 25){
		cout << "Debe estar jubilado" << endl;;
	}
	else{
		cout << "Aun no debe estar jubilado\nEdad minima para jubilarse es 60 anios\nAnios de trabajo minimos son 25" << endl;
	}
}

int proccessFemale( int age, int workingLife){
	int sexFemale = 55;
	int workingTime = 25;
	
	//Determinating women retirement 
	if(age >= 55 && workingTime >= 25){
		cout << "Debe estar jubilada" << endl;;
	}
	else{
		cout << "Aun no debe estar jubilada\nEdad minima para jubilarse es 55 anios\nAnios de trabajo minimos son 25" << endl;
	}
	
}

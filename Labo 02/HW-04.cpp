#include <iostream>
#include <math.h>
using namespace std;

//Struct
struct proccess{
	int first;
	int second;
	int third;
	float squareRoot;
	float sumatory;
	float subtract;
		
};

//Prototipe
int root(int a, int b, int c);
float lastPart(float squareResult, int a, int b);

//Main funtion
int main(){
	proccess value;
	
	//Printing 
	cout << "Ingrese los valores de 'a', 'b' y 'c' \n";
	cout << "Notas:\n- El valor de 'a' o 'c' no pueden ser mayor al valor 'b'";
	cout << "\n- El valor 'a' no puede ser igual a cero\n- El valor 'a' o 'c' deben ser iguales o uno mayor al otro" << endl;
	cout << "Valor de a:\t"; cin >> value.first;
	cout << "Valor de b:\t"; cin >> value.second;
	cout << "Valor de c:\t"; cin >> value.third;
	
	//Declaring root function
	root(value.first, value.second, value.third);
	
	return 0;
}

//root function
int root(int a, int b, int c){
	proccess result;
	int squareNumber;
	int multiplication;
	int final;
	
	
	//Determinating values
	if (a == 0 || a > b ){
		cout << "El valor de 'a' no puede ser mayor al valor 'b', ni igual a cero o al valor 'c'" << endl;
		return 0;
	}
	else if (c > b){
		cout << "El valor de 'c' no puede ser mayor al valor 'b'" << endl;
		return 0;
	}
	
	//Square root proccess, line 53 to line 63
	squareNumber = pow(b,2);
	cout << endl << "Elevando 'b' al cuadrado: " << squareNumber;
	
	multiplication = (4 * (a * c));
	cout << endl << "Multiplicando 4 x (a x c): " << multiplication;
	
	final = ((squareNumber) - multiplication);
	cout << endl << "Restando resultados: " << final << endl;
	
	result.squareRoot = sqrt(final);
	cout << "Mostrando raiz cuadrada: " << result.squareRoot << endl;
	
	//Function that makes a proccess to find the answers of the problem
	lastPart(result.squareRoot, a, b);
	
	return 0;
	
}

float lastPart(float squareResult, int a, int b){
	float add, subtract;
	int multiplicationAdd, multiplicationSubtract;
	float resultAdd, resultSubtract;
	
	proccess sumatory;
	
	//Sumatory proccess
	add = ((-1 * b) + (squareResult));
	cout << endl << "El resultado de su sumatoria es: " << add << endl;
	
	//Subtract proccess
	subtract = ((-1 * b) - (squareResult));
	cout << "El resultado de su resta es: " << subtract << endl;
	
	//Add multiplication
	multiplicationAdd = (2 * a);
	cout << "La multiplicacion de los valores a dividir es: " << multiplicationAdd << endl;
	
	//Subtract multiplication
	multiplicationSubtract = (2 * a);
	
	//result Add
	resultAdd = (add / multiplicationAdd);
	
	//result Subtract
	resultSubtract = (subtract / multiplicationSubtract);
	
	//Determinating values
	if (resultAdd != 0 || resultSubtract !=0 ){
		cout << endl << "La operacion tiene dos raices respuesta" << endl;
		cout << "El resultado de su suma es: " << resultAdd << endl;
		cout << "El resultado de su resta es: " << resultSubtract << endl;
	}
	if (resultAdd == 0){
		cout << endl << "La operacion solo tiene una raiz respuesta" << endl;
		cout << "El resultado de su resta es: " << resultSubtract << endl;
	}
	if (resultSubtract == 0){
		cout << endl << "La operacion solo tiene una raiz respuesta" << endl;
		cout << "El resultado de su suma es: " << resultAdd << endl;
	}
	else if (resultAdd == 0 && resultSubtract == 0){
		cout << "No posee ninguna raiz" << endl;
	}
	
	return 0;
		
}

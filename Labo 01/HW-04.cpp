#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Main function
int main(){
	int arreglo;
	int num;
	int acum;
	
	//Inicialize random numbers 
    srand(time(NULL));
    
    //
    for(int i = 1; i <= 15; i++)
    {
        num = 1 + rand() % (16 - 1);
        cout << num<< " ";
    	if (num%7 == 0){
    		acum= acum + num;
    	}
	}
    
    cout<<endl<<"La suma de los multiplos de 7 es: "<<acum<<endl;
    
    return 0;
}


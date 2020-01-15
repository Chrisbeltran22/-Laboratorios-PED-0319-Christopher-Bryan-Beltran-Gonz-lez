#include <iostream>
#include <string>
using namespace std;

struct address{
	int houseNumber;
	string city, state;
};

void printInfo(address printAd);

int main(void){
	address ad1;
	
	cout << "Numero de casa: "; cin >> ad1.houseNumber;
	cout << "Ciudad: "; cin >> ad1.city;
	cout << "Departamento: "; cin >> ad1.state; 
	
	
	printInfo(ad1);
	
	return 0;
}

void printInfo(address printAd){
	cout << "Numero de casa:\t " << printAd.houseNumber;
	cout << "Ciudad:\t " << printAd.city;
	cout << "Departamento:\t" <<printAd.state; 
}

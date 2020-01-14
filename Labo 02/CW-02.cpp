#include <iostream>
using namespace std;

int main(){ 
	
	int num = 1;
	int matrix [3][3];

	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			matrix[i][j] = num++;
		}
	}
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

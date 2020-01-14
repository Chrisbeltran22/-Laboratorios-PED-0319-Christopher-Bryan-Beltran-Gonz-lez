#include <iostream>
using namespace std;

int main(void){
    char incognit[] = {'c', 'o', 'd', 'i', 'f', 'i', 'c', 'a', 'r'};
    char verification[9];
    char guessLetter;
    int a = 13;

    cout << "Ahorcado" << endl;
    cout << "La palabra a adivinar contiene nueve letras" << endl;

    do{
        cout << "Letra: "; cin >> guessLetter;

    } while(a > 0);


    return 0;
}

void verifyLetter(char arr1[9], char arr2[9], char letter, int size){
    for (int i = 0; i< size; i++){
        if (arr1[i] == letter){
            arr2[i] = letter;
        }
        
    }
}
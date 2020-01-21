#include <iostream>
#include <cmath>
using namespace std;

struct monomio{
    float coef, exp;
};

float evaluate(monomio* array, int size, int aux);

int main(void){
    int size = 0;
    cin >> size;

    monomio* numbers;
    numbers = new monomio[size];

    for (int i = 0; i < size; i++){
        cin >> numbers[i].coef >> numbers[i].exp;
    }

    cout << evaluate(numbers, size, 0) << endl;

    return 0;
}

float evaluate(monomio* array, int size, int aux){

    if(size == aux){
       return 0;
    }
    else{
        return pow(array[aux].coef, array[aux].exp) + evaluate(array, size , aux +1);
    }

}
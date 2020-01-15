#include <iostream>
using namespace std;

//Main function
int main(){
    // Inicialize variables
    int numbers = 0;
    int total = 0;
    // For cycle 
    for (int i=1; i <= 100; i++){
        for (int j=1; j<= i; j++){
            //Verifying options
            if (i%j==0){
                numbers++;
            }
        } 
        //It's option is true
        if (numbers==2){
            cout<<i<<"\t";
            total = total + i;
            cout<<total<<endl;
        }
        //It's option false
        else numbers=0;
    }

}
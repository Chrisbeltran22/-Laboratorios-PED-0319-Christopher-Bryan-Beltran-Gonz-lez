#include <iostream>
#include <string>

//Derclaracion de un define
#define PASSWORD "password"

using namespace std;

//Sirve para almacenar los valores que unicamente se necesitarán en el sistema.
enum mainDish{pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymentType {cash, card};

//Declaracion de estructuras
struct address{
    string sttlement, municipality, department;
    int houseNumber;
};

struct mainInfo{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymentType pay; 
    int idOrder;
    float total;
};

struct delivery{
    address deliveryAddres;
    int cellphone;
    mainInfo deliveryInfo;
};

struct houseOrder{
    int pTable;
    mainInfo houseInfo;

};

//variables globales
bool isAdmin = false;
int idOrder = 1;


//prototipos
bool loginUser(void);
void printMenu(void);
void searchByName(delivery* array, int size);

int main(void){
    //Declaracion de variables y arreglos a usar
    delivery* dArray = NULL;
    houseOrder* hArray = NULL;
    int option = 0;

    //Verificaion para iniciar seccion
    if(!loginUser())
        return 0;

    //Lógica principal para la ejecuicios del programa (menu)
    do{
        printMenu(); cin >> option;
        cin.ignore();

        switch(option){
            //Agregar ordenes a domicilio
            case 1:
                addOrder(dArray);
            break;
            //Agregar ordenes en restaurante
            case 2:
                addOrder(hArray);
            break;
            case 3:
                searchByName();
            break;
            case 4:

            break;
            case 0:
            break;
        }

    }while(option != 0);
    
    return 0;
}

bool loginUser(void){
    string enterPass = "";
    char option;
    cout << "Inicio de secion" << endl;
    cout << "ADMINISTRADOR" << endl;
    cout << "EMPLEADO" << endl;
    cout << "Su opcion:\t"; cin >> option;

    switch(option){
        case 'a':
        break;
        case 'A':
            cout << "Digite contrasena: "; cin >> enterPass;
            
            if(enterPass.compare(PASSWORD) == 0){
                isAdmin = true;
                return true;
            }
            else{
                cout << "Contrasena incorrecta" << endl;
            }
        break;
        case 'e':
        case 'E':
            isAdmin = false;
            return true;
        break;
    }
    return false;
}

void printMenu(void){
    cout << "SISTEMA DESPACHO DE PIZZERIA KALVOS_PIZZA" << endl;
    cout << "1. Agregar ordenes a domicilio" << endl;
    cout << "2. Agregar ordenes a restaurante" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurante" << endl;
    cout << "Su opcion:\t"; 
}

void addOrder(delivery* array){
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new delivery[size];

    for (int i = 0; i < size; i++){
        int aux = 0;
        
        cout << "Nombre:\t"; getline(cin, array[i].deliveyInfo.name);
        cout << "Direccion:";
        cout << "Colonia:\t"; getline(cin, array[i].deliveyAddress.settlement);
        cout << "Municipio:\t"; getline(cin, array[i].deliveyAddress.municipality);
        cout << "Departamento:\t"; getline(cin, array[i].deliveyAddress.department);
        cout << "No. casa:\t"; cin >> array[i].deliveyAddress.houseNumber;
        cin.ignore();

        cout << "Entrada" << endl;
        cout << "1- Pan con ajo" << endl;
        cout << "2- Pizza rolls" << endl;
        cout << "3- Palitos de queso" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1){
            array[i].deliveryInfo.pStarter = garlicBread;
        else if(aux == 2){
            array[i].deliveryInfo.pStarter = pizzaRolls;
        else{
            array[i].deliveryInfo.pStarter = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1- Pizza" << endl;
        cout << "2- Pasta" << endl;
        cout << "3- Lasagna" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1){
            array[i].deliveryInfo.pDish = pizza;
        else if(aux == 2){
            array[i].deliveryInfo.pDish = pasta;
        else{
            array[i].deliveryInfo.pDish = lasagna;

        cout << "Bebida" << endl;
        cout << "1- Cerveza" << endl;
        cout << "2- Soda" << endl;
        cout << "3- Te helado" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pDrink = beer;
        else if(aux == 2)
            array[i].deliveryInfo.pDrink = soda;
        else
            array[i].deliveryInfo.pDrink = tea;

        array[i].deliveryInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1- Tarjeta" << endl;
        cout << "2- Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].deliveryInfo.pay = card;
        else
            array[i].deliveryInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].deliveryInfo.total;    
        cin.ignore();
        cout << "Telefono: "; cin >> array[i].cellphone;
        cin.ignore();
    }
} 

void addOrder(houseOrder* array){
    int size = 0;
    cout << "Cantidad de pedidos a ingresar: "; cin >> size;
    cin.ignore();

    array = new houseOrder[size];

    for (int i = 0; i < size; i++){
        int aux = 0;
        
        cout << "Nombre:\t"; getline(cin, array[i].houseInfo.name);
        cout << "Acompanantes por mesa: "; cin >> array[i].houseOrder.pTable;
        cin.ignore();

        cout << "Entrada" << endl;
        cout << "1- Pan con ajo" << endl;
        cout << "2- Pizza rolls" << endl;
        cout << "3- Palitos de queso" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pStarter = garlicBread;
        else if(aux == 2)
            array[i].houseInfo.pStarter = pizzaRolls;
        else
            array[i].houseInfo.pStarter = cheeseSticks;

        cout << "Plato principal" << endl;
        cout << "1- Pizza" << endl;
        cout << "2- Pasta" << endl;
        cout << "3- Lasagna" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1){
            array[i].houseInfo.pDish = pizza;
        }
        else if(aux == 2){
            array[i].houseInfo.pDish = pasta;
        }
        else{
            array[i].houseInfo.pDish = lasagna;
        }

        cout << "Bebida" << endl;
        cout << "1- Cerveza" << endl;
        cout << "2- Soda" << endl;
        cout << "3- Te helado" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pDrink = beer;
        else if(aux == 2)
            array[i].houseInfo.pDrink = soda;
        else
            array[i].houseInfo.pDrink = tea;

        array[i].houseInfo.idOrder = idOrder++;
        
        cout << "Tipo de pago" << endl;
        cout << "1- Tarjeta" << endl;
        cout << "2- Efectivo" << endl;
        cout << "Su opcion:\t"; cin >> aux;
        cin.ignore();

        if(aux == 1)
            array[i].houseInfo.pay = card;
        else
            array[i].houseInfo.pay = cash;

        cout << "Monto: "; cin >> array[i].houseInfo.total;    
        cin.ignore();
    }
}

void searchByName(delivery* array, int size){
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: "; getiline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].deliveryInfo.name) == 0){
            userExists = true;
        }
    }
    (!userExists) ? cout << "No existe el usuario" : cout << "";
}

void searchByName(houseOrder* array, int size){
    bool userExists = false;
    string aux = "";
    cout << "Nombre a buscar: "; getiline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].houseInfo.name) == 0){
            userExists = true;
        }
    }
    (!userExists) ? cout << "No existe el usuario" : cout << "";
}
#include <iostream>
#include <string>
using namespace std;

struct pedido{
    string remitente, destinatario;
    char tipo, modalidad;
    int peso;
};

struct cola{
    pedido elemento;
    cola*sig;
};

cola* queue(cola* C, pedido elemento);

int main(void){
    cola* pInicio = NULL;
    pedido aux;
    int opcion = 0;

    do{
        cout << "Remitente:\t"; getline(cin, aux.remitente);
        cout << "Destinatario:\t"; getline(cin, aux.destinatario);
        cout << "Tipo:\t"; cin >> aux.tipo; cin.ignore();
        cout << "Modalidad:\t"; cin >> aux.tipo; cin.ignore();
        cout << "Peso:\t"; cin >> aux.tipo; cin.ignore();

        pInicio = queue(pInicio, aux);

        cout << "Mas pedidos (1- si, 0- no)\t"; cin >> opcion; cin.ignore();

    }while(opcion != 0);

    cout << "Total por sus pedidos:\t" << calcularTotal(pInicio);
    cout << "Muchas gracias por usar COrreos de El Salvador!" << endl;

    return 0;
}

cola* queue(cola* C, pedido elemento){
    cola* nuevo = new cola;
    nuevo->elemento = elemento;
    nuevo->sig = NULL;

    if(!C)
        C = nuevo;
    else{
        cola* aux = C;
        while(aux->sig)
            aux = aux->sig;
        aux->sig = nuevo;
    }
    return C;
}

float calcularTotal(cola* lista){
    if(!lista)
        return 0;
    else{
        float sub = 0;
        switch(lista->elemento.tipo){
            case 'c':
            case 'C':
                switch(lista->elemento.modalidad){
                    case 'u':
                    case 'U':
                        sub = 3;
                    break;
                    case 'n':
                    case 'N':
                        sub = 1;
                    break;
                    case 'i':
                    case 'I':
                        sub = 2;
                    break;
                }
            break;
            case 'p':
            case 'P':
                switch(lista->elemento.modalidad){
                    case 'u':
                    case 'U':
                        if(lista->elemento.peso <= 500)
                            sub = 10;
                        else
                            sub = 15;
                    break;
                    case 'n':
                    case 'N':
                        sub = 5;
                    break;
                    case 'i':
                    case 'I':
                        if(lista->elemento.peso < 100)
                            sub = 5;
                        else
                            sub = 10;
                    break;
                }
            break;
            default:
                break;
        }
        return sub + calcularTotal(lista->sig);
    }
}
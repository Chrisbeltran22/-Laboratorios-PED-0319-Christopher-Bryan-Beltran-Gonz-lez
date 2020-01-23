#include <iostream>
#include <string>
using namespace std;

struct node{
    string content, address;
    float weigth;
    node* next;
};
typedef node* st;

void push(st* pSt, string content, string address, float weigth);
node top(st* pSt);
node pop(st* pSt);
bool isEmpty(st* pSt);

int main(void){
    st pSt = NULL;

    int option = 0;
    string content, address;
    float weigth;

    do{
        cout << "Peso: "; cin >> weigth; cin.ignore();
        cout << "Contenido: "; getline(cin, aux.content);
        cout << "Destino: "; getline(cin, aux.address);

        push(&pSt, content, address, weigth);

        cout << "INgresar mas datos (1 = si, 0 = no)\t"; cin >> option;
        cin.ignore();

    }while(option != 0);

    node aux = top(&pSt);

    cout << "Peso: " << aux.weigth << endl;
    cout << "Contenido: " << aux.content << endl;
    cout << "Direccion: " << aux.address << endl;

    aux = pop(&pSt);

    return 0;
}

void push(st* pSt, string content, string address, float weigth){
    node* newNode = new node;
    newNode->address = address;
    newNode->content = content;
    newNode->weigth = weigth;

    newNode->next = *pSt;
    *pSt = newNode;
}

node top(st* pSt){
    node aux;
    if(!(*pSt)){
        aux.address = "";
        aux.content = "";
        aux.weigth = 0;
        aux.next = NULL;
    }
    else{
        aux.address = (*pSt)->address;
        aux.content = (*pSt)->content;
        aux.weigth = (*pSt)->weigth;
        aux.next = NULL;
    }
    return aux;
}

node pop(st* pSt){
    node aux;
    if(!(*pSt)){
        aux.address = "";
        aux.content = "";
        aux.weigth = 0;
        aux.next = NULL;
    }netx
    else{
        aux.address = (*pSt)->address;
        aux.content = (*pSt)->content;
        aux.weigth = (*pSt)->weigth;
        aux.next = NULL;

        (*pSt) = (*pSt)->next;
    }
    return aux;
}

bool isEmpty(st* pSt){
    return 0;

}

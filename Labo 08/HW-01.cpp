#include <iostream>
#include <string>
using namespace std;

struct node{
    string name;
    string lastName;
    int DUI;
    node *left, *right;
};
typedef struct node T;

void preOrder(node* pTree);
void postOrder (node* pTree);
void inOrder(node* pTree);

void insertInTree(node** pTree, string lastName);
node* createLeaf(string lastName);


int main(void){
    T unNode;
    node* pTree = NULL;
    char option;
    bool verification = true;

    do{
        cout << "Ingrese datos" << endl;
        cout << "Nombre:\n";
        getline(cin , unNode.name);
        cout << "Apellido:\n";
        getline(cin , unNode.lastName);
        cout << "DUI:\n";
        cin >> unNode.DUI; cin.ignore();

        cout << "Agregar un usuario (s/n)\n";
        cin >> option;
        if(option == 'n' || option == 'N'){
            verification = false;
        }
    }while(verification);
    
    cout << "Imprimiendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;

    cout << "Imprimiendo en in Order" << endl;
    inOrder(pTree); cout << endl << endl;
    
    cout << "Imprimiendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;

    return 0;
}

node* createLeaf(string lastName){
    node* leaf = new node;
    leaf->lastName = lastName;
    leaf->left = NULL;
    leaf->right =NULL;

    return leaf;
}

void insertInTree(node** pTree, string lastName){
    if(!(*pTree)){
        *pTree = createLeaf(lastName);
    }
    else{
        if(lastName.compare((*(*pTree)).lastName) <= 0)
            insertInTree(&(*(*pTree)).left, lastName);
        else
            insertInTree(&(*(*pTree)).right, lastName);
    }
}

void preOrder(node* pTree){
    if(!pTree)
        return;
    else{
        cout << pTree->lastName << "\t";
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

void postOrder(node* pTree){
    if(!pTree)
        return;
    else{
        postOrder(pTree->left);
        postOrder(pTree->right);
        cout << pTree->lastName << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree)
        return;
    else{
        inOrder(pTree->left);
        cout << pTree->lastName << "\t";
        inOrder(pTree->right);
    }
}
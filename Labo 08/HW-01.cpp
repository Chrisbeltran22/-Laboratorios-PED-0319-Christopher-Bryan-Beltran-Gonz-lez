#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct node{
    string lastName;
    node *left, * right;
};

//Prototipos
void show(node* pTree);
void inOrder(node* pTree);
void insertInTree(node** pTree, string lastName);
node* createLeaf(string lastName);

int main(void){
    node* pTree = NULL;
    bool process = true;
    string name, lastName; int election = 0;
    
    do{
    	cout << "1- Ingresar una persona\n2- Mostrar palabras ordenadas\n3- salir\n";
    	cin >> election; cin.ignore();
    	system("cls");
    	if(election == 1){
		    cout << "\nIngrese apellido y nombre: " << endl;
            getline(cin, lastName);
    		insertInTree(&pTree, lastName);
    		cout << endl;
    		system("pause");
    		system("cls");
    	}
    	else if(election == 2){
    		show(pTree);
    	}
    	else if(election == 3){
			process = false;
    	}
	}while(process);

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

void inOrder(node* pTree){
    if(!pTree)
        return;
    else{
        inOrder(pTree->left);
        cout << pTree->lastName << "\t";
        inOrder(pTree->right);
    }
}

void show(node* pTree){
	cout << "\nImprimiendo en in Order las palabras ingresadas\n" << endl;
    inOrder(pTree);
	cout << endl;
    system("pause");
    system("cls");
}

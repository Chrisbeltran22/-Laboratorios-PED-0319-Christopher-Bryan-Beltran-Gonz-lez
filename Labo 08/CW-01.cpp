#include <iostream>
using namespace std;

struct node{
    int n;
    node *left, * right;
};

//Declaración 1
void preOrder(node* pTree);
void postOrder (node* pTree);
void inOrder(node* pTree);

//Declaración 2
node* createLeaf(int n);
void insertINTree(node**, int);


int main(void){
    node* pTree = NULL;

    insertINTree(&pTree, 12);
    insertINTree(&pTree, 22);
    insertINTree(&pTree, 8);
    insertINTree(&pTree, 15);
    insertINTree(&pTree, 1);
    insertINTree(&pTree, 0);
    insertINTree(&pTree, 27);

    cout << "Imprimiendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;

    cout << "Imprimiendo en in Order" << endl;
    inOrder(pTree); cout << endl << endl;
    
    cout << "Imprimiendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;

    
    return 0;
}

node* createLeaf(int n){
    node* leaf = new node;
    leaf->n = n;
    leaf->left = NULL;
    leaf->right =NULL;

    return leaf;
}

void insertINTree(node** tree, int n){
    if(!(*tree)){
        *tree = createLeaf(n);
    }
    else{
        if(n <=(*(*tree)).n)
            insertINTree(&(*(*tree)).left, n);
        else
            insertINTree(&(*(*tree)).right, n);
    }
}

void preOrder(node* pTree){
    if(!pTree)
        return;
    else{
        cout << pTree->n << "\t";
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
        cout << pTree->n << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree)
        return;
    else{
        inOrder(pTree->left);
        cout << pTree->n << "\t";
        inOrder(pTree->right);
    }
}
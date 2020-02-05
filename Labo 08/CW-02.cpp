#include <iostream>
#include <string>
using namespace std;

struct node{
    string word;
    node *left, * right;
};

void preOrder(node* pTree);
void postOrder (node* pTree);
void inOrder(node* pTree);

void insertInTree(node** pTree, string word);
node* createLeaf(string word);


int main(void){
    node* pTree = NULL;
    insertInTree(&pTree, "Hola");
    insertInTree(&pTree, "Pupusas");
    insertInTree(&pTree, "Codigo");
    insertInTree(&pTree, "Adios");
    insertInTree(&pTree, "F");
    
    cout << "Imprimiendo en preOrder" << endl;
    preOrder(pTree); cout << endl << endl;

    cout << "Imprimiendo en in Order" << endl;
    inOrder(pTree); cout << endl << endl;
    
    cout << "Imprimiendo en postOrder" << endl;
    postOrder(pTree); cout << endl << endl;

    return 0;
}

node* createLeaf(string word){
    node* leaf = new node;
    leaf->word = word;
    leaf->left = NULL;
    leaf->right =NULL;

    return leaf;
}

void insertInTree(node** pTree, string word){
    if(!(*pTree)){
        *pTree = createLeaf(word);
    }
    else{
        if(word.compare((*(*pTree)).word) <= 0)
            insertInTree(&(*(*pTree)).left, word);
        else
            insertInTree(&(*(*pTree)).right, word);
    }
}

void preOrder(node* pTree){
    if(!pTree)
        return;
    else{
        cout << pTree->word << "\t";
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
        cout << pTree->word << "\t";
    }
}

void inOrder(node* pTree){
    if(!pTree)
        return;
    else{
        inOrder(pTree->left);
        cout << pTree->word << "\t";
        inOrder(pTree->right);
    }
}
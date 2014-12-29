#include <stdio.h>
#include <iostream>

#include <memory>

#include <cmath> 

using namespace std;


struct node
{
	char* data;
	node *left;
	node *right;
};

/* This funcion version uses three pointer variables */
node* buildTreeFigure1(){
	node *root = new node();
	root->data = (char *)"A";
	
	
  // Left side of root
  node *node_B = new node();
  node_B->data = (char *) "B";
  
  node *node_C = new node();
  node_C->data = (char *) "C";
  
  node *node_D = new node();
  node_D->data = (char *) "D";
  
  node *node_E = new node();
  node_E->data = (char *) "E";
  
  node *node_F = new node();
  node_F->data = (char *) "F";
  
  node *node_G = new node();
  node_G->data = (char *) "G";
  
  node *node_H = new node();
  node_H->data = (char *) "H";
  
  root->left = node_B;
  
  node_B->left = node_C;
  node_B->right = node_F;
  
  node_C->left = node_D;
  node_C->right = node_E;
  
  node_F->right = node_G;
  
  node_G->left = node_H;
  
  // Right side of root
  node *node_I = new node();
  node_I->data = (char *) "I";
  
  node *node_J = new node();
  node_J->data = (char *) "J";
  
  node *node_K = new node();
  node_K->data = (char *) "K";
  
  node *node_L = new node();
  node_L->data = (char *) "L";
  
  node *node_M = new node();
  node_M->data = (char *) "M";
  
  node *node_N = new node();
  node_N->data = (char *) "N";
  
  node *node_O = new node();
  node_O->data = (char *) "O";
  
  node *node_P = new node();
  node_P->data = (char *) "P";
  
  root->right = node_I;
  
  node_I->left = node_J;
  node_I->right = node_O;
  
  node_J->right = node_K;
  
  node_K->left = node_L;
  node_K->right = node_N;
  
  node_L->right = node_M;
  
  node_O->right = node_P;
  
	return root;
}

void printInOrder(node *node){
	if(node==NULL){
		return;
	}
	else
	{
		printInOrder(node->left);
		cout << node->data << " ";
		printInOrder(node->right);
	}
}


int size(node *node){
	if(node==NULL){
		return 0;
	}
	else{
		return(size(node->left) + 1 + size(node->right));
	}
}

bool isKBalancede(node *root, int k){

  if (root==NULL){
    return true;
  }

  int sizeL = size(root->left);
  int sizeR = size(root->right);

  return abs(sizeL - sizeR) <= k;
}

/*
1. Considere que um nó em uma  ́árvore binária  ́e considerado k-balanceado se a
  diferença entre as quantidades de nós em suas subárvores esquerda e direita não
  é maior do que k.
  Desenvolva um algoritmo ou fun ̧ao em C/C++ denominada findNonKBalancedeNode
  que recebe como entrada um ponteiro para a raiz de uma  ́arvore binária e um inteiro
  positivo k e retorna um ponteiro para um nó "u" na  ́árvore binária tal que "u"
  *não é* k-balanceado mas todos seus descendentes são k-balanceados. Se um nó com tal
  característica não existir na  ́arvore, a função deverá retornar null. Por exemplo, se
  a função recebesse como entrada um ponteiro para árvore apresentada na Figura 1,
  e um valor inteiro k = 3, ela deveria retornar um ponteiro para o nó J.
*/
node* findNonKBalancedeNode(node *root, int k){
  if(root==NULL){
    return NULL;
  }
  
  if (!isKBalancede(root, k)){
    cout << root->data << " nao é K-balanceado " << endl;
    bool isLeftBalanced = isKBalancede(root->left, k);
    bool isRightBalanced = isKBalancede(root->right, k);
    
    if (isLeftBalanced && isRightBalanced){
      return root;
    }
  }
  
  node* left = findNonKBalancedeNode(root->left, k);
  if(left){
    return left;
  }
  node* right = findNonKBalancedeNode(root->right, k);
  if(right){
    return right;
  }
  
  cout << root->data << " é K-balanceado " << endl;
  return NULL;
}

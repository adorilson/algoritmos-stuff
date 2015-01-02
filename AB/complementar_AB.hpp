#include <stdio.h>
#include <iostream>

#include <memory>

#include <cmath> 

#include <string>

using namespace std;


struct node
{
	char* data;
	node *left;
	node *right;
	node *parent;
	bool lock;
	
	int countLeftLock;
	int countRightLock;
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
  node_B->parent = root;
  
  node_B->left = node_C;
  node_C->parent = node_B;
  
  node_B->right = node_F;
  node_F->parent = node_B;
  
  node_C->left = node_D;
  node_D->parent = node_C;
  node_C->right = node_E;
  node_E->parent = node_C;
  
  node_F->right = node_G;
  node_G->parent = node_F;
  
  node_G->left = node_H;
  node_H->parent = node_G;
  
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
  node_I->parent = root;
  
  node_I->left = node_J;
  node_J->parent = node_I;
  
  node_I->right = node_O;
  node_O->parent = node_I;
  
  node_J->right = node_K;
  node_K->parent = node_J;
  
  node_K->left = node_L;
  node_L->parent = node_K;
  node_K->right = node_N;
  node_N->parent = node_K;
  
  node_L->right = node_M;
  node_M->parent = node_L;
  
  node_O->right = node_P;
  node_P->parent = node_O;
  
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

void printParents(node *node){
  if (node == NULL){
    cout << endl;
    return;
  }
  
  cout << node->data << " ";
  printParents(node->parent);
  
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

/*
2. Esta questão envolve a criação de uma pequena API para definir o estado de um
nó qualquer de uma  ́arvore binária como sendo lock (bloqueado) ou unlock (desblo-
queado). O estado de um nó de árvore binária não pode ser mudado para lock caso
qualquer um de seus descendentes ou ascendentes já ́estejam em estado lock.
Ao modificar o estado de um nó ́para lock nenhum outro nó ́deve ter seu estado
alterado. Por exemplo, todas as folhas podem estar simultaneamente em estado
lock. (Neste caso, nenhum outro nó ́ interno pode estar em estado lock.)

Escreva os seguintes métodos para uma classe representando uma árvore binária:
bool isLock(), bool lock(), e void unLock(). O método lock() deve retornar
um valor booleano indicando se a chamada modificou o estado do nó ́ de unlock para
lock. A complexidade temporal para os três métodos deve ser, respectivamente,
O(1), O(h), e O(h), onde h corresponde a altura da  ́arvore binaria que contém o nó.
Assuma que cada nó possui um ponteiro para seu antecessor imediato (o “pai”). A
API deve ser utilizada em um programa com uma unica linha de execução (single
thread ), de maneira que não é ́necessario utilizar programação concorrente.
*/

bool isLock(node *node){
  if (node == NULL){
    return false;
  }
  return node->lock;
}

bool hasParentsLock(node *node){
  if (node == NULL){
    return false;
  }
  
  if (isLock(node->parent)){
    return true;
  }
  if (hasParentsLock(node->parent)){
    return true;
  }
  return false;
}

void updateLockParents(node *node){
  if (node->parent==NULL){
    return;
  }
  
  if (node==node->parent->left){
    node->parent->countLeftLock++;
  }else{
    node->parent->countRightLock++;
  }
  
  updateLockParents(node->parent);
}

void updateUnlockParents(node *node){
  if (node->parent==NULL){
    return;
  }
  
  if (node==node->parent->left){
    node->parent->countLeftLock--;
  }else{
    node->parent->countRightLock--;
  }
  
  updateUnlockParents(node->parent);
}

bool lock(node *node){
  
  // checking if has locked children in O(1)
  if (node->countLeftLock || node->countRightLock){
    return false;
  }
  
  // checking if has locked parents in O(h)
  if (hasParentsLock(node)){
    return false;
  }
  
  // locking parents in O(h)
  updateLockParents(node);
  
  node->lock = true;
  return true;
}

void unLock(node *node){
  updateUnlockParents(node);
  
  node->lock = false;
}


void printTreeInBarMode2(node *node, string valor){
	if(node->right!=NULL){
		printTreeInBarMode2(node->right, valor+"--");
	}
	else{
		cout << "--" << valor << "x" <<endl;
	}
	if(node!=NULL){
		cout << valor << node->data << endl;
	}
	else{
		return;
	}
	if(node->left!=NULL){
		printTreeInBarMode2(node->left, valor+"--");
	}
	else{
		cout << "--" << valor << "x" <<endl;
	}
}


/*
3. Muitas arvores binárias distintas produzem a mesma sequência de chaves se percor-
ridas em ordem, em pré-ordem ou em pós-ordem. Contudo, se assumirmos que uma
árvore binária T possui chaves únicas, podemos encontrar uma árvore T única dado
o resultado de um percorrimento em ordem sobre T e o resultado de qualquer um dos
outros dois percorrimentos acima mencionados. Por exemplo, a  ́arvore binária única
T cuja sequência obtida via percorrimento em ordem  ́é F, B, A, E, H, C, D, I, G
e cuja sequência obtida via percorrimento pré-ordem é H, B, F, E, A, C, D, G, I
é apresentada abaixo.
         H
       /   \
      B     C
     / \     \
    F   E     D
       /       \
      A         G
               /
              I
*/

node* rebuild(string inorder, string preorder){

  string data_root = preorder.substr(0, 1);
  node *root = new node();
  root->data = new char[data_root.size() + 1];
  std::copy(data_root.begin(), data_root.end(), root->data);
  root->data[data_root.size()] = '\0';

  // it is a leaf
  if(inorder==preorder){
    return root;
  }

  int pos_root = inorder.find(data_root);
  string tree_left = inorder.substr(0, pos_root);
  string tree_right = inorder.substr(pos_root+1, inorder.length()-1);

  // call this function to rebuild the left and rigth trees recursily
  string left = preorder.substr(1, tree_left.length());
  if(left.length()!=0){
    root->left = rebuild(tree_left, left);
  }

  string right = preorder.substr(tree_left.length()+1, preorder.length()-1);
  if(right.length()!=0){
    root->right = rebuild(tree_right, right);
  }

  return root;
}

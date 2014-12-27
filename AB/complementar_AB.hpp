#include <stdio.h>

using namespace std;

template <typename T>
class BinaryTree{
  public:
    T data ;
    BinaryTree <T> *left, *right ;
    BinaryTree add_node(T new_data);
    
    BinaryTree(T data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

BinaryTree<char*> buildTree(){
	BinaryTree<char*> *root = new BinaryTree<char*>("A");
	
  // Left side of root
  BinaryTree<char*> *node_B = new BinaryTree<char*>("B");
  BinaryTree<char*> *node_C = new BinaryTree<char*>("C");
  BinaryTree<char*> *node_D = new BinaryTree<char*>("D");
  BinaryTree<char*> *node_E = new BinaryTree<char*>("E");
  BinaryTree<char*> *node_F = new BinaryTree<char*>("F");
  BinaryTree<char*> *node_G = new BinaryTree<char*>("G");
  BinaryTree<char*> *node_H = new BinaryTree<char*>("H");
  
  root->left = node_B;
  
  node_B->left = node_C;
  node_B->right = node_F;
  
  node_C->left = node_D;
  node_C->right = node_E;
  
  node_F->right = node_G;
  
  node_G->left = node_H;
  
  // Right side of root
  BinaryTree<char*> *node_I = new BinaryTree<char*>("I");
  BinaryTree<char*> *node_J = new BinaryTree<char*>("J");  
  BinaryTree<char*> *node_K = new BinaryTree<char*>("K");
  BinaryTree<char*> *node_L = new BinaryTree<char*>("L");
  BinaryTree<char*> *node_M = new BinaryTree<char*>("M");
  BinaryTree<char*> *node_N = new BinaryTree<char*>("N");
  BinaryTree<char*> *node_O = new BinaryTree<char*>("O");
  BinaryTree<char*> *node_P = new BinaryTree<char*>("P");
  
  root->right = node_I;
  
  node_I->left = node_J;
  node_I->right = node_O;
  
  node_J->right = node_K;
  
  node_K->left = node_L;
  
  node_L->left = node_M;
  
  node_O->right = node_P;
  
	return *root;
}


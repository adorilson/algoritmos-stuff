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

	return *root;
}


#include "complementar_AB.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
  BinaryTree<char*> tree = buildTree();
  std::cout << tree.data << endl;
  
  BinaryTree<char*> node_B = * tree.left;
  std::cout << node_B.data << endl;
  
  BinaryTree<char*> node_C = * node_B.left;
  std::cout << node_C.data << endl;
  
  BinaryTree<char*> node_I = * tree.right;
  std::cout << node_I.data << endl;
  
  BinaryTree<char*> node_J = * node_I.left;
  std::cout << node_J.data << endl;
}

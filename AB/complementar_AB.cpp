#include "complementar_AB.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
  BinaryTree<char*> tree = buildTree();
  std::cout << tree.data << endl;
}


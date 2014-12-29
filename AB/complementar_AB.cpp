#include "complementar_AB.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
  
  node *tree;	

	cout << "BuildTree1: " << endl;
	tree = buildTreeFigure1();
	
  cout << tree->data << endl;
  node *B = tree->left;
  cout << B->data << endl;
  
  printInOrder(tree);
  
  // testando findNonKBalancedeNode e relacionados
  cout << size(tree) << endl;
  
  char* result = NULL;
  cout << isKBalancede(tree, 3) << endl;
  
  node *J = tree->right->left;
  cout << J->data << endl;
  cout << isKBalancede(J, 3) << endl;
  
  node *nonKBalancedeNode = findNonKBalancedeNode(tree, 3);
  if (nonKBalancedeNode!=NULL){
    result = nonKBalancedeNode->data;
  }
  
  cout << "result do findNonKBalancedeNode: " << result << endl;
  cout << endl;
}

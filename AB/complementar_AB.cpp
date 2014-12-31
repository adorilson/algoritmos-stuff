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
  
  cout << endl << " === testando a API lock === " << endl;
  
  cout <<  "lock(J) = " << lock(J) << endl; // deve retorna true
  cout <<  "lock(tree) = " <<lock(tree) << endl; // deve retornar false
  cout <<  "lock(B) = " << lock(B) << endl; // deve retorna true
  
  cout << "printParents(J) = ";
  printParents(J);
  
  cout << "isParentsLock(J) = " << isParentsLock(J) << endl; // deve retornar false
  
  node *L = J->right->left;
  cout << "printParents(L) = ";
  printParents(L); // deve ser L K J I A
  cout << "isParentsLock(L) = " << isParentsLock(L) << endl; // deve retorna true
  cout <<  "lock(L) = " << lock(L) << endl; // deve retorna false (J is lock)
  
}

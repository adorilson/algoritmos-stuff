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
  
  node *F  = B->right;
  cout << "lockParents(F)" << endl;
  cout << "antes: " << B->countRightLock << " " << tree->countLeftLock << " // deve ser 0 0" << endl;
  updateLockParents(F);
  cout << "depois: " << B->countRightLock << " " << tree->countLeftLock << " // deve ser 1 1" << endl;
  
  cout << "unLockParents(F)" << endl;
  updateUnlockParents(F);
  cout << "antes: " << B->countRightLock << " " << tree->countLeftLock << " // deve ser 0 0" << endl;
  
  cout << "isLock(J) = " << isLock(J) << "// deve ser 0 "  << endl;
  cout <<  "lock(J) = " << lock(J) << " // deve retorna true " << endl;
  cout << "isLock(J) = " << isLock(J) << "// deve ser 1 "  << endl;
  cout << J->parent->countLeftLock << " " << tree->countRightLock << " // deve ser 1 1" << endl;
  cout <<  "lock(tree) = " << lock(tree) << "// deve retornar false" << endl;
  cout <<  "lock(B) = " << lock(B) << " // deve retorna true" << endl;
  
  cout << "printParents(J) = ";
  printParents(J);
  
  cout << "isParentsLock(J) = " << hasParentsLock(J) <<  " deve retornar false" << endl;
  
  node *L = J->right->left;
  cout << "printParents(L) = "; printParents(L);
  cout << "// deve ser L K J I A" << endl;
  cout << "isParentsLock(L) = " << hasParentsLock(L)  << " // deve retorna true" << endl;
  cout <<  "lock(L) = " << lock(L) << " // deve retorna false (J is lock)" << endl;
  
  
  node *P = tree->right->right->right;
  cout << "lock(" << P->data << ")" << endl;
  cout <<  "lock(P) = " << lock(P) << " // deve retorna 1" << endl;
  cout << P->parent->countRightLock << " " << P->parent->parent->countRightLock
        << " " << tree->countRightLock << " // deve retornar 1 1 2 " << endl; 
  
  
  cout << "unLock(J)" << endl;
  unLock(J);
  cout << "isLock(J) = " << isLock(J) << "// deve ser 0 "  << endl;
  cout << J->parent->countLeftLock << " " << tree->countRightLock << " // deve ser 0 1" << endl; 
}

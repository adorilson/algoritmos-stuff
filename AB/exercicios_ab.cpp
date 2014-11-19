#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};


int size(node *node){
	if(node==NULL){
		return 0;
	}
	else{
		return(size(node->left) + 1 + size(node->right));
	}
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

void printPosOrder(node *node){
	if(node==NULL){
		return;
	}
	else
	{
		printPosOrder(node->left);
		printPosOrder(node->right);
		cout << node->data << " ";
	}
}

void printPreOrder(node *node){
	if(node==NULL){
		return;
	}
	else
	{
		cout << node->data << " ";
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
}


int minValue(node *node){
	if(node==NULL){
		return -1;
	}
	else{
		if(node->left==NULL){
			return node->data;
		}
		else{
			return minValue(node->left);
		}
	}
}


int maxValue(node *node){
	if(node==NULL){
		return -1;
	}
	else{
		if(node->right==NULL){
			return node->data;
		}
		else{
			return maxValue(node->right);
		}
	}
}

node * insert(int data, node *no)
{
  if(no==NULL){
    no=new node;
    no->data=data;
    no->left=NULL;
    no->right=NULL;
    return no;
  }
  else
  {
   	if(data!=no->data){
   		if(data < no->data){
   			no->left = insert(data, no->left);
   		}
   		else{
   			no->right = insert(data, no->right);
   		}
   	} 
   	return no;
  }
}



node *search(int data, node *leaf)
{
  if(leaf!=NULL)
  {
    if(data==leaf->data)
      return leaf;
    if(data<leaf->data)
      return search(data, leaf->left);
    else
      return search(data, leaf->right);
  }
  else return NULL;
}

void printTreeInBarMode(node *node, string valor){
	if(node!=NULL){
		cout << valor << node->data << endl;
	}
	else{
		return;
	}
	if(node->left!=NULL){
		printTreeInBarMode(node->left, valor+"--");
	}
	if(node->right!=NULL){
		printTreeInBarMode(node->right, valor+"--");
	}
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

/* This funcion version uses three pointer variables */
node* buildTree1(){
	node *node1 = new node;
	node *node2 = new node;
	node *node3 = new node;

	node1->data=2;
	node2->data=1;
	node3->data=3;

	node1->left=node2;
	node1->right=node3;
	node2->left=NULL;
	node2->right=NULL;
	node3->left=NULL;
	node3->right=NULL;

	return node1;
}

node* buildTree2(){
	node *node1 = new node;
	node1->data=2;
	node1->left=new node;
	node1->right=new node;
	node1->left->data=1;
	node1->right->data=3;
	node1->left->left=NULL;
	node1->left->right=NULL;
	node1->right->left=NULL;
	node1->right->right=NULL;

	return node1;
}
node* buildTree3(){
	node *node1 = NULL;
	node1=insert(2, node1);
	node1=insert(1, node1);
	node1=insert(3, node1);

	return node1;
}

int maxDepth(node *node){
   if (node==NULL) 
       return 0;
   else
   {
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}

void doubleTree(node *&no){
	if(no==NULL){
		return;
	}
	else{
		doubleTree(no->left);
		doubleTree(no->right);
		node *aux = new node;
		aux->data=no->data;
		aux->left=no->left;
		aux->right=NULL;
		no->left=aux;
	}
}

void printPathsRecur(node *node, int path[], int pathLen){
  if (node==NULL){
  	return;
  }

  /* append this node to the path array */
  path[pathLen] = node->data;
  pathLen++;

  /* it's a leaf, so print the path that led to here */
  if (node->left==NULL && node->right==NULL) 
  {
  	for(int a = 0 ; a < pathLen ; a++){
    	cout << path[a] << " ";
	}
	cout << endl;
  }
  else 
  {
  /* otherwise try both subtrees */
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

/*
 9. Escreva a função printPaths() que, dado uma  árvore binária, imprime todos seus
	caminhos raiz-para-folha, um por linha, como definido na Questão 8. Este problema
	é um pouco mais complicado do que parece, uma vez que o “caminho ate certo
	ponto” precisa ser passado entre chamadas recursivas.
	Dica: Possivelmente a melhor solução é criar uma função auxiliar recursiva
	printPathsRecur(node, int path[], int pathLen ), onde o vetor path  é usado para indicar a
	sequncia de nós que compõem caminho até chamada atual. Alternativamente, o problema pode
	ser resolvido de baixo para cima, com cada n ́ retornando sua lista de caminhos. O protótipo
	do procedimento:
	procedimento printPaths (ptRoot: ref NoAB)
 */
void printPaths(node *node){
  int path[1000];
  printPathsRecur(node, path, 0);
}


/* 
 8. Definimos um “caminho raiz-para-folha” como sendo a sequncia de nos
 de uma árvore considerados a partir do nó raiz até uma das folhas árvore.
 Assume-se que uma árvore vazia não contém nenhum caminho raiz-para-folha.
 Portanto, para a árvore abaixo, existem exatamente quatro caminhos raiz-para-folha:
		 5
		/ \
	   4	8
      /	   / \
     11	  13  4
	/  \	   \
   7    2		1

Os caminhos raiz-para-folha são:
path 1: 5 4 11 7
path 2: 5 4 11 2
path 3: 5 8 13
path 4: 5 8 4 1

Para este problema especificamente, estamos interessados na soma dos valores
contidos em um caminho deste tipo — por exemplo, a soma dos valores do caminho
5-4-11-7  é 5 + 4 + 11 + 7 = 27.

Dado uma  árvore binária e um valor de soma, escreva a função hasPathSum() que
retorna verdadeiro se a  árvore em questão possui, pelo menos, um caminho raiz-
para-folha cuja soma seja igual ao valor passado como parâmetro; caso contrário a
função deve retornar falso. O protótipo da função:
 
	função hasPathSum (ptRoot: ref NoAB; soma: inteiro): booleano
*/

bool hasPathSum(node *node, int soma){
	if (node == NULL) {
		return (soma == 0);
	}
	else {
		int subSum = soma - node->data; // caso contrário, verifica ambas subárvores
		return(hasPathSum(node->left, subSum) ||
				hasPathSum(node->right, subSum));
	}
}

/*
10. Implementa a função mirror() recebe uma  árvore binária e a modifica de forma que
	os ponteiros left e right tem seus conteúdos trocados em todos os nós da árvore.
	Assim, a  ́rvore (a) deve ser transformada na  ́rvore (b) da seguinte forma:
	(a) 		(b)
	 4 		 	 4
	/ \ 		/ \
   2  5  =>    5   2
  / \			  / \	
 1  3			 3	 1
 
 A solução é curta, mas bastante recursiva. Esta solução não requer que o ponteiro
 raiz seja modificado, portanto não é preciso retornar o ponteiro para a nova raiz.
 Alternativamente, se você não quiser modificar árvore original, pode fazer com que a
 a função crie uma nova árvore, espelhada, e a retorne. O protótipo do procedimento:

	procedimento mirror (ptRoot: ref NoAB)

*/
void mirror(node *node){
	if (node==NULL) {
		return;
	}
	else {
		struct node* temp;

		// faça as subárvores
		mirror(node->left);
		mirror(node->right);

		// trocar os ponteiros neste nó
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

/*
12. Escreva a função sameTree() que recebe duas  àrvores binárias e retorna verdadeiros
	caso as  árvores forem estruturalmente idênticas — i.e. as  àrvores devem possuir nós
	em posisões estruturalmente correspondentes e o conteúdo dos nós correspondentes
	devem ser iguais. O protótipo da função é:
	função sameTree (ptA: ref NoAB; ptB: ref NoAB): booleano
*/
bool sameTree(node *node_one, node *node_two){
	// 1. Ambas vazias -> true
	if (node_one==NULL && node_two==NULL) return(true);

	// 2. ambas não vazias -> compará-las
	else{
		if (node_one!=NULL && node_two!=NULL) {
			return(node_one->data == node_two->data &&
					sameTree(node_one->left, node_two->left) &&
					sameTree(node_one->right, node_two->right)
			);
		}// 3. uma vazia, e a noutra não -> false
		else return(false);
	}
}

/*

13. Na verdade este problema não é um problema de  árvore binária propriamente dito
	—  é mais um problema de combinatória e recursão que utiliza árvores binárias.
	Suponha que você está construindo uma  árvore binária de busca com N nós, para
	conter os valores 1 . . . N . Quantas  árvores binárias estruturalmente diferentes
	existem que são capazes de armazenar estes valores? Escreva uma função recursiva
	countTree() que, dado um número de valores distintos, computa o número de árvores
	binárias de busca estruturalmente unicas que são capazes de armazenar estes valores.
	Por exemplo, countTrees(4) deve retornar 14, já que existem 14  árvores binárias
	estruturalmente unicas capazes de armazenar os valores 1, 2, 3 e 4 (desenhe as
	árvores). O caso base  é fácil, e a recursão é curta mas densa. Seu código, na verdade,
	não deve construir nenhuma árvore; isto  é apenas um problema de contagem.
	O protótipo da função é:
	
	função countTree (numKeys: inteiro): inteiro
*/
int countTree(int numKeys){
	if (numKeys <=1) {
		return(1);
	}
	else {
		// haverá um valor na raiz,com o que resta na esquerda e na direita
		// que formam suas próprias subárvores
		// percorrer todos os valores que possam ser a raiz
		int sum = 0;
		int left, right, root;
		for (root=1; root<=numKeys; root++) {
			left = countTree(root - 1);
			right = countTree(numKeys - root);
			// o número de árvores possiveis com root == left*right
			sum += left*right;
		}
		return(sum);
	}
}

/*
14. Suponha que você tem funções auxiliares minValue() e maxValue() que retornam,
	respectivamente, o valor mínimo e máximo de um árvore não-vazia (veja Questão 4).
	Escreva a função isBST() que retorna verdadeiro se uma árvore é certificada como
	uma ABB; ou falso, caso contrário. Utilize as funções auxiliares e não esqueça de
	verificar cada nó da árvore. Não se preocupe se sua solução não for muito eficiente.
	O protótipo da função  é:
	função isBST (ptRoot: ref NoAB): inteiro
*/ 

bool isBST(node *node){
	if (node == NULL){
    	return true; 
  	}
    if (node->left != NULL && minValue(node->left) > node->data){
    	return false; 
  	}    
  	if (node->right != NULL && maxValue(node->right) < node->data){
    	return false; 
  	}
  	if (!isBST(node->left) || !isBST(node->right)){
    	return false; 
  	}  

  	return true; 
}

/*
15. A versão de isBST(), descrita acima, apresenta um fraco desempenho, uma vez que
	a ela percorre partes da  árvore várias vezes. Uma solução mais eficiente deveria
	investigar cada nó apenas uma vez. O truque é escrever uma função auxiliar
	isBSTRecur que percorre a árvore mantendo o valor dos limites “dinâmicos” mínimos
	e máximo à medida que desce pela árvore, investigando cada nó apenas uma vez. Os valores
	iniciais para min e max devem ser INT_MIN e INT_MAX (respectivamente, o menor e o
	maior valor inteiro possível).
*/ 

bool isBSTRecur(node *node, int min, int max){
	if(node==NULL){
		return true;
	}
	
	// necessário "inicializar" valores de min e max com o dado da raiz
	if (min=INT_MIN){
		min = node->data;
	}
	if(max=INT_MAX){
		max = node->data;
	}
	
	if(node->left && node->left->data > min){
		cout << "1o if " << node->left->data << " > " << min << endl;
		return false;
	}
	if(node->right && node->right->data < max){
		cout << "2o if" <<  endl;
		return false;
	}
	
	cout << node->data << " min: " << min << " max: " << max << endl;
	
	return isBSTRecur(node->left, min, node->data) &&
			isBSTRecur(node->right, node->data+1, max);
	
}

int isBST2(node *node){
	return isBSTRecur(node, INT_MIN, INT_MAX);
}

/*
16. Escreva a função remove() que recebe uma  ́rvores bin ́ria de busca e um valor alvo,
    então procura e remove o alvo da  ́árvore. Como a função pode modificar o nó raiz,
    ela deve retornar o ponteiro para a nova raiz da árvore modificada.
    Existem 3 casos a considerar com relação ao nó a ser eliminado:
    i) O nó não possui filhos ⇒ a arvore n ̃o necessita de ajustes;
    ii) O nó possui um unico filho ⇒ o unico filho toma o lugar do nó removido;
    iii) O nó possui dois filhos ⇒ o nó sucessor (menor nó da sub-árvore da direita)
    ocupa o lugar do nóremovido.
*/
node *minValueNode(node *root){
	node *aux = root;

	while(aux->left != NULL){
		aux=aux->left;
	}
	return aux;
}

node *remove(node *root, int target){
	if (root == NULL){
		return root;
	}
	if (target < root->data){
		root->left=remove(root->left, target);
	}
	else if (target > root->data){
		root->right=remove(root->right, target);
	}
	else{
		if(root->left==NULL&&root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			node *aux = root->right;
			free(root);
			return aux;
		}
		else if(root->right==NULL){
			node *aux = root->left;
			free(root);
			return aux;
		}

		node *aux = minValueNode(root->right);
		root->data=aux->data;
		root->right=remove(root->right, aux->data);
	}
	return root;
}


int main(){
	node *tree;	

	cout << "BuildTree1: ";
	tree = buildTree1();
	printInOrder(tree);
	cout << endl;

	cout << "BuildTree2: ";
	tree = buildTree2();
	printInOrder(tree);
	cout << endl;

	cout << "BuildTree3: ";
	tree = buildTree3();
	printInOrder(tree);
	cout << endl;
	
	cout << "Size: ";
	cout << size(tree) << endl;

	tree=NULL;
	tree=insert(4, tree);
	tree=insert(2, tree);
	tree=insert(5, tree);
	tree=insert(1, tree);
	tree=insert(3, tree);
	cout << "Tree with 5 nodes: " << endl;
	printInOrder(tree);
	cout << endl;
	cout << "Size: ";
	cout << size(tree) << endl;
	
	cout << "MaxDepth: " << maxDepth(tree) << endl;
	cout << "minValue: " << minValue(tree) << endl;
	cout << "maxValue: " << maxValue(tree) << endl;
	
	cout << "In order: ";
	printInOrder(tree);
	cout << endl;
	cout << "PosOrder: ";
	printPosOrder(tree);
	cout << endl;
	cout << "size: " << size(tree) << endl;
	
	cout << "Print Tree in Bar Mode" << endl;
	printTreeInBarMode(tree, "");
	
	cout << endl << "=== hasPathSum ===" << endl;
	cout << "hasPathSum(tree, 10) = " << hasPathSum(tree, 10) << endl;
	cout << "hasPathSum(tree, 14) = " << hasPathSum(tree, 14) << endl; 
	cout << "hasPathSum(tree, 9) = " << hasPathSum(tree, 9) << endl;

	cout << endl << "=== Print Path Array: ===" << endl;
	printPaths(tree);
	cout << endl; 
	
	cout << endl << "=== Print Tree in Bar Mode before Mirror ===" << endl;
	printTreeInBarMode2(tree, "");
	cout << endl << "=== Print Tree in Bar Mode after Mirror ===" << endl;
	mirror(tree);
	printTreeInBarMode2(tree, "");
	
	doubleTree(tree);
	cout << "=== Print Tree in Bar Mode after doubletree ===" << endl;
	printTreeInBarMode(tree, "");

	// Trees to test sameTree function
	tree=NULL;
	tree=insert(4, tree);
	tree=insert(2, tree);
	tree=insert(5, tree);
	tree=insert(1, tree);
	tree=insert(3, tree);
	
	node *tree_same;
	tree_same=NULL;
	tree_same=insert(4, tree_same);
	tree_same=insert(2, tree_same);
	tree_same=insert(5, tree_same);
	tree_same=insert(1, tree_same);
	tree_same=insert(3, tree_same);

	node *tree_diff;
	tree_diff=NULL;
	tree_diff=insert(1, tree_diff);
	tree_diff=insert(3, tree_diff);
	tree_diff=insert(4, tree_diff);
	tree_diff=insert(2, tree_diff);
	tree_diff=insert(5, tree_diff);
	
	
	cout << endl << "=== sameTree ===" << endl;
	cout << "sameTree(tree, tree_same) = " << sameTree(tree, tree_same) << endl;
	cout << "sameTree(tree, tree_diff) = " << sameTree(tree, tree_diff) << endl;
	
	cout << endl << "=== countTree ===" << endl;
	cout << "countTree(4) = " << countTree(4) << endl;
	
	
	printTreeInBarMode2(tree, "");
	
	cout << endl << "=== isBST ===" << endl;
	cout << isBST(tree) << endl;
	mirror(tree); // uma BST espelhada não é BST
	cout << isBST(tree) << endl;
	
	cout << endl << "=== isBST2 ===" << endl;
	cout << "isBST2(tree) = " << isBST2(tree) << endl;
	
	mirror(tree); // uma espelho de BST espelhada é uma BST
	printTreeInBarMode2(tree, "");
	cout << "isBST2(tree) = " << isBST2(tree) << endl;
	
	cout << endl << "=== remove ===" << endl;
	remove(tree, 3);
	cout << "remove(tree, 3)" << endl;
	printTreeInBarMode2(tree, "");
	remove(tree, 4);
	cout << "remove(tree, 4)" << endl;
	printTreeInBarMode2(tree, "");
	
	return 0;
}

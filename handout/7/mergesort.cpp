/** 
 * \file mergesort.cpp
 *  
 * \brief Implementation of a class that contains a virtual method for
 * for  sorting an  array  of  integer numbers  using  the merge  sort
 * algorithm.
 *
 * \author
 * Marcelo Ferreira Siqueira \n
 * Universidade Federal do Rio Grande do Norte, \n
 * Departamento de Informatica e Matematica Aplicada, \n
 * marcelo at dimap (dot) ufrn (dot) br
 *
 * \version 1.0
 * \date April 2013
 *
 * \attention This program is distributed WITHOUT ANY WARRANTY, and it
 *            may be freely redistributed under the condition that the
 *            copyright notices  are not removed,  and no compensation
 *            is received. Private, research, and institutional use is
 *            free. Distribution of this  code as part of a commercial
 *            system  is permissible ONLY  BY DIRECT  ARRANGEMENT WITH
 *            THE AUTHOR.
 */

#include "mergesort.hpp"         // MergeSort


/**
 * \fn void MergeSort::sort( int* a , int size )
 *
 * \brief Sort an array of integers using the merge sort algorithm.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 */
void
MergeSort::sort( int* a , int size )
{
  mergesort(a, 0, size-1);

  return ;
  // ESCREVA O CÓDIGO DO MERGE SORT TOP-DOWN AQUI!

  // -----------------------------------------------------------------
  //
  // Esta implementação do mergesort() deve conter três otimizações. A
  // primeira é  a que dispensa a  cópia de elementos entre  o vetor a
  // ser  ordenado   e  o   vetor  auxiliar  dentro   do  procedimento
  // "merge()". A segunda é a  que dispensa a execução do procedimento
  // "merge()" quando todos os  elementos do subarray à esquerda forem
  // menores do que o primeiro elemento do subarray à direita.
  //
  // -----------------------------------------------------------------

}



/**
 * \fn void MergeSort::mergesort( int* a , int e , int d )
 *
 * \brief Recursively  sorts a subarray  delimited by the  indices "e"
 * and  "d"  of a  given  array "a",  using  the  top-down merge  sort
 * algorithm.
 *
 * \param a A pointer to an array of integers.
 * \param l The index of the first element of the left subarray of a.
 * \param r The index of the last element of the right subarray of a.
 */
void
MergeSort::mergesort( 
		     int* a ,
		     int l ,
		     int r
		    )
{
  // ESCREVA O CÓDIGO DO MERGESORT-AUX AQUI!
  if (l>=r){
    return;
  }

  int m = (l+r)/2;
  mergesort(a, l, m);
  mergesort(a, m+1, r);
  if (a[m]>a[m+1]){ // otimização 1: só chama merge se a[m]>a[m+1]
    // otimização 2: adição de array auxiliar na chamada a merge
    int tmp_size = r-l+1;
    int* b = new int[tmp_size];
    merge(a, b, l, m, r); // <- o array ordenado está em b

    // colocando o conteudo de b de volta em a
    for (int i=0; i<tmp_size; i++){
      a[l+i] = b[i];
    }

    delete b;
  }

  return;
}


/**
 * \fn void MergeSort::merge( int* a , int* b , int l , int m , int r )
 *
 * \brief  Merge two sorted,  consecutive subarrays  of a  given array
 * using an auxiliary array.  The result is a sorted subarray with the
 * same elements of the two  merged subarrays, and whose first element
 * occupies in  the first position of  the left subarray  and the last
 * element occupies the last position of the right subarray.
 *
 * \param a A pointer to an array of integers.
 * \param b A pointer to the auxiliary array.
 * \param l The index of the first element of the left subarray of a.
 * \param m The index of the last element of the left subarray of a.
 * \param r The index of the last element of the right subarray of a.
 */
void
MergeSort::merge( int* a , int* b , int l , int m , int r )
{
  // ESCREVA O CÓDIGO DO PROCEDIMENTO MERGE AQUI!
  int t = 0;
  int sl = l;
  int sr = m+1;
  // fazendo a intercalação dos elementos das duas partes de a em b
  while (sl<=m && sr <= r){
    if (a[sl]<=a[sr]){
        b[t] = a[sl];
        sl++;
    }else{
        b[t] = a[sr];
        sr++;
    };
    t++;
  };
  // copiando o restantes dos elementos da primeira parte de a para b
  while (sl<=m){
    b[t] = a[sl];
    sl++;
    t++;
  }
  //copiando o restantes dos elementos da segunda parte de a para b
  while(sr<=r){
    b[t] = a[sr];
    sr++;
    t++;
  }

  return ;

}

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

#include <iostream>            // cout, cerr, endl
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
}


/**
 * \fn void MergeSort::mergesort( int* a , int e, int d )
 *
 * \brief Recursively  sorts a subarray  of a given array  of integers
 * delimited by two given indices.
 *
 * \param a A pointer to an array of integers.
 * \param l The  index of the first element of  the subarray.
 * \param r The  index of the last element of the subarray.
 */
void
MergeSort::mergesort( int* a , int l, int r)
{
  // ESCREVA O CÓDIGO DO MERGE-SORT

  // -----------------------------------------------------------------
  //
  // Esta implementação do mergesort() não deve ser otimizada; isto é,
  // ela deve  corresponder à implementação do  pseudocódigo que vimos
  // em sala de aula.
  //
  // -----------------------------------------------------------------
  using std::cerr ;
  using std::endl ;
  
  if (l<r){
    int m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r); // Será que está certo essa chamada????
  }
  
  return;
}


/**
 * \fn void merge( int* a , int* b , int e , int m , int d )
 *
 * \brief  Merge two sorted,  consecutive subarrays  of a  given array
 * using an auxiliary array.  The result is a sorted subarray with the
 * same elements of the two  merged subarrays, and whose first element
 * occupies in  the first position of  the left subarray  and the last
 * element occupies the last position of the right subarray.
 *
 * \param a A pointer to an array of integers.
 * \param l The index of the first element of the left subarray of a.
 * \param m The index of the last element of the left subarray of a.
 * \param r The index of the last element of the right subarray of a.
 */
void
MergeSort::merge( int* a, int l, int m, int r )
{
  // ESCREVA O CÓDIGO DO PROCEDIMENTO MERGE AQUI!
  int* b = new int[r-l+1];

  int t = 0;
  int sl = l;
  int sr = m+1;
  while (sl<=m && sr < r){
    if (a[sl]<=a[sr]){
        b[t] = a[sl];
        sl++;
    }else{
        b[t] = a[sr];
        sr++;
    };
    t++;
  };
  while (sl<=m){
    b[t] = a[sl];
    sl++;
    t++;
  }
  while(sr<=r){
    b[t] = a[sr];
    sr++;
    t++;
  }

  for(int i=0; i<=r-l; i++){
    a[l+i] = b[1+i];
  }

  return ;
}

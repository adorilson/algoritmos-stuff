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
void MergeSort::sort(int* a ,	int size )
{
  // mergesort(a, size -1);
  int d = 0;
  int e = 0;
  int m = 0;
  int findFirstArray = 0;
  int isOrdered = 0;  
  while(isOrdered==0){
    isOrdered=1;

    while ((d < size - 1)) {
      if (a[d] <= a[d + 1]) {
          if(findFirstArray==0){
            m++;
          }
          d++;
      } else {
          isOrdered = 0;
          if(findFirstArray==0){
            d++;
            findFirstArray=1;
          }
          else{
            merge(a, e, m, d);
            findFirstArray=0;
            d++;
            e=d;
            m=d;
          }
      }
    }

    if(findFirstArray==1){
      merge(a, e, m, d);
    }
    d=0;
    e=0;
    m=0;
    findFirstArray=0;
  }

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

  // -----------------------------------------------------------------
  //
  // ESCREVA O CÓDIGO DO MERGESORT AQUI!
  //
  // Este  método  deve  ser  uma  espécie  de  merge  sort  bottom-up
  // modificado   para  considerar   subarranjos   contendo  elementos
  // ordenados apenas. Esta  modificação pode descaracterizar o método
  // visto em  sala de aula  completamente. Logo, você deve  pensar em
  // termos de algoritmo primeiro.
  //
  // -----------------------------------------------------------------

  if (l<r){
    int m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
  }
   
  return;
}

/**
 * \fn void MergeSort::merge( int* a , int l , int m , int r )
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
void MergeSort::merge(int* a , int l , int m , int r)
{
  // ESCREVA O CÓDIGO DO PROCEDIMENTO MERGE AQUI!
  int temp_size = r-l+1;
  int* b = new int[temp_size];

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

  // copiando b para o subarray de a
  for(int i=0; i<temp_size; i++){
    a[l+i] = b[i];
  }

  delete b;
  return ;

}

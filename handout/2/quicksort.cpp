/** 
 * \file quicksort.cpp
 *  
 * \brief Implementation of a class that contains a virtual method for
 * for  sorting  an  array  of  integer numbers  using  the  quicksort
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

#include "quicksort.hpp"         // QuickSort


/**
 * \fn void QuickSort::sort( int* a , int size )
 *
 * \brief Sort an array of integers using the quicksort algorithm.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 */
void
QuickSort::sort( int* a , int size )
{
  /*
   * Initialize the number of key comparisons and array accesses.
   */
  _ncomps = 0 ;
  _nacces = 0 ;

  quicksort( a , 0 , size - 1 ) ;
}


/**
 * \fn void QuickSort::quicksort( int* a , int e , int d )
 *
 * \brief Recursively  sorts a subarray  of a given array  of integers
 * delimited by two given indices.
 *
 * \param a A pointer to an array of integers.
 * \param e The  index of the first element of  the subarray.
 * \param d The  index of the last element of the subarray.
 */
void
QuickSort::quicksort( int* a , int e , int d )
{
  // ESCREVA O CÓDIGO DO QUICKSORT AQUI!
  if (e<d){
    int m = partition(a, e, d);
    quicksort(a, e, m);
    quicksort(a, m+1, d);
  }
}


/**
 * \fn int QuickSort::partition( int* a , int e , int d )
 *
 * \brief Partitions a subarray of  a given array around an element of
 * the subarray, called pivot, such  that all subarray elements on the
 * left of the pivot are less  than or equal to it, while all subarray
 * elements on the right of the pivot are greater than or equal to it.
 *
 * \param a A pointer to an array of integers.
 * \param e The  index of the first element of the subarray.
 * \param d The  index of the last element of  the subarray.
 *
 * \return The index of the pivot.
 */
int
QuickSort::partition( int* a , int e , int d )
{
  // ------------------------------------------------------------------
  //
  // ESCREVA O CÓDIGO DO PROCEDIMENTO PARTITION() AQUI!
  //
  // Você deverá inserir chamadas a
  //
  // increment_the_number_of_array_accesses()
  //
  // e a 
  //
  // increment_the_number_of_key_comparisons()
  //
  // para  contar o  número de  acessos a  elementos do  arranjo  e de
  // comparações entre chaves.
  //
  // -----------------------------------------------------------------

  int p = a[e]; // não conta aqui pq conta abaixo
  int i = e; // na descrição do projeto esta x-1
  int j = d;
  while (true){
    while (a[j]>p){
        increment_the_number_of_key_comparisons(1);
        increment_the_number_of_array_accesses(1);
        j--;
    }
    increment_the_number_of_key_comparisons(1);
    increment_the_number_of_array_accesses(1);
    
    while (a[i]<p){
        increment_the_number_of_key_comparisons(1);
        increment_the_number_of_array_accesses(1);
        i++;
    }
    increment_the_number_of_key_comparisons(1);
    increment_the_number_of_array_accesses(1);
    
    if (i<j){
        int aux = a[i];
        a[i] = a[j];
        a[j] = aux;
        i++;
        increment_the_number_of_array_accesses(4);
    }else{
        return j;
    }
  }
}

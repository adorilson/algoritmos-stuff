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
  // ESCREVA O CÓDIGO DO QUICKSORT-AUX AQUI!

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
  // ESCREVA O CÓDIGO DO PARTITION AQUI!

  // REMOVA A LINHA ABAIXO:
  return 0 ;
}

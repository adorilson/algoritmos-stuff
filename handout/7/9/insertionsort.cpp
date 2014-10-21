/** 
 * \file insertionsort.cpp
 *  
 * \brief Implementation of a class that contains a virtual method for
 * for sorting  an array of  integer numbers using the  insertion sort
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

#include "insertionsort.hpp"         // InsertionSort


/**
 * \fn void InsertionSort::sort( int* a , int size )
 *
 * \brief Sort an array of integers using the insertion sort method.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 */
void
InsertionSort::sort( int* a , int size )
{
  for ( int i = 1 ; i < size ; i++ ) {
    int x = a[ i ] ;
    int j = i - 1 ; 
    while ( ( j >= 0 ) && ( a[ j ] > x ) ) {
      a[ j + 1 ] = a[ j ] ;
      --j ;
    }
    a[ j + 1 ] = x ;
  }

  return ;
}

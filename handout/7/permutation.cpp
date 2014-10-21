/** 
 * \file permutation.cpp
 *  
 * \brief Implementation of class Permutation, which contains a method
 * for  generating  the "next"  permutation  of  an  array of  integer
 * numbers. The next  permutation is the one that  follows the current
 * permutation of the  array in a sequence of  permutations. The first
 * permutation of the array is the  one defined by a sorted array. So,
 * to generate  the N!, the  method must be  called N! - 1  times such
 * that the i-th call takes  in the permutation returned by the method
 * for the (i-1)-th  execution. In addition, the very  first call must
 * take in the sorted array.
 *
 * \author
 * Marcelo Ferreira Siqueira \n
 * Universidade Federal do Rio Grande do Norte, \n
 * Departamento de Informatica e Matematica Aplicada, \n
 * mfsiqueira at dimap (dot) ufrn (dot) br
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

#include "permutation.hpp"     // Permutation


// -------------------------------------------------------------------
//
// Public methods
//
// -------------------------------------------------------------------

/**
 * \fn void Permutation::permute( int* a , int size )
 *
 * \brief Generates the "next" permutation  of a given array. The next
 * permutation is the one that  follows the current permutation of the
 * array in a  sequence of permutations. The first  permutation of the
 * array is the one defined by a sorted array. So, to generate the N!,
 * the method  must be  called N! -  1 times  such that the  i-th call
 * takes in  the permutation returned  by the method for  the (i-1)-th
 * execution. In addition, the very first call must take in the sorted
 * array.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 *
 */
void 
Permutation::permute( int* a , int size )
{    
  /*
   * Find the largest index j for which a[ j ] < a[ j + 1 ]. 
   */
  int j = size - 2 ;
  while ( ( j > 0 ) && ( a[ j ] > a[ j + 1 ] ) ) {
    --j ;
  }

  /*
   * Find the  element, a[ k ],  which is the  smaller integer greater
   * than a[ j ] to the right  of a[ j ], and then interchange it with
   * a[ j ].
   */
  int k = size - 1 ;
  while ( a[ k ] < a[ j ] ) {
    --k ;
  }

  int temp = a[ k ] ;
  a[ k ] = a[ j ] ;
  a[ j ] = temp ;

  /*
   * Puts the tail  end of the permutation after  the j-th position in
   * increasing order.
   */

  int r = size - 1 ;
  int s = j + 1 ;
  while ( r > s ) {
    int temp = a[ r ] ;
    a[ r ] = a[ k ] ;
    a[ k ] = temp ;

    r = r - 1 ;
    s = s + 1 ;
  }

  return ;
}

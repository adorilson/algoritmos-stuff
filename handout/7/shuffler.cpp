/** 
 * \file shuffler.cpp
 *  
 * \brief Implementation  of class  Shuffler, which contains  a method
 * for  shuffling an array  of integer  numbers using  a pseudo-random
 * number generator.
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

#include "shuffler.hpp"     // Shuffler


// -------------------------------------------------------------------
//
// Public methods
//
// -------------------------------------------------------------------

/**
 * \fn void Shuffler::shuffle( int* a , int size )
 *
 * \brief Shuffles  an array of integer numbers  using a pseudo-random
 * number generator.  In principle,  any permutation of the numbers is
 * equally likely to be the result of one execution of this method.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 *
 */
void 
Shuffler::shuffle( int* a , int size )
{    
  /*
   * Shuffle the array.
   */
  for ( int i = 0 ; i < size ; i++ ) 
  {
    /*
     * Draw a pseudo-random number in the interval [ i , size - 1 ].
     */
    int index = _drawer.draw( size , i ) ;
	
    /*
     * Exchange the elements a[ i ] and a[ index ]
     */
    int temp = a[ index ] ;
    a[ index ] = a[ i ] ;
    a[ i ] = temp ;
  }

  return ;
}

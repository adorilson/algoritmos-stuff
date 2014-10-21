/** 
 * \file shuffler.hpp
 *  
 * \brief Definition  of class Shuffler,  which contains a  method for
 * shuffling an array of  integer numbers using a pseudo-random number
 * generator.
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

#ifndef SHUFFLER_HPP
#define SHUFFLER_HPP


#include "randint.hpp"     // Randint


/**
 * \class Shuffler
 *
 * \brief This class contains a  method for shuffling a given array of
 * integer numbers (using a pseudo-random number generator).
 */
class Shuffler {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn Shuffler( )
   *
   * \brief Constructor.
   *
   */
  Shuffler()
  {
  }


  /**
   * \fn void shuffle( int* a , int size )
   *
   * \brief Shuffles an array of integer numbers using a pseudo-random
   * number generator.   In principle, any permutation  of the numbers
   * is  equally likely  to be  the result  of one  execution  of this
   * method.
   *
   * \param a A pointer to an array of integers.
   * \param size The number of elements in the array.
   *
   */
  void shuffle( int* a , int size ) ;


  // -----------------------------------------------------------------
  //
  // Private attributes
  //
  // -----------------------------------------------------------------

  Randint _drawer ;    ///< a pseudo-random generator.

} ;

#endif    // SHUFFLER_HPP

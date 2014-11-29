/** 
 * \file randint.hpp
 *  
 * \brief Definition  and implementation of class Randint,  which is a
 * pseudorandom number  generator that draws  pseudorandom number from
 * the interval [i,  N-1], where i and N,  with 0 <= i <  N, are given
 * numbers.
 *
 * \author
 * Luciane Machado Fraga \n
 * Universidade Federal do Rio Grande do Norte, \n
 * Departamento de Informatica e Matematica Aplicada, \n
 * lmfraga at gmail (dot) com
 *
 * \author
 * Marcelo Ferreira Siqueira \n
 * Universidade Federal do Rio Grande do Norte, \n
 * Departamento de Informatica e Matematica Aplicada, \n
 * mfsiqueira at dimap (dot) ufrn (dot) br
 *
 * \version 1.0
 * \date September 2012
 *
 * \attention This program is distributed WITHOUT ANY WARRANTY, and it
 *            may be freely redistributed under the condition that the
 *            copyright notices  are not removed,  and no compensation
 *            is received. Private, research, and institutional use is
 *            free. Distribution of this  code as part of a commercial
 *            system  is permissible ONLY  BY DIRECT  ARRANGEMENT WITH
 *            THE AUTHOR.
 */

#ifndef RANDINT_HPP
#define RANDINT_HPP

#include <cstdlib>        // srand()
#include <ctime>          // time()
#include <cassert>        // assert()


/**
 * \class Randint
 *
 * \brief This class represents a generator of pseudo-random, which is
 * a pseudorandom number generator that draws pseudorandom number from
 * the interval [i,  N-1], where i and N,  with 0 <= i <  N, are given
 * numbers.
 */
class Randint {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn Randint( )
   *
   * \brief Constructor.
   *
   */
  Randint()
  {
    srand( ( unsigned ) time( 0 ) ) ;
  }


  /**
   * \fn unsigned draw( unsigned int n , unsigned int i )
   *
   * \brief Returns a random number from the interval [i, n-1]
   *
   * \param n A positive integer number.
   * \param i A non-negative integer number.
   *
   * \return A random number from the interval [i, n-1].
   */
  unsigned draw( 
		unsigned int n ,
		unsigned int i 
	       ) 
  {
    //
    // Check pre-conditions:
    //
    // n > 0 && ( i < n )
    //
    assert( ( n > 0 ) && ( i < n ) ) ;

    return unsigned( i + ( rand() % ( n - i ) ) ) ;
  }

} ;

#endif    // RANDINT_HPP

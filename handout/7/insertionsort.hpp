/** 
 * \file insertionsort.hpp
 *  
 * \brief Definition of a class that contains a virtual method for for
 * sorting  an  array of  integer  numbers  using  the insertion  sort
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

#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP


#include "mysort.hpp"         // MySort


/**
 * \class InsertionSort
 *
 * \brief This class contains a virtual method for sorting an array of
 * integer numbers using the insertion sort algorithm.
 *
 */
class InsertionSort : public MySort {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn InsertionSort()
   *
   * \brief Default constructor.
   */
  InsertionSort()  
  {
  }


  /**
   * \fn virtual void sort( int* a , int size )
   *
   * \brief  Sort  an  array  of  integers using  the  insertion  sort
   * algorithm.
   *
   * \param a A pointer to an array of integers.
   * \param size The number of elements in the array.
   */
  virtual void sort( int* a , int size ) ;

} ;

#endif    // INSERTIONSORT_HPP

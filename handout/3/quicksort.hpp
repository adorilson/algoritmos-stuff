/** 
 * \file quicksort.hpp
 *  
 * \brief Definition of a class that contains a virtual method for for
 * sorting an array of integer numbers using the quicksort algorithm.
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

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP


#include "mysort.hpp"         // MySort


/**
 * \class QuickSort
 *
 * \brief This class contains a virtual method for sorting an array of
 * integer numbers using the quicksort algorithm - the one given by C.
 * A. Hoare.
 */
class QuickSort : public MySort {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn QuickSort()
   *
   * \brief Default constructor.
   */
  QuickSort()  
  {
  }


  /**
   * \fn virtual void sort( int* a , int size )
   *
   * \brief Sort an array of integers using the quicksort algorithm.
   *
   * \param a A pointer to an array of integers.
   * \param size The number of elements in the array.
   */
  virtual void sort( int* a , int size ) ;


private:

  // -----------------------------------------------------------------
  //
  // Private methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn void quicksort( int* a , int e , int d )
   *
   * \brief Recursively sorts a subarray  of a given array of integers
   * delimited by two given indices.
   *
   * \param a A pointer to an array of integers.
   * \param e The  index of the first element of  the subarray.
   * \param d The  index of the last element of the subarray.
   */
  void quicksort( int* a , int e , int d ) ;


  /**
   * \fn int partition( int* a , int e , int d )
   *
   * \brief Partitions a  subarray of a given array  around an element
   * of the subarray, called pivot, such that all subarray elements on
   * the left  of the pivot  are less than  or equal to it,  while all
   * subarray elements on  the right of the pivot  are greater than or
   * equal to it.
   *
   * \param a A pointer to an array of integers.
   * \param e The  index of the first element of the subarray.
   * \param d The  index of the last element of  the subarray.
   *
   * \return The index of the pivot.
   */
  int partition( int* a , int e , int d ) ;

} ;

#endif    // QUICKSORT_HPP

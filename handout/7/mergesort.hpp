/** 
 * \file mergesort.hpp
 *  
 * \brief Definition of a class that contains a virtual method for for
 * sorting an array of integer numbers using the mergesort algorithm.
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

#ifndef MERGESORT_HPP
#define MERGESORT_HPP


#include "mysort.hpp"         // MySort


/**
 * \class MergeSort
 *
 * \brief This class contains a virtual method for sorting an array of
 * integer numbers using the insertion sort algorithm.
 *
 */
class MergeSort : public MySort {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn MergeSort()
   *
   * \brief Default constructor.
   */
  MergeSort()  
  {
  }


  /**
   * \fn virtual void sort( int* a , int size )
   *
   * \brief Sort an array of integers using the merge sort algorithm.
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
   * \fn void mergesort( int* a , int e , int d )
   *
   * \brief Recursively sorts a  subarray delimited by the indices "e"
   * and  "d" of  a given  array "a",  using the  top-down  merge sort
   * algorithm.
   *
   * \param a A pointer to an array of integers.
   * \param e The  index of the first element of  the left subarray of
   * a.
   * \param d The  index of the last element of  the right subarray of
   * a.
   */
  void mergesort( int* a , int l , int r ) ;


  /**
   * \fn void merge( int* a , int* b , int l , int m , int r )
   *
   * \brief Merge  two sorted, consecutive subarrays of  a given array
   * using an auxiliary  array.  The result is a  sorted subarray with
   * the same  elements of the  two merged subarrays, and  whose first
   * element occupies in  the first position of the  left subarray and
   * the  last  element  occupies  the  last  position  of  the  right
   * subarray.
   *
   * \param a A pointer to an array of integers.
   * \param b A pointer to the auxiliary array.
   * \param l The  index of the first element of  the left subarray of
   * a.
   * \param m The index of the last element of the left subarray of a.
   * \param r The  index of the last element of  the right subarray of
   * a.
   */
  void merge( int* a , int* b , int l , int m , int r ) ;
  
} ;


#endif    // MERGESORT_HPP

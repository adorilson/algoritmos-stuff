/** 
 * \file mysort.hpp
 *  
 * \brief Definition of an abstract class that contains a pure virtual
 * method for sorting an array of integer numbers.
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

#ifndef MYSORT_HPP
#define MYSORT_HPP


/**
 * \class MySort
 *
 * \brief This abstract class defines an interface of concrete classes
 * for sorting arrays of  integer numbers using some available sorting
 * method.
 */
class MySort {
public:
  // -----------------------------------------------------------------
  //
  // Public methods
  //
  // -----------------------------------------------------------------

  /**
   * \fn MySort()
   *
   * \brief Default constructor.
   */
  MySort()  
  {
  }


  /**
   * \fn virtual void sort( int* a , int size ) = 0
   *
   * \brief Sort an array of integers.
   *
   * \param a A pointer to an array of integers.
   * \param size The number of elements in the array.
   */
  virtual void sort( int* a , int size ) = 0 ;

} ;

#endif    // MYSORT_HPP

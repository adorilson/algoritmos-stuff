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
  MySort() : 
    _ncomps( 0 ) ,
    _nacces( 0 )
  {
  }


  /**
   * \fn unsigned get_the_number_of_key_comparisons() const
   *
   * \brief Returns  of the number  of key comparisons carried  out by
   * the last execution of the sorting method.
   *
   * \return The  number of  key comparisons carried  out by  the last
   * execution of the sorting method.
   */
  unsigned get_the_number_of_key_comparisons() const
  {
    return _ncomps ;
  }


  /**
   * \fn unsigned get_the_number_of_array_accesses() const
   *
   * \brief Returns of the number of array accesses carried out by the
   * last execution of the sorting method.
   *
   * \return  The number  of array  accesses carried  out by  the last
   * execution of the sorting method.
   */
  unsigned get_the_number_of_array_accesses() const
  {
    return _nacces ;
  }


  /**
   * \fn void increment_the_number_of_key_comparisons( unsigned n )
   *
   * \brief Increments  the number of  key comparisons carried  out by
   * the last execution of the sorting method.
   *
   * \param n The factor to be added to the number of key comparisons.
   */
  void increment_the_number_of_key_comparisons( unsigned n )
  {
    _ncomps = _ncomps + int( n ) ;
  }


  /**
   * \fn void increment_the_number_of_array_accesses( unsigned n )
   *
   * \brief Increments the number of array accesses carried out by the
   * last execution of the sorting method.
   *
   * \param n The factor to be added to the number of key comparisons.
   */
  void increment_the_number_of_array_accesses( unsigned n )
  {
    _nacces = _nacces + int( n ) ;
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


protected:


  // -----------------------------------------------------------------
  //
  // Protected data
  //
  // -----------------------------------------------------------------

  unsigned _ncomps ;   ///< number of key comparisons of the sorting method.
  unsigned _nacces ;   ///< number of array accesses of the sorting method.

} ;

#endif    // MYSORT_HPP

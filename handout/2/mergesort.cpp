/** 
 * \file mergesort.cpp
 *  
 * \brief Implementation of a class that contains a virtual method for
 * for  sorting an  array  of  integer numbers  using  the merge  sort
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

#include "mergesort.hpp"         // MergeSort


/**
 * \fn void MergeSort::sort( int* a , int size )
 *
 * \brief Sort an array of integers using the merge sort algorithm.
 *
 * \param a A pointer to an array of integers.
 * \param size The number of elements in the array.
 */
void
MergeSort::sort( int* a , int size )
{
  /*
   * Initialize the number of key comparisons and array accesses.
   */
  _ncomps = 0 ;
  _nacces = 0 ;


  // ESCREVA O RESTANTE DO CÓDIGO DO MERGESORT BOTTOM-UP AQUI!

  // -----------------------------------------------------------------
  //
  // Esta  implementação do mergesort()  não precisa  estar otimizada,
  // mas você  deve contar o número  de comparações entre  chaves e de
  // acessos a elementos  de array nesta função e  na função intercala
  // (merge).
  //
  // -----------------------------------------------------------------
}


/**
 * \fn void merge( int* a , int* b , int e , int m , int d )
 *
 * \brief  Merge two sorted,  consecutive subarrays  of a  given array
 * using an auxiliary array.  The result is a sorted subarray with the
 * same elements of the two  merged subarrays, and whose first element
 * occupies in  the first position of  the left subarray  and the last
 * element occupies the last position of the right subarray.
 *
 * \param a A pointer to an array of integers.
 * \param b A pointer to the auxiliary array.
 * \param e The index of the first element of the left subarray of a.
 * \param m The index of the last element of the left subarray of a.
 * \param d The index of the last element of the right subarray of a.
 */
void
MergeSort::merge( int* a , int* b , int e , int m , int d )
{
  // ------------------------------------------------------------------
  //
  // ESCREVA O CÓDIGO DO PROCEDIMENTO MERGE AQUI!
  //
  // Você deverá inserir chamadas a
  //
  // increment_the_number_of_array_accesses()
  //
  // e a 
  //
  // increment_the_number_of_key_comparisons()
  //
  // para  contar o  número de  acessos a  elementos do  arranjo  e de
  // comparações entre chaves.
  //
  // -----------------------------------------------------------------

  return ;
}

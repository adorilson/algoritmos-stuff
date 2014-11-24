/** 
 * \file mainapp.cpp
 *  
 * \brief This application creates an array consisting of the integers
 * from 1  to N, where N is  a given integer, shuffles  the array, and
 * then  sorts the  array using  the mergesort()  and  the quicksort()
 * algorithms. The  average number of key comparisons  and the average
 * number of array  accesses are computed and then  written out to the
 * standard output.
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

#include <cstdlib>             // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream>            // cout, cerr, endl
#include <ios>                 // std::scientific
#include <iomanip>             // std::setprecision(), std::setw()

#include "mysort.hpp"          // MySort
#include "mergesort.hpp"       // MergeSort
#include "quicksort.hpp"       // QuickSort

#include "shuffler.hpp"        // Shuffler

/**
 * \fn int main()
 *
 * \brief Executes  the mergesort() and the  quicksort() algorithms on
 * several arrays of  varying size, and then counts  the number of key
 * comparisons and  the number of  array accesses carried out  by each
 * method.
 *
 * \return The status of the function termination.
 *
 * -------------------------------------------------------------------
 *
 * You should run this code with the following command-line:
 *
 * ./mainapp 
 *
 * or
 *
 * ./mainapp > output filename
 *
 * -------------------------------------------------------------------
 */
int main()
{
  /*
   * Usage: ./mainapp [ > output filename ]
   */
  using std::cout ;
  using std::cerr ;
  using std::endl ;

  /*
   * Instantiate the mergesort and quicksort objects.
   */
  MySort* ms_sorter = new MergeSort() ;
  MySort* qs_sorter = new QuickSort() ;

  /*
   * Instantiate the array "shuffler".
   */
  Shuffler shuffler ;


  /*
   * Run the method for arrays of size 2^i, where i = 3,...,20.
   */
  cerr << "Executing the sorting method on 18 distinctly-sized arrays (100 times for each)..."
       << endl ;

  int n = 8 ;

  for ( int i = 0 ; i < 18 ; i++ ) {
    cerr << endl ;
    cerr << "-----------------------------------------------------" 
	 << endl ;
    cerr << "Allocating memory for an array of size "
         << n
         << "..."
	 << endl ;

    /*
     * Allocate memory for two arrays of n integers each.
     */
    int* a = new int[ n ] ;
    int* b = new int[ n ] ;

    cerr << "Filling in the array with integers from 1 to "
         << n
         << "..."
	 << endl ;

    /*
     * Fill out the array with the integers from 1 to n.
     */
    for ( int i = 0 ; i < n ; i++ ) {
      a[ i ] = i + 1 ;
    }

    /*
     * Execute each method 100 times for the exact same input. In each
     * execution the  input is  a permutation of  the same array  of n
     * numbers.
     */

    cerr << "Shuffling and sorting the array 100 times..."
	 << endl ;

    cerr << "This may take some time... Get a coffee or play a game!"
         << endl ;

    double ms_comps = 0 ;
    double qs_comps = 0 ;
    double ms_acces = 0 ;
    double qs_acces = 0 ;

    for ( int j = 0 ; j < 100 ; j++ ) {
      /*
       * Shuffle the  array (again). In principle,  any permutation of
       * the  array is  equally likely  to be  produced by  the method
       * shuffle().
       */
      shuffler.shuffle( &a[ 0 ] , n ) ;

      /*
       * Copy array "a" to array "b".
       */
      for ( int i = 0 ; i < n ; i++ ) {
	b[ i ] = a[ i ] ;
      }

      /*
       * Sort the  array in non-decreasing  order and record  the time
       * (in milliseconds)  that the mergesort algorithm  took to sort
       * the array.
       */
      clock_t start , end ;
      
      start = clock() ;
      ms_sorter->sort( a , n ) ;
      end = clock() ;

      /*
       * Check if the sorting method correctly sorted the array. If it
       * did, then write  out the size of the  array and the execution
       * time.  Otherwise,  write out an  error message and  abort the
       * execution.
       */

      for ( int j = 1 ; j < n ; j++ ) {
	if ( a[ j ] < a[ j - 1 ] ) {
	  cerr << "Your implementation of the merge sort algorithm is incorrect!" << endl;
	  return EXIT_FAILURE ;
	}
      }

      /*
       * Get the number of key comparisons.
       */
      ms_comps += ms_sorter->get_the_number_of_key_comparisons() ;
      
      /*
       * Get the number of array acesses.
       */
      ms_acces += ms_sorter->get_the_number_of_array_accesses() ;


      /*
       * Sort the  array in non-decreasing  order and record  the time
       * (in milliseconds)  that the quicksort algorithm  took to sort
       * the array.
       */      
      start = clock() ;
      qs_sorter->sort( b , n ) ;
      end = clock() ;

      /*
       * Check if the sorting method correctly sorted the array. If it
       * did, then write  out the size of the  array and the execution
       * time.  Otherwise,  write out an  error message and  abort the
       * execution.
       */

      for ( int j = 1 ; j < n ; j++ ) {
	if ( b[ j ] < b[ j - 1 ] ) {
	  cerr << "Your implementation of the quick sort algorithm is incorrect!" 
	       << endl ;
	  return EXIT_FAILURE ;
	}
      }

      /*
       * Get the number of key comparisons.
       */
      qs_comps += qs_sorter->get_the_number_of_key_comparisons() ;
      
      /*
       * Get the number of array acesses.
       */
      qs_acces += qs_sorter->get_the_number_of_array_accesses() ;
    }

    cerr << "Done sorting..."
         << endl ;
      
    /*
     * Write  out  the array  size  and  the  average numbers  of  key
     * comparisons and  array accesses of both algorithms  in a single
     * line.
     */

    cout << std::fixed << std::setprecision( 0 ) ;

    cout << n 
         << '\t'
	 << std::setw( 15 )
         << ms_comps 
         << '\t'
	 << std::setw( 15 )
         << ms_acces
         << '\t'
	 << std::setw( 15 )
         << qs_comps 
         << '\t'
	 << std::setw( 15 )
         << qs_acces
	 << endl ; 

    /*
     * Double the size of the array.
     */
    n <<= 1 ;

    /*
     * Release the memory allocated for the arrays.
     */
    if ( a != 0 ) {
      delete a ;
    }

    if ( b != 0 ) {
      delete b ;
    }

    cerr << "-----------------------------------------------------" 
         << endl ;
  }

  /*
   * Release the memory allocated for the sorting method objects.
   */
  if ( ms_sorter != 0 ) {
    delete ms_sorter ;
  }

  if ( qs_sorter != 0 ) {
    delete qs_sorter ;
  }

  cerr << endl << endl ;

  return EXIT_SUCCESS ;
}

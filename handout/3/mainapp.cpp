/** 
 * \file mainapp.cpp
 *  
 * \brief This application creates an array consisting of the integers
 * from 1  to N, where N is  a given integer, shuffles  the array, and
 * then  sorts the  array using  the mergesort()  and  the quicksort()
 * algorithms. The  average execution times of each  algorithm on each
 * same-sized  array are  recorded  and written  out  to the  standard
 * output.  The  required implementation  of the merge  sort algorithm
 * must  contain two  optimizations: a  test whether  the  subarray is
 * already sorted,  and the elimination  of the copy to  the auxiliary
 * array.
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
#include <ctime>               // time, clock, CLOCKS_PER_SEC, clock_t 

#include "mysort.hpp"          // MySort
#include "mergesort.hpp"       // MergeSort
#include "quicksort.hpp"       // QuickSort

#include "shuffler.hpp"        // Shuffler

using std::cout ;
using std::cerr ;
using std::endl ;

/**
  util functions
*/

void print(int* a, int l, int r){
  for(int i=l; i<=r; i++){
    cerr << a[i] << " ";
  }
  cerr << endl;
}


/**
 * \fn int main()
 *
 * \brief Executes  the mergesort() and the  quicksort() algorithms on
 * several  arrays of  varying  size, and  then  computes the  average
 * execution time of  each method on each array of  the same size. The
 * size  of each  array is  always a  power of  2, varying  from  8 to
 * 2^20. The average  execution times are written out  to the standard
 * output.
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
   * Set up the format for displaying the output numbers.
   */
  cout << std::scientific << std::setprecision( 16 ) ;
  
  /*
   * Set up the execution params
   */
  int begin_power = 3;
  int end_power = 20;
  int times_sorting = 5;

  /*
   * Run the method for arrays of size 2^i
   */
  cerr << "Executing the sorting method on " << end_power - begin_power + 1
        << " distinctly-sized arrays (" << times_sorting << ") times for each)..."
       << endl ;

  cerr << endl ;

  cerr << "This may take some time... Get a coffee or play a game!"
       << endl ;

  cerr << endl ;

  int n = 2;
  n <<= begin_power-1;

  for ( int i = begin_power ; i <= end_power ; i++ ) {
    cerr << endl ;
    cerr << "-----------------------------------------------------" 
         << endl ;
    cerr << "Allocating memory for an array of size "
         << n << " (2^" << i << ")"
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
     * Execute the method some times, each of which takes in a possibly
     * distinct permutation of  the array.  This is not  ideal, as the
     * number of permutations of  the arrays grows exponentially as we
     * double the size of the array.   However, if we try to be "fair"
     * (say, by executing the method a  number of times equal to 1% of
     * the number of permutations), this application will take forever
     * to run.   So, just keep in  mind that the average  time is less
     * representative  as the  size of  the array  grows (this  is not
     * ideal).
     */

    cerr << "Shuffling and sorting the array " << times_sorting << " times..."
         << endl ;

    double mstime = 0 ;
    double qstime = 0 ;

    for ( int j = 0 ; j < times_sorting ; j++ ) {
      /*
       * Shuffle the  array (again). In principle,  any permutation of
       * the  array is  equally likely  to be  produced by  the method
       * shuffle().
       */
      shuffler.shuffle( &a[ 0 ] , n ) ;

      /*
       * Make a copy of array "a".
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
       * Compute the cpu time of the execution.
       */
      mstime += double( end - start ) ;
    
      /*
       * Check if the sorting method correctly sorted the array. If it
       * did, then write  out the size of the  array and the execution
       * time.  Otherwise,  write out an  error message and  abort the
       * execution.
       */
      for ( int j = 1 ; j < n ; j++ ) {
        if ( a[ j ] < a[ j - 1 ] ) {
          cerr << "Your implementation of the mergesort algorithm is incorrect!" << endl ;
          return EXIT_FAILURE ;
        }
      }

      /*
       * Sort the  array in non-decreasing  order and record  the time
       * (in milliseconds) that the  quick sort algorithm took to sort
       * the array.
       */     
      start = clock() ;
      qs_sorter->sort( b , n ) ;
      end = clock() ;

      /*
       * Compute the cpu time of the execution.
       */
      qstime += double( end - start ) ;
    
      /*
       * Check if the sorting method correctly sorted the array. If it
       * did, then write  out the size of the  array and the execution
       * time.  Otherwise,  write out an  error message and  abort the
       * execution.
       */
      for ( int j = 1 ; j < n ; j++ ) {
        if ( b[ j ] < b[ j - 1 ] ) {
          cerr << "Your implementation of the quicksort algorithm is incorrect!" << endl ;
          return EXIT_FAILURE ;
        }
      }

    cerr << "Done sorting for array with " << n << " elements "
        << "the " << j+1 << "th time" 
        << endl ;
    }
    /*
     * Write out array size and the average execution size.
     */
    cout << n 
         << '\t'
         << std::setw( 24 )
         << mstime / ( 100 * CLOCKS_PER_SEC )
         << '\t'
         << std::setw( 24 )
         << qstime / ( 100 * CLOCKS_PER_SEC )
	 << endl ; 

    /*
     * Double the size of the array.
     */
    n <<= 1 ;

    /*
     * Release the memory allocated for the arrays "a" and "b".
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

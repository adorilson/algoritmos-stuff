/** 
 * \file mainapp.cpp
 *  
 * \brief This application has  the purpose of comparing the execution
 * time of two  sorting algorithms, insertion sort and  merge sort, on
 * several inputs consisting of a permutation of 1,...,N, where N is a
 * given integer.
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

#include <cstdlib>             // EXIT_SUCCESS, EXIT_FAILURE, atoi()
#include <iostream>            // cout, cerr, endl
#include <ios>                 // std::scientifc
#include <iomanip>             // std::setprecision(), std::setw()
#include <ctime>               // time, clock, CLOCKS_PER_SEC, clock_t 
#include <cassert>             // assert()

#include "mysort.hpp"          // MySort
#include "insertionsort.hpp"   // InsertionSort
#include "mergesort.hpp"       // MergeSort

#include "shuffler.hpp"        // Shuffler


/**
 * \fn int main( int argc , char* argv[] )
 *
 * \brief  Executes the insertion  sort algorithm  and the  merge sort
 * algorithm  on several permutations  of an  array consisting  of the
 * integers 1 thru N, where N is a given positive integer. You can use
 * this  application to estimate  the average  execution time  of both
 * merge sort  and insertion sort for  "small" arrays. The  idea is to
 * estimate the largest value of N for which the average time taken by
 * the insertion sort algorithm is smaller than the average time taken
 * by the  merge sort algorithm to  sort some permutations  of a given
 * array of  fixed size. Once you know  N, you can change  the code of
 * the  merge sort  algorithm, so  that  it calls  the insertion  sort
 * algorithm  whenever the  size  of  the subarray  gets  equal to  or
 * smaller than N. 
 *
 * You should run this code with the following command-line:
 *
 * ./mainapp N
 *
 * \param argc The number of command line arguments.
 * \param argv The command line arguments.
 *
 * \return The status of the function termination.
 */
int main( int argc, char* argv[] ) 
{
  using std::cout ;
  using std::cerr ;
  using std::endl ;

  /*
   * Check the number of input parameters.
   */
  if ( argc != 2 ) {
    cerr << "Usage: ./mainapp N"
         << endl ;
    return EXIT_FAILURE ;
  }

  /*
   * Get the size of the array to be sorted.
   */
  int n = atoi( argv[ 1 ] ) ;

  assert( n > 0 ) ;

  /*
   * Instantiate the insertion sort and merge sort objects.
   */
  MySort* is_sorter = new InsertionSort() ;
  MySort* ms_sorter = new MergeSort() ;

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
  int times_sorting = 100;


  /*
   * Run the method for 100 permutations of an arrays of size n.
   */
  cerr << "Executing the sorting method on " << n
       << "distinctly-sized arrays (" << times_sorting << ") times for each)..."
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
   * Execute the method  100 times, each of which  takes in a possibly
   * distinct permutation of the array.
   */

    cerr << "Shuffling and sorting the array " << times_sorting
         << " times..." << endl ;

  double istime = 0 ;
  double mstime = 0 ;

  for ( int j = 0 ; j < times_sorting ; j++ ) {
    /*
     * Shuffle the array (again). In principle, any permutation of the
     * array is equally likely to be produced by the method shuffle().
     */
    shuffler.shuffle( &a[ 0 ] , n ) ;

    /*
     * Make a copy of array "a".
     */
    for ( int i = 0 ; i < n ; i++ ) {
      b[ i ] = a[ i ] ;
    }

    /*
     * Sort the array in non-decreasing  order and record the time (in
     * milliseconds) that  the insertion  sort algorithm took  to sort
     * the array.
     */
    clock_t start , end ;
      
    start = clock() ;
    is_sorter->sort( a , n ) ;
    end = clock() ;

    /*
     * Compute the cpu time of the execution.
     */
    istime += double( end - start ) ;
    
    /*
     * Check if the  sorting method correctly sorted the  array. If it
     * did, then  write out  the size of  the array and  the execution
     * time.   Otherwise, write  out an  error message  and  abort the
     * execution.
     */
    for ( int j = 1 ; j < n ; j++ ) {
      if ( a[ j ] < a[ j - 1 ] ) {
	cerr << "Your implementation of the insertion sort algorithm is incorrect!" << endl ;
	return EXIT_FAILURE ;
      }
    }

    /*
     * Sort the array in non-decreasing  order and record the time (in
     * milliseconds) that  the merge sort  algorithm took to  sort the
     * array.
     */     
    start = clock() ;
    ms_sorter->sort( b , n ) ;
    end = clock() ;

    /*
     * Compute the cpu time of the execution.
     */
    mstime += double( end - start ) ;
    
    /*
     * Check if the  sorting method correctly sorted the  array. If it
     * did, then  write out  the size of  the array and  the execution
     * time.   Otherwise, write  out an  error message  and  abort the
     * execution.
     */
    for ( int j = 1 ; j < n ; j++ ) {
      if ( b[ j ] < b[ j - 1 ] ) {
	      cerr << "Your implementation of the merge sort algorithm is incorrect!"
	           << endl ;
        return EXIT_FAILURE ;
      }
    }


  cerr << "Done sorting for array with " << n << " elements "
        << "the " << j+1 << "th time"
        << endl ;
  
  }
  /*
   * Write the average execution time of each method.
   */
  cout << "INSERTION SORT: "
       << std::setw( 24 )
       << istime / ( 100 * CLOCKS_PER_SEC )
       << endl
       << "    MERGE SORT: "
       << std::setw( 24 )
       << mstime / ( 100 * CLOCKS_PER_SEC )
       << endl ; 

  /*
   * Release the memory allocated for the arrays.
   */
  if ( a != 0 ) {
    delete a ;
  }

  if ( b != 0 ) {
    delete b ;
  }

  /*
   * Release the memory allocated for the sorting method object.
   */
  if ( is_sorter != 0 ) {
    delete is_sorter ;
  }

  if ( ms_sorter != 0 ) {
    delete ms_sorter ;
  }

  cerr << endl << endl ;

  return EXIT_SUCCESS ;
}

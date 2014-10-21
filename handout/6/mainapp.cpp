/** 
 * \file mainapp.cpp
 *  
 * \brief  This application creates  an array  consisting of  10 (ten)
 * integers, and then run the quicksort() algorithm on each one of the
 * 10! (factorial of 10) permutations  of the array. The number of key
 * comparisons of each execution  is recorded, and the "exact" average
 * number of comparisons  is calculated in the end  and written out to
 * the standard  output.  The main  purpose of this application  is to
 * give  you a  "real" value  for  the average  number of  comparisons
 * between keys,  carried out by quicksort()  on an array  of size 15.
 * This value can  be compared with the theoretical  estimation we saw
 * in  classroom  for the  average  execution  time  of the  quicksort
 * algorithm.
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
#include <ios>                 // std::scientific, std::fixed
#include <iomanip>             // std::setprecision(), std::setw()

#include "mysort.hpp"          // MySort
#include "quicksort.hpp"       // QuickSort

#include "permutation.hpp"     // Permutation

/**
 * \fn int main()
 *
 * \brief Executes  the quicksort() algorithm  on an array  10! times,
 * and   then   computes  the   average   execution   time  over   all
 * executions. The size  of the array is 10,  and each execution takes
 * in a distinct permutation of  the array. The average execution time
 * is written out to the standard output.
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
   * Define some constants.
   */
  const int   N    = 10 ;
  const float NFAT = 3628800 ;

  /*
   * Instantiate the quicksort objects.
   */
  MySort* qs_sorter = new QuickSort() ;

  /*
   * Instantiate the array "permutation".
   */
  Permutation permutter ;

  /*
   * Run the method for arrays of size N.
   */
  cerr << "Executing the quick sort algorithm on an array of size "
       << N
       << " "
       << NFAT
       << " times..."
       << endl ;

  cerr << endl ;

  cerr << "This may take some time... Get a coffee or play a game!"
       << endl ;

  cerr << endl ;


  cerr << "Declaring two arrays to store the numbers 1 to 10... "
       << endl ;

  /*
   * Declare two arrays of 10 integers each.
   */
  int a[ N ] ;
  int b[ N ] ;

  cerr << "Filling in the array with integers from 1 to 10..."
       << endl ;
  
  /*
   * Fill out the array with the integers from 1 to 10.
   */
  for ( int i = 0 ; i < N ; i++ ) {
    a[ i ] = i + 1 ;
  }

  cerr << endl << endl ;

  /* 
   * For  each permutation  of the  array,  sort the  array, and  then
   * compute and  acummulate the  number of comparisons  between array
   * elements.
   */
  unsigned int comps = 0 ;
  unsigned int count = 0 ;

  do {

    cerr << "Considering the " 
	 << count + 1
         << "-th permutation of the array..."
         << endl ;

    cerr << "Backing up the array..." << endl ;

    /*
     * Copy the array "a" to the array "b".
     */
    for ( int i = 0 ; i < N ; i++ ) {
      b[ i ] = a[ i ] ;
    }

    cerr << "Sorting the array using quicksort..." << endl ;
      
    /*
     * Sort the  array in non-decreasing order and  compute the number
     * of comparisons between the array keys carried out by quicksort.
     */
    qs_sorter->sort( a , N ) ;
 
    /*
     * Check whether the sorting method correctly sorted the array.
     */
    for ( int j = 1 ; j < N ; j++ ) {
      if ( a[ j ] < a[ j - 1 ] ) {
	cerr << "Your implementation of the mergesort algorithm is incorrect!" << endl ;
	return EXIT_FAILURE ;
      }
    }

    cerr << "Done sorting..." << endl ;

    cerr << "Accumulating the number of key comparisons..." << endl ;

    /*
     * Accumulate the number of key comparisons.
     */
    comps +=  qs_sorter->get_the_number_of_key_comparisons() ;

    cerr << "Computing the next permutation..." << endl ;

    /*
     * Get the next permutation of the array "b".
     */
    permutter.permute( b , N ) ;

    /*
     * Copy the array "b" to the array "a".
     */
    for ( int i = 0 ; i < N ; i++ ) {
      a[ i ] = b[ i ] ;
    }

    /*
     * Increment the permutation counter.
     */
    ++count ;

    cerr << endl << endl ;

  } 
  while ( count < NFAT ) ;

  cerr << "Computing the average number of key comparisons..." << endl ;
      
  /*
   * Compute the average number of key comparisons.
   */
  double avgcomps = double( comps ) / double( NFAT ) ;

  cerr << "Writing out the average number of key comparisons..." << endl ;

  /*
   * Set up the format for displaying the output numbers.
   */
  cout << std::scientific << std::setprecision( 16 ) ;

  /*
   * Write out the average number of key comparisons.
   */
  cout << "The average number of key comparisons is: "
       << std::setw( 24 )
       << avgcomps 
       << endl ; 

  cerr << "Releasing memory..." << endl ;

  /*
   * Release the memory allocated for the sorting method objects.
   */
  if ( qs_sorter != 0 ) {
    delete qs_sorter ;
  }

  cerr << "Done!" << endl ;

  cerr << endl << endl ;

  return EXIT_SUCCESS ;
}

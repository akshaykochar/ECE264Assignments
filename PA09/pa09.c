
#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"
//#include "tree.h"


int main ( int argc , char * argv )
{
  // int i; //index
  int flag ;
  //check arguments
  if (argc != 3)
    {
      printf("usage: ./pa09 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("File error!\n");
      return EXIT_FAILURE;
    }
  /**********************************
   //checking binary vs character tree
   **********************************/
  flag = file_check(argv[1]) ;
  printf("flag: %d",flag) ;

  /* /\*********************************** */
  /*  *********************************** */
  /*  * Printing results */
  /*  *********************************** */
  /*  **********************************\/ */
 
  
 

  /* /\******************************************************** */
  /*  * Huffman tree  */
  /*  ********************************************************\/ */

 


  
  
  

  
  fclose(fptr);
  return EXIT_SUCCESS ;
}

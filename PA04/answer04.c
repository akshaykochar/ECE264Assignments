/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>

// Global Declarations 
void partitionHelp1 (int end,int pos, int *arr) ;
void partitionHelp2(int pos , int *arr) ;
void partitionIncreasingHelp1(int end, int pos,int *arr);
void partitionDecreasingHelp1(int end, int pos, int *arr) ;
void partitionOddHelp1(int end, int pos, int *arr);
void partitionEvenHelp1(int end, int pos, int *arr) ;
void partitionOddAndEvenHelp1(int end, int pos, int *arr,int flag);
void partitionPrimeHelp1(int end, int pos, int *arr) ;


/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */


void partitionAll(int value)
{
  int *arr = malloc(sizeof(int)*value) ;
  printf("partitionAll %d\n", value);
  partitionHelp1(value, 0, arr);
  free(arr);
 
}

void partitionHelp1(int end, int pos, int *arr)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }

  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
      partitionHelp1(end - val , pos + 1 , arr);
    }
}


void partitionHelp2(int pos , int *arr)
{
  int i ;
  printf("=");
  for(i = 0 ; i < pos - 1 ; i++)
    {
      printf("%d + ",arr[i]);
    }
  printf("%d\n",arr[pos - 1]);
}






/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
  int *arr = malloc(sizeof(int)*value) ;
  partitionIncreasingHelp1(value, 0, arr);
  free(arr);
}


void partitionIncreasingHelp1(int end, int pos, int *arr)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
      if( pos == 0 || arr[pos] > arr[pos-1] )
	{
	  partitionIncreasingHelp1(end - val , pos + 1 , arr) ;
	}	
    }
}


/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */


void partitionDecreasing(int value)
{
  int *arr = malloc(sizeof(int)*value) ;
  printf("partitionDecreasing %d\n", value);
  partitionDecreasingHelp1(value, 0, arr);
  free(arr); 

}

void partitionDecreasingHelp1(int end, int pos, int *arr)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
	  arr[pos] = val ;
	  
      
       if(pos == 0 ||  arr[pos] < arr[pos-1])
        {
	 partitionDecreasingHelp1(end - val , pos + 1 , arr) ;
	}

    }
}


/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  int *arr = malloc(sizeof(int)*value) ;
  partitionOddHelp1(value, 0, arr);  
  free(arr);
}

void partitionOddHelp1(int end, int pos, int *arr)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
       if(val%2 == 1)
        {
	  partitionOddHelp1(end - val , pos + 1 , arr) ;
	}
    }
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  int *arr = malloc(sizeof(int)*value) ;
  partitionEvenHelp1(value, 0, arr);  
  free(arr);
}

void partitionEvenHelp1(int end, int pos, int *arr)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
       if(val%2 == 0)
        {
	  partitionEvenHelp1(end - val , pos + 1 , arr) ;
	}
    }
}




/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  
  int *arr = malloc(sizeof(int)*value) ;
  partitionOddAndEvenHelp1(value, 0, arr,0);  
  free(arr);
}

void partitionOddAndEvenHelp1(int end, int pos, int *arr,int flag)
{
  int val ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
       if(flag == 0 && val%2 == 1)
        {
	  partitionOddAndEvenHelp1(end - val , pos + 1 , arr,1) ;
	}
      else if(flag == 1 && val%2 == 0)
        {
	  partitionOddAndEvenHelp1(end - val , pos + 1 , arr,0) ;
	}
    }
}




/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */



void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int *arr = malloc(sizeof(int)*value) ;
  partitionPrimeHelp1(value, 0, arr);  
  free(arr);
}

void partitionPrimeHelp1(int end, int pos, int *arr)
{
  int val ;
  int flag = 1 ;
  int i ;
  if(end == 0)
    {
      partitionHelp2(pos, arr);
      return ;
    }
  for(val = 1 ; val <= end ; val ++)
    {
      arr[pos] = val ;
      for (i = 2 ; i < val ; i ++)
	{
	  if(val % i == 0 && val != 1)
	    { 
	      flag = 0 ;
	    }
	}
      if(val == 1)
	{
	  flag = 0 ;
	}
      if(flag == 1 )
        {
	  partitionPrimeHelp1(end - val , pos + 1 , arr) ;
	}
      flag = 1 ;
    }
}


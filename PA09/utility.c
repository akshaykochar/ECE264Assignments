#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"
//#include "tree.h"

int file_check(char * name)
{
  if(strstr(name,"bit") != NULL )
    {
      return 1 ;
    }
  return 0 ;
}

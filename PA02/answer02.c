#include "pa02.h"

/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s)
{
  int count = 0 ;
  int charnum = 0 ;

  while(s[charnum] != '\0')
    {
      count = count + 1 ;
      charnum = charnum + 1 ;
    }

    return count;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c)
{
  int count = 0 ;
  int charnum =  0 ;

  while(s[charnum] != '\0')
    {
      if(s[charnum] == c)
	{
	  count = count + 1 ;
	}
      charnum = charnum + 1 ;
    }

    return count;
}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)
{
  int charnum = 0 ;

  while(s[charnum] != '\0')
    {
      if(s[charnum] >= 'a' && s[charnum] <= 'z')
	{
	  s[charnum] = s[charnum] - 32 ;
	}
      charnum = charnum + 1 ;
    }

}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s)
{
  int charnum = 0 ;

  while(s[charnum] != '\0')
    {
      if(s[charnum] >= 'A' && s[charnum] <= 'Z')
	{
	  s[charnum] = s[charnum] + 32 ;
	}
      charnum = charnum + 1 ;
    }
    
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2)
{
  int charnum = 0 ;
  do
    {
      s1[charnum] = s2[charnum] ;
      charnum = charnum + 1 ;
    }while(s2[charnum - 1 ] != '\0');

}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)
{
  int charnum = 0 ;

  while( charnum < num )
    {
      s1[charnum] = s2[charnum] ; 
      charnum = charnum + 1 ;
    }
  s1[charnum] = '\0' ;

}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) 
{
  int charnums1 = 0 ;
  int charnums2 = 0 ;
 
  while(s1[charnums1] != '\0')
    {
      charnums1 = charnums1 + 1 ;
    }
  
  do
    {
      s1[charnums1] = s2[charnums2] ;
      charnums2 = charnums2 + 1 ;
      charnums1 = charnums1 + 1 ;
    }while(s2[charnums2 - 1 ] != '\0');
    
}

/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)
{
  int charnums1 = 0 ;
  int charnums2 = 0 ;
 
  while(s1[charnums1] != '\0')
    {
      charnums1 = charnums1 + 1 ;
    }
  
  while(charnums2 < num)
    {
      s1[charnums1] = s2[charnums2] ;
      charnums2 = charnums2 + 1 ;
      charnums1 = charnums1 + 1 ;
    }

  s1[charnums1] = '\0' ;

   
}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2)
{
  const char *ptr1 = NULL ;
  int i ;
  int j ;
  int lengths1 = my_strlen(s1) ;
  int lengths2 = my_strlen(s2) ;

  for(i = 0 ; i < lengths1 ; i++)
    {
      for(j = 0 ; j<lengths2 ; j++)
	{
	  if(s1[i+j] == '\0')
	    {
	      ptr1 = NULL;
	      break ;
	    }
	  ptr1 = s1 + i ;
	  if(s1[i+j] != s2[j])
	    {
	      ptr1 = NULL ;
	    }
	
	}
      if(ptr1 != NULL)
	{
	  break ;
	}
    }
  
    return ptr1;
}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
  int lengths1 = my_strlen(s1) ;
  int lengths2 = my_strlen(s2) ;
  int i ;
  int j ;

  if(pos > lengths1)
    {
      pos = lengths1 ;
    }

  for(i = lengths1 ; i >= pos ; i--)
    {
      s1[i + lengths2] = s1[i] ;
    } 
  for(j = pos ; j < lengths2 ; j++)
    {
      s1[j] = s2[j - pos] ;
    }
  
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)
{
  int stringlength = my_strlen(s) ;
  int i ;

 if(pos < stringlength)
    {
      if(pos+length >= stringlength)
	{
	  s[pos] = '\0' ;
	}
      else
	{
	  for(i = pos ; i < stringlength ; i++)
	    {
	      s[i] = s[ i + length] ;
	    }
	}
      s[stringlength - length ] = '\0' ;
    }
}

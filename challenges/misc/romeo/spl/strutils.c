/***********************************************************************

SPL, the Shakespeare Programming Language

Copyright (C) 2001 Karl Hasselström and Jon Åslund

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
USA.

***********************************************************************/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "strutils.h"

char *cat2(char *str1, char *str2)
{
  int len;
  char *ret;

  /* malloc new string */
  len = strlen(str1) + strlen(str2) + 1;
  ret = (char *) malloc(len*sizeof(char));

  /* copy the strings */
  strcpy(ret, str1);
  strcat(ret, str2);

  /* free old strings */
  free(str1);
  free(str2);

  return ret;
}

char *cat3(char *str1, char *str2, char *str3)
{
  return cat2(cat2(str1, str2), str3);
}

char *cat4(char *str1, char *str2, char *str3, char *str4)
{
  return cat2(cat2(str1, str2), cat2(str3, str4));
}

char *cat5(char *str1, char *str2, char *str3, char *str4,
	   char *str5)
{
  return cat3(cat2(str1, str2), cat2(str3, str4), str5);
}

char *cat6(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6)
{
  return cat3(cat2(str1, str2), cat2(str3, str4), cat2(str5, str6));
}

char *cat7(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7)
{
  return cat4(cat2(str1, str2), cat2(str3, str4), cat2(str5, str6), str7);
}

char *cat8(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7, char *str8)
{
  return cat4(cat2(str1, str2), cat2(str3, str4),
	      cat2(str5, str6), cat2(str7, str8));
}

char *cat9(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7, char *str8,
	   char *str9)
{
  return cat5(cat2(str1, str2), cat2(str3, str4), cat2(str5, str6),
	      cat2(str7, str8), str9);
}

char *int2str(int i)
{
  char *str;

  str = (char *) malloc(25*sizeof(char));
  sprintf(str, "%d", i);

  return str;
}

char *newstr(const char *str)
{
  int len;
  char *ret;

  /* malloc new string */
  len = strlen(str) + 1;
  ret = (char *) malloc(len*sizeof(char));

  /* copy the strings */
  strcpy(ret, str);
  
  return ret;
}

char *space2underscore(char *str)
{
  char *c;
  for(c = str; *c != '\0'; c++) {
    if(isspace((int) *c))
      *c = '_';
  }
  return str;
}

char *singlespace(char *str)
{
  char *read;
  char *write;

  int last_space = 0;
  int this_space = 0;

  /* Walk through the string, deleting multiple spaces. */
  for (read = write = str; *read != '\0'; read++) {

    /* Was the last character a space? */
    last_space = this_space;

    /* Is this character a space? */
    this_space = isspace((int) *read);

    /* Copy the character unless this would make more than one space
       in a row. */
    if (!(last_space && this_space)) {

      /* Copy. */
      *write = *read;

      /* Advance write position. */
      write++;
    }
  }

  /* Write \0 at end of string. */
  *write = '\0';

  /* Return the modified string. */
  return str;
}

char *str2lower(char *str)
{
  char *c;
  for (c = str; *c != '\0'; c++) {
    *c = (char) tolower((int) *c);
  }
  return str;
}

char *str2upper(char *str)
{
  char *c;
  for (c = str; *c != '\0'; c++) {
    *c = (char) toupper((int) *c);
  }
  return str;
}

char *str2varname(char *str)
{
  return str2lower(space2underscore(singlespace(str)));
}

char *strindent(char *str, char *indent)
{
  int newlines, len;
  char *newstr;
  int i, j;

  newlines = 1;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\n') {
      newlines++;
    }
  }

  len = strlen(str) + strlen(indent)*newlines + 1;
  newstr = (char *) malloc(len*sizeof(char));
  
  j = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (i == 0 || str[i - 1] == '\n') {
      strcpy(newstr + j, indent);
      j += strlen(indent);
    }
    newstr[j] = str[i];
    j++;
  }
  newstr[j] = '\0';

  free(str);
  free(indent);
  return newstr;
}

char *strpad(char *str, int length, char fill)
{
  int i;
  
  if (strlen(str) >= length) {
    return str;
  }
  
  str = (char *) realloc(str, (length+1)*sizeof(char));
  
  for (i = strlen(str); i < length; i++) {
    str[i] = fill;
  }
  str[length] = '\0';

  return str;
}

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

#ifndef STRUTILS_H
#define STRUTILS_H

char *cat2(char *str1, char *str2);
char *cat3(char *str1, char *str2, char *str3);
char *cat4(char *str1, char *str2, char *str3, char *str4);
char *cat5(char *str1, char *str2, char *str3, char *str4,
	   char *str5);
char *cat6(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6);
char *cat7(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7);
char *cat8(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7, char *str8);
char *cat9(char *str1, char *str2, char *str3, char *str4,
	   char *str5, char *str6, char *str7, char *str8,
	   char *str9);
char *int2str(int i);
char *newstr(const char *str);
char *space2underscore(char *str);
char *singlespace(char *str);
char *str2lower(char *str);
char *str2upper(char *str);
char *str2varname(char *str);
char *strindent(char *str, char *indent);
char *strpad(char *str, int length, char fill);

#endif /* STRUTILS_H */

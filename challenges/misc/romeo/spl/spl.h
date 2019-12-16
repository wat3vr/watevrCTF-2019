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

#ifndef __SHAKESPEARE__
#define __SHAKESPEARE__

#include <stdlib.h>

#define BUF_SIZE 1024

typedef struct _STACKNODE STACKNODE;
struct _STACKNODE {
  int value;
  STACKNODE *next;
};

typedef struct {
  int value;
  char *name;
  int on_stage;
  STACKNODE *stack;
} CHARACTER;

/* global variables */

CHARACTER **cast;
CHARACTER *first_person;
CHARACTER *second_person;

int truth_flag;
int num_on_stage;
int num_cast;

/* function prototypes */
extern void activate_character(int line, CHARACTER *character);
extern void assign(int line, CHARACTER *character, int value);
extern void char_input(int line, CHARACTER *character);
extern void char_output(int line, CHARACTER *character);
extern void enter_scene(int line, CHARACTER *character);
extern void exit_scene(int line, CHARACTER *character);
extern void exit_scene_all(int line);
extern void global_initialize();
extern CHARACTER *initialize_character(char *name);
extern int int_add(int line, int a, int b);
extern int int_cube(int line, int value);
extern int int_div(int line, int a, int b);
extern int int_factorial(int line, int n);
extern void int_input(int line, CHARACTER *character);
extern int int_mod(int line, int a, int b);
extern int int_mul(int line, int a, int b);
extern void int_output(int line, CHARACTER *character);
extern int int_sqrt(int line, int value);
extern int int_square(int line, int value);
extern int int_sub(int line, int a, int b);
extern int int_twice(int line, int value);
extern void pop(int line, CHARACTER *character);
extern void push(int line, CHARACTER *character, int value);
extern int value_of(int line, CHARACTER *character);

#endif /* __SHAKESPEARE__ */

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

#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "spl.h"
#include "strutils.h"

/* debug functions */
#ifdef DEBUG
void dump_cast_whereabouts(FILE *out)
{
  int i;

  for (i = 0; i < num_cast; i++) {
    fprintf(out, "%20s", cast[i]->name);
    if (cast[i]->on_stage == 1) {
      fprintf(out, " on stage");
    }
    fprintf(out, "\n");
  }
}

void dump_stack(FILE *out, CHARACTER *character)
{
  STACKNODE *node;

  fprintf(out, "%s's stack is now:", character->name);
  for (node = character->stack; node != NULL; node = node->next) {
    fprintf(out, " %d", node->value);
  }
  fprintf(out, "\n");
}
#endif /* DEBUG */

/* local function prototypes */

static void runtime_error(int line, char *msg);

/* function definitions */

void activate_character(int line, CHARACTER *character)
{
  int i;

  /* Make sure the character is on stage */
  if (character->on_stage == 0) {
    runtime_error(line, cat2(newstr(character->name), newstr(" is not on stage, and thus cannot speak!\n")));
  }

  /* If there are exactly two people on stage, the other one should be
     second person */
  if (num_on_stage == 2) {
    for (i = 0; i < num_cast; i++) {
      if (cast[i]->on_stage == 1 && cast[i] != character) {
	second_person = cast[i];
      }
    }
  } else {
    second_person = NULL;
  }

  /* Make this character the first person */
  first_person = character;
}

void assign(int line, CHARACTER *character, int value)
{
  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }

#ifdef DEBUG
  fprintf(stderr, "\n%s's previous value was %d.\n", character->name, character->value);
#endif

  /* Assign the value */
  character->value = value;

#ifdef DEBUG
  fprintf(stderr, "%s's new value is %d.\n", character->name, character->value);
#endif
}

void char_input(int line, CHARACTER *character)
{
  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }

  /* Read a character from stdin */
  character->value = getc(stdin);

  /* If EOF was encountered, record the value -1 */
  if (character->value == EOF) {
    character->value = -1;
  }

#ifdef DEBUG
  fprintf(stderr, "\n%s read the character %c (ascii code %d)\n", character->name, (char) character->value, character->value);
#endif
}

void char_output(int line, CHARACTER *character)
{
  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }

  /* Make sure the value is in range */
  if (character->value < 0 || character->value > UCHAR_MAX) {
    runtime_error(line, cat3(newstr("The value "), int2str(character->value),
			     newstr(" does not correspond to a character.")));
  }

  /* Write a character to stdout */
  putc(character->value, stdout);

#ifdef DEBUG
  fprintf(stderr, "\n%s wrote the character %c (ascii code %d)\n", character->name, (char) character->value, character->value);
#endif
}

void enter_scene(int line, CHARACTER *character)
{
  /* Make sure the character isn't already on stage */
  if (character->on_stage == 1) {
    runtime_error(line, cat2(newstr(character->name), newstr(" is already on stage, and thus cannot enter!\n")));
  }
  
  /* Set on_stage flag */
  character->on_stage = 1;

  /* Increase num_on_stage counter */
  num_on_stage++;

#ifdef DEBUG
  fprintf(stderr, "\n%s just entered\n", character->name);
  dump_cast_whereabouts(stderr);
#endif
}

void exit_scene(int line, CHARACTER *character)
{
  /* Make sure the character is on stage */
  if (character->on_stage == 0) {
    runtime_error(line, cat2(newstr(character->name), newstr(" is not on stage, and thus cannot exit!\n")));
  }
  
  /* Set on_stage flag */
  character->on_stage = 0;

  /* Decrease num_on_stage counter */
  num_on_stage--;

#ifdef DEBUG
  fprintf(stderr, "\n%s just exited\n", character->name);
  dump_cast_whereabouts(stderr);
#endif
}

void exit_scene_all(int line)
{
  int i;

  /* Kick everyone off stage! */
  for (i = 0; i < num_cast; i++) {
    cast[i]->on_stage = 0;
  }

  /* Reset num_on_stage counter */
  num_on_stage = 0;

#ifdef DEBUG
  fprintf(stderr, "\nEverybody just exeunted\n");
  dump_cast_whereabouts(stderr);
#endif
}

void global_initialize()
{
  cast = NULL;
  first_person = NULL;
  second_person = NULL;
  truth_flag = 0;
  num_on_stage = 0;
  num_cast = 0;
}

CHARACTER *initialize_character(char *name)
{
  CHARACTER *newchar;

  newchar = (CHARACTER *) malloc(sizeof(CHARACTER));
  newchar->name = newstr(name);
  newchar->on_stage = 0;
  newchar->stack = NULL;
  newchar->value = 0;

  num_cast++;
  cast = (CHARACTER **) realloc(cast, num_cast*sizeof(CHARACTER *));
  cast[num_cast - 1] = newchar;

  return newchar;
}

int int_add(int line, int a, int b)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_add(%d, %d) = %d\n", a, b, a + b);
#endif

  /* Compute the result */
  return a + b;
}

int int_cube(int line, int value)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_cube(%d) = %d\n", value, value*value*value);
#endif
  
  return value*value*value;
}

int int_div(int line, int a, int b)
{
  /* Make sure the denominator is nonzero */
  if (b == 0) {
    runtime_error(line, cat3(newstr("Unable to divide "), int2str(a), newstr(" by zero!")));
  }

#ifdef DEBUG
  fprintf(stderr, "\nComputing int_div(%d, %d) = %d\n", a, b, a/b);
#endif

  /* Compute the result */
  return a/b;
}

int int_factorial(int line, int n)
{
  int i;

#ifdef DEBUG
  int orig = n;
#endif

  /* Make sure the argument is nonnegative */
  if (n < 0) {
    runtime_error(line, cat3(newstr("Unable to compute factorial of "), int2str(n), newstr(", since it is negative!")));
  }
  
  /* Compute the result */
  if (n == 0) {
    n = 1;
  }
  for (i = n - 1; i > 1; i--) {
    n *= i;
  }

#ifdef DEBUG
  fprintf(stderr, "\nComputing int_factorial(%d) = %d\n", orig, n);
#endif

  return n;
}

void int_input(int line, CHARACTER *character)
{
  char buf[BUF_SIZE];
  long lval;

  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }
  
  /* Get a line of text */
  fgets(buf, BUF_SIZE, stdin);

  /* Try to parse that into an integer */
  errno = 0;
  lval = strtol(buf, NULL, 10);
  if (lval == 0) {
    switch (errno) {
    case EINVAL:
      runtime_error(line, cat2(newstr(character->name), newstr("'s heart whispered something that was not a valid integer.")));
      break;
    case ERANGE:
      runtime_error(line, cat2(newstr(character->name), newstr("'s heart whispered an integer that was out of range.")));
      break;
    default:
      /* No error, buf really contained the integer zero */
      break;
    }
  }

  /* Make sure it was not out of range */
  if (lval < INT_MIN || lval > INT_MAX) {
    runtime_error(line, cat2(newstr(character->name), newstr("'s heart whispered an integer that was out of range.")));
  }

  /* Store the value */
  character->value = (int) lval;

#ifdef DEBUG
  fprintf(stderr, "\n%s read the value %d\n", character->name, character->value);
#endif
}

int int_mod(int line, int a, int b)
{
  /* Make sure the denominator is nonzero */
  if (b == 0) {
    runtime_error(line, cat3(newstr("Unable to divide "), int2str(a), newstr(" by zero!")));
  }

#ifdef DEBUG
  fprintf(stderr, "\nComputing int_mod(%d, %d) = %d\n", a, b, a%b);
#endif

  /* Compute the result */
  return a%b;
}

int int_mul(int line, int a, int b)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_mul(%d, %d) = %d\n", a, b, a*b);
#endif

  /* Compute the result */
  return a*b;
}

void int_output(int line, CHARACTER *character)
{
  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }

  /* Write the number to stdout */
  printf("%d", character->value);

#ifdef DEBUG
  fprintf(stderr, "\n%s wrote the value %d\n", character->name, character->value);
#endif
}

int int_sqrt(int line, int value)
{
  /* Make sure the number is positive */
  if (value < 0) {
    runtime_error(line, cat3(newstr("Unable to compute the square root of "), int2str(value),
			     newstr(", since it is negative.")));
  }

#ifdef DEBUG
  fprintf(stderr, "\nComputing int_sqrt(%d) = %d\n", value, (int) sqrt((double) value));
#endif

  /* Compute the square root */
  return (int) sqrt((double) value);
}

int int_square(int line, int value)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_square(%d) = %d\n", value, value*value);
#endif
  
  return value*value;
}

int int_sub(int line, int a, int b)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_sub(%d, %d) = %d\n", a, b, a - b);
#endif

  /* Compute the result */
  return a - b;
}

int int_twice(int line, int value)
{
#ifdef DEBUG
  fprintf(stderr, "\nComputing int_twice(%d) = %d\n", value, 2*value);
#endif
  
  return 2*value;
}

void pop(int line, CHARACTER *character)
{
  STACKNODE *node;

  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of imperative. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of imperative. There are more than two characters on stage!"));
    }
  }

  /* Try to pop a value from the stack */
  node = character->stack;
  if (node == NULL) {
    runtime_error(line, cat2(newstr(character->name), newstr(" is unable to recall anything.")));
  } else {
    character->value = node->value;
    character->stack = node->next;
    free(node);
  }

#ifdef DEBUG
  fprintf(stderr, "\nPopping %s, getting the value %d\n", character->name, character->value);
  dump_stack(stderr, character);
#endif
}

void push(int line, CHARACTER *character, int value)
{
  STACKNODE *node;

  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of imperative. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of imperative. There are more than two characters on stage!"));
    }
  }

  /* Push a value onto the stack */
  node = (STACKNODE *) malloc(sizeof(STACKNODE));
  node->value = value;
  node->next = character->stack;
  character->stack = node;

#ifdef DEBUG
  fprintf(stderr, "\nPushing %d onto %s\n", value, character->name);
  dump_stack(stderr, character);
#endif
}

void runtime_error(int line, char *msg)
{
  fprintf(stderr, "\nRuntime error at line %d: %s\n", line, msg);
  free(msg);
  exit(1);
}

int value_of(int line, CHARACTER *character)
{
  /* Make sure the character isn't NULL */
  if (character == NULL) {
    if (num_on_stage == 1) {
      runtime_error(line, newstr("Erroneous use of second person pronoun. There is only one character on stage!"));
    } else {
      runtime_error(line, newstr("Ambiguous use of second person pronoun. There are more than two characters on stage!"));
    }
  }

  /* Return the value */
  return character->value;
}

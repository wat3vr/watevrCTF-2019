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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 4096

int main(int argc, char *argv[]);
void insert_file(char *filename);
void rules_from_file(char *filename, char *token);
void rule_for_word(char *word, char *token);
void remove_newline(char *string);
void make_regexp(char *string);
void remove_repeated_whitespace(char *string);
void trim_whitespace(char *string);

int main(int argc, char *argv[])
{
  char filename[STRING_LENGTH];
  char *include_path;
  
  /* Command line parameters */
  if (argc < 2) {
    include_path = (char *) malloc(sizeof(char)*2);
    strcpy(include_path, ".");
  }
  else {
    include_path = (char *) malloc(sizeof(char)*strlen(argv[1]));
    strcpy(include_path, argv[1]);
  }

  /* User code at top of file */
  sprintf(filename, "%s/%s", include_path, "user_code_top.metaflex");
  insert_file(filename);
  
  /* Definitions */
  sprintf(filename, "%s/%s", include_path, "roman_numbers.metaflex");
  insert_file(filename);

  /* Separator */
  printf("\n%%%%\n");

  /* Rules */

  /* - Wordlist rules */
  sprintf(filename, "%s/%s", include_path, "article.wordlist");
  rules_from_file(filename, "ARTICLE");
  sprintf(filename, "%s/%s", include_path, "be.wordlist");
  rules_from_file(filename, "BE");
  sprintf(filename, "%s/%s", include_path, "character.wordlist");
  rules_from_file(filename, "CHARACTER");
  sprintf(filename, "%s/%s", include_path, "first_person.wordlist");
  rules_from_file(filename, "FIRST_PERSON");
  sprintf(filename, "%s/%s", include_path, "first_person_possessive.wordlist");
  rules_from_file(filename, "FIRST_PERSON_POSSESSIVE");
  sprintf(filename, "%s/%s", include_path, "first_person_reflexive.wordlist");
  rules_from_file(filename, "FIRST_PERSON_REFLEXIVE");
  sprintf(filename, "%s/%s", include_path, "negative_adjective.wordlist");
  rules_from_file(filename, "NEGATIVE_ADJECTIVE");
  sprintf(filename, "%s/%s", include_path, "negative_comparative.wordlist");
  rules_from_file(filename, "NEGATIVE_COMPARATIVE");
  sprintf(filename, "%s/%s", include_path, "negative_noun.wordlist");
  rules_from_file(filename, "NEGATIVE_NOUN");
  sprintf(filename, "%s/%s", include_path, "neutral_adjective.wordlist");
  rules_from_file(filename, "NEUTRAL_ADJECTIVE");
  sprintf(filename, "%s/%s", include_path, "neutral_noun.wordlist");
  rules_from_file(filename, "NEUTRAL_NOUN");
  sprintf(filename, "%s/%s", include_path, "nothing.wordlist");
  rules_from_file(filename, "NOTHING");
  sprintf(filename, "%s/%s", include_path, "positive_adjective.wordlist");
  rules_from_file(filename, "POSITIVE_ADJECTIVE");
  sprintf(filename, "%s/%s", include_path, "positive_comparative.wordlist");
  rules_from_file(filename, "POSITIVE_COMPARATIVE");
  sprintf(filename, "%s/%s", include_path, "positive_noun.wordlist");
  rules_from_file(filename, "POSITIVE_NOUN");
  sprintf(filename, "%s/%s", include_path, "second_person.wordlist");
  rules_from_file(filename, "SECOND_PERSON");
  sprintf(filename, "%s/%s", include_path, "second_person_possessive.wordlist");
  rules_from_file(filename, "SECOND_PERSON_POSSESSIVE");
  sprintf(filename, "%s/%s", include_path, "second_person_reflexive.wordlist");
  rules_from_file(filename, "SECOND_PERSON_REFLEXIVE");
  sprintf(filename, "%s/%s", include_path, "third_person_possessive.wordlist");
  rules_from_file(filename, "THIRD_PERSON_POSSESSIVE");

  /* - Single word rules */
  printf("\n /* single word rules */\n");
  rule_for_word("and",                                   "AND");
  rule_for_word("as",                                    "AS");
  rule_for_word("enter",                                 "ENTER");
  rule_for_word("exeunt",                                "EXEUNT");
  rule_for_word("exit",                                  "EXIT");
  rule_for_word("heart",                                 "HEART");
  rule_for_word("if not",                                "IF_NOT");
  rule_for_word("if so",                                 "IF_SO");
  rule_for_word("less",                                  "LESS");
  rule_for_word("let us",                                "LET_US");
  rule_for_word("listen to",                             "LISTEN_TO");
  rule_for_word("mind",                                  "MIND");
  rule_for_word("more",                                  "MORE");
  rule_for_word("not",                                   "NOT");
  rule_for_word("open",                                  "OPEN");
  rule_for_word("proceed to",                            "PROCEED_TO");
  rule_for_word("recall",                                "RECALL");
  rule_for_word("remember",                              "REMEMBER");
  rule_for_word("return to",                             "RETURN_TO");
  rule_for_word("speak",                                 "SPEAK");
  rule_for_word("than",                                  "THAN");
  rule_for_word("the cube of",                           "THE_CUBE_OF");
  rule_for_word("the difference between",                "THE_DIFFERENCE_BETWEEN");
  rule_for_word("the factorial of",                      "THE_FACTORIAL_OF");
  rule_for_word("the product of",                        "THE_PRODUCT_OF");
  rule_for_word("the quotient between",                  "THE_QUOTIENT_BETWEEN");
  rule_for_word("the remainder of the quotient between", "THE_REMAINDER_OF_THE_QUOTIENT_BETWEEN");
  rule_for_word("the square of",                         "THE_SQUARE_OF");
  rule_for_word("the square root of",                    "THE_SQUARE_ROOT_OF");
  rule_for_word("the sum of",                            "THE_SUM_OF");
  rule_for_word("twice",                                 "TWICE");
  rule_for_word("we must",                               "WE_MUST");
  rule_for_word("we shall",                              "WE_SHALL");

  /* - Other rules */
  sprintf(filename, "%s/%s", include_path, "terminals.metaflex");
  printf("\n /* rules for terminals from file %s */", filename);
  insert_file(filename);

  /* Separator */
  printf("\n%%%%\n");

  /* User code */
  sprintf(filename, "%s/%s", include_path, "user_code_bottom.metaflex");
  insert_file(filename);

  /* We did it, no problemas */
  free(include_path);
  return 0;
}

void insert_file(char *filename)
{
  FILE *file;
  int c;

  /* Open file */
  file = fopen(filename,"r");
  if (file == NULL) {
    fprintf(stderr, "Could not find %s.\n", filename);
    exit(1);
  }

  /* An initial newline is nice */
  printf("\n");

  /* Copy file to stdout */
  while((c = getc(file)) != EOF) {
    putchar(c);
  }
  
  fclose(file);
}

void rules_from_file(char *filename, char *token)
{
  FILE *file;
  char *s, string[STRING_LENGTH];

  /* Open file */
  file = fopen(filename,"r");
  if (file == NULL) {
    fprintf(stderr, "Could not find %s.\n", filename);
    exit(1);
  }

  /* An initial newline is nice */
  printf("\n /* rules from file %s */\n", filename);

  /* For each line */
  while(!feof(file)) {

    /* Get line */
    s = fgets(string, sizeof(string), file);
    if (s == NULL)
      break;
    
    /* Write the rule */
    remove_newline(string);
    rule_for_word(string, token);
  }

  fclose(file);
}

void rule_for_word(char *word, char *token)
{
  char regexp[STRING_LENGTH];

  strcpy(regexp, word);
  make_regexp(regexp);
  printf("%s {\n   yylval.str = newstr(yytext); return %s;\n}\n", regexp, token);
}

void remove_newline(char *string)
{
  while((string[strlen(string) - 1] == '\n') ||
	(string[strlen(string) - 1] == '\r')) {
    string[strlen(string) - 1] = '\0';
  }
}

void make_regexp(char *string)
{
  char temp_string[STRING_LENGTH];
  char *read = string, *write = temp_string;
  char c;
  char space_string[] = "\"[[:space:]]+\"";

  /* Remove repeated whitespace */
  remove_repeated_whitespace(string);

  /* Remove whitespace from beginning and end */
  trim_whitespace(string);

  /* Replace space with [:space:], and quote */
  *write = '\"';
  write++;
  while(*read != '\0') {
    c = *read;
    read++;
    if(isspace((int) c)) {
      strcpy(write, space_string);
      write += sizeof(space_string) - 1;
    }
    else {
      *write = c;
      write++;
    }
  }
  *write = '\"';
  write++;
  *write = '\0';

  /* Copy working string to original string */
  strcpy(string, temp_string);
}

void remove_repeated_whitespace(char *string)
{
  char *read = string, *write = string;
  int last_was_white = 0;
  char c;

  while(*read != '\0') {
    c = *read;
    read++;
    if(isspace((int) c)) {
      if(!last_was_white) {
	last_was_white = 1;
	*write = ' ';
	write++;
      }
    }
    else {
      last_was_white = 0;
      *write = c;
      write++;
    }
  }
  *write = '\0';
}

void trim_whitespace(char *string)
{
  char *read = string, *write = string;
  char c;

  /* Remove whitespace at the end */
  read = string + strlen(string) - 1;
  while(isspace((int) *read))
    read--;
  write = read + 1;
  *write = '\0';

  /* Remove whitespace at the beginning */
  for(read = string; isspace((int) *read); read++)
    continue;
  write = string;
  while(*read != '\0') {
    c = *read;
    read++;
    *write = c;
    write++;
  }
  *write = '\0';
}

/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARTICLE = 258,
    BE = 259,
    CHARACTER = 260,
    FIRST_PERSON = 261,
    FIRST_PERSON_POSSESSIVE = 262,
    FIRST_PERSON_REFLEXIVE = 263,
    NEGATIVE_ADJECTIVE = 264,
    NEGATIVE_COMPARATIVE = 265,
    NEGATIVE_NOUN = 266,
    NEUTRAL_ADJECTIVE = 267,
    NEUTRAL_NOUN = 268,
    NOTHING = 269,
    POSITIVE_ADJECTIVE = 270,
    POSITIVE_COMPARATIVE = 271,
    POSITIVE_NOUN = 272,
    SECOND_PERSON = 273,
    SECOND_PERSON_POSSESSIVE = 274,
    SECOND_PERSON_REFLEXIVE = 275,
    THIRD_PERSON_POSSESSIVE = 276,
    COLON = 277,
    COMMA = 278,
    EXCLAMATION_MARK = 279,
    LEFT_BRACKET = 280,
    PERIOD = 281,
    QUESTION_MARK = 282,
    RIGHT_BRACKET = 283,
    AND = 284,
    AS = 285,
    ENTER = 286,
    EXEUNT = 287,
    EXIT = 288,
    HEART = 289,
    IF_NOT = 290,
    IF_SO = 291,
    LESS = 292,
    LET_US = 293,
    LISTEN_TO = 294,
    MIND = 295,
    MORE = 296,
    NOT = 297,
    OPEN = 298,
    PROCEED_TO = 299,
    RECALL = 300,
    REMEMBER = 301,
    RETURN_TO = 302,
    SPEAK = 303,
    THAN = 304,
    THE_CUBE_OF = 305,
    THE_DIFFERENCE_BETWEEN = 306,
    THE_FACTORIAL_OF = 307,
    THE_PRODUCT_OF = 308,
    THE_QUOTIENT_BETWEEN = 309,
    THE_REMAINDER_OF_THE_QUOTIENT_BETWEEN = 310,
    THE_SQUARE_OF = 311,
    THE_SQUARE_ROOT_OF = 312,
    THE_SUM_OF = 313,
    TWICE = 314,
    WE_MUST = 315,
    WE_SHALL = 316,
    ACT_ROMAN = 317,
    SCENE_ROMAN = 318,
    ROMAN_NUMBER = 319,
    NONMATCH = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 50 "grammar.y" /* yacc.c:1909  */

  char *str;
  struct {
    int num;
    char **list;
  } stringlist;

#line 128 "grammar.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

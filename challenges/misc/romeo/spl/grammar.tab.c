/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 24 "grammar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
  
#include "strutils.h"
#include "telma.h"

#define COMMENT_COLUMN   40  // 
#define INDENTATION_SIZE 2   // number of spaces to indent output C code

/* macro to create indentation space */
#define INDENT (strpad(newstr(""), INDENTATION_SIZE, ' '))

/* Local function prototypes */
static void report_error(const char *expected_symbol);
static void report_warning(const char *expected_symbol);

/* Global variables local to this file */
static char *current_act = NULL;
static char *current_scene = NULL;
static int num_errors = 0;           // error counter
static int num_warnings = 0;         // warning counter
static int i;                        // all-purpose counter


#line 92 "grammar.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
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
#line 50 "grammar.y" /* yacc.c:355  */

  char *str;
  struct {
    int num;
    char **list;
  } stringlist;

#line 206 "grammar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "grammar.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1063

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   188,   193,   200,   207,   216,   219,   222,
     227,   234,   241,   248,   255,   264,   274,   280,   288,   294,
     302,   309,   317,   320,   326,   330,   336,   340,   345,   349,
     355,   359,   363,   367,   371,   377,   380,   385,   391,   402,
     408,   419,   425,   432,   439,   446,   454,   460,   466,   474,
     478,   484,   490,   497,   504,   510,   516,   523,   530,   537,
     544,   550,   557,   564,   572,   577,   583,   591,   594,   599,
     606,   609,   612,   617,   620,   625,   630,   636,   644,   647,
     650,   655,   659,   663,   669,   674,   677,   682,   687,   694,
     700,   703,   710,   716,   723,   726,   729,   734,   738,   742,
     748,   751,   756,   759,   762,   765,   770,   777,   785,   793,
     803,   808,   814,   820,   828,   833,   839,   846,   851,   854,
     857,   860,   865,   872,   879,   888,   891,   894,   900,   903,
     908,   930,   936,   941,   948,   954,   961,   967,   972,   978,
     985,   993,  1000,  1009,  1012,  1017,  1020,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1044,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1080,  1081,  1082,  1084,  1088,  1096,  1099,  1104,  1110,  1116,
    1122,  1128,  1136,  1139,  1142,  1145,  1148,  1151,  1156,  1159,
    1162,  1165,  1170,  1174,  1184,  1189,  1199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARTICLE", "BE", "CHARACTER",
  "FIRST_PERSON", "FIRST_PERSON_POSSESSIVE", "FIRST_PERSON_REFLEXIVE",
  "NEGATIVE_ADJECTIVE", "NEGATIVE_COMPARATIVE", "NEGATIVE_NOUN",
  "NEUTRAL_ADJECTIVE", "NEUTRAL_NOUN", "NOTHING", "POSITIVE_ADJECTIVE",
  "POSITIVE_COMPARATIVE", "POSITIVE_NOUN", "SECOND_PERSON",
  "SECOND_PERSON_POSSESSIVE", "SECOND_PERSON_REFLEXIVE",
  "THIRD_PERSON_POSSESSIVE", "COLON", "COMMA", "EXCLAMATION_MARK",
  "LEFT_BRACKET", "PERIOD", "QUESTION_MARK", "RIGHT_BRACKET", "AND", "AS",
  "ENTER", "EXEUNT", "EXIT", "HEART", "IF_NOT", "IF_SO", "LESS", "LET_US",
  "LISTEN_TO", "MIND", "MORE", "NOT", "OPEN", "PROCEED_TO", "RECALL",
  "REMEMBER", "RETURN_TO", "SPEAK", "THAN", "THE_CUBE_OF",
  "THE_DIFFERENCE_BETWEEN", "THE_FACTORIAL_OF", "THE_PRODUCT_OF",
  "THE_QUOTIENT_BETWEEN", "THE_REMAINDER_OF_THE_QUOTIENT_BETWEEN",
  "THE_SQUARE_OF", "THE_SQUARE_ROOT_OF", "THE_SUM_OF", "TWICE", "WE_MUST",
  "WE_SHALL", "ACT_ROMAN", "SCENE_ROMAN", "ROMAN_NUMBER", "NONMATCH",
  "$accept", "Act", "ActHeader", "Adjective", "BinaryOperator",
  "CharacterDeclaration", "CharacterDeclarationList", "CharacterList",
  "Comment", "Comparative", "Comparison", "Conditional", "Constant",
  "EndSymbol", "EnterExit", "Equality", "Inequality", "InOut", "Jump",
  "JumpPhrase", "JumpPhraseBeginning", "JumpPhraseEnd", "Line",
  "NegativeComparative", "NegativeConstant", "NegativeNoun",
  "NonnegatedComparison", "OpenYour", "Play", "PositiveComparative",
  "PositiveConstant", "PositiveNoun", "Pronoun", "Question",
  "QuestionSymbol", "Recall", "Remember", "Scene", "SceneContents",
  "SceneHeader", "Sentence", "SentenceList", "StartSymbol", "Statement",
  "StatementSymbol", "String", "StringSymbol", "Title",
  "UnarticulatedConstant", "UnaryOperator", "UnconditionalSentence",
  "Value", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -195

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-195)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     242,   119,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,   -36,
      28,   499,  -195,   263,    20,    40,  -195,    10,    32,    52,
      52,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,    -3,
      13,   307,   307,   307,    52,  -195,   307,   307,    38,  -195,
      46,  -195,    52,    20,    52,  -195,   625,   562,   625,   625,
     625,    75,   307,   307,    99,    65,  -195,  -195,    46,  -195,
    -195,  -195,  -195,  -195,  -195,   625,   118,   113,   627,   111,
     265,    37,   328,  -195,  -195,  -195,  -195,  -195,   401,   688,
     440,  -195,  -195,  -195,    90,   117,   372,   709,   131,  -195,
    -195,    80,  -195,  -195,     5,    11,    12,  -195,  -195,  -195,
    -195,    44,  -195,  -195,   401,   438,  -195,   143,   612,   422,
     426,   176,  -195,   433,   441,   450,  -195,  -195,  -195,   127,
     819,  -195,  -195,   819,  -195,  -195,  -195,   819,  -195,   819,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
     768,  -195,  -195,   789,   125,   629,   461,   649,  -195,   819,
    -195,   740,  -195,  -195,  -195,  -195,  -195,    87,   112,    16,
    -195,  -195,   370,   177,   370,   139,   358,    24,   638,   638,
     370,   370,   370,  -195,  -195,   370,   146,   178,  -195,  -195,
     395,  -195,   484,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
     478,   101,   145,   430,     8,  1004,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,   468,    18,  -195,  -195,  1004,
     848,   370,  1004,  -195,   947,   243,   869,   649,  -195,  -195,
    -195,   740,  -195,  -195,  -195,   370,   370,   308,  -195,  -195,
    -195,  -195,  -195,  -195,   370,   370,   373,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,   491,
    -195,  -195,  -195,    31,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,   497,  1004,  1004,   928,   497,   497,   497,  -195,   370,
    -195,   370,  -195,  -195,   370,   446,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   130,
       0,     0,   145,     0,     0,     0,    18,     0,     0,    90,
       0,     1,   143,   144,   110,   204,    35,    36,   146,     0,
       0,     0,     0,     0,    93,    19,     0,     0,     0,     3,
       0,     2,    92,    91,    89,    23,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,   117,    16,
      17,    15,     6,     5,     4,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   121,   124,   123,   122,     0,     0,
       0,    29,    28,    70,     0,     0,     0,     0,     0,    71,
      72,     0,   212,   213,     0,     0,     0,   214,   215,   216,
     128,     0,   217,   125,    76,     0,    45,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    73,    74,    68,     0,
       0,   218,   102,     0,   103,    34,   104,     0,   105,     0,
     207,    10,   208,    11,    12,    13,   209,   210,    14,   211,
       0,   219,   220,     0,     0,     0,     0,     0,    84,     0,
     100,     0,   101,   206,    81,   205,    97,     0,     0,     0,
      88,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    67,     0,     0,     0,   129,    42,
       0,    37,     0,    38,    44,    40,    43,    39,    78,    94,
       0,     0,     0,     0,     0,     0,    85,    86,    24,    27,
      25,    30,    31,    32,    33,     0,     0,   226,   222,     0,
       0,     0,     0,   138,     0,     0,     0,     0,    82,    83,
      99,     0,    98,   137,   132,     0,     0,     0,   112,   113,
     111,   115,   116,   114,     0,     0,     0,   127,   126,    66,
      64,    65,    55,    60,    51,    63,    54,    21,    20,     0,
       9,     8,     7,     0,    96,    80,    79,    95,    26,    50,
      49,     0,     0,     0,     0,     0,     0,     0,   136,     0,
     135,     0,   134,   131,     0,     0,    57,    59,    62,    53,
      56,    58,    61,    52,    47,    48,    46,   107,   225,   224,
     223,   221,   108,   109,   106,   142,   141,   140,   139,   133
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,   567,  -195,  -195,  -195,   -40,   464,  -118,   618,  -195,
     392,  -195,   270,   635,   479,   300,  -195,  -195,  -195,  -195,
    -195,   485,   521,  -195,  -189,  -195,   390,  -195,  -195,  -195,
    -194,  -195,  -195,  -195,   273,  -195,  -195,   568,  -195,  -195,
     180,   519,  -195,  -195,  -191,     2,   -60,  -195,   315,  -195,
     240,  -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    69,    70,   303,   190,    66,    67,   159,    96,   244,
     245,   141,   191,    75,   106,   246,   247,   142,   143,   144,
     145,   168,   107,   248,   203,   204,   249,   146,    59,   250,
     205,   206,   192,   147,    76,   148,   149,    89,   108,    90,
     150,   151,    60,   152,    77,    97,    62,    63,   207,   193,
     153,   194
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     215,    78,    61,   163,   263,   270,   220,   272,   268,   309,
     269,    64,   223,   225,    93,    65,   274,   276,    65,   313,
      81,   278,   280,   281,   283,   285,    68,    85,    71,   289,
     290,   291,   335,    86,   292,   294,   296,    78,   160,   102,
      85,    82,   161,    81,   -77,   128,   226,   314,   129,   -77,
     277,   104,   227,   256,    87,   166,   258,   310,   167,    68,
     103,   336,   130,    83,   286,   162,   119,   221,   222,   -77,
     318,   105,    68,   320,   323,    68,   113,   270,   269,   131,
     132,   218,   133,   134,   326,   327,   329,   135,   273,   136,
     137,   208,   138,   330,   331,   333,   120,   121,   122,    72,
     117,    73,    74,   219,   139,   140,   -77,   -77,   311,   209,
     304,    72,   297,    73,   128,    88,   305,   129,   210,   126,
      64,   118,   315,   317,    65,   319,   259,   321,   345,   325,
     346,   130,   216,   347,   349,   238,   211,   238,   213,   156,
     282,   239,    72,   239,    73,    74,   275,   293,   131,   132,
     217,   133,   134,    78,   306,   240,   135,   240,   136,   137,
     307,   138,   241,    72,   241,    73,   242,   243,   242,   243,
      72,   229,    73,   139,   140,   338,   339,   341,   279,   295,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   230,
      21,    72,    72,    73,    73,   232,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     1,   322,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    79,    21,   157,    72,    65,    73,
     158,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    95,   328,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   164,
      21,   228,    72,   165,    73,   228,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   212,   332,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    72,    21,    73,    72,   284,    73,
     161,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   -75,   128,
     238,   195,   129,   -75,   196,   166,   239,   348,   167,   197,
     233,   198,   199,   200,   234,   201,   130,   202,   287,   288,
     240,   235,   264,   -75,   170,   261,   265,   241,   173,   236,
      72,   242,    73,   131,   132,   175,   133,   134,   237,   299,
     177,   135,   179,   136,   137,   251,   138,   300,   252,   298,
     301,   240,   253,   302,   254,   262,   266,   312,   139,   140,
     -75,   -75,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   334,    21,    72,    74,    73,    74,    80,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   337,    21,   260,   123,   342,   343,
     344,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   154,   124,
     224,   129,   170,   308,    84,   230,   173,   155,    91,   128,
     231,   232,   129,   175,     0,   130,    92,    94,   177,    72,
     179,    73,    74,    72,     0,    73,   130,     0,   197,   240,
     198,   267,   131,   132,     0,   133,   134,     0,     0,     0,
     135,     0,   136,   137,     0,   138,   133,   134,     0,     0,
       0,   135,     0,   136,   137,     0,   138,   139,   140,   169,
       0,   170,     0,   171,   172,   173,   174,     0,   139,   140,
      98,    99,   175,     0,   100,   101,   176,   177,   178,   179,
     214,     0,   170,     0,   171,   172,   173,   174,     0,     0,
     115,   116,     0,   175,     0,     0,     0,   176,   177,   178,
     179,   109,     0,   110,   111,   112,   114,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
     125,   127,   271,   200,     0,   201,     0,   202,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   255,
       0,   170,     0,   171,   172,   173,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,   176,   177,   178,   179,
     257,     0,   170,     0,   171,   172,   173,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   197,     0,
     198,   199,   200,     0,   201,     0,   202,     0,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   316,
       0,   170,     0,   171,   172,   173,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,   176,   177,   178,   179,
     324,     0,   170,     0,   171,   172,   173,   174,     0,     0,
       0,     0,     0,   175,     0,     0,     0,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   340,
       0,   170,     0,   171,   172,   173,   174,     0,     0,     0,
       0,     0,   175,     0,     0,     0,   176,   177,   178,   179,
     170,     0,   171,   172,   173,   174,     0,     0,     0,     0,
       0,   175,     0,     0,     0,   176,   177,   178,   179,     0,
       0,    72,     0,    73,     0,     0,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   170,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,   175,     0,
       0,     0,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189
};

static const yytype_int16 yycheck[] =
{
     137,    61,     0,   121,   195,   199,     1,   201,   197,     1,
     199,     1,     1,     1,     1,     5,   207,     1,     5,     1,
      23,   212,   213,   214,   215,     1,    62,    67,     0,   220,
     221,   222,     1,     1,   225,   226,   227,    97,     1,     1,
      80,     1,     5,    23,     0,     1,    34,    29,     4,     5,
      34,     5,    40,   190,    22,    44,   193,    49,    47,    62,
      22,    30,    18,    23,    40,    28,     1,    62,    63,    25,
     261,    25,    62,   264,   265,    62,     1,   271,   267,    35,
      36,     1,    38,    39,   275,   276,   277,    43,     1,    45,
      46,     1,    48,   284,   285,   286,    31,    32,    33,    24,
       1,    26,    27,    23,    60,    61,    62,    63,   245,    19,
       9,    24,   230,    26,     1,    63,    15,     4,     1,     1,
       1,    22,   259,   260,     5,   262,     1,   264,   319,   266,
     321,    18,     1,   324,   325,    10,    19,    10,   136,    28,
       1,    16,    24,    16,    26,    27,    34,     1,    35,    36,
      19,    38,    39,   213,     9,    30,    43,    30,    45,    46,
      15,    48,    37,    24,    37,    26,    41,    42,    41,    42,
      24,    28,    26,    60,    61,   312,   313,   314,     1,     1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    23,
      23,    24,    24,    26,    26,    29,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     1,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     1,    23,     1,    24,     5,    26,
       5,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     1,     1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
      23,   151,    24,     5,    26,   155,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     1,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    24,    23,    26,    24,    40,    26,
       5,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     1,
      10,     1,     4,     5,     4,    44,    16,     1,    47,     9,
      28,    11,    12,    13,    28,    15,    18,    17,   218,   219,
      30,    28,     1,    25,     3,   195,   196,    37,     7,    28,
      24,    41,    26,    35,    36,    14,    38,    39,    28,     1,
      19,    43,    21,    45,    46,   170,    48,     9,   173,     5,
      12,    30,   177,    15,   179,   195,   196,    29,    60,    61,
      62,    63,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    30,    23,    24,    27,    26,    27,    63,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   311,    23,   194,   108,   315,   316,
     317,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     1,   108,
     145,     4,     3,   243,    67,    23,     7,   118,    70,     1,
      28,    29,     4,    14,    -1,    18,    79,    80,    19,    24,
      21,    26,    27,    24,    -1,    26,    18,    -1,     9,    30,
      11,    12,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    -1,    48,    38,    39,    -1,    -1,
      -1,    43,    -1,    45,    46,    -1,    48,    60,    61,     1,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    60,    61,
      82,    83,    14,    -1,    86,    87,    18,    19,    20,    21,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
     102,   103,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    96,    -1,    98,    99,   100,   101,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
     115,   116,    12,    13,    -1,    15,    -1,    17,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     1,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,    21,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     9,    -1,
      11,    12,    13,    -1,    15,    -1,    17,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     1,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,    21,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     1,
      -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    19,    20,    21,
       3,    -1,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,    24,    -1,    26,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     3,    -1,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    23,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    94,
     108,   111,   112,   113,     1,     5,    71,    72,    62,    67,
      68,     0,    24,    26,    27,    79,   100,   110,   112,     1,
      72,    23,     1,    23,    67,    71,     1,    22,    63,   103,
     105,   103,    67,     1,    67,     1,    74,   111,    74,    74,
      74,    74,     1,    22,     5,    25,    80,    88,   104,    79,
      79,    79,    79,     1,    79,    74,    74,     1,    22,     1,
      31,    32,    33,    80,    88,    79,     1,    79,     1,     4,
      18,    35,    36,    38,    39,    43,    45,    46,    48,    60,
      61,    77,    83,    84,    85,    86,    93,    99,   101,   102,
     106,   107,   109,   116,     1,   107,    28,     1,     5,    73,
       1,     5,    28,    73,     1,     5,    44,    47,    87,     1,
       3,     5,     6,     7,     8,    14,    18,    19,    20,    21,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      70,    78,    98,   115,   117,     1,     4,     9,    11,    12,
      13,    15,    17,    90,    91,    96,    97,   114,     1,    19,
       1,    19,     1,   111,     1,   117,     1,    19,     1,    23,
       1,    62,    63,     1,    87,     1,    34,    40,   106,    28,
      23,    28,    29,    28,    28,    28,    28,    28,    10,    16,
      30,    37,    41,    42,    75,    76,    81,    82,    89,    92,
      95,   114,   114,   114,   114,     1,   117,     1,   117,     1,
      76,    78,    81,   110,     1,    78,    81,    12,    90,    90,
      96,    12,    96,     1,   110,    34,     1,    34,   110,     1,
     110,   110,     1,   110,    40,     1,    40,   116,   116,   110,
     110,   110,   110,     1,   110,     1,   110,    73,     5,     1,
       9,    12,    15,    69,     9,    15,     9,    15,    92,     1,
      49,   117,    29,     1,    29,   117,     1,   117,   110,   117,
     110,   117,     1,   110,     1,   117,   110,   110,     1,   110,
     110,   110,     1,   110,    30,     1,    30,   100,   117,   117,
       1,   117,   100,   100,   100,   110,   110,   110,     1,   110
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      89,    90,    90,    90,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,    99,    99,
     100,   101,   101,   101,   102,   102,   102,   103,   104,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   107,   107,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   114,   114,   115,   115,   115,
     115,   115,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     1,     2,
       3,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     4,     4,     4,
       4,     3,     4,     4,     4,     3,     3,     3,     3,     2,
       2,     3,     4,     4,     3,     3,     4,     4,     4,     4,
       3,     4,     4,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     2,
       2,     1,     2,     2,     1,     1,     1,     2,     2,     3,
       2,     3,     3,     3,     1,     2,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       2,     2,     4,     4,     4,     1,     3,     3,     1,     2,
       1,     4,     3,     5,     4,     4,     4,     3,     3,     5,
       5,     5,     5,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     4,     4,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 185 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 1719 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 188 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 1727 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 193 "grammar.y" /* yacc.c:1646  */
    {
  free(current_act);
  current_act = newstr(str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_act), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 1739 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  free(current_act);
  current_act = newstr(str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_act), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[-2].str));
}
#line 1751 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 207 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("colon");
  free(current_act);
  current_act = newstr(str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_act), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[0].str));
}
#line 1763 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 216 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 1771 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 219 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 1779 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 222 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 1787 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 227 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(3*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_sub("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(", ");
  (yyval.stringlist).list[2] = newstr(")");
  free((yyvsp[0].str));
}
#line 1799 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 234 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(3*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_mul("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(", ");
  (yyval.stringlist).list[2] = newstr(")");
  free((yyvsp[0].str));
}
#line 1811 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 241 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(3*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_div("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(", ");
  (yyval.stringlist).list[2] = newstr(")");
  free((yyvsp[0].str));
}
#line 1823 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 248 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(3*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_mod("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(", ");
  (yyval.stringlist).list[2] = newstr(")");
  free((yyvsp[0].str));
}
#line 1835 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 255 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(3*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_add("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(", ");
  (yyval.stringlist).list[2] = newstr(")");
  free((yyvsp[0].str));
}
#line 1847 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 264 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(strpad(cat3(newstr("CHARACTER *"), str2varname(newstr((yyvsp[-3].str))),
				newstr(";")), COMMENT_COLUMN, ' '),
		    (yyvsp[-1].str), newstr("\n"));
  (yyval.stringlist).list[1] = cat4(str2varname(newstr((yyvsp[-3].str))), newstr(" = initialize_character(\""),
		    (yyvsp[-3].str), newstr("\");\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 1862 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 274 "grammar.y" /* yacc.c:1646  */
    {
  report_error("character name");
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = newstr("");
  (yyval.stringlist).list[1] = newstr("");
}
#line 1873 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 280 "grammar.y" /* yacc.c:1646  */
    {
  report_error("comma");
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = newstr("");
  (yyval.stringlist).list[1] = newstr("");
}
#line 1884 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 288 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = (yyvsp[0].stringlist).list[0];
  (yyval.stringlist).list[1] = (yyvsp[0].stringlist).list[1];
  free((yyvsp[0].stringlist).list);
}
#line 1895 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 294 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (yyvsp[-1].stringlist).list;
  (yyval.stringlist).list[0] = cat2((yyvsp[-1].stringlist).list[0], (yyvsp[0].stringlist).list[0]);
  (yyval.stringlist).list[1] = cat2((yyvsp[-1].stringlist).list[1], (yyvsp[0].stringlist).list[1]);
  free((yyvsp[0].stringlist).list);
}
#line 1906 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 302 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = (yyvsp[-2].str);
  (yyval.stringlist).list[1] = (yyvsp[0].str);
  (yyval.stringlist).num = 2;
  free((yyvsp[-1].str));
}
#line 1918 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 309 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).num = (yyvsp[0].stringlist).num + 1;
  (yyval.stringlist).list = realloc((yyvsp[0].stringlist).list, (yyval.stringlist).num*sizeof(char **));
  (yyval.stringlist).list[(yyval.stringlist).num - 1] = (yyvsp[-2].str);
  free((yyvsp[-1].str));
}
#line 1929 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 317 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("/* "), (yyvsp[0].str), newstr(" */"));
}
#line 1937 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 320 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("comment");
  (yyval.str) = newstr("/* NO COMMENT FOUND */");
}
#line 1946 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 326 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("comp1 < comp2");
  free((yyvsp[0].str));
}
#line 1955 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 330 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("comp1 > comp2");
  free((yyvsp[0].str));
}
#line 1964 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 336 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(newstr("!"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 1973 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 340 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 1981 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 345 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("truth_flag");
  free((yyvsp[0].str));
}
#line 1990 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 349 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("!truth_flag");
  free((yyvsp[0].str));
}
#line 1999 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 355 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
  free((yyvsp[-1].str));
}
#line 2008 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 359 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
  free((yyvsp[-1].str));
}
#line 2017 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 363 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
  free((yyvsp[-1].str));
}
#line 2026 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 367 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
  free((yyvsp[-1].str));
}
#line 2035 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 371 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("0");
  free((yyvsp[0].str));
}
#line 2044 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 377 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2052 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 380 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2060 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 385 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("\nenter_scene("), int2str(yylineno), newstr(", "), str2varname((yyvsp[-1].str)), newstr(");\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2071 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 391 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("\n");
  for (i = 0; i < (yyvsp[-1].stringlist).num; i++) {
    (yyval.str) = cat6((yyval.str), newstr("enter_scene("), int2str(yylineno), newstr(", "),
	      str2varname((yyvsp[-1].stringlist).list[i]), newstr(");\n"));
  }
  free((yyvsp[-1].stringlist).list);
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2087 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 402 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("\nexit_scene("), int2str(yylineno), newstr(", "), str2varname((yyvsp[-1].str)), newstr(");\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2098 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 408 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("\n");
  for (i = 0; i < (yyvsp[-1].stringlist).num; i++) {
    (yyval.str) = cat6((yyval.str), newstr("exit_scene("), int2str(yylineno), newstr(", "),
	      str2varname((yyvsp[-1].stringlist).list[i]), newstr(");\n"));
  }
  free((yyvsp[-1].stringlist).list);
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2114 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 419 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("\nexit_scene_all("), int2str(yylineno), newstr(");\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2125 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 425 "grammar.y" /* yacc.c:1646  */
    {
  report_error("character or character list");
  (yyval.str) = newstr("");
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2137 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 432 "grammar.y" /* yacc.c:1646  */
    {
  report_error("character");
  (yyval.str) = newstr("");
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2149 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 439 "grammar.y" /* yacc.c:1646  */
    {
  report_error("character list or nothing");
  (yyval.str) = newstr("");
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2161 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 446 "grammar.y" /* yacc.c:1646  */
    {
  report_error("'enter', 'exit' or 'exeunt'");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2172 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 454 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("comp1 == comp2");
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2183 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 460 "grammar.y" /* yacc.c:1646  */
    {
  report_error("adjective");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2194 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 466 "grammar.y" /* yacc.c:1646  */
    {
  report_error("as");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2205 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 474 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[-1].str);
  free((yyvsp[0].str));
}
#line 2214 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 478 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'than'");
  (yyval.str) = (yyvsp[-1].str);
}
#line 2223 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 484 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("int_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2234 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 490 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("char_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2246 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 497 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("int_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2258 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 504 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("char_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2269 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 510 "grammar.y" /* yacc.c:1646  */
    {
  report_error("'mind' or 'heart'");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2280 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 516 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("possessive pronoun, second person");
  (yyval.str) = cat3(newstr("char_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2292 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 523 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("possessive pronoun, second person");
  (yyval.str) = cat3(newstr("int_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2304 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 530 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'mind'");
  (yyval.str) = cat3(newstr("char_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2316 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 537 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'heart'");
  (yyval.str) = cat3(newstr("int_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2328 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 544 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat3(newstr("int_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2339 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 550 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat3(newstr("char_output("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2351 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 557 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat3(newstr("int_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2363 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 564 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat3(newstr("char_input("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2374 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 572 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("goto "), str2varname((yyvsp[-1].str)), newstr(";\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2384 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 577 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("goto "), newstr(current_act), newstr("_"),
	    str2varname((yyvsp[-1].str)), newstr(";\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2395 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 583 "grammar.y" /* yacc.c:1646  */
    {
  report_error("'act [roman number]' or 'scene [roman number]'");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2406 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 591 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 2414 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 594 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'let us', 'we must' or 'we shall'");
  (yyval.str) = newstr("");
  free((yyvsp[0].str));
}
#line 2424 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 599 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'proceed to' or 'return to'");
  (yyval.str) = newstr("");
  free((yyvsp[-1].str));
}
#line 2434 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 606 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2442 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 609 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2450 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 612 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2458 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 617 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2466 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 620 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2474 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 625 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat6(newstr("\nactivate_character("), int2str(yylineno), newstr(", "), str2varname((yyvsp[-2].str)),
	    newstr(");\n"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 2484 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 630 "grammar.y" /* yacc.c:1646  */
    {
  report_error("sentence list");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2495 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 636 "grammar.y" /* yacc.c:1646  */
    {
  report_error("colon");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2506 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 644 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2514 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 647 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 2522 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 650 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 2530 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 655 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("(-1)");
  free((yyvsp[0].str));
}
#line 2539 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 659 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(newstr("2*"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 2548 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 663 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(newstr("2*"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 2557 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 669 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2565 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 674 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("("), (yyvsp[0].str), newstr(")"));;
}
#line 2573 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 677 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("("), (yyvsp[0].str), newstr(")"));;
}
#line 2581 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 682 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("");
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2591 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 687 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("possessive pronoun, second person");
  (yyval.str) = newstr("");
  free((yyvsp[-1].str));
}
#line 2601 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 694 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat6((yyvsp[-2].str), newstr("\n"), (yyvsp[-1].stringlist).list[0], 
	    newstr("\nint comp1, comp2;\n\nglobal_initialize();\n\n"),
	    (yyvsp[-1].stringlist).list[1], (yyvsp[0].str));
  free((yyvsp[-1].stringlist).list);
}
#line 2612 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 700 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));  
}
#line 2620 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 703 "grammar.y" /* yacc.c:1646  */
    {
  report_error("act");
  (yyval.str) = newstr("");
  free((yyvsp[-1].stringlist).list[0]);
  free((yyvsp[-1].stringlist).list[1]);
  free((yyvsp[-1].stringlist).list);
}
#line 2632 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 710 "grammar.y" /* yacc.c:1646  */
    {
  report_error("character declaration list");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2643 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 716 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("title");
  (yyval.str) = cat4((yyvsp[-1].stringlist).list[0], newstr("\n"), (yyvsp[-1].stringlist).list[1], (yyvsp[0].str));
  free((yyvsp[-1].stringlist).list);
}
#line 2653 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 723 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2661 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 726 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 2669 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 729 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 2677 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 734 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("1");
  free((yyvsp[0].str));
}
#line 2686 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 738 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(newstr("2*"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 2695 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 742 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(newstr("2*"), (yyvsp[0].str));
  free((yyvsp[-1].str));
}
#line 2704 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 748 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2712 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 751 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2720 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 756 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("first_person");
}
#line 2728 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 759 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("first_person");
}
#line 2736 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 762 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("second_person");
}
#line 2744 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 765 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = newstr("second_person");
}
#line 2752 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 770 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat9(newstr("comp1 = "), (yyvsp[-3].str), newstr(";\n"),
	    newstr("comp2 = "), (yyvsp[-1].str), newstr(";\n"),
	    newstr("truth_flag = "), (yyvsp[-2].str), newstr(";\n"));
  free((yyvsp[-4].str));
  free((yyvsp[0].str));
}
#line 2764 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 777 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-4].str));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2777 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 785 "grammar.y" /* yacc.c:1646  */
    {
  report_error("comparison");
  (yyval.str) = newstr("");
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2790 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 793 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2803 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 803 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2811 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 808 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("pop("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 2822 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 814 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("string");
  (yyval.str) = cat3(newstr("pop("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2833 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 820 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat3(newstr("pop("), int2str(yylineno), newstr(", second_person);\n"));
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 2844 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 828 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("push("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2854 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 833 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2865 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 839 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat5(newstr("push("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-2].str));
}
#line 2875 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 846 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2883 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 851 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2891 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 854 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2899 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 857 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2907 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 860 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2915 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 865 "grammar.y" /* yacc.c:1646  */
    {
  free(current_scene);
  current_scene = cat3(newstr(current_act), newstr("_"), str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_scene), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 2927 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 872 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  free(current_scene);
  current_scene = cat3(newstr(current_act), newstr("_"), str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_scene), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[-2].str));
}
#line 2939 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 879 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("colon");
  free(current_scene);
  current_scene = cat3(newstr(current_act), newstr("_"), str2varname((yyvsp[-3].str)));
  (yyval.str) = cat4(newstr("\n"), strpad(cat2(newstr(current_scene), newstr(":")), COMMENT_COLUMN, ' '), (yyvsp[-1].str), newstr("\n"));
  free((yyvsp[0].str));
}
#line 2951 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 888 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2959 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 891 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("if ("), (yyvsp[-2].str), newstr(") {\n"), strindent((yyvsp[0].str), INDENT), newstr("}\n"));
}
#line 2967 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 894 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("comma");
  (yyval.str) = cat5(newstr("if ("), (yyvsp[-2].str), newstr(") {\n"), strindent((yyvsp[0].str), INDENT), newstr("}\n"));
}
#line 2976 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 900 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 2984 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 903 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str));
}
#line 2992 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 908 "grammar.y" /* yacc.c:1646  */
    {
  char *program;

  program = strindent(cat2((yyvsp[0].str), newstr("\nreturn 0;")), INDENT);
  if (num_errors == 0) {
    printf("/********************************************************************\n");
    printf(" *   This C program was generated by spl2c, the Shakespeare to C    *\n");
    printf(" *          converter by Jon Åslund and Karl Hasselström.           *\n");
    printf(" ********************************************************************/\n");
    printf("\n");
    printf("/* libspl definitions and function prototypes */\n");
    printf("#include <spl.h>\n");
    printf("\n");
    printf("int main(void)\n");
    printf("{\n");
    printf("%s\n", program);
    printf("}\n");
  }
  free(program);
}
#line 3017 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 930 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3028 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 936 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3038 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 941 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3050 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 948 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
}
#line 3061 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 954 "grammar.y" /* yacc.c:1646  */
    {
  report_error("constant");
  (yyval.str) = newstr("");
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3073 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 961 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("be");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-3].str));
  free((yyvsp[0].str));
}
#line 3084 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 967 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-2].str));
}
#line 3094 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 972 "grammar.y" /* yacc.c:1646  */
    {
  report_error("constant without article");
  (yyval.str) = newstr("");
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3105 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 978 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("period or exclamation mark");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
}
#line 3117 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 985 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3130 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 993 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("equality");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-4].str));
  free((yyvsp[-3].str));
  free((yyvsp[0].str));
}
#line 3142 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1000 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("be");
  (yyval.str) = cat5(newstr("assign("), int2str(yylineno), newstr(", second_person, "), (yyvsp[-1].str), newstr(");\n"));
  free((yyvsp[-4].str));
  free((yyvsp[-2].str));
  free((yyvsp[0].str));
}
#line 3154 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1009 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3162 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1012 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3170 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1017 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3178 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1020 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].str), newstr(" "), (yyvsp[0].str));
}
#line 3186 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1024 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3192 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1025 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3198 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1026 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3204 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1027 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3210 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1028 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3216 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1029 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3222 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1030 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3228 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1031 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3234 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1032 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3240 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1033 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3246 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1034 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3252 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1035 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3258 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1036 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3264 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1037 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3270 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1038 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3276 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1039 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3282 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1040 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3288 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1041 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3294 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1042 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3300 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1044 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3306 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1046 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3312 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1047 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3318 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1048 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3324 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1049 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3330 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1050 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3336 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1051 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3342 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1052 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3348 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1053 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3354 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1054 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3360 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1055 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3366 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1056 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3372 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1057 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3378 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1058 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3384 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1059 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3390 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1060 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3396 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1061 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3402 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1062 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3408 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1063 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3414 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1064 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3420 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1065 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3426 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1066 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3432 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1067 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3438 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1068 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3444 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1069 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3450 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1070 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3456 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1071 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3462 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1072 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3468 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1073 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3474 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1074 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3480 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1075 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3486 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1076 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3492 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1077 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3498 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1078 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3504 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1080 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3510 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1081 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3516 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1082 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3522 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1084 "grammar.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3528 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1088 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3(newstr("/******************************************************************\n * "),
	    strpad(str2upper((yyvsp[-1].str)), 63, ' '),
	    newstr("*\n ******************************************************************/\n"));
  free((yyvsp[0].str));
}
#line 3539 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1096 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3547 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1099 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3555 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1104 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_cube("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(")");
  free((yyvsp[0].str));
}
#line 3566 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1110 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_factorial("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(")");
  free((yyvsp[0].str));
}
#line 3577 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1116 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_square("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(")");
  free((yyvsp[0].str));
}
#line 3588 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1122 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_sqrt("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(")");
  free((yyvsp[0].str));
}
#line 3599 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1128 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.stringlist).list = (char **) malloc(2*sizeof(char **));
  (yyval.stringlist).list[0] = cat3(newstr("int_twice("), int2str(yylineno), newstr(", "));
  (yyval.stringlist).list[1] = newstr(")");
  free((yyvsp[0].str));
}
#line 3610 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1136 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3618 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1139 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3626 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1142 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3634 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1145 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3642 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1148 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3650 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1151 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3658 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1156 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat2(str2varname((yyvsp[0].str)), newstr("->value"));
}
#line 3666 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1159 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = (yyvsp[0].str);
}
#line 3674 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1162 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5(newstr("value_of("), int2str(yylineno), newstr(", "), (yyvsp[0].str), newstr(")"));
}
#line 3682 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1165 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat5((yyvsp[-3].stringlist).list[0], (yyvsp[-2].str), (yyvsp[-3].stringlist).list[1], (yyvsp[0].str), (yyvsp[-3].stringlist).list[2]);
  free((yyvsp[-3].stringlist).list);
  free((yyvsp[-1].str));
}
#line 3692 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1170 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.str) = cat3((yyvsp[-1].stringlist).list[0], (yyvsp[0].str), (yyvsp[-1].stringlist).list[1]);
  free((yyvsp[-1].stringlist).list);
}
#line 3701 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1174 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-3].stringlist).list[0]);
  free((yyvsp[-3].stringlist).list[1]);
  free((yyvsp[-3].stringlist).list[2]);
  free((yyvsp[-3].stringlist).list);
  free((yyvsp[-2].str));
  free((yyvsp[-1].str));
}
#line 3716 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1184 "grammar.y" /* yacc.c:1646  */
    {
  report_warning("'and'");
  (yyval.str) = cat5((yyvsp[-3].stringlist).list[0], (yyvsp[-2].str), (yyvsp[-3].stringlist).list[1], (yyvsp[0].str), (yyvsp[-3].stringlist).list[2]);
  free((yyvsp[-3].stringlist).list);
}
#line 3726 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1189 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-3].stringlist).list[0]);
  free((yyvsp[-3].stringlist).list[1]);
  free((yyvsp[-3].stringlist).list[2]);
  free((yyvsp[-3].stringlist).list);
  free((yyvsp[-1].str));
  free((yyvsp[0].str));
}
#line 3741 "grammar.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1199 "grammar.y" /* yacc.c:1646  */
    {
  report_error("value");
  (yyval.str) = newstr("");
  free((yyvsp[-1].stringlist).list[0]);
  free((yyvsp[-1].stringlist).list[1]);
  free((yyvsp[-1].stringlist).list);
}
#line 3753 "grammar.tab.c" /* yacc.c:1646  */
    break;


#line 3757 "grammar.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1207 "grammar.y" /* yacc.c:1906  */


int yyerror(char *s)
{
  /* Don't do anything special here. */
  return 0;
}

void report_error(const char *expected_symbol)
{
  fprintf(stderr, "Error at line %d: %s expected\n", yylineno, expected_symbol);
  num_errors++;
}

void report_warning(const char *expected_symbol)
{
  fprintf(stderr, "Warning at line %d: %s expected\n", yylineno, expected_symbol);
  num_warnings++;
}

int main(void)
{
#if(YYDEBUG == 1)
  yydebug = 1;
#endif
  if (yyparse() == 0) {
    if (num_errors > 0) {
      fprintf(stderr, "%d errors and %d warnings found. No code output.\n", num_errors, num_warnings);
      exit(1);
    } else if (num_warnings > 0) {
      fprintf(stderr, "%d warnings found. Code may be defective.\n", num_warnings);
    }
  } else {
      fprintf(stderr, "Unrecognized error encountered. No code output.\n");
      exit(1);
  }
  return 0;
}

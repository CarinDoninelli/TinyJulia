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
#line 6 "parser.y" /* yacc.c:339  */

    #include <cstdio>
    #include <string>
    #include <iostream>

    #include "ast.h"
    #include "types.h"

    using namespace std;

    extern int yylineno;

    int yylex();

    int errors;
    void yyerror(const char *str)
    {
        printf("Line %d: %s\n", yylineno, str);
    }

    #define YYERROR_VERBOSE 1

    Expression *expression;

#line 91 "parser.cpp" /* yacc.c:339  */

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
   by #include "tokens.h".  */
#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:355  */

    #include <string>
    #include "ast.h"

#line 126 "parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_ID = 259,
    STRING_LITERAL = 260,
    CHAR_LITERAL = 261,
    BOOL_LITERAL = 262,
    KW_IF = 263,
    KW_ELSE = 264,
    KW_WHILE = 265,
    KW_FOR = 266,
    KW_PRINTLN = 267,
    KW_END = 268,
    KW_ELIF = 269,
    KW_PRINT = 270,
    KW_FUNCTION = 271,
    KW_BOOL = 272,
    KW_INT = 273,
    KW_ARRAY = 274,
    KW_RETURN = 275,
    TK_EOL = 276,
    TK_LPAREN = 277,
    TK_RPAREN = 278,
    TK_LBRACK = 279,
    TK_RBRACK = 280,
    TK_DOUBLE_COLON = 281,
    TK_LBRACE = 282,
    TK_RBRACE = 283,
    OP_PLUS_ASSIGN = 284,
    OP_SUB_ASSIGN = 285,
    OP_MUL_ASSIGN = 286,
    OP_DIV_ASSIGN = 287,
    OP_MOD_ASSIGN = 288,
    OP_POW_ASSIGN = 289,
    OP_LTE = 290,
    OP_GTE = 291,
    OP_NE = 292,
    OP_EQ = 293,
    TK_AND = 294,
    TK_OR = 295,
    TK_RSHIFT = 296,
    TK_LSHIFT = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:355  */

    string *id_t;
    int num_t;
    bool bool_t;
    Expression *expression_t;
    vector<Expression *> *expression_list_t;
    ReturnType type_t;
    vector<FunctionDeclaration::Param> *params_t;

#line 191 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,    48,    56,    49,     2,
       2,     2,    54,    53,    44,    52,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    43,
      51,    45,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    47,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    73,    74,    75,    78,    79,    82,    85,
      86,    89,    90,    91,    92,    93,    94,    95,    96,    99,
     102,   105,   106,   109,   112,   115,   116,   117,   120,   123,
     124,   127,   128,   131,   132,   135,   138,   139,   140,   143,
     144,   147,   150,   151,   152,   153,   154,   155,   156,   157,
     160,   161,   164,   165,   168,   169,   172,   173,   176,   177,
     180,   181,   182,   183,   184,   185,   186,   189,   190,   191,
     194,   195,   196,   197,   200,   201,   204,   205,   206,   209,
     210,   211,   216,   217,   218,   221,   222,   223,   226,   227
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_ID", "STRING_LITERAL",
  "CHAR_LITERAL", "BOOL_LITERAL", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR",
  "KW_PRINTLN", "KW_END", "KW_ELIF", "KW_PRINT", "KW_FUNCTION", "KW_BOOL",
  "KW_INT", "KW_ARRAY", "KW_RETURN", "TK_EOL", "TK_LPAREN", "TK_RPAREN",
  "TK_LBRACK", "TK_RBRACK", "TK_DOUBLE_COLON", "TK_LBRACE", "TK_RBRACE",
  "OP_PLUS_ASSIGN", "OP_SUB_ASSIGN", "OP_MUL_ASSIGN", "OP_DIV_ASSIGN",
  "OP_MOD_ASSIGN", "OP_POW_ASSIGN", "OP_LTE", "OP_GTE", "OP_NE", "OP_EQ",
  "TK_AND", "TK_OR", "TK_RSHIFT", "TK_LSHIFT", "';'", "','", "'='", "':'",
  "'|'", "'$'", "'&'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "'^'", "'!'", "$accept", "program", "new_line", "opEol",
  "unending_block", "statement_list", "statement", "return", "function",
  "function_params", "for", "if", "else", "while", "print_statement",
  "print_argument_list", "print_argument", "declaration_statement", "type",
  "optType", "expression", "assignment", "condition_or", "condition_and",
  "bitwise_or", "bitwise_xor", "bitwise_and", "relational", "arithmetic",
  "term", "exponent", "unary", "factor", "postfix", "expression_list", YY_NULLPTR
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
     295,   296,   297,    59,    44,    61,    58,   124,    36,    38,
      62,    60,    45,    43,    42,    47,    37,    94,    33
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -82,   -82,    14,    19,    96,   -82,   -82,   -82,    22,
     -82,   133,   133,    39,    47,    50,    73,   133,   133,   133,
     133,   133,    -5,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,    58,    66,    62,    77,    78,   114,   -24,    26,
      71,   -82,   -82,   149,   110,   133,    68,    70,    -7,   117,
     -82,   117,    90,   119,   119,   131,   -82,   116,   -82,   -12,
     -82,   -82,   -82,    15,   -82,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   -82,
      -3,   134,   -82,   -82,   -82,   133,    -5,    65,   143,   133,
     -82,    -2,   -82,   -82,     1,   154,   -82,   -82,   133,   -82,
      66,    62,    77,    78,   114,   -24,   -24,   -24,   -24,   -24,
     -24,    26,    26,    71,    71,    71,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,    96,   117,   -82,
     133,   -82,   -82,   115,   -82,   119,   -82,   137,    24,   -82,
      -5,   147,   117,   133,   -82,   -82,   137,   162,   -82,   -82,
      65,   117,   -82,   117,   137,   -82,   156,   157,   -82,   -82,
     -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     4,     5,     0,     6,     0,     1,     3,    79,    82,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    10,    18,    17,    16,    15,    14,    11,
      12,    13,    49,    51,    53,    55,    57,    59,    66,    69,
      73,    75,    85,    78,     0,     0,     0,     0,    82,     0,
      41,     0,     0,     0,     0,     0,    19,     0,    89,     0,
      76,    78,    77,     6,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,    37,    36,    38,     0,     7,     0,     0,     0,
      33,     0,    32,    34,     0,     0,    84,    81,     0,     9,
      50,    52,    54,    56,    58,    65,    64,    61,    60,    62,
      63,    67,    68,    70,    71,    72,    74,    43,    44,    45,
      46,    47,    48,    42,    86,    83,    35,     0,     0,    27,
       0,    24,    28,     0,    29,     0,    30,     0,     0,    88,
       7,     0,     0,     0,    31,    22,    40,     0,     8,    26,
       0,     0,    39,     0,     0,    25,     0,     0,    21,    23,
      20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -19,   -20,   -42,    30,   109,   -82,   -82,   -82,
     -82,   -82,    13,   -82,   -82,   120,    31,   -82,   -81,   -82,
     -11,     7,   -82,   121,   118,   108,   122,   123,   125,    25,
      67,   -10,   -82,   -16,   144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    97,    22,    23,    24,    25,   148,
      26,    27,   141,    28,    29,   101,   102,    30,    47,   163,
     103,    50,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    51,    64,    63,    61,    61,    56,    57,    58,    98,
      60,    62,    31,   107,     6,    44,     1,    45,     8,     9,
     134,   144,    10,    11,   146,    12,    13,    14,    76,    77,
      15,    16,   108,    58,    91,    17,     7,    18,     2,    19,
       7,   108,   145,    52,    44,   145,    45,   156,    46,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,   155,    20,   157,    53,
      31,   126,    54,    21,   138,   162,   137,    55,   139,   140,
      78,    79,    80,   168,   136,    92,    93,    94,   143,   127,
     128,   129,   130,   131,   132,   133,   151,   149,    65,     8,
       9,   121,   122,    10,    11,    66,    12,    13,    14,    67,
     160,    15,    16,     8,    48,    95,    17,    10,    18,   166,
      19,   167,     8,    48,   100,    68,    10,    69,    81,   152,
     158,    63,    18,    89,    19,    99,     8,    48,    96,   106,
      10,    18,   161,    19,    31,   123,   124,   125,    20,    70,
      71,    72,    73,   105,    21,    18,   142,    19,   147,   135,
     159,   153,    20,    46,    74,    75,   164,   150,    21,   169,
     170,    20,   109,   165,   104,   112,   154,    21,    82,    83,
      84,    85,    86,    87,   111,    20,   110,     0,    90,     0,
     113,    21,   114,     0,    88,   115,   116,   117,   118,   119,
     120
};

static const yytype_int16 yycheck[] =
{
      11,    12,    22,    22,    20,    21,    17,    18,    19,    51,
      20,    21,     5,    25,     0,    22,    21,    24,     3,     4,
      23,    23,     7,     8,    23,    10,    11,    12,    52,    53,
      15,    16,    44,    44,    45,    20,    21,    22,    43,    24,
      21,    44,    44,     4,    22,    44,    24,    23,    26,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   147,    52,    44,    22,
      63,    81,    22,    58,     9,   156,    96,     4,    13,    14,
      54,    55,    56,   164,    95,    17,    18,    19,    99,    82,
      83,    84,    85,    86,    87,    88,   138,   108,    40,     3,
       4,    76,    77,     7,     8,    39,    10,    11,    12,    47,
     152,    15,    16,     3,     4,    45,    20,     7,    22,   161,
      24,   163,     3,     4,     5,    48,     7,    49,    57,   140,
     150,   150,    22,    23,    24,    45,     3,     4,    21,    23,
       7,    22,   153,    24,   137,    78,    79,    80,    52,    35,
      36,    37,    38,    22,    58,    22,    13,    24,     4,    25,
      13,    46,    52,    26,    50,    51,     4,   137,    58,    13,
      13,    52,    63,   160,    54,    67,   145,    58,    29,    30,
      31,    32,    33,    34,    66,    52,    65,    -1,    44,    -1,
      68,    58,    69,    -1,    45,    70,    71,    72,    73,    74,
      75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    43,    60,    61,    62,     0,    21,     3,     4,
       7,     8,    10,    11,    12,    15,    16,    20,    22,    24,
      52,    58,    64,    65,    66,    67,    69,    70,    72,    73,
      76,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    22,    24,    26,    77,     4,    79,
      80,    79,     4,    22,    22,     4,    79,    79,    79,    93,
      90,    92,    90,    61,    62,    40,    39,    47,    48,    49,
      35,    36,    37,    38,    50,    51,    52,    53,    54,    55,
      56,    57,    29,    30,    31,    32,    33,    34,    45,    23,
      93,    79,    17,    18,    19,    45,    21,    63,    63,    45,
       5,    74,    75,    79,    74,    22,    23,    25,    44,    65,
      82,    83,    84,    85,    86,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    89,    90,    80,    80,    80,
      80,    80,    80,    80,    23,    25,    79,    62,     9,    13,
      14,    71,    13,    79,    23,    44,    23,     4,    68,    79,
      64,    63,    79,    46,    75,    77,    23,    44,    62,    13,
      63,    79,    77,    78,     4,    71,    63,    63,    77,    13,
      13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    68,    69,    70,    71,    71,    71,    72,    73,
      73,    74,    74,    75,    75,    76,    77,    77,    77,    78,
      78,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     0,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       8,     4,     2,     8,     4,     4,     3,     1,     4,     4,
       4,     3,     1,     1,     1,     4,     2,     2,     2,     1,
       0,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     3,     1,     4,     3,     1,     4,     3,     3,     1
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
#line 70 "parser.y" /* yacc.c:1661  */
    { expression = new Block(*(yyvsp[-1].expression_list_t)); }
#line 1417 "parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 82 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Block(*(yyvsp[-1].expression_list_t)); }
#line 1423 "parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 85 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1429 "parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 86 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression *>{ (yyvsp[0].expression_t) }; }
#line 1435 "parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 89 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1441 "parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 90 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1447 "parser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 91 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1453 "parser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 92 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1459 "parser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 93 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1465 "parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 94 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1471 "parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 95 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1477 "parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 96 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1483 "parser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 99 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Return((yyvsp[0].expression_t)); }
#line 1489 "parser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 102 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionDeclaration(*(yyvsp[-6].id_t), *(yyvsp[-4].params_t), (yyvsp[-2].type_t), (yyvsp[-1].expression_t)); }
#line 1495 "parser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 105 "parser.y" /* yacc.c:1661  */
    { (yyval.params_t) = (yyvsp[-3].params_t); (yyval.params_t)->push_back(FunctionDeclaration::Param{*(yyvsp[-1].id_t), (yyvsp[0].type_t)}); }
#line 1501 "parser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 106 "parser.y" /* yacc.c:1661  */
    { (yyval.params_t) = new vector<FunctionDeclaration::Param>{ FunctionDeclaration::Param(*(yyvsp[-1].id_t), (yyvsp[0].type_t)) }; }
#line 1507 "parser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 109 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new For(*(yyvsp[-6].id_t), (yyvsp[-4].expression_t), (yyvsp[-2].expression_t), (yyvsp[-1].expression_t)); }
#line 1513 "parser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 112 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new If((yyvsp[-2].expression_t), (yyvsp[-1].expression_t), (yyvsp[0].expression_t)); }
#line 1519 "parser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 115 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new If((yyvsp[-2].expression_t), (yyvsp[-1].expression_t), (yyvsp[0].expression_t)); }
#line 1525 "parser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 116 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[-1].expression_t); }
#line 1531 "parser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 117 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = nullptr; }
#line 1537 "parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 120 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new While((yyvsp[-2].expression_t), (yyvsp[-1].expression_t)); }
#line 1543 "parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 123 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Print{ *(yyvsp[-1].expression_list_t), true }; }
#line 1549 "parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 124 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Print{ *(yyvsp[-1].expression_list_t), false }; }
#line 1555 "parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 127 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1561 "parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 128 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression*>; (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1567 "parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 131 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new StringExpression{ *(yyvsp[0].id_t) }; }
#line 1573 "parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 132 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1579 "parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 135 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Declaration{ *(yyvsp[-3].id_t), (yyvsp[-2].type_t), (yyvsp[0].expression_t) }; }
#line 1585 "parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 138 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::INTEGER; }
#line 1591 "parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 139 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::BOOL; }
#line 1597 "parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 140 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::INT_ARRAY; }
#line 1603 "parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 143 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = (yyvsp[0].type_t); }
#line 1609 "parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 144 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::UNIT; }
#line 1615 "parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 147 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1621 "parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 150 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1627 "parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 151 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new AddExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1633 "parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 152 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new SubExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1639 "parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 153 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new MulExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1645 "parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 154 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new DivExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1651 "parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 155 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new ModExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1657 "parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 156 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new PowExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1663 "parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 157 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1669 "parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 160 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new OrExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1675 "parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 161 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1681 "parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 164 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new AndExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1687 "parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 165 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1693 "parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 168 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BitwiseOrExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1699 "parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 169 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1705 "parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 172 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new XorExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1711 "parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 173 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1717 "parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 176 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BitwiseAndExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1723 "parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 177 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1729 "parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 180 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new EqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };              }
#line 1735 "parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 181 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new NotEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };           }
#line 1741 "parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 182 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new GreaterThanExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };        }
#line 1747 "parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 183 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new LessThanExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };           }
#line 1753 "parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 184 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new GreaterThanOrEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1759 "parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 185 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new LessThanOrEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };    }
#line 1765 "parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 186 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1771 "parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 189 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new SubExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1777 "parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 190 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new AddExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1783 "parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 191 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1789 "parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 194 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new MulExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1795 "parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 195 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new DivExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1801 "parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 196 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new ModExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1807 "parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 197 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1813 "parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 200 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new PowExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1819 "parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 201 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1825 "parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 204 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new UnaryMinus((yyvsp[0].expression_t)); }
#line 1831 "parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 205 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Negation((yyvsp[0].expression_t)); }
#line 1837 "parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 206 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1843 "parser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 209 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new IntExpression((yyvsp[0].num_t)); }
#line 1849 "parser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 210 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BoolExpression((yyvsp[0].bool_t)); }
#line 1855 "parser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 211 "parser.y" /* yacc.c:1661  */
    { 
                                               auto values = (yyvsp[-1].expression_list_t);
                                               values->insert(values->begin(), new IntExpression(0));
                                               (yyval.expression_t) = new Array(*values); 
                                             }
#line 1865 "parser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 216 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new IdExpression(*(yyvsp[0].id_t)); }
#line 1871 "parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 217 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new ArrayAccess(*(yyvsp[-3].id_t), (yyvsp[-1].expression_t)); }
#line 1877 "parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 218 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[-1].expression_t); }
#line 1883 "parser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 221 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1889 "parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 222 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionCall{ *(yyvsp[-3].id_t), *(yyvsp[-1].expression_list_t) }; }
#line 1895 "parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 223 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionCall{ *(yyvsp[-2].id_t), vector<Expression *>() }; }
#line 1901 "parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 226 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1907 "parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 227 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression *>{ (yyvsp[0].expression_t) }; }
#line 1913 "parser.cpp" /* yacc.c:1661  */
    break;


#line 1917 "parser.cpp" /* yacc.c:1661  */
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
#line 230 "parser.y" /* yacc.c:1906  */

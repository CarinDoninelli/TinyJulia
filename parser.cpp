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
    KW_BREAK = 275,
    KW_CONTINUE = 276,
    KW_RETURN = 277,
    TK_EOL = 278,
    TK_LPAREN = 279,
    TK_RPAREN = 280,
    TK_LBRACK = 281,
    TK_RBRACK = 282,
    TK_DOUBLE_COLON = 283,
    TK_LBRACE = 284,
    TK_RBRACE = 285,
    OP_PLUS_ASSIGN = 286,
    OP_SUB_ASSIGN = 287,
    OP_MUL_ASSIGN = 288,
    OP_DIV_ASSIGN = 289,
    OP_MOD_ASSIGN = 290,
    OP_POW_ASSIGN = 291,
    OP_LTE = 292,
    OP_GTE = 293,
    OP_NE = 294,
    OP_EQ = 295,
    TK_AND = 296,
    TK_OR = 297,
    TK_RSHIFT = 298,
    TK_LSHIFT = 299
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

#line 193 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,    50,    58,    51,     2,
       2,     2,    56,    55,    46,    54,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
      53,    47,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,     2,    61,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    75,    76,    77,    80,    81,    84,    87,
      88,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   103,   106,   109,   112,   115,   116,   117,   120,   123,
     126,   127,   128,   131,   134,   135,   138,   139,   142,   143,
     146,   147,   150,   151,   152,   153,   156,   157,   160,   163,
     164,   165,   166,   167,   168,   169,   170,   173,   174,   177,
     178,   181,   182,   185,   186,   189,   190,   193,   194,   197,
     198,   201,   202,   203,   204,   205,   206,   207,   210,   211,
     212,   215,   216,   217,   218,   221,   222,   225,   226,   227,
     228,   231,   232,   233,   238,   239,   240,   243,   244,   245,
     248,   249
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
  "KW_INT", "KW_ARRAY", "KW_BREAK", "KW_CONTINUE", "KW_RETURN", "TK_EOL",
  "TK_LPAREN", "TK_RPAREN", "TK_LBRACK", "TK_RBRACK", "TK_DOUBLE_COLON",
  "TK_LBRACE", "TK_RBRACE", "OP_PLUS_ASSIGN", "OP_SUB_ASSIGN",
  "OP_MUL_ASSIGN", "OP_DIV_ASSIGN", "OP_MOD_ASSIGN", "OP_POW_ASSIGN",
  "OP_LTE", "OP_GTE", "OP_NE", "OP_EQ", "TK_AND", "TK_OR", "TK_RSHIFT",
  "TK_LSHIFT", "';'", "','", "'='", "':'", "'|'", "'$'", "'&'", "'>'",
  "'<'", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "'!'", "'~'", "$accept",
  "program", "new_line", "opEol", "unending_block", "statement_list",
  "statement", "break", "continue", "return", "function",
  "function_params", "for", "if", "else", "while", "print_statement",
  "print_argument_list", "print_argument", "declaration_statement", "type",
  "optType", "expression", "assignment", "condition_or", "condition_and",
  "bitwise_or", "bitwise_xor", "bitwise_and", "left_shift", "right_shift",
  "relational", "arithmetic", "term", "exponent", "unary", "factor",
  "postfix", "expression_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,    59,    44,    61,    58,   124,
      36,    38,    62,    60,    45,    43,    42,    47,    37,    94,
      33,   126
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,  -144,  -144,    22,     3,   124,  -144,  -144,  -144,    -8,
    -144,   164,   164,    28,    31,    53,    48,  -144,  -144,   164,
     164,   164,   164,   164,   164,   -12,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,    37,    45,    57,
      47,    61,    75,    77,   154,   -26,    33,    63,  -144,  -144,
      82,   148,   164,    91,    83,    -5,   110,  -144,   110,   100,
     156,   156,   114,  -144,   128,  -144,    49,  -144,  -144,  -144,
    -144,    27,  -144,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,  -144,
      -2,   122,  -144,  -144,   130,   164,   -12,    71,   145,   164,
    -144,    -1,  -144,  -144,     0,   158,  -144,  -144,   164,  -144,
      45,    57,    47,    61,    75,    77,   154,   -26,   -26,   -26,
     -26,   -26,   -26,    33,    33,    63,    63,    63,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   164,  -144,
     124,   110,  -144,   164,  -144,  -144,   116,  -144,   156,  -144,
     137,    29,  -144,   141,   -12,   157,   110,   164,  -144,  -144,
     137,   165,  -144,  -144,  -144,    71,   110,  -144,   110,   137,
    -144,   162,   163,  -144,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     4,     5,     0,     6,     0,     1,     3,    91,    94,
      92,     0,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     7,    10,    19,    20,    18,
      17,    16,    15,    14,    11,    12,    13,    56,    58,    60,
      62,    64,    66,    68,    70,    77,    80,    84,    86,    97,
      90,     0,     0,     0,    41,    94,     0,    48,     0,     0,
       0,     0,     0,    23,     0,   101,     0,    87,    90,    88,
      89,     6,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,    43,    42,    45,     0,     7,     0,     0,     0,
      38,     0,    37,    39,     0,    27,    96,    93,     0,     9,
      57,    59,    61,    63,    65,    67,    69,    76,    75,    72,
      71,    73,    74,    78,    79,    81,    82,    83,    85,    50,
      51,    52,    53,    54,    55,    49,    98,    95,     0,    40,
       0,     0,    32,     0,    29,    33,     0,    34,     0,    35,
       0,     0,   100,     0,     7,     0,     0,     0,    36,    26,
      47,     0,    44,     8,    31,     0,     0,    46,     0,     0,
      30,     0,     0,    25,    28,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,   -21,   -23,   -55,    39,   106,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,     4,  -144,  -144,   120,    25,  -144,
    -143,  -144,   -11,     7,  -144,   113,   127,   112,   129,   126,
     133,   125,   115,     6,    36,    -9,  -144,   -17,   161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   107,    25,    26,    27,    28,    29,
      30,   161,    31,    32,   154,    33,    34,   111,   112,    35,
      54,   178,   113,    57,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    58,    72,   108,    71,    68,    68,    68,    63,    64,
      65,     1,    36,    67,    69,    70,    51,   169,    52,    51,
      53,    52,     6,   146,   157,   159,     7,   177,    86,    87,
       8,     9,    59,     2,    10,    11,   183,    12,    13,    14,
      65,   101,    15,    16,   118,   158,   158,    17,    18,    19,
       7,    20,    62,    21,   170,    60,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,   171,   117,    61,    36,    73,
     151,    22,   138,   150,   152,   153,    74,    23,    24,    88,
      89,    90,   133,   134,   149,   118,   165,    76,   156,   139,
     140,   141,   142,   143,   144,   145,    75,   162,   102,   103,
     104,   175,    77,    92,    93,    94,    95,    96,    97,    78,
      79,   181,    91,   182,   135,   136,   137,     8,     9,    98,
     105,    10,    11,   106,    12,    13,    14,   163,   115,    15,
      16,   173,   166,    71,    17,    18,    19,   109,    20,   147,
      21,     8,    55,   116,   148,    10,   176,    36,   155,     8,
      55,   110,   160,    10,   167,    53,   172,     8,    55,   179,
     174,    10,    20,    99,    21,   184,   185,   119,    22,   180,
      20,   114,    21,   168,    23,    24,   120,   122,    20,   164,
      21,    80,    81,    82,    83,   127,   128,   129,   130,   131,
     132,   121,    22,   124,   126,   123,    84,    85,    23,    24,
      22,   125,   100,     0,     0,     0,    23,    24,    22,     0,
       0,     0,     0,     0,    23,    24
};

static const yytype_int16 yycheck[] =
{
      11,    12,    25,    58,    25,    22,    23,    24,    19,    20,
      21,    23,     5,    22,    23,    24,    24,   160,    26,    24,
      28,    26,     0,    25,    25,    25,    23,   170,    54,    55,
       3,     4,     4,    45,     7,     8,   179,    10,    11,    12,
      51,    52,    15,    16,    46,    46,    46,    20,    21,    22,
      23,    24,     4,    26,    25,    24,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    46,    27,    24,    71,    42,
       9,    54,    91,   106,    13,    14,    41,    60,    61,    56,
      57,    58,    86,    87,   105,    46,   151,    50,   109,    92,
      93,    94,    95,    96,    97,    98,    49,   118,    17,    18,
      19,   166,    51,    31,    32,    33,    34,    35,    36,    44,
      43,   176,    59,   178,    88,    89,    90,     3,     4,    47,
      47,     7,     8,    23,    10,    11,    12,   148,    24,    15,
      16,   164,   153,   164,    20,    21,    22,    47,    24,    27,
      26,     3,     4,    25,    24,     7,   167,   150,    13,     3,
       4,     5,     4,     7,    48,    28,    25,     3,     4,     4,
      13,     7,    24,    25,    26,    13,    13,    71,    54,   175,
      24,    61,    26,   158,    60,    61,    73,    75,    24,   150,
      26,    37,    38,    39,    40,    80,    81,    82,    83,    84,
      85,    74,    54,    77,    79,    76,    52,    53,    60,    61,
      54,    78,    51,    -1,    -1,    -1,    60,    61,    54,    -1,
      -1,    -1,    -1,    -1,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    45,    63,    64,    65,     0,    23,     3,     4,
       7,     8,    10,    11,    12,    15,    16,    20,    21,    22,
      24,    26,    54,    60,    61,    67,    68,    69,    70,    71,
      72,    74,    75,    77,    78,    81,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    24,    26,    28,    82,     4,    84,    85,    84,     4,
      24,    24,     4,    84,    84,    84,   100,    97,    99,    97,
      97,    64,    65,    42,    41,    49,    50,    51,    44,    43,
      37,    38,    39,    40,    52,    53,    54,    55,    56,    57,
      58,    59,    31,    32,    33,    34,    35,    36,    47,    25,
     100,    84,    17,    18,    19,    47,    23,    66,    66,    47,
       5,    79,    80,    84,    79,    24,    25,    27,    46,    68,
      87,    88,    89,    90,    91,    92,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    96,    97,    85,
      85,    85,    85,    85,    85,    85,    25,    27,    24,    84,
      65,     9,    13,    14,    76,    13,    84,    25,    46,    25,
       4,    73,    84,    84,    67,    66,    84,    48,    80,    82,
      25,    46,    25,    65,    13,    66,    84,    82,    83,     4,
      76,    66,    66,    82,    13,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    70,    71,    72,    73,    73,    73,    74,    75,
      76,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     0,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     8,     4,     2,     0,     8,     4,
       4,     3,     1,     4,     4,     4,     3,     1,     1,     1,
       4,     2,     2,     2,     5,     2,     1,     0,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     3,     1,     4,     3,     1,     4,     3,
       3,     1
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
#line 72 "parser.y" /* yacc.c:1661  */
    { expression = new Block(*(yyvsp[-1].expression_list_t)); }
#line 1435 "parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 84 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Block(*(yyvsp[-1].expression_list_t)); }
#line 1441 "parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 87 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1447 "parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 88 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression *>{ (yyvsp[0].expression_t) }; }
#line 1453 "parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 91 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1459 "parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 92 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1465 "parser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 93 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1471 "parser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 94 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1477 "parser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 95 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1483 "parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 96 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1489 "parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 97 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1495 "parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 98 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1501 "parser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 99 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1507 "parser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 100 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1513 "parser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 103 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Break(); }
#line 1519 "parser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 106 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Continue(); }
#line 1525 "parser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 109 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Return((yyvsp[0].expression_t)); }
#line 1531 "parser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 112 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionDeclaration(*(yyvsp[-6].id_t), *(yyvsp[-4].params_t), (yyvsp[-2].type_t), (yyvsp[-1].expression_t)); }
#line 1537 "parser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 115 "parser.y" /* yacc.c:1661  */
    { (yyval.params_t) = (yyvsp[-3].params_t); (yyval.params_t)->push_back(FunctionDeclaration::Param{*(yyvsp[-1].id_t), (yyvsp[0].type_t)}); }
#line 1543 "parser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 116 "parser.y" /* yacc.c:1661  */
    { (yyval.params_t) = new vector<FunctionDeclaration::Param>{ FunctionDeclaration::Param(*(yyvsp[-1].id_t), (yyvsp[0].type_t)) }; }
#line 1549 "parser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 117 "parser.y" /* yacc.c:1661  */
    { (yyval.params_t) = new vector<FunctionDeclaration::Param>(); }
#line 1555 "parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 120 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new For(*(yyvsp[-6].id_t), (yyvsp[-4].expression_t), (yyvsp[-2].expression_t), (yyvsp[-1].expression_t)); }
#line 1561 "parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 123 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new If((yyvsp[-2].expression_t), (yyvsp[-1].expression_t), (yyvsp[0].expression_t)); }
#line 1567 "parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 126 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new If((yyvsp[-2].expression_t), (yyvsp[-1].expression_t), (yyvsp[0].expression_t)); }
#line 1573 "parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 127 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[-1].expression_t); }
#line 1579 "parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 128 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = nullptr; }
#line 1585 "parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 131 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new While((yyvsp[-2].expression_t), (yyvsp[-1].expression_t)); }
#line 1591 "parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 134 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Print{ *(yyvsp[-1].expression_list_t), true }; }
#line 1597 "parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 135 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Print{ *(yyvsp[-1].expression_list_t), false }; }
#line 1603 "parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 138 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1609 "parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 139 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression*>; (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1615 "parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 142 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new StringExpression{ *(yyvsp[0].id_t) }; }
#line 1621 "parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 143 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1627 "parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 146 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Declaration{ *(yyvsp[-3].id_t), (yyvsp[-2].type_t), (yyvsp[0].expression_t) }; }
#line 1633 "parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 147 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Declaration{ *(yyvsp[-1].id_t), (yyvsp[0].type_t), nullptr }; }
#line 1639 "parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 150 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::INTEGER; }
#line 1645 "parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 151 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::BOOL; }
#line 1651 "parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 152 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::INT_ARRAY; }
#line 1657 "parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 153 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::INT_ARRAY; }
#line 1663 "parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 156 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = (yyvsp[0].type_t); }
#line 1669 "parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 157 "parser.y" /* yacc.c:1661  */
    { (yyval.type_t) = ReturnType::UNIT; }
#line 1675 "parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 160 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1681 "parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 163 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1687 "parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 164 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new AddExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1693 "parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 165 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new SubExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1699 "parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 166 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new MulExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1705 "parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 167 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new DivExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1711 "parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 168 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new ModExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1717 "parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 169 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Assignment{ (yyvsp[-2].expression_t), new PowExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) } };  }
#line 1723 "parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 170 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1729 "parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 173 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new OrExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1735 "parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 174 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1741 "parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 177 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new AndExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1747 "parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 178 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1753 "parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 181 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BitwiseOrExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1759 "parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 182 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1765 "parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 185 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new XorExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1771 "parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 186 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1777 "parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 189 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BitwiseAndExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1783 "parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 190 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1789 "parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 193 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new LeftShiftExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1795 "parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 194 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1801 "parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 197 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new RightShiftExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1807 "parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 198 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1813 "parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 201 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new EqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };              }
#line 1819 "parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 202 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new NotEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };           }
#line 1825 "parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 203 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new GreaterThanExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };        }
#line 1831 "parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 204 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new LessThanExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };           }
#line 1837 "parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 205 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new GreaterThanOrEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) }; }
#line 1843 "parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 206 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new LessThanOrEqualExpression{ (yyvsp[-2].expression_t), (yyvsp[0].expression_t) };    }
#line 1849 "parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 207 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1855 "parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 210 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new SubExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1861 "parser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 211 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new AddExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1867 "parser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 212 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1873 "parser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 215 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new MulExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1879 "parser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 216 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new DivExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1885 "parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 217 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new ModExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t));  }
#line 1891 "parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 218 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1897 "parser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 221 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new PowExpression((yyvsp[-2].expression_t), (yyvsp[0].expression_t)); }
#line 1903 "parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 222 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1909 "parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 225 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new UnaryMinus((yyvsp[0].expression_t)); }
#line 1915 "parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 226 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new Negation((yyvsp[0].expression_t)); }
#line 1921 "parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 227 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BitwiseNegation((yyvsp[0].expression_t)); }
#line 1927 "parser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 228 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1933 "parser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 231 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new IntExpression((yyvsp[0].num_t)); }
#line 1939 "parser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 232 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new BoolExpression((yyvsp[0].bool_t)); }
#line 1945 "parser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 233 "parser.y" /* yacc.c:1661  */
    { 
                                               auto values = (yyvsp[-1].expression_list_t);
                                               values->insert(values->begin(), new IntExpression(0));
                                               (yyval.expression_t) = new Array(*values); 
                                             }
#line 1955 "parser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 238 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new IdExpression(*(yyvsp[0].id_t)); }
#line 1961 "parser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 239 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new ArrayAccess(*(yyvsp[-3].id_t), (yyvsp[-1].expression_t)); }
#line 1967 "parser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 240 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[-1].expression_t); }
#line 1973 "parser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 243 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = (yyvsp[0].expression_t); }
#line 1979 "parser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 244 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionCall{ *(yyvsp[-3].id_t), *(yyvsp[-1].expression_list_t) }; }
#line 1985 "parser.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 245 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_t) = new FunctionCall{ *(yyvsp[-2].id_t), vector<Expression *>() }; }
#line 1991 "parser.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 248 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = (yyvsp[-2].expression_list_t); (yyval.expression_list_t)->push_back((yyvsp[0].expression_t)); }
#line 1997 "parser.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 249 "parser.y" /* yacc.c:1661  */
    { (yyval.expression_list_t) = new vector<Expression *>{ (yyvsp[0].expression_t) }; }
#line 2003 "parser.cpp" /* yacc.c:1661  */
    break;


#line 2007 "parser.cpp" /* yacc.c:1661  */
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
#line 252 "parser.y" /* yacc.c:1906  */

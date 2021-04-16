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
#line 1 "yacc.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	int yyerror(char const *); 
	extern FILE* yyin;
	#include "codegen.c"
	int yylex(void);
	struct Typetable *curr_type,*Ftype,*Ptype,*Ttype;

#line 78 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    START = 259,
    END = 260,
    ASSIGN = 261,
    ID = 262,
    READ = 263,
    WRITE = 264,
    IF = 265,
    THEN = 266,
    ELSE = 267,
    ENDIF = 268,
    WHILE = 269,
    DO = 270,
    ENDWHILE = 271,
    BREAK = 272,
    CONTINUE = 273,
    REPEAT = 274,
    UNTIL = 275,
    DECL = 276,
    ENDDECL = 277,
    INT = 278,
    STR = 279,
    STRING = 280,
    MAIN = 281,
    RETURN = 282,
    TYPE = 283,
    ENDTYPE = 284,
    INITIALIZE = 285,
    ALLOC = 286,
    FREE = 287,
    NIL = 288,
    LT = 289,
    GT = 290,
    LE = 291,
    GE = 292,
    NE = 293,
    EQ = 294,
    OR = 295,
    AND = 296,
    PLUS = 297,
    MINUS = 298,
    MUL = 299,
    DIV = 300,
    NOT = 301
  };
#endif
/* Tokens.  */
#define NUM 258
#define START 259
#define END 260
#define ASSIGN 261
#define ID 262
#define READ 263
#define WRITE 264
#define IF 265
#define THEN 266
#define ELSE 267
#define ENDIF 268
#define WHILE 269
#define DO 270
#define ENDWHILE 271
#define BREAK 272
#define CONTINUE 273
#define REPEAT 274
#define UNTIL 275
#define DECL 276
#define ENDDECL 277
#define INT 278
#define STR 279
#define STRING 280
#define MAIN 281
#define RETURN 282
#define TYPE 283
#define ENDTYPE 284
#define INITIALIZE 285
#define ALLOC 286
#define FREE 287
#define NIL 288
#define LT 289
#define GT 290
#define LE 291
#define GE 292
#define NE 293
#define EQ 294
#define OR 295
#define AND 296
#define PLUS 297
#define MINUS 298
#define MUL 299
#define DIV 300
#define NOT 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "yacc.y" /* yacc.c:355  */

    struct tnode* Node;

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      53,    54,     2,     2,    50,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    29,    30,    32,    34,    35,    37,    37,
      46,    47,    49,    51,    52,    53,    55,    63,    66,    67,
      69,    71,    72,    73,    81,    82,    85,    86,    87,    88,
      89,    92,    93,    95,    96,    97,   105,   113,   121,   122,
     124,   133,   136,   137,   138,   146,   147,   150,   151,   154,
     157,   158,   159,   160,   163,   164,   167,   168,   171,   172,
     173,   174,   175,   176,   177,   180,   189,   206,   207,   208,
     211,   214,   215,   216,   217,   218,   219,   220,   221,   224,
     225,   227,   228,   229,   232,   235,   238,   241,   242,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "START", "END", "ASSIGN", "ID",
  "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "DECL", "ENDDECL",
  "INT", "STR", "STRING", "MAIN", "RETURN", "TYPE", "ENDTYPE",
  "INITIALIZE", "ALLOC", "FREE", "NIL", "LT", "GT", "LE", "GE", "NE", "EQ",
  "OR", "AND", "PLUS", "MINUS", "MUL", "DIV", "NOT", "'{'", "'}'", "';'",
  "','", "'['", "']'", "'('", "')'", "'.'", "$accept", "program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@1", "FieldDeclList",
  "FieldDecl", "TypeName", "GdeclBlock", "GDecllist", "GDec1", "Type",
  "GidList", "Gid", "FDefBlock", "Ftype", "Fdef", "MainBlock", "ParamList",
  "Param", "Ptype", "LdeclBlock", "LDecList", "LDecl", "IdList", "Body",
  "Slist", "Stmt", "Field", "InputStmt", "OutputStmt", "AsgStmt", "Ifstmt",
  "Whilestmt", "Continuestmt", "Breakstmt", "Returnstmt", "ArgList", "E", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   123,   125,    59,
      44,    91,    93,    40,    41,    46
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    54,    14,    73,  -115,    18,  -115,  -115,   124,    15,
     151,  -115,    39,  -115,  -115,  -115,  -115,  -115,  -115,   145,
    -115,    -4,    26,  -115,    15,  -115,   151,    86,  -115,  -115,
     349,  -115,  -115,    50,    99,   -14,  -115,    59,  -115,  -115,
      84,  -115,  -115,  -115,    66,  -115,   133,   146,    68,  -115,
    -115,    -4,   104,    68,  -115,  -115,   114,   149,  -115,  -115,
    -115,   354,   -33,  -115,   169,  -115,   164,    34,  -115,   155,
     231,    68,  -115,  -115,   193,   229,   192,   237,  -115,  -115,
    -115,     2,   200,  -115,    90,   205,   164,   202,  -115,   259,
       1,  -115,  -115,  -115,    27,   219,   232,   245,   258,   211,
    -115,  -115,   211,   271,   163,  -115,     7,   230,   243,   256,
     269,   282,   295,   313,  -115,   229,  -115,  -115,  -115,    16,
      23,    -1,   356,   357,    -1,    -1,    -1,   227,   179,   358,
      -1,  -115,   363,    24,   359,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,   321,  -115,   364,  -115,    32,  -115,   317,   322,
    -115,    -1,   319,   361,   291,  -115,    88,    78,   213,   226,
     239,   323,   332,   129,   137,   345,  -115,   333,   361,  -115,
    -115,  -115,    -1,    -1,   337,   338,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,    -1,  -115,
    -115,  -115,   390,   398,    -1,    -1,  -115,  -115,  -115,   348,
     303,    61,   361,  -115,  -115,  -115,   373,   373,   373,   373,
     373,   373,   187,   187,  -115,  -115,    -1,   315,   211,   211,
     265,   278,  -115,  -115,    -1,  -115,   361,   360,   147,   109,
     398,  -115,   361,  -115,   211,  -115,  -115,   195,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     8,     0,     7,     1,     0,     0,
       0,     4,     0,     5,     6,    23,    17,    21,    22,     0,
      19,     0,     0,    35,    33,    34,     0,     0,    32,     3,
       0,    16,    18,    26,     0,     0,    25,     0,    31,     2,
       0,    15,    13,    14,     0,    11,     0,     0,     0,    29,
      20,     0,     0,     0,     9,    10,     0,     0,    44,    42,
      43,     0,     0,    39,     0,    24,     0,     0,    12,    27,
       0,     0,    30,    40,     0,     0,     0,     0,    41,    38,
      46,     0,     0,    48,     0,     0,     0,     0,    52,     0,
       0,    45,    47,    55,     0,     0,     0,     0,     0,     0,
      85,    84,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    28,    53,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,    58,    59,    60,    61,    62,
      64,    63,     0,    50,     0,   100,   102,   101,     0,     0,
     105,     0,   106,    71,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,    75,    66,
      36,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      69,    70,     0,     0,     0,     0,    77,    78,    86,     0,
       0,     0,    88,    73,    74,    93,    98,    99,    96,    97,
      95,    94,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,    76,   103,     0,   104,    72,     0,     0,     0,
      83,    82,    87,    68,     0,    80,    81,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,   414,  -115,  -115,   376,  -115,  -115,
    -115,   402,   -40,  -115,   371,  -115,  -115,   397,    12,   372,
     353,   365,   341,  -115,   346,  -115,   314,   -98,   -99,   -84,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    12,    44,    45,    46,    10,
      19,    20,    21,    35,    36,    26,    27,    28,    11,    62,
      63,    64,    75,    82,    83,    90,    85,   104,   105,   152,
     107,   108,   109,   110,   111,   112,   113,   132,   201,   153
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   127,   145,    33,   128,   131,   146,   154,     1,    88,
     158,   159,   160,   133,     7,   106,   165,    71,   106,   168,
     106,    72,    29,   143,   147,     4,   145,   145,   131,   131,
     146,   146,   150,   120,    81,    50,    51,   176,    39,   157,
      34,    22,    81,   106,   106,   164,    89,    13,   147,   147,
     118,   119,   151,   148,   149,   167,   150,   150,   200,   202,
     144,     4,   134,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    41,   217,    58,   151,   151,   121,    37,
     220,   221,   122,   172,    71,   173,    30,   122,    76,    42,
      43,    59,    60,    40,     8,    93,     9,    94,    95,    96,
      97,    47,   226,    48,    98,    99,    49,   100,   101,   102,
     232,   224,    61,    52,    54,   225,    94,    95,    96,    97,
     228,   229,   103,    98,    99,   236,   100,   101,   102,   131,
     131,    15,   190,   134,   106,   106,   237,    53,   131,   188,
      56,   103,   189,   122,   106,   106,    16,    17,    18,    57,
     106,    66,    15,   106,    94,    95,    96,    97,    23,   234,
     235,    98,    99,    68,   100,   101,   102,    31,    17,    18,
      94,    95,    96,    97,    24,    25,    73,    98,    99,   103,
     100,   101,   102,   196,   122,    74,    94,    95,    96,    97,
     130,   197,   134,    98,    99,   103,   100,   101,   102,   162,
      15,    69,    94,    95,    96,    97,    77,    15,   238,    98,
      99,   103,   100,   101,   102,    80,    17,    18,    94,    95,
      96,    97,    91,    17,    18,    98,    99,   103,   100,   101,
     102,   185,   186,    84,    94,    95,    96,    97,    78,    86,
      87,   161,    99,   103,   100,   101,   102,   177,   178,   179,
     180,   181,   182,   114,   116,   183,   184,   185,   186,   103,
     177,   178,   179,   180,   181,   182,   117,   191,   183,   184,
     185,   186,   123,   177,   178,   179,   180,   181,   182,   135,
     192,   183,   184,   185,   186,   124,   177,   178,   179,   180,
     181,   182,   136,   193,   183,   184,   185,   186,   125,   177,
     178,   179,   180,   181,   182,   137,   205,   183,   184,   185,
     186,   126,   177,   178,   179,   180,   181,   182,   138,   230,
     183,   184,   185,   186,   129,   177,   178,   179,   180,   181,
     182,   139,   231,   183,   184,   185,   186,   177,   178,   179,
     180,   181,   182,   187,   140,   183,   184,   185,   186,   177,
     178,   179,   180,   181,   182,   223,    41,   183,   184,   185,
     186,    58,   141,   155,   156,   163,   169,   227,   166,   170,
     174,   171,    42,    43,   134,   175,   194,    59,    60,   177,
     178,   179,   180,   181,   182,   195,   199,   183,   184,   185,
     186,   203,   204,   216,   198,   177,   178,   179,   180,   181,
     182,   218,   222,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   233,   183,   184,   185,   186,    14,
      55,    32,    65,    38,    79,    67,    70,   115,    92,   142
};

static const yytype_uint8 yycheck[] =
{
      84,    99,     3,     7,   102,   104,     7,   121,    28,     7,
     124,   125,   126,     6,     0,    99,   130,    50,   102,   133,
     104,    54,    10,     7,    25,     7,     3,     3,   127,   128,
       7,     7,    33,     6,    74,    49,    50,   151,    26,   123,
      44,    26,    82,   127,   128,   129,    44,    29,    25,    25,
      49,    50,    53,    30,    31,    31,    33,    33,   172,   173,
      44,     7,    55,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     7,   188,     7,    53,    53,    51,    53,
     194,   195,    55,    51,    50,    53,    47,    55,    54,    23,
      24,    23,    24,     7,    21,     5,    23,     7,     8,     9,
      10,    51,   216,    53,    14,    15,     7,    17,    18,    19,
     224,    50,    44,    54,    48,    54,     7,     8,     9,    10,
     218,   219,    32,    14,    15,    16,    17,    18,    19,   228,
     229,     7,    54,    55,   218,   219,   234,    53,   237,    51,
       7,    32,    54,    55,   228,   229,    22,    23,    24,     3,
     234,    47,     7,   237,     7,     8,     9,    10,     7,    12,
      13,    14,    15,    49,    17,    18,    19,    22,    23,    24,
       7,     8,     9,    10,    23,    24,     7,    14,    15,    32,
      17,    18,    19,    54,    55,    21,     7,     8,     9,    10,
      27,    54,    55,    14,    15,    32,    17,    18,    19,    20,
       7,    52,     7,     8,     9,    10,    51,     7,    13,    14,
      15,    32,    17,    18,    19,    22,    23,    24,     7,     8,
       9,    10,    22,    23,    24,    14,    15,    32,    17,    18,
      19,    44,    45,     4,     7,     8,     9,    10,     7,    47,
       3,    14,    15,    32,    17,    18,    19,    34,    35,    36,
      37,    38,    39,    48,    52,    42,    43,    44,    45,    32,
      34,    35,    36,    37,    38,    39,     7,    54,    42,    43,
      44,    45,    53,    34,    35,    36,    37,    38,    39,    49,
      54,    42,    43,    44,    45,    53,    34,    35,    36,    37,
      38,    39,    49,    54,    42,    43,    44,    45,    53,    34,
      35,    36,    37,    38,    39,    49,    54,    42,    43,    44,
      45,    53,    34,    35,    36,    37,    38,    39,    49,    54,
      42,    43,    44,    45,    53,    34,    35,    36,    37,    38,
      39,    49,    54,    42,    43,    44,    45,    34,    35,    36,
      37,    38,    39,    52,    49,    42,    43,    44,    45,    34,
      35,    36,    37,    38,    39,    52,     7,    42,    43,    44,
      45,     7,    49,     7,     7,     7,     7,    52,     5,    48,
      53,     7,    23,    24,    55,    53,    53,    23,    24,    34,
      35,    36,    37,    38,    39,    53,    53,    42,    43,    44,
      45,    54,    54,     6,    49,    34,    35,    36,    37,    38,
      39,    11,    54,    42,    43,    44,    45,    34,    35,    36,
      37,    38,    39,    15,    54,    42,    43,    44,    45,     5,
      44,    19,    51,    26,    71,    53,    61,    86,    82,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    57,    58,     7,    59,    60,     0,    21,    23,
      65,    74,    61,    29,    60,     7,    22,    23,    24,    66,
      67,    68,    26,     7,    23,    24,    71,    72,    73,    74,
      47,    22,    67,     7,    44,    69,    70,    53,    73,    74,
       7,     7,    23,    24,    62,    63,    64,    51,    53,     7,
      49,    50,    54,    53,    48,    63,     7,     3,     7,    23,
      24,    44,    75,    76,    77,    70,    47,    75,    49,    52,
      77,    50,    54,     7,    21,    78,    54,    51,     7,    76,
      22,    68,    79,    80,     4,    82,    47,     3,     7,    44,
      81,    22,    80,     5,     7,     8,     9,    10,    14,    15,
      17,    18,    19,    32,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    48,    78,    52,     7,    49,    50,
       6,    51,    55,    53,    53,    53,    53,    83,    83,    53,
      27,    84,    93,     6,    55,    49,    49,    49,    49,    49,
      49,    49,    82,     7,    44,     3,     7,    25,    30,    31,
      33,    53,    85,    95,    95,     7,     7,    85,    95,    95,
      95,    14,    20,     7,    85,    95,     5,    31,    95,     7,
      48,     7,    51,    53,    53,    53,    95,    34,    35,    36,
      37,    38,    39,    42,    43,    44,    45,    52,    51,    54,
      54,    54,    54,    54,    53,    53,    54,    54,    49,    53,
      95,    94,    95,    54,    54,    54,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,     6,    95,    11,    15,
      95,    95,    54,    52,    50,    54,    95,    52,    83,    83,
      54,    54,    95,    54,    12,    13,    16,    83,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    59,    59,    61,    60,
      62,    62,    63,    64,    64,    64,    65,    65,    66,    66,
      67,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    73,    74,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    86,    86,    86,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    91,    92,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     0,     5,
       2,     1,     3,     1,     1,     1,     3,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     4,     7,     2,
       4,     2,     1,     1,     1,     1,     9,     8,     3,     1,
       2,     3,     1,     1,     1,     3,     2,     2,     1,     3,
       3,     4,     1,     2,     4,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     4,     7,     4,
       4,     3,     6,     5,     5,     3,     5,     4,     4,     9,
       7,     7,     6,     6,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     4,     4,     1,     1
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
#line 28 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 29 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 30 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 32 "yacc.y" /* yacc.c:1646  */
    {/*printTypetable();*/}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 37 "yacc.y" /* yacc.c:1646  */
    {TInstall((yyvsp[0].Node)->varname,0,NULL);}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 38 "yacc.y" /* yacc.c:1646  */
    {
	Ttype= TLookup((yyvsp[-4].Node)->varname);
	Ttype->fields=Fhead;
	Ttype->size= Typesizeallocator(Ttype);
	Fhead=NULL;
	F_INDEX=0;
	}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 49 "yacc.y" /* yacc.c:1646  */
    {FInstall(Ttype,(yyvsp[-1].Node)->varname);}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 51 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup("Integer");}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 52 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup("String");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 53 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup((yyvsp[0].Node)->varname);}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "yacc.y" /* yacc.c:1646  */
    {
									
									initialxsmcode();
									Phead=NULL;
									Lhead=NULL;
									LOCAL_BIND=1;
									PARAM_BIND=1;
                            		}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "yacc.y" /* yacc.c:1646  */
    {initialxsmcode();}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "yacc.y" /* yacc.c:1646  */
    {curr_type = TLookup("Integer");}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 72 "yacc.y" /* yacc.c:1646  */
    {curr_type = TLookup("String");}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 73 "yacc.y" /* yacc.c:1646  */
    {
		curr_type = TLookup((yyvsp[0].Node)->varname); 
		if(curr_type==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 85 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].Node)->varname, curr_type, 1, 1, _ID, NULL);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 86 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].Node)->varname, curr_type, (yyvsp[-1].Node)->val, 1, _ARRAY, NULL);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 87 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-6].Node)->varname, curr_type, (yyvsp[-4].Node)->val, (yyvsp[-1].Node)->val, _MATRIX, NULL);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 89 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].Node)->varname, curr_type, 0, 0, _FUNC, Phead);Phead=NULL;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "yacc.y" /* yacc.c:1646  */
    {Ftype = TLookup("Integer");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "yacc.y" /* yacc.c:1646  */
    {Ftype = TLookup("String");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 97 "yacc.y" /* yacc.c:1646  */
    {
		Ftype = TLookup((yyvsp[0].Node)->varname); 
		if(Ftype==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "yacc.y" /* yacc.c:1646  */
    {funcdef(curr_type,(yyvsp[-7].Node), Phead,(yyvsp[-1].Node));
														//print_local_declarations(Lhead);
														Phead= NULL;
														Lhead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 113 "yacc.y" /* yacc.c:1646  */
    {mainfuncdef((yyvsp[-1].Node));
														//print_local_declarations(Lhead);
														Lhead=NULL;
														Phead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
														}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
		struct Paramstruct *temp;
		temp= PLookup((yyvsp[0].Node)->varname);
		if(temp!=NULL){
			printf("Multiple declarations for %s in paramlist",(yyvsp[0].Node)->varname);
			exit(0);
		}
		PInstall((yyvsp[0].Node)->varname, Ptype, _ID);
	}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 133 "yacc.y" /* yacc.c:1646  */
    {PInstall((yyvsp[0].Node)->varname, Ptype,_PTR);}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 136 "yacc.y" /* yacc.c:1646  */
    {Ptype = TLookup("Integer");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 137 "yacc.y" /* yacc.c:1646  */
    {Ptype = TLookup("String");}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 138 "yacc.y" /* yacc.c:1646  */
    {
		Ptype = TLookup((yyvsp[0].Node)->varname); 
		if(Ptype==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 157 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _ID);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _PTR);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _ID);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _PTR);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 163 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, (yyvsp[-2].Node),NULL,(yyvsp[-1].Node));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= NULL;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 167 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, (yyvsp[-1].Node),NULL,(yyvsp[0].Node));}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= (yyvsp[0].Node);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 171 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 173 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 174 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 175 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 176 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 177 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 180 "yacc.y" /* yacc.c:1646  */
    {
	struct Fieldlist *Ftemp= FLookup((yyvsp[-2].Node)->type, (yyvsp[0].Node)->varname);
	if(Ftemp == NULL){
		printf("No field name %s in %s \n",(yyvsp[0].Node)->varname,(yyvsp[-2].Node)->varname);
		exit(0);
	}
	(yyval.Node)= createTree(VAL_NONE,  Ftemp->type, "\0", _FIELD, (yyvsp[-2].Node),NULL, createTree(VAL_NONE,TLookup("void"),"\0",_FIELD,(yyvsp[0].Node),NULL,NULL));
	}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 189 "yacc.y" /* yacc.c:1646  */
    {
		struct tnode *t1, *t2;
		t2= (yyvsp[-2].Node);
		while(t2->right!=NULL)
			t2= t2->right;
		struct Fieldlist *Ftemp= FLookup((yyvsp[-2].Node)->type,(yyvsp[0].Node)->varname);
		if(Ftemp==NULL){
			printf("No Field named %s in %s \n",(yyvsp[0].Node)->varname,t2->left->varname);	
			exit(0);
		}
		t1= createTree(VAL_NONE, TLookup("void"), "\0", _FIELD, (yyvsp[0].Node),NULL,NULL);
		t2->right= t1;
		(yyval.Node)= (yyvsp[-2].Node);
		(yyval.Node)->type= (yyvsp[0].Node)->type;
	}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 206 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _READ, (yyvsp[-1].Node),NULL,NULL);}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 207 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("void"), "\0", _READ_ARRAY, (yyvsp[-4].Node), (yyvsp[-2].Node), NULL);}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 208 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE,TLookup("void"),"\0",_READ_FIELD,(yyvsp[-1].Node),NULL,NULL);}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _WRITE, (yyvsp[-1].Node),NULL,NULL);}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _ASSIGN, (yyvsp[-2].Node),NULL,(yyvsp[0].Node));}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 215 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0, TLookup("void"), "\0", _ASGN_ARRAY,(yyvsp[-5].Node), (yyvsp[-3].Node), (yyvsp[0].Node));}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 216 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Integer"),"\0",_INIT,NULL,NULL,NULL));}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 217 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 218 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN_FIELD,(yyvsp[-2].Node),NULL,(yyvsp[0].Node));}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN_FIELD,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 220 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_FREE,(yyvsp[-1].Node),NULL,NULL);}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 221 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_FREE,(yyvsp[-1].Node),NULL,NULL);}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 224 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN_ELSE, (yyvsp[-6].Node),(yyvsp[-3].Node),(yyvsp[-1].Node));}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 225 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN, (yyvsp[-4].Node), (yyvsp[-1].Node), NULL);}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 227 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _WHILE, (yyvsp[-4].Node), (yyvsp[-1].Node) ,NULL);}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 228 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _REAPEAT_UNTIL, (yyvsp[-1].Node), (yyvsp[-4].Node), NULL);}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 229 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _DO_WHILE, (yyvsp[-1].Node), (yyvsp[-4].Node), NULL);}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 232 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONTINUE, NULL, NULL, NULL);}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 235 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _BREAK, NULL, NULL, NULL);}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 238 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _RET, (yyvsp[-1].Node), NULL, NULL);}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 241 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE,TLookup("void"), "\0", _ARG,  (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 242 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _ARG, NULL, NULL, (yyvsp[0].Node));}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 245 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _PLUS, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 246 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _MINUS, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 247 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _MUL, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 248 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _DIV, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 249 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[-1].Node);}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 250 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _EQ, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 251 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _NE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 252 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 253 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 254 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LT, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 255 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GT, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 256 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 257 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 258 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 259 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, (yyvsp[-3].Node)->type, (yyvsp[-3].Node)->varname, _ARRAY, (yyvsp[-3].Node), (yyvsp[-1].Node), NULL);}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 260 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, (yyvsp[-3].Node)->type, (yyvsp[-3].Node)->varname, _FUNC, (yyvsp[-3].Node), NULL, (yyvsp[-1].Node));}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 261 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE,TLookup("Type"), "\0", _NULL, NULL, NULL, NULL);}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 262 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2092 "y.tab.c" /* yacc.c:1646  */
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
#line 265 "yacc.y" /* yacc.c:1906  */

int yyerror(char const *s){
	printf("yyerror %s",s);
}

int main(int argc, char *argv[]) 
{	
	
	FILE *fp = fopen(argv[1],"r");
	if(fp)
		yyin=fp;
	target_file=fopen("target.xsm","w");	
	
	TypeTableCreate();
	
	yyparse();
	return 0;
}

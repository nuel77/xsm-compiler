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
	struct Classtable *Ctype;

#line 79 "y.tab.c" /* yacc.c:339  */

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
    CLASS = 289,
    ENDCLASS = 290,
    EXTENDS = 291,
    SELF = 292,
    NEW = 293,
    DELETE = 294,
    LT = 295,
    GT = 296,
    LE = 297,
    GE = 298,
    NE = 299,
    EQ = 300,
    OR = 301,
    AND = 302,
    PLUS = 303,
    MINUS = 304,
    MUL = 305,
    DIV = 306,
    NOT = 307
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
#define CLASS 289
#define ENDCLASS 290
#define EXTENDS 291
#define SELF 292
#define NEW 293
#define DELETE 294
#define LT 295
#define GT 296
#define LE 297
#define GE 298
#define NE 299
#define EQ 300
#define OR 301
#define AND 302
#define PLUS 303
#define MINUS 304
#define MUL 305
#define DIV 306
#define NOT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "yacc.y" /* yacc.c:355  */

    struct tnode* Node;

#line 227 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   491

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      59,    60,     2,     2,    56,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    31,    32,    33,    35,    37,    38,    40,
      40,    49,    50,    52,    54,    55,    56,    58,    66,    69,
      70,    72,    74,    75,    76,    84,    85,    88,    89,    90,
      91,    92,    94,    98,    99,   101,   134,   138,   142,   143,
     145,   155,   156,   158,   172,   173,   175,   176,   178,   179,
     180,   188,   196,   204,   205,   206,   208,   217,   220,   221,
     222,   230,   231,   232,   235,   236,   239,   242,   243,   244,
     245,   248,   249,   252,   253,   256,   257,   258,   259,   260,
     261,   262,   265,   274,   289,   302,   325,   338,   348,   349,
     350,   353,   356,   357,   358,   359,   360,   361,   362,   363,
     366,   367,   369,   370,   371,   374,   377,   380,   383,   384,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405
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
  "INITIALIZE", "ALLOC", "FREE", "NIL", "CLASS", "ENDCLASS", "EXTENDS",
  "SELF", "NEW", "DELETE", "LT", "GT", "LE", "GE", "NE", "EQ", "OR", "AND",
  "PLUS", "MINUS", "MUL", "DIV", "NOT", "'{'", "'}'", "';'", "','", "'['",
  "']'", "'('", "')'", "'.'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "$@1", "FieldDeclList", "FieldDecl",
  "TypeName", "GdeclBlock", "GDecllist", "GDec1", "Type", "GidList", "Gid",
  "ClassDefBlock", "ClassDefList", "ClassDef", "Cname", "Fieldlists",
  "FID", "MethodDecls", "MDecl", "MethodDefns", "FDefBlock", "Ftype",
  "Fdef", "MainBlock", "ParamList", "Param", "Ptype", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "Body", "Slist", "Stmt", "Field",
  "FieldFunction", "InputStmt", "OutputStmt", "AsgStmt", "Ifstmt",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   123,   125,    59,    44,    91,    93,    40,
      41,    46
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,    16,   110,    64,  -136,    11,  -136,  -136,   119,    -8,
      81,  -136,  -136,   118,    12,  -136,   103,    95,   133,     7,
    -136,    98,   164,  -136,  -136,   163,  -136,  -136,  -136,  -136,
     146,  -136,    46,   115,  -136,   133,  -136,     7,   183,  -136,
    -136,  -136,  -136,  -136,    52,  -136,   199,  -136,   105,  -136,
    -136,    54,   207,     8,  -136,   177,  -136,  -136,   187,  -136,
    -136,   193,   255,   105,  -136,   261,    18,  -136,  -136,    46,
     218,    18,  -136,   225,   274,  -136,   188,  -136,   244,  -136,
    -136,  -136,   138,   153,  -136,   301,  -136,   268,   222,  -136,
      49,   165,   314,  -136,   271,   327,    18,  -136,  -136,   208,
     311,   288,    18,  -136,    60,  -136,   350,   344,  -136,  -136,
    -136,    70,   231,  -136,   123,   300,   268,   381,  -136,  -136,
     302,  -136,   360,    68,  -136,  -136,     1,   351,   352,   361,
     372,   242,  -136,  -136,   242,     2,   387,   319,   123,  -136,
       4,   337,   349,   364,   377,   392,   393,   395,   446,  -136,
     311,   397,  -136,  -136,  -136,    75,    41,     2,   447,    15,
       2,     2,     2,   258,   184,  -136,    42,  -136,  -136,   394,
       2,   396,  -136,   357,    90,   449,  -136,   448,    48,   451,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   405,  -136,
    -136,   453,   402,   403,   373,   321,  -136,   106,   136,   243,
     256,   269,   404,   406,     2,     2,   457,   459,   282,   460,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    -136,   147,   162,  -136,  -136,   409,   373,  -136,  -136,  -136,
     410,   411,   463,     2,  -136,  -136,  -136,   461,   458,     2,
       2,   333,   382,   373,   415,   416,  -136,   417,   385,   385,
     385,   385,   385,   385,   219,   219,  -136,  -136,  -136,  -136,
     418,  -136,  -136,     2,   345,   242,   242,   295,   308,  -136,
       2,  -136,     2,     2,     2,  -136,   373,   419,   168,   210,
     458,  -136,   373,   383,   384,   389,  -136,   242,  -136,  -136,
    -136,  -136,  -136,   226,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     9,     0,     8,     1,     0,     5,
       0,     6,     7,    36,     0,    34,     0,     0,     0,     0,
       4,     0,     0,    32,    33,     0,    24,    18,    22,    23,
       0,    20,     0,     0,    50,    48,    49,     0,     0,    47,
       3,    16,    14,    15,     0,    12,     0,    37,     0,    17,
      19,    27,     0,     0,    26,     0,    46,     2,     0,    10,
      11,     0,     0,     0,    39,     0,    55,    30,    21,     0,
       0,    55,    13,     0,     0,    38,     0,    42,     0,    60,
      58,    59,     0,     0,    54,     0,    25,    63,     0,    40,
       0,     0,     0,    41,    28,     0,     0,    31,    56,     0,
       0,     0,    55,    48,     0,    45,     0,     0,    57,    53,
      62,     0,     0,    65,     0,     0,    63,     0,    35,    44,
       0,    69,     0,     0,    61,    64,     0,     0,     0,     0,
       0,     0,   106,   105,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,    29,    70,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   123,   122,   126,     0,
       0,   127,   128,     0,     0,     0,    73,     0,     0,     0,
      75,    76,    77,    78,    79,    81,    80,    72,     0,    43,
      67,     0,     0,     0,    92,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,    84,    71,     0,    96,    83,    51,    68,
       0,     0,     0,     0,    88,    90,    91,     0,     0,     0,
       0,     0,     0,   109,    82,    84,   114,    83,   119,   120,
     117,   118,   116,   115,   110,   111,   112,   113,    98,    99,
       0,    94,    95,     0,     0,     0,     0,     0,     0,   124,
       0,   125,     0,     0,     0,    97,    93,     0,     0,     0,
     104,   103,   108,     0,     0,     0,    89,     0,   101,   102,
      85,    86,    87,     0,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   472,  -136,  -136,   436,  -136,  -136,
    -136,   452,   -42,  -136,   412,  -136,  -136,   469,  -136,  -136,
     421,  -136,   413,  -136,  -136,  -136,   -35,   -11,   -59,   390,
     408,   369,  -136,   375,  -136,   338,  -130,  -135,  -114,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,   353,  -125,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    10,    44,    45,    46,    19,
      30,    31,    32,    53,    54,     9,    14,    15,    16,    63,
      64,    76,    77,   104,    37,    38,    39,    20,    83,    84,
      85,   100,   112,   113,   123,   115,   138,   139,   171,   172,
     141,   142,   143,   144,   145,   146,   147,   148,   242,   243
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   163,    56,   176,   164,   165,    62,   156,    40,   166,
     178,   173,    88,    17,    34,    18,     1,   140,     4,    13,
     140,    74,   197,     4,   140,    79,    57,   167,   176,   176,
      35,    36,   194,   195,    92,   168,   199,   200,   201,   169,
      11,    80,    81,   117,   165,   198,   208,    23,   166,   140,
     140,   165,   137,    51,   226,   166,   105,   111,   157,    41,
     222,   170,   158,    68,    69,   179,   167,    34,    82,   119,
     111,   192,   193,   167,   168,    42,    43,   121,   169,   225,
     241,   168,   190,   103,    36,   169,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    52,   221,     8,   204,
     170,   205,    26,   206,    89,    41,    59,   170,   102,   264,
       7,    65,    26,    66,   118,   267,   268,    27,    28,    29,
     122,    42,    43,   154,   155,   191,    13,   137,    28,    29,
     126,   127,   128,   129,    21,   278,   279,   130,   131,   276,
     132,   133,   134,   176,   176,    79,   282,   283,   284,   285,
     135,   140,   140,    26,    22,   136,    25,   293,   176,    33,
     137,    80,    81,   233,   140,   140,   234,   158,    49,    28,
      29,    47,    34,   140,    55,   126,   127,   128,   129,   140,
     287,   288,   130,   131,    48,   132,   133,   134,   103,    36,
      58,   126,   127,   128,   129,    26,   235,   179,   130,   131,
     136,   132,   133,   134,   203,   137,    61,   258,   158,    96,
      91,    28,    29,    97,    67,    26,   136,   126,   127,   128,
     129,   137,   259,   179,   130,   131,   289,   132,   133,   134,
     110,    28,    29,   126,   127,   128,   129,    70,    26,   294,
     130,   131,   136,   132,   133,   134,    71,   137,    72,   126,
     127,   128,   129,   124,    28,    29,   130,   131,   136,   132,
     133,   134,    73,   137,    78,   126,   127,   128,   129,   218,
     219,    87,   202,   131,   136,   132,   133,   134,    96,   137,
      89,    90,   101,   210,   211,   212,   213,   214,   215,    99,
     136,   216,   217,   218,   219,   137,   210,   211,   212,   213,
     214,   215,    94,   236,   216,   217,   218,   219,    98,   210,
     211,   212,   213,   214,   215,   114,   237,   216,   217,   218,
     219,   106,   210,   211,   212,   213,   214,   215,   107,   238,
     216,   217,   218,   219,   108,   210,   211,   212,   213,   214,
     215,   116,   246,   216,   217,   218,   219,   120,   210,   211,
     212,   213,   214,   215,   149,   280,   216,   217,   218,   219,
     152,   210,   211,   212,   213,   214,   215,   153,   281,   216,
     217,   218,   219,   210,   211,   212,   213,   214,   215,   232,
     175,   216,   217,   218,   219,   210,   211,   212,   213,   214,
     215,   269,   180,   216,   217,   218,   219,   210,   211,   212,
     213,   214,   215,   277,   181,   216,   217,   218,   219,   102,
     159,   160,   220,   210,   211,   212,   213,   214,   215,   182,
     161,   216,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   183,   216,   217,   218,   219,    96,   270,   270,
     270,   151,   271,   290,   291,   270,   174,   184,   185,   292,
     186,   187,   189,   224,   196,   207,   223,   209,   227,   228,
     229,   230,   231,   239,   244,   240,   245,   247,   260,   263,
     261,   262,   265,   266,   272,   273,   274,    12,   275,   286,
      60,    86,    50,    24,    75,   150,   109,   125,   188,    93,
      95,   177
};

static const yytype_uint16 yycheck[] =
{
     114,   131,    37,   138,   134,     3,    48,     6,    19,     7,
       6,   135,    71,    21,     7,    23,    28,   131,     7,     7,
     134,    63,     7,     7,   138,     7,    37,    25,   163,   164,
      23,    24,   156,   157,    76,    33,   160,   161,   162,    37,
      29,    23,    24,   102,     3,   159,   170,    35,     7,   163,
     164,     3,    37,     7,   178,     7,    91,    99,    57,     7,
     174,    59,    61,    55,    56,    61,    25,     7,    50,   104,
     112,    30,    31,    25,    33,    23,    24,     7,    37,    31,
     204,    33,     7,    23,    24,    37,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    50,     7,    34,    57,
      59,    59,     7,    61,    55,     7,    54,    59,    59,   233,
       0,    57,     7,    59,    54,   239,   240,    22,    23,    24,
      50,    23,    24,    55,    56,    50,     7,    37,    23,    24,
       7,     8,     9,    10,    53,   265,   266,    14,    15,   263,
      17,    18,    19,   278,   279,     7,   270,   272,   273,   274,
      27,   265,   266,     7,    36,    32,    53,   287,   293,    26,
      37,    23,    24,    57,   278,   279,    60,    61,    22,    23,
      24,     7,     7,   287,    59,     7,     8,     9,    10,   293,
      12,    13,    14,    15,    21,    17,    18,    19,    23,    24,
       7,     7,     8,     9,    10,     7,    60,    61,    14,    15,
      32,    17,    18,    19,    20,    37,     7,    60,    61,    56,
      22,    23,    24,    60,     7,     7,    32,     7,     8,     9,
      10,    37,    60,    61,    14,    15,    16,    17,    18,    19,
      22,    23,    24,     7,     8,     9,    10,    60,     7,    13,
      14,    15,    32,    17,    18,    19,    59,    37,    55,     7,
       8,     9,    10,    22,    23,    24,    14,    15,    32,    17,
      18,    19,     7,    37,     3,     7,     8,     9,    10,    50,
      51,    53,    14,    15,    32,    17,    18,    19,    56,    37,
      55,     7,    60,    40,    41,    42,    43,    44,    45,    21,
      32,    48,    49,    50,    51,    37,    40,    41,    42,    43,
      44,    45,    58,    60,    48,    49,    50,    51,     7,    40,
      41,    42,    43,    44,    45,     4,    60,    48,    49,    50,
      51,     7,    40,    41,    42,    43,    44,    45,    57,    60,
      48,    49,    50,    51,     7,    40,    41,    42,    43,    44,
      45,    53,    60,    48,    49,    50,    51,     3,    40,    41,
      42,    43,    44,    45,    54,    60,    48,    49,    50,    51,
      58,    40,    41,    42,    43,    44,    45,     7,    60,    48,
      49,    50,    51,    40,    41,    42,    43,    44,    45,    58,
      61,    48,    49,    50,    51,    40,    41,    42,    43,    44,
      45,    58,    55,    48,    49,    50,    51,    40,    41,    42,
      43,    44,    45,    58,    55,    48,    49,    50,    51,    59,
      59,    59,    55,    40,    41,    42,    43,    44,    45,    55,
      59,    48,    49,    50,    51,    40,    41,    42,    43,    44,
      45,    59,    55,    48,    49,    50,    51,    56,    56,    56,
      56,    60,    60,    60,    60,    56,    59,    55,    55,    60,
      55,     5,    55,     5,     7,    61,     7,    61,     7,    54,
       7,    59,    59,    59,     7,    59,     7,     7,    59,     6,
      60,    60,    11,    15,    59,    59,    59,     5,    60,    60,
      44,    69,    30,    14,    63,   116,    96,   112,   150,    76,
      82,   138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    63,    64,     7,    65,    66,     0,    34,    77,
      67,    29,    66,     7,    78,    79,    80,    21,    23,    71,
      89,    53,    36,    35,    79,    53,     7,    22,    23,    24,
      72,    73,    74,    26,     7,    23,    24,    86,    87,    88,
      89,     7,    23,    24,    68,    69,    70,     7,    21,    22,
      73,     7,    50,    75,    76,    59,    88,    89,     7,    54,
      69,     7,    74,    81,    82,    57,    59,     7,    55,    56,
      60,    59,    55,     7,    74,    82,    83,    84,     3,     7,
      23,    24,    50,    90,    91,    92,    76,    53,    90,    55,
       7,    22,    74,    84,    58,    92,    56,    60,     7,    21,
      93,    60,    59,    23,    85,    88,     7,    57,     7,    91,
      22,    74,    94,    95,     4,    97,    53,    90,    54,    88,
       3,     7,    50,    96,    22,    95,     7,     8,     9,    10,
      14,    15,    17,    18,    19,    27,    32,    37,    98,    99,
     100,   102,   103,   104,   105,   106,   107,   108,   109,    54,
      93,    60,    58,     7,    55,    56,     6,    57,    61,    59,
      59,    59,    59,    98,    98,     3,     7,    25,    33,    37,
      59,   100,   101,   111,    59,    61,    99,   109,     6,    61,
      55,    55,    55,    55,    55,    55,    55,     5,    97,    55,
       7,    50,    30,    31,   111,   111,     7,     7,   100,   111,
     111,   111,    14,    20,    57,    59,    61,    61,   111,    61,
      40,    41,    42,    43,    44,    45,    48,    49,    50,    51,
      55,     7,   100,     7,     5,    31,   111,     7,    54,     7,
      59,    59,    58,    57,    60,    60,    60,    60,    60,    59,
      59,   111,   110,   111,     7,     7,    60,     7,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,    60,    60,
      59,    60,    60,     6,   111,    11,    15,   111,   111,    58,
      56,    60,    59,    59,    59,    60,   111,    58,    98,    98,
      60,    60,   111,   110,   110,   110,    60,    12,    13,    16,
      60,    60,    60,    98,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    64,    65,    65,    67,
      66,    68,    68,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    90,    90,    90,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    94,    95,    96,    96,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   102,   102,
     102,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   106,   107,   108,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     2,     3,     2,     1,     0,
       5,     2,     1,     3,     1,     1,     1,     3,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     4,     7,
       2,     4,     3,     2,     1,     8,     1,     3,     2,     1,
       3,     2,     1,     6,     2,     1,     2,     1,     1,     1,
       1,     9,     8,     3,     1,     0,     2,     3,     1,     1,
       1,     3,     2,     0,     2,     1,     3,     3,     4,     1,
       2,     4,     3,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     6,     6,     6,     4,     7,
       4,     4,     3,     6,     5,     5,     3,     5,     4,     4,
       9,     7,     7,     6,     6,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     4,     4,     1,     1,     1
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
#line 30 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 32 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 33 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 35 "yacc.y" /* yacc.c:1646  */
    {/*printTypetable();*/}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 40 "yacc.y" /* yacc.c:1646  */
    {TInstall((yyvsp[0].Node)->varname,0,NULL);}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 41 "yacc.y" /* yacc.c:1646  */
    {
	Ttype= TLookup((yyvsp[-4].Node)->varname);
	Ttype->fields=Fhead;
	Ttype->size= Typesizeallocator(Ttype);
	Fhead=NULL;
	F_INDEX=0;
	}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 52 "yacc.y" /* yacc.c:1646  */
    {FInstall(Ttype,(yyvsp[-1].Node)->varname);}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 54 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup("Integer");}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 55 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup("String");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 56 "yacc.y" /* yacc.c:1646  */
    {Ttype = TLookup((yyvsp[0].Node)->varname);}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 58 "yacc.y" /* yacc.c:1646  */
    {
									
									initialxsmcode();
									Phead=NULL;
									Lhead=NULL;
									LOCAL_BIND=1;
									PARAM_BIND=1;
                            		}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 66 "yacc.y" /* yacc.c:1646  */
    {initialxsmcode();}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "yacc.y" /* yacc.c:1646  */
    {curr_type = TLookup("Integer");}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 75 "yacc.y" /* yacc.c:1646  */
    {curr_type = TLookup("String");}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
		curr_type = TLookup((yyvsp[0].Node)->varname); 
		if(curr_type==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].Node)->varname, curr_type, 1, 1, _ID, NULL);}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].Node)->varname, curr_type, (yyvsp[-1].Node)->val, 1, _ARRAY, NULL);}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 90 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-6].Node)->varname, curr_type, (yyvsp[-4].Node)->val, (yyvsp[-1].Node)->val, _MATRIX, NULL);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 92 "yacc.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].Node)->varname, curr_type, 0, 0, _FUNC, Phead);Phead=NULL;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 94 "yacc.y" /* yacc.c:1646  */
    {
	printClasstable();
}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 101 "yacc.y" /* yacc.c:1646  */
    {
	struct Fieldlist *Ftemp= Class->Memberfield;
	struct Memberfunclist *Mtemp= Class->Vfuncptr;

	//performing some basic checks for memeory consitency
	int cnt=0;
	while(Ftemp !=NULL){
		Ftemp->fieldIndex= cnt++;
		if(Ftemp->type == NULL)
			cnt++;
		Ftemp= Ftemp->next;
	}
	if(cnt > 8){
		printf("Class member field count cannot exceed 8 %s \n", Class->name);
		exit(0);
	}
	
	cnt= 0;
	while(Mtemp != NULL){
		if(Mtemp->Funcposition = -1){
			printf("Class member Function not defined %s.%s \n",Class->name, Mtemp->name);
			exit(0);
		}
		Mtemp->Funcposition= cnt++;
		Mtemp= Mtemp->next;
	}
	if(cnt > 8){
		printf("Class member function count cannot exceed 8 %s \n", Class->name);
		exit(0);
	}
	Class= NULL;
}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "yacc.y" /* yacc.c:1646  */
    {
	CInstall((yyvsp[0].Node)->varname,NULL);
	Class= Clookup((yyvsp[0].Node)->varname);
	}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 138 "yacc.y" /* yacc.c:1646  */
    {

	}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 145 "yacc.y" /* yacc.c:1646  */
    {
	//installing memberfield to the class, can be of primitive/userdefined type or a class
	if(curr_type != NULL){
		Class_Finstall(Class,curr_type->name,(yyvsp[-1].Node)->varname);
	}
	else if(Ctype!=NULL){
		Class_Finstall(Class,Ctype->name,(yyvsp[-1].Node)->varname);
	}
}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "yacc.y" /* yacc.c:1646  */
    {
	//installing methods to the class
	if(Ctype!=NULL){
		printf("Return type of method %s cannot be  a  class \n", (yyvsp[-4].Node)->varname);
		exit(0);
	}
	Class_Minstall(Class,(yyvsp[-4].Node)->varname,curr_type,Phead);
	Phead= NULL;
	Lhead= NULL;
	LOCAL_BIND=1;
	PARAM_BIND=1;
}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 178 "yacc.y" /* yacc.c:1646  */
    {Ftype = TLookup("Integer");}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 179 "yacc.y" /* yacc.c:1646  */
    {Ftype = TLookup("String");}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 180 "yacc.y" /* yacc.c:1646  */
    {
		Ftype = TLookup((yyvsp[0].Node)->varname); 
		if(Ftype==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 188 "yacc.y" /* yacc.c:1646  */
    {funcdef(curr_type,Class,(yyvsp[-7].Node), Phead,(yyvsp[-1].Node));
														//print_local_declarations(Lhead);
														Phead= NULL;
														Lhead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 196 "yacc.y" /* yacc.c:1646  */
    {mainfuncdef((yyvsp[-1].Node));
														//print_local_declarations(Lhead);
														Lhead=NULL;
														Phead=NULL;
														LOCAL_BIND=1;
														PARAM_BIND=1;
														}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 208 "yacc.y" /* yacc.c:1646  */
    {
		struct Paramstruct *temp;
		temp= PLookup((yyvsp[0].Node)->varname);
		if(temp!=NULL){
			printf("Multiple declarations for %s in paramlist",(yyvsp[0].Node)->varname);
			exit(0);
		}
		PInstall((yyvsp[0].Node)->varname, Ptype, _ID);
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 217 "yacc.y" /* yacc.c:1646  */
    {PInstall((yyvsp[0].Node)->varname, Ptype,_PTR);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 220 "yacc.y" /* yacc.c:1646  */
    {Ptype = TLookup("Integer");}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 221 "yacc.y" /* yacc.c:1646  */
    {Ptype = TLookup("String");}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 222 "yacc.y" /* yacc.c:1646  */
    {
		Ptype = TLookup((yyvsp[0].Node)->varname); 
		if(Ptype==NULL){
			printf("Unknown type:%s",(yyvsp[0].Node)->varname); 
			exit(0);
		}
	}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 242 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _ID);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _PTR);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _ID);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "yacc.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].Node)->varname, curr_type, _PTR);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 248 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, (yyvsp[-2].Node),NULL,(yyvsp[-1].Node));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 249 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, NULL ,NULL,(yyvsp[-1].Node));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 252 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONNECTOR, (yyvsp[-1].Node),NULL,(yyvsp[0].Node));}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 253 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= (yyvsp[0].Node);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 256 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 257 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 258 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 259 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 260 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 261 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 262 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 265 "yacc.y" /* yacc.c:1646  */
    {
	struct Fieldlist *Ftemp= FLookup((yyvsp[-2].Node)->type, (yyvsp[0].Node)->varname);
	if(Ftemp == NULL){
		printf("No field name %s in %s \n",(yyvsp[0].Node)->varname,(yyvsp[-2].Node)->varname);
		exit(0);
	}
	(yyval.Node)= createTree(VAL_NONE,  Ftemp->type, "\0", _FIELD, (yyvsp[-2].Node),NULL, createTree(VAL_NONE,TLookup("void"),"\0",_FIELD,(yyvsp[0].Node),NULL,NULL));
	}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 274 "yacc.y" /* yacc.c:1646  */
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
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 289 "yacc.y" /* yacc.c:1646  */
    {
		if(Class == NULL){
			printf("no class for self found\n");
			exit(0);
		}
		struct Fieldlist *Ftemp= Class_Flookup(Class,(yyvsp[0].Node)->varname);
		if(Ftemp ==NULL){
			printf("no member field named %s in class %s\n",(yyvsp[0].Node)->varname,Class->name);
			exit(0);
		}
		(yyval.Node)= createTree(VAL_NONE,Ftemp->type,Class->name,_FIELD,(yyvsp[0].Node),NULL,NULL);
	}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 302 "yacc.y" /* yacc.c:1646  */
    {
	struct Gsymbol *Gtemp;
	Gtemp= GLookup((yyvsp[-5].Node)->varname);
	if(Gtemp==NULL){
		printf("unkown identifier %s\n",(yyvsp[-5].Node)->varname);
		exit(0);
	}
	if(Class!=NULL){
		printf("self should be used inside class definition\n");
		exit(0);
	}
	if((yyvsp[-5].Node)->Gentry->Ctype ==NULL){
		printf("method %s can be called only by an object\n",(yyvsp[-3].Node)->varname);
		exit(0);
	}
	struct Memberfunclist *Mtemp= Class_Mlookup(Gtemp->Ctype,(yyvsp[-3].Node)->varname);
	if(Mtemp ==NULL){
		printf("no method called %s in class %s",(yyvsp[-3].Node)->varname,Class->name);
		exit(0);
	}
	(yyval.Node)= createTree(VAL_NONE,Mtemp->type,"\0",_METHOD3,(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node));
	}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 325 "yacc.y" /* yacc.c:1646  */
    {
		if(Class ==NULL){
			printf("self cannot be used outside class definition\n");
			exit(0);
		}
		struct Memberfunclist *Mtemp= Class_Mlookup(Class,(yyvsp[-3].Node)->varname);
		if(Mtemp == NULL){
			printf("no method called %s in class %s",(yyvsp[-3].Node)->varname,Class->name);
			exit(0);
		}
		(yyval.Node)= createTree(VAL_NONE,Mtemp->type,"\0",_METHOD2,(yyvsp[-3].Node),NULL,(yyvsp[-1].Node));
	}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 338 "yacc.y" /* yacc.c:1646  */
    {
		struct Fieldlist *Ftemp= Class_Flookup(Class,(yyvsp[-5].Node)->left->varname);
		struct Memberfunclist *Mtemp= Class_Mlookup(Ftemp->Ctype,(yyvsp[-3].Node)->varname);
		if(Mtemp == NULL){
			printf("no method named %s in class %s *\n",(yyvsp[-3].Node)->varname,(yyvsp[-5].Node)->varname);
			exit(0);
		}
		(yyval.Node)= createTree(VAL_NONE,Mtemp->type,"\0",_METHOD3,(yyvsp[-5].Node),(yyvsp[-3].Node),(yyvsp[-1].Node));
	}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 348 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _READ, (yyvsp[-1].Node),NULL,NULL);}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 349 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("void"), "\0", _READ_ARRAY, (yyvsp[-4].Node), (yyvsp[-2].Node), NULL);}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 350 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE,TLookup("void"),"\0",_READ_FIELD,(yyvsp[-1].Node),NULL,NULL);}
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 353 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _WRITE, (yyvsp[-1].Node),NULL,NULL);}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 356 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _ASSIGN, (yyvsp[-2].Node),NULL,(yyvsp[0].Node));}
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 357 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0, TLookup("void"), "\0", _ASGN_ARRAY,(yyvsp[-5].Node), (yyvsp[-3].Node), (yyvsp[0].Node));}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 358 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Integer"),"\0",_INIT,NULL,NULL,NULL));}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 359 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 360 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN_FIELD,(yyvsp[-2].Node),NULL,(yyvsp[0].Node));}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 361 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_ASSIGN_FIELD,(yyvsp[-4].Node),NULL, createTree(VAL_NONE,TLookup("Type"),"\0",_ALLOC,NULL,NULL,NULL));}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 362 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_FREE,(yyvsp[-1].Node),NULL,NULL);}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 363 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(0,TLookup("void"),"\0",_FREE,(yyvsp[-1].Node),NULL,NULL);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 366 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN_ELSE, (yyvsp[-6].Node),(yyvsp[-3].Node),(yyvsp[-1].Node));}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 367 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _IF_THEN, (yyvsp[-4].Node), (yyvsp[-1].Node), NULL);}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 369 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _WHILE, (yyvsp[-4].Node), (yyvsp[-1].Node) ,NULL);}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 370 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _REAPEAT_UNTIL, (yyvsp[-1].Node), (yyvsp[-4].Node), NULL);}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 371 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _DO_WHILE, (yyvsp[-1].Node), (yyvsp[-4].Node), NULL);}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 374 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _CONTINUE, NULL, NULL, NULL);}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 377 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _BREAK, NULL, NULL, NULL);}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 380 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _RET, (yyvsp[-1].Node), NULL, NULL);}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 383 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE,TLookup("void"), "\0", _ARG,  (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 384 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, TLookup("void"), "\0", _ARG, NULL, NULL, (yyvsp[0].Node));}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 387 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _PLUS, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 388 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _MINUS, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 389 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _MUL, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 390 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Integer"), "\0", _DIV, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 391 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[-1].Node);}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 392 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _EQ, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 393 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _NE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 394 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 395 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GE, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 396 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _LT, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 397 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, TLookup("Boolean"), "\0", _GT, (yyvsp[-2].Node), NULL, (yyvsp[0].Node));}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 398 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 399 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 400 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 401 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE, (yyvsp[-3].Node)->type, (yyvsp[-3].Node)->varname, _ARRAY, (yyvsp[-3].Node), (yyvsp[-1].Node), NULL);}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 402 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node)= createTree(VAL_NONE, (yyvsp[-3].Node)->type, (yyvsp[-3].Node)->varname, _FUNC, (yyvsp[-3].Node), NULL, (yyvsp[-1].Node));}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 403 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = createTree(VAL_NONE,TLookup("Type"), "\0", _NULL, NULL, NULL, NULL);}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 404 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 405 "yacc.y" /* yacc.c:1646  */
    {(yyval.Node) = (yyvsp[0].Node);}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2329 "y.tab.c" /* yacc.c:1646  */
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
#line 408 "yacc.y" /* yacc.c:1906  */

int yyerror(char const *s){
	printf("yyerror %s\n",s);
}

int main(int argc, char *argv[]) 
{	
	
	FILE *fp = fopen(argv[1],"r");
	if(fp)
		yyin=fp;
	target_file=fopen("target.xsm","w");	
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "JMP L%d\n", LABEL_COUNT);
	TypeTableCreate();
	
	yyparse();
	return 0;
}

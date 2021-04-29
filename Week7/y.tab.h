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
#line 14 "yacc.y" /* yacc.c:1909  */

    struct tnode* Node;

#line 162 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_EXPRYY_EXPR_TAB_HH_INCLUDED
# define YY_EXPRYY_EXPR_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int expryydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DOUBLETYPE = 258,              /* DOUBLETYPE  */
    INTTYPE = 259,                 /* INTTYPE  */
    STRINGTYPE = 260,              /* STRINGTYPE  */
    BOOLTYPE = 261,                /* BOOLTYPE  */
    XMLTYPE = 262,                 /* XMLTYPE  */
    TRUE_ = 263,                   /* TRUE_  */
    FALSE_ = 264,                  /* FALSE_  */
    THIS_ = 265,                   /* THIS_  */
    ASK_ = 266,                    /* ASK_  */
    DEFAULT_ = 267,                /* DEFAULT_  */
    CONST_ = 268,                  /* CONST_  */
    SIZEOF_ = 269,                 /* SIZEOF_  */
    INDEX_ = 270,                  /* INDEX_  */
    XMLDOC_ = 271,                 /* XMLDOC_  */
    NAME = 272,                    /* NAME  */
    INTCONSTANT = 273,             /* INTCONSTANT  */
    REALCONSTANT = 274,            /* REALCONSTANT  */
    STRINGCONSTANT = 275,          /* STRINGCONSTANT  */
    EQ_ = 276,                     /* EQ_  */
    NE_ = 277,                     /* NE_  */
    GE_ = 278,                     /* GE_  */
    LE_ = 279,                     /* LE_  */
    AND_ = 280,                    /* AND_  */
    OR_ = 281,                     /* OR_  */
    XOR_ = 282,                    /* XOR_  */
    NOT_ = 283,                    /* NOT_  */
    BINAND_ = 284,                 /* BINAND_  */
    BINOR_ = 285,                  /* BINOR_  */
    BINXOR_ = 286,                 /* BINXOR_  */
    BINCOMPL_ = 287,               /* BINCOMPL_  */
    SHIFTLEFT_ = 288,              /* SHIFTLEFT_  */
    SHIFTRIGHT_ = 289,             /* SHIFTRIGHT_  */
    INVALID_CHAR = 290,            /* INVALID_CHAR  */
    UMIN_ = 291                    /* UMIN_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DOUBLETYPE 258
#define INTTYPE 259
#define STRINGTYPE 260
#define BOOLTYPE 261
#define XMLTYPE 262
#define TRUE_ 263
#define FALSE_ 264
#define THIS_ 265
#define ASK_ 266
#define DEFAULT_ 267
#define CONST_ 268
#define SIZEOF_ 269
#define INDEX_ 270
#define XMLDOC_ 271
#define NAME 272
#define INTCONSTANT 273
#define REALCONSTANT 274
#define STRINGCONSTANT 275
#define EQ_ 276
#define NE_ 277
#define GE_ 278
#define LE_ 279
#define AND_ 280
#define OR_ 281
#define XOR_ 282
#define NOT_ 283
#define BINAND_ 284
#define BINOR_ 285
#define BINXOR_ 286
#define BINCOMPL_ 287
#define SHIFTLEFT_ 288
#define SHIFTRIGHT_ 289
#define INVALID_CHAR 290
#define UMIN_ 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE expryylval;


int expryyparse (void);


#endif /* !YY_EXPRYY_EXPR_TAB_HH_INCLUDED  */

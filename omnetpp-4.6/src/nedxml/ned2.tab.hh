/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

#ifndef YY_NED2YY_NED2_TAB_HH_INCLUDED
# define YY_NED2YY_NED2_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ned2yydebug;
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
    IMPORT = 258,                  /* IMPORT  */
    PACKAGE = 259,                 /* PACKAGE  */
    PROPERTY = 260,                /* PROPERTY  */
    MODULE = 261,                  /* MODULE  */
    SIMPLE = 262,                  /* SIMPLE  */
    NETWORK = 263,                 /* NETWORK  */
    CHANNEL = 264,                 /* CHANNEL  */
    MODULEINTERFACE = 265,         /* MODULEINTERFACE  */
    CHANNELINTERFACE = 266,        /* CHANNELINTERFACE  */
    EXTENDS = 267,                 /* EXTENDS  */
    LIKE = 268,                    /* LIKE  */
    TYPES = 269,                   /* TYPES  */
    PARAMETERS = 270,              /* PARAMETERS  */
    GATES = 271,                   /* GATES  */
    SUBMODULES = 272,              /* SUBMODULES  */
    CONNECTIONS = 273,             /* CONNECTIONS  */
    ALLOWUNCONNECTED = 274,        /* ALLOWUNCONNECTED  */
    DOUBLETYPE = 275,              /* DOUBLETYPE  */
    INTTYPE = 276,                 /* INTTYPE  */
    STRINGTYPE = 277,              /* STRINGTYPE  */
    BOOLTYPE = 278,                /* BOOLTYPE  */
    XMLTYPE = 279,                 /* XMLTYPE  */
    VOLATILE = 280,                /* VOLATILE  */
    INPUT_ = 281,                  /* INPUT_  */
    OUTPUT_ = 282,                 /* OUTPUT_  */
    INOUT_ = 283,                  /* INOUT_  */
    IF = 284,                      /* IF  */
    FOR = 285,                     /* FOR  */
    RIGHTARROW = 286,              /* RIGHTARROW  */
    LEFTARROW = 287,               /* LEFTARROW  */
    DBLARROW = 288,                /* DBLARROW  */
    TO = 289,                      /* TO  */
    TRUE_ = 290,                   /* TRUE_  */
    FALSE_ = 291,                  /* FALSE_  */
    THIS_ = 292,                   /* THIS_  */
    DEFAULT = 293,                 /* DEFAULT  */
    ASK = 294,                     /* ASK  */
    CONST_ = 295,                  /* CONST_  */
    SIZEOF = 296,                  /* SIZEOF  */
    INDEX_ = 297,                  /* INDEX_  */
    TYPENAME = 298,                /* TYPENAME  */
    XMLDOC = 299,                  /* XMLDOC  */
    NAME = 300,                    /* NAME  */
    PROPNAME = 301,                /* PROPNAME  */
    INTCONSTANT = 302,             /* INTCONSTANT  */
    REALCONSTANT = 303,            /* REALCONSTANT  */
    STRINGCONSTANT = 304,          /* STRINGCONSTANT  */
    CHARCONSTANT = 305,            /* CHARCONSTANT  */
    PLUSPLUS = 306,                /* PLUSPLUS  */
    DOUBLEASTERISK = 307,          /* DOUBLEASTERISK  */
    EQ = 308,                      /* EQ  */
    NE = 309,                      /* NE  */
    GE = 310,                      /* GE  */
    LE = 311,                      /* LE  */
    AND = 312,                     /* AND  */
    OR = 313,                      /* OR  */
    XOR = 314,                     /* XOR  */
    NOT = 315,                     /* NOT  */
    BIN_AND = 316,                 /* BIN_AND  */
    BIN_OR = 317,                  /* BIN_OR  */
    BIN_XOR = 318,                 /* BIN_XOR  */
    BIN_COMPL = 319,               /* BIN_COMPL  */
    SHIFT_LEFT = 320,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 321,             /* SHIFT_RIGHT  */
    EXPRESSION_SELECTOR = 322,     /* EXPRESSION_SELECTOR  */
    CHAR = 323,                    /* CHAR  */
    INVALID_CHAR = 324,            /* INVALID_CHAR  */
    UMIN = 325                     /* UMIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE ned2yylval;
extern YYLTYPE ned2yylloc;
int ned2yyparse (void);

#endif /* !YY_NED2YY_NED2_TAB_HH_INCLUDED  */

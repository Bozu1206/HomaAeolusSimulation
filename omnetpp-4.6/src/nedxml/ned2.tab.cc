/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0




/* Substitute the variable and function names.  */
#define yyparse ned2yyparse
#define yylex   ned2yylex
#define yyerror ned2yyerror
#define yydebug ned2yydebug
#define yylval  ned2yylval
#define yychar  ned2yychar
#define yynerrs ned2yynerrs
#define yylloc  ned2yylloc

/* First part of user prologue.  */
#line 75 "ned2.y"


#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "nedyydefs.h"
#include "nederror.h"
#include "nedexception.h"
#include "commonutil.h"
#include "stringutil.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <string.h>         /* YYVERBOSE needs it */
#endif

/* increase GLR stack -- with the default 200 some NED files have reportedly caused a "memory exhausted" error */
#define YYINITDEPTH 500

#define yylloc ned2yylloc
#define yyin ned2yyin
#define yyout ned2yyout
#define yyrestart ned2yyrestart
#define yy_scan_string ned2yy_scan_string
#define yy_delete_buffer ned2yy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (const char *s);

#include "nedparser.h"
#include "nedfilebuffer.h"
#include "nedelements.h"
#include "nedutil.h"
#include "nedyylib.h"

USING_NAMESPACE

static struct NED2ParserState
{
    bool inTypes;
    bool inConnGroup;
    std::stack<NEDElement *> propertyscope; // top(): where to insert properties as we parse them
    std::stack<NEDElement *> blockscope;    // top(): where to insert parameters, gates, etc
    std::stack<NEDElement *> typescope;     // top(): as blockscope, but ignore submodules and connection channels

    /* tmp flags, used with param, gate and conn */
    int paramType;
    int gateType;
    bool isVolatile;
    bool isDefault;
    YYLTYPE exprPos;
    int subgate;
    std::vector<NEDElement *> propvals; // temporarily collects property values

    /* tmp flags, used with msg fields */
    bool isAbstract;
    bool isReadonly;

    /* NED-II: modules, channels */
    NedFileElement *nedfile;
    CommentElement *comment;
    PackageElement *package;
    ImportElement *import;
    PropertyDeclElement *propertydecl;
    ExtendsElement *extends;
    InterfaceNameElement *interfacename;
    NEDElement *component;  // compound/simple module, module interface, channel or channel interface
    ParametersElement *parameters;
    ParamElement *param;
    PropertyElement *property;
    PropertyKeyElement *propkey;
    TypesElement *types;
    GatesElement *gates;
    GateElement *gate;
    SubmodulesElement *submods;
    SubmoduleElement *submod;
    ConnectionsElement *conns;
    ConnectionGroupElement *conngroup;
    ConnectionElement *conn;
    LoopElement *loop;
    ConditionElement *condition;
} ps;


static void resetParserState()
{
    static NED2ParserState cleanps;
    ps = cleanps;
}

static NED2ParserState globalps;  // for error recovery

static void restoreGlobalParserState()  // for error recovery
{
    ps = globalps;
}

static void assertNonEmpty(std::stack<NEDElement *>& somescope)
{
    // for error recovery: STL stack::top() crashes if stack is empty
    if (somescope.empty())
    {
        INTERNAL_ERROR0(NULL, "error during parsing: scope stack empty");
        somescope.push(NULL);
    }
}


#line 183 "ned2.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ned2.tab.hh"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IMPORT = 3,                     /* IMPORT  */
  YYSYMBOL_PACKAGE = 4,                    /* PACKAGE  */
  YYSYMBOL_PROPERTY = 5,                   /* PROPERTY  */
  YYSYMBOL_MODULE = 6,                     /* MODULE  */
  YYSYMBOL_SIMPLE = 7,                     /* SIMPLE  */
  YYSYMBOL_NETWORK = 8,                    /* NETWORK  */
  YYSYMBOL_CHANNEL = 9,                    /* CHANNEL  */
  YYSYMBOL_MODULEINTERFACE = 10,           /* MODULEINTERFACE  */
  YYSYMBOL_CHANNELINTERFACE = 11,          /* CHANNELINTERFACE  */
  YYSYMBOL_EXTENDS = 12,                   /* EXTENDS  */
  YYSYMBOL_LIKE = 13,                      /* LIKE  */
  YYSYMBOL_TYPES = 14,                     /* TYPES  */
  YYSYMBOL_PARAMETERS = 15,                /* PARAMETERS  */
  YYSYMBOL_GATES = 16,                     /* GATES  */
  YYSYMBOL_SUBMODULES = 17,                /* SUBMODULES  */
  YYSYMBOL_CONNECTIONS = 18,               /* CONNECTIONS  */
  YYSYMBOL_ALLOWUNCONNECTED = 19,          /* ALLOWUNCONNECTED  */
  YYSYMBOL_DOUBLETYPE = 20,                /* DOUBLETYPE  */
  YYSYMBOL_INTTYPE = 21,                   /* INTTYPE  */
  YYSYMBOL_STRINGTYPE = 22,                /* STRINGTYPE  */
  YYSYMBOL_BOOLTYPE = 23,                  /* BOOLTYPE  */
  YYSYMBOL_XMLTYPE = 24,                   /* XMLTYPE  */
  YYSYMBOL_VOLATILE = 25,                  /* VOLATILE  */
  YYSYMBOL_INPUT_ = 26,                    /* INPUT_  */
  YYSYMBOL_OUTPUT_ = 27,                   /* OUTPUT_  */
  YYSYMBOL_INOUT_ = 28,                    /* INOUT_  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_RIGHTARROW = 31,                /* RIGHTARROW  */
  YYSYMBOL_LEFTARROW = 32,                 /* LEFTARROW  */
  YYSYMBOL_DBLARROW = 33,                  /* DBLARROW  */
  YYSYMBOL_TO = 34,                        /* TO  */
  YYSYMBOL_TRUE_ = 35,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 36,                    /* FALSE_  */
  YYSYMBOL_THIS_ = 37,                     /* THIS_  */
  YYSYMBOL_DEFAULT = 38,                   /* DEFAULT  */
  YYSYMBOL_ASK = 39,                       /* ASK  */
  YYSYMBOL_CONST_ = 40,                    /* CONST_  */
  YYSYMBOL_SIZEOF = 41,                    /* SIZEOF  */
  YYSYMBOL_INDEX_ = 42,                    /* INDEX_  */
  YYSYMBOL_TYPENAME = 43,                  /* TYPENAME  */
  YYSYMBOL_XMLDOC = 44,                    /* XMLDOC  */
  YYSYMBOL_NAME = 45,                      /* NAME  */
  YYSYMBOL_PROPNAME = 46,                  /* PROPNAME  */
  YYSYMBOL_INTCONSTANT = 47,               /* INTCONSTANT  */
  YYSYMBOL_REALCONSTANT = 48,              /* REALCONSTANT  */
  YYSYMBOL_STRINGCONSTANT = 49,            /* STRINGCONSTANT  */
  YYSYMBOL_CHARCONSTANT = 50,              /* CHARCONSTANT  */
  YYSYMBOL_PLUSPLUS = 51,                  /* PLUSPLUS  */
  YYSYMBOL_DOUBLEASTERISK = 52,            /* DOUBLEASTERISK  */
  YYSYMBOL_EQ = 53,                        /* EQ  */
  YYSYMBOL_NE = 54,                        /* NE  */
  YYSYMBOL_GE = 55,                        /* GE  */
  YYSYMBOL_LE = 56,                        /* LE  */
  YYSYMBOL_AND = 57,                       /* AND  */
  YYSYMBOL_OR = 58,                        /* OR  */
  YYSYMBOL_XOR = 59,                       /* XOR  */
  YYSYMBOL_NOT = 60,                       /* NOT  */
  YYSYMBOL_BIN_AND = 61,                   /* BIN_AND  */
  YYSYMBOL_BIN_OR = 62,                    /* BIN_OR  */
  YYSYMBOL_BIN_XOR = 63,                   /* BIN_XOR  */
  YYSYMBOL_BIN_COMPL = 64,                 /* BIN_COMPL  */
  YYSYMBOL_SHIFT_LEFT = 65,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 66,               /* SHIFT_RIGHT  */
  YYSYMBOL_EXPRESSION_SELECTOR = 67,       /* EXPRESSION_SELECTOR  */
  YYSYMBOL_CHAR = 68,                      /* CHAR  */
  YYSYMBOL_INVALID_CHAR = 69,              /* INVALID_CHAR  */
  YYSYMBOL_70_ = 70,                       /* '?'  */
  YYSYMBOL_71_ = 71,                       /* ':'  */
  YYSYMBOL_72_ = 72,                       /* '>'  */
  YYSYMBOL_73_ = 73,                       /* '<'  */
  YYSYMBOL_74_ = 74,                       /* '+'  */
  YYSYMBOL_75_ = 75,                       /* '-'  */
  YYSYMBOL_76_ = 76,                       /* '*'  */
  YYSYMBOL_77_ = 77,                       /* '/'  */
  YYSYMBOL_78_ = 78,                       /* '%'  */
  YYSYMBOL_79_ = 79,                       /* '^'  */
  YYSYMBOL_UMIN = 80,                      /* UMIN  */
  YYSYMBOL_81_ = 81,                       /* ';'  */
  YYSYMBOL_82_ = 82,                       /* '}'  */
  YYSYMBOL_83_ = 83,                       /* '.'  */
  YYSYMBOL_84_ = 84,                       /* '('  */
  YYSYMBOL_85_ = 85,                       /* ')'  */
  YYSYMBOL_86_ = 86,                       /* '@'  */
  YYSYMBOL_87_ = 87,                       /* '['  */
  YYSYMBOL_88_ = 88,                       /* ']'  */
  YYSYMBOL_89_ = 89,                       /* '{'  */
  YYSYMBOL_90_ = 90,                       /* ','  */
  YYSYMBOL_91_ = 91,                       /* '='  */
  YYSYMBOL_92_ = 92,                       /* '$'  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_startsymbol = 94,               /* startsymbol  */
  YYSYMBOL_nedfile = 95,                   /* nedfile  */
  YYSYMBOL_definitions = 96,               /* definitions  */
  YYSYMBOL_definition = 97,                /* definition  */
  YYSYMBOL_packagedeclaration = 98,        /* packagedeclaration  */
  YYSYMBOL_dottedname = 99,                /* dottedname  */
  YYSYMBOL_import = 100,                   /* import  */
  YYSYMBOL_importspec = 101,               /* importspec  */
  YYSYMBOL_importname = 102,               /* importname  */
  YYSYMBOL_propertydecl = 103,             /* propertydecl  */
  YYSYMBOL_propertydecl_header = 104,      /* propertydecl_header  */
  YYSYMBOL_opt_propertydecl_keys = 105,    /* opt_propertydecl_keys  */
  YYSYMBOL_propertydecl_keys = 106,        /* propertydecl_keys  */
  YYSYMBOL_propertydecl_key = 107,         /* propertydecl_key  */
  YYSYMBOL_fileproperty = 108,             /* fileproperty  */
  YYSYMBOL_channeldefinition = 109,        /* channeldefinition  */
  YYSYMBOL_110_1 = 110,                    /* $@1  */
  YYSYMBOL_channelheader = 111,            /* channelheader  */
  YYSYMBOL_112_2 = 112,                    /* $@2  */
  YYSYMBOL_opt_inheritance = 113,          /* opt_inheritance  */
  YYSYMBOL_extendsname = 114,              /* extendsname  */
  YYSYMBOL_likenames = 115,                /* likenames  */
  YYSYMBOL_likename = 116,                 /* likename  */
  YYSYMBOL_channelinterfacedefinition = 117, /* channelinterfacedefinition  */
  YYSYMBOL_118_3 = 118,                    /* $@3  */
  YYSYMBOL_channelinterfaceheader = 119,   /* channelinterfaceheader  */
  YYSYMBOL_120_4 = 120,                    /* $@4  */
  YYSYMBOL_opt_interfaceinheritance = 121, /* opt_interfaceinheritance  */
  YYSYMBOL_extendsnames = 122,             /* extendsnames  */
  YYSYMBOL_simplemoduledefinition = 123,   /* simplemoduledefinition  */
  YYSYMBOL_124_5 = 124,                    /* $@5  */
  YYSYMBOL_simplemoduleheader = 125,       /* simplemoduleheader  */
  YYSYMBOL_126_6 = 126,                    /* $@6  */
  YYSYMBOL_compoundmoduledefinition = 127, /* compoundmoduledefinition  */
  YYSYMBOL_128_7 = 128,                    /* $@7  */
  YYSYMBOL_compoundmoduleheader = 129,     /* compoundmoduleheader  */
  YYSYMBOL_130_8 = 130,                    /* $@8  */
  YYSYMBOL_networkdefinition = 131,        /* networkdefinition  */
  YYSYMBOL_132_9 = 132,                    /* $@9  */
  YYSYMBOL_networkheader = 133,            /* networkheader  */
  YYSYMBOL_134_10 = 134,                   /* $@10  */
  YYSYMBOL_moduleinterfacedefinition = 135, /* moduleinterfacedefinition  */
  YYSYMBOL_136_11 = 136,                   /* $@11  */
  YYSYMBOL_moduleinterfaceheader = 137,    /* moduleinterfaceheader  */
  YYSYMBOL_138_12 = 138,                   /* $@12  */
  YYSYMBOL_opt_paramblock = 139,           /* opt_paramblock  */
  YYSYMBOL_140_13 = 140,                   /* $@13  */
  YYSYMBOL_opt_params = 141,               /* opt_params  */
  YYSYMBOL_params = 142,                   /* params  */
  YYSYMBOL_paramsitem = 143,               /* paramsitem  */
  YYSYMBOL_param = 144,                    /* param  */
  YYSYMBOL_param_typenamevalue = 145,      /* param_typenamevalue  */
  YYSYMBOL_param_typename = 146,           /* param_typename  */
  YYSYMBOL_pattern_value = 147,            /* pattern_value  */
  YYSYMBOL_paramtype = 148,                /* paramtype  */
  YYSYMBOL_opt_volatile = 149,             /* opt_volatile  */
  YYSYMBOL_paramvalue = 150,               /* paramvalue  */
  YYSYMBOL_opt_inline_properties = 151,    /* opt_inline_properties  */
  YYSYMBOL_inline_properties = 152,        /* inline_properties  */
  YYSYMBOL_pattern = 153,                  /* pattern  */
  YYSYMBOL_pattern2 = 154,                 /* pattern2  */
  YYSYMBOL_pattern_elem = 155,             /* pattern_elem  */
  YYSYMBOL_pattern_name = 156,             /* pattern_name  */
  YYSYMBOL_pattern_index = 157,            /* pattern_index  */
  YYSYMBOL_property = 158,                 /* property  */
  YYSYMBOL_property_namevalue = 159,       /* property_namevalue  */
  YYSYMBOL_property_name = 160,            /* property_name  */
  YYSYMBOL_opt_property_keys = 161,        /* opt_property_keys  */
  YYSYMBOL_property_keys = 162,            /* property_keys  */
  YYSYMBOL_property_key = 163,             /* property_key  */
  YYSYMBOL_property_values = 164,          /* property_values  */
  YYSYMBOL_property_value = 165,           /* property_value  */
  YYSYMBOL_property_literal = 166,         /* property_literal  */
  YYSYMBOL_opt_gateblock = 167,            /* opt_gateblock  */
  YYSYMBOL_gateblock = 168,                /* gateblock  */
  YYSYMBOL_169_14 = 169,                   /* $@14  */
  YYSYMBOL_opt_gates = 170,                /* opt_gates  */
  YYSYMBOL_gates = 171,                    /* gates  */
  YYSYMBOL_gate = 172,                     /* gate  */
  YYSYMBOL_173_15 = 173,                   /* $@15  */
  YYSYMBOL_gate_typenamesize = 174,        /* gate_typenamesize  */
  YYSYMBOL_gatetype = 175,                 /* gatetype  */
  YYSYMBOL_opt_typeblock = 176,            /* opt_typeblock  */
  YYSYMBOL_typeblock = 177,                /* typeblock  */
  YYSYMBOL_178_16 = 178,                   /* $@16  */
  YYSYMBOL_opt_localtypes = 179,           /* opt_localtypes  */
  YYSYMBOL_localtypes = 180,               /* localtypes  */
  YYSYMBOL_localtype = 181,                /* localtype  */
  YYSYMBOL_opt_submodblock = 182,          /* opt_submodblock  */
  YYSYMBOL_submodblock = 183,              /* submodblock  */
  YYSYMBOL_184_17 = 184,                   /* $@17  */
  YYSYMBOL_opt_submodules = 185,           /* opt_submodules  */
  YYSYMBOL_submodules = 186,               /* submodules  */
  YYSYMBOL_submodule = 187,                /* submodule  */
  YYSYMBOL_188_18 = 188,                   /* $@18  */
  YYSYMBOL_submoduleheader = 189,          /* submoduleheader  */
  YYSYMBOL_submodulename = 190,            /* submodulename  */
  YYSYMBOL_likeexpr = 191,                 /* likeexpr  */
  YYSYMBOL_opt_condition = 192,            /* opt_condition  */
  YYSYMBOL_opt_connblock = 193,            /* opt_connblock  */
  YYSYMBOL_connblock = 194,                /* connblock  */
  YYSYMBOL_195_19 = 195,                   /* $@19  */
  YYSYMBOL_196_20 = 196,                   /* $@20  */
  YYSYMBOL_opt_connections = 197,          /* opt_connections  */
  YYSYMBOL_connections = 198,              /* connections  */
  YYSYMBOL_connectionsitem = 199,          /* connectionsitem  */
  YYSYMBOL_connectiongroup = 200,          /* connectiongroup  */
  YYSYMBOL_201_21 = 201,                   /* $@21  */
  YYSYMBOL_opt_loops_and_conditions = 202, /* opt_loops_and_conditions  */
  YYSYMBOL_loops_and_conditions = 203,     /* loops_and_conditions  */
  YYSYMBOL_loop_or_condition = 204,        /* loop_or_condition  */
  YYSYMBOL_loop = 205,                     /* loop  */
  YYSYMBOL_connection = 206,               /* connection  */
  YYSYMBOL_leftgatespec = 207,             /* leftgatespec  */
  YYSYMBOL_leftmod = 208,                  /* leftmod  */
  YYSYMBOL_leftgate = 209,                 /* leftgate  */
  YYSYMBOL_parentleftgate = 210,           /* parentleftgate  */
  YYSYMBOL_rightgatespec = 211,            /* rightgatespec  */
  YYSYMBOL_rightmod = 212,                 /* rightmod  */
  YYSYMBOL_rightgate = 213,                /* rightgate  */
  YYSYMBOL_parentrightgate = 214,          /* parentrightgate  */
  YYSYMBOL_opt_subgate = 215,              /* opt_subgate  */
  YYSYMBOL_channelspec = 216,              /* channelspec  */
  YYSYMBOL_217_22 = 217,                   /* $@22  */
  YYSYMBOL_channelspec_header = 218,       /* channelspec_header  */
  YYSYMBOL_opt_channelname = 219,          /* opt_channelname  */
  YYSYMBOL_condition = 220,                /* condition  */
  YYSYMBOL_vector = 221,                   /* vector  */
  YYSYMBOL_expression = 222,               /* expression  */
  YYSYMBOL_expr = 223,                     /* expr  */
  YYSYMBOL_simple_expr = 224,              /* simple_expr  */
  YYSYMBOL_funcname = 225,                 /* funcname  */
  YYSYMBOL_identifier = 226,               /* identifier  */
  YYSYMBOL_special_expr = 227,             /* special_expr  */
  YYSYMBOL_literal = 228,                  /* literal  */
  YYSYMBOL_stringliteral = 229,            /* stringliteral  */
  YYSYMBOL_boolliteral = 230,              /* boolliteral  */
  YYSYMBOL_numliteral = 231,               /* numliteral  */
  YYSYMBOL_quantity = 232,                 /* quantity  */
  YYSYMBOL_opt_semicolon = 233             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  341
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  587
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 22
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    92,    78,     2,     2,
      84,    85,    76,    74,    90,    75,    83,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    81,
      73,    91,    72,    70,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    88,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    82,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   198,   198,   200,   207,   208,   212,   213,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   229,
     231,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   256,   266,   267,   274,   284,   285,   289,   290,   291,
     292,   293,   294,   301,   306,   314,   319,   328,   329,   333,
     334,   338,   350,   362,   361,   385,   384,   394,   395,   396,
     397,   401,   410,   411,   415,   428,   427,   451,   450,   460,
     461,   465,   466,   474,   473,   498,   497,   511,   510,   538,
     537,   551,   550,   578,   577,   594,   593,   618,   617,   630,
     639,   638,   648,   649,   653,   654,   658,   659,   663,   664,
     671,   677,   695,   702,   710,   732,   734,   736,   738,   740,
     745,   748,   752,   754,   756,   760,   768,   769,   773,   774,
     778,   779,   783,   784,   788,   789,   790,   791,   795,   796,
     797,   798,   799,   800,   801,   802,   806,   807,   808,   809,
     816,   824,   825,   829,   835,   845,   849,   850,   854,   863,
     875,   877,   882,   887,   895,   896,   897,   898,   905,   906,
     911,   910,   923,   924,   928,   932,   943,   942,   954,   959,
     965,   972,   976,   981,   990,   992,   994,  1002,  1003,  1008,
    1007,  1024,  1025,  1029,  1030,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1048,  1049,  1054,  1053,  1066,  1067,  1071,
    1072,  1076,  1082,  1081,  1101,  1106,  1116,  1121,  1130,  1132,
    1134,  1139,  1142,  1149,  1150,  1155,  1154,  1166,  1165,  1178,
    1179,  1183,  1184,  1188,  1189,  1202,  1201,  1223,  1226,  1230,
    1235,  1243,  1244,  1248,  1263,  1268,  1273,  1279,  1285,  1289,
    1296,  1297,  1301,  1307,  1315,  1320,  1326,  1335,  1342,  1350,
    1361,  1362,  1366,  1370,  1378,  1383,  1389,  1398,  1403,  1409,
    1418,  1429,  1433,  1435,  1434,  1449,  1450,  1454,  1463,  1464,
    1472,  1485,  1491,  1501,  1502,  1504,  1507,  1509,  1511,  1513,
    1515,  1517,  1520,  1524,  1526,  1528,  1530,  1532,  1534,  1537,
    1539,  1541,  1544,  1548,  1550,  1552,  1555,  1558,  1560,  1562,
    1565,  1567,  1569,  1572,  1574,  1576,  1578,  1580,  1582,  1584,
    1586,  1588,  1590,  1592,  1598,  1599,  1600,  1604,  1605,  1606,
    1610,  1612,  1614,  1616,  1621,  1623,  1625,  1630,  1631,  1632,
    1636,  1641,  1643,  1648,  1650,  1652,  1657,  1658,  1659,  1660,
    1664,  1665
};
#endif

#define YYPACT_NINF (-458)
#define YYTABLE_NINF (-318)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,    30,    31,    -7,    39,    68,   177,   178,   190,   191,
     541,  -458,    56,   193,  -458,    40,  -458,  -458,  -458,  -458,
     340,  -458,  -458,     9,  -458,    11,  -458,    15,  -458,    18,
    -458,    19,  -458,    20,    87,   130,  -458,  -458,  -458,   350,
     182,  -458,   357,   172,   197,  -458,   201,  -458,   207,  -458,
     225,  -458,   251,  -458,   259,  -458,   266,   297,   298,  -458,
    -458,  -458,   308,   311,   314,   319,  -458,   239,   366,   372,
    -458,   541,   541,   541,   541,  1151,  -458,   341,  -458,  -458,
    -458,  -458,  -458,  -458,   264,   347,  -458,  -458,    -8,   354,
     353,  -458,   359,  -458,   369,  -458,   376,  -458,   377,  -458,
     380,  -458,   381,  -458,  -458,    -8,  -458,    30,  -458,  -458,
    -458,  -458,   409,   383,  -458,   333,  -458,   333,  -458,   333,
    -458,   333,  -458,   452,  -458,   452,   541,   541,   541,   422,
     541,   230,   384,   426,   541,  -458,  -458,  -458,  -458,  -458,
     926,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   352,   428,   435,   436,  -458,  -458,   396,   410,
    -458,   170,  -458,  -458,  -458,   179,  -458,   179,  -458,    78,
    -458,   161,  -458,   161,  -458,    78,   414,   431,  -458,   427,
    -458,   149,   182,  -458,   412,    31,    31,  -458,  -458,  -458,
    -458,    31,  -458,  -458,   959,   992,  1025,  -458,  1058,     3,
     424,  -458,  -458,   898,  -458,   286,   286,   286,   286,  1259,
    1205,  1232,   419,   344,   400,   446,   446,  1124,   286,   286,
     290,   290,   437,   437,   437,   437,  -458,   556,  -458,  -458,
     430,   353,    -8,  -458,  -458,  -458,   456,  -458,   294,  -458,
    -458,    33,   447,  -458,   187,  -458,  -458,  -458,   353,  -458,
     511,   448,   445,  -458,    -6,  -458,   459,   455,   526,   526,
     526,   526,  -458,    -8,    -8,    -8,  -458,   460,   531,   460,
     457,  -458,  -458,   458,  -458,  -458,  -458,  -458,  -458,   462,
     541,  -458,   541,  -458,   465,  -458,  -458,   504,   505,   517,
     471,  -458,  -458,   168,  -458,  -458,  -458,  -458,  -458,   509,
     408,   113,  -458,  -458,   153,    33,  -458,  -458,   484,   474,
    -458,   543,   543,   477,  -458,  -458,   170,   427,    31,    31,
      31,   515,  1151,   594,  -458,   187,  -458,  -458,   519,  -458,
    -458,   408,  -458,   483,  -458,   487,  -458,  1178,  -458,   478,
     486,   485,   491,   490,  -458,  -458,   513,   558,  -458,   558,
    -458,   457,  -458,  -458,  -458,  -458,   541,  -458,  -458,   353,
     541,  -458,  -458,  -458,  -458,   276,  -458,   516,   562,  -458,
     562,   632,   510,   507,  -458,  -458,  -458,   506,  -458,   276,
    -458,  -458,   549,    47,  -458,    58,   514,  -458,   518,  -458,
     541,  -458,  -458,   250,  -458,  -458,   353,   508,   552,   553,
     554,   557,   559,   561,  -458,  -458,  -458,   534,  -458,   535,
    -458,   538,  -458,   547,  -458,   548,  -458,   550,  -458,    47,
    -458,   563,   532,  -458,  -458,  -458,   670,  -458,   555,   539,
     295,  -458,  -458,   520,  -458,   563,  -458,   212,   567,  -458,
      82,  -458,   541,  -458,  -458,  -458,   541,  -458,  -458,  -458,
    -458,    26,    82,   541,   595,   213,  -458,    82,  -458,  -458,
     565,   568,  -458,  -458,   324,   382,   578,  -458,  -458,   708,
      78,   466,    -5,   629,  -458,  -458,   571,   599,     8,  -458,
    -458,  -458,   324,   564,   618,   620,   630,   631,  -458,   541,
     526,   590,  -458,   605,  -458,  -458,    31,   541,  -458,  -458,
    -458,   224,  -458,  -458,   237,  -458,   597,  -458,   647,   592,
      26,  -458,   650,  -458,   659,   591,  -458,   746,   614,   541,
    -458,    -5,   665,    43,  -458,    14,  -458,   655,   656,  -458,
     460,   690,   656,   656,   112,  -458,   541,   633,   627,  -458,
     541,   633,  -458,  -458,   591,  -458,   226,  -458,   179,    31,
    -458,  -458,  -458,  -458,   784,  -458,  -458,   641,  -458,  -458,
     118,   634,   460,  -458,   541,  -458,  -458,  -458,  -458,   822,
    -458,   541,   860,  -458,   541,  1091,  -458
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     3,     4,     7,     8,     9,    10,
     117,    11,    12,     0,    13,     0,    14,     0,    15,     0,
      16,     0,    17,     0,     0,   141,    40,    42,    41,     0,
      36,    33,     0,     0,     0,    79,     0,    75,     0,    83,
       0,    55,     0,    87,     0,    67,     0,     0,     0,   319,
     331,   332,     0,     0,     0,   324,   318,   320,   333,   334,
     330,     0,     0,     0,     0,     2,   273,     0,   314,   315,
     316,   327,   328,   329,   335,   143,     1,     6,    48,     0,
     116,   119,     0,    53,     0,    65,     0,    73,     0,    77,
       0,    81,     0,    85,    52,   153,    34,     0,    37,    39,
      38,    31,     0,    45,    24,    57,    22,    57,    26,    57,
      30,    57,    28,    70,    20,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   292,   296,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   156,     0,    47,
      50,    51,    43,   118,    29,   111,    19,   111,    21,   111,
      23,    93,    25,    93,    27,   111,     0,   145,   147,   149,
     151,   152,    35,    32,     0,     0,     0,    80,    76,    84,
      56,     0,    88,    68,     0,     0,     0,   321,     0,   320,
       0,   325,   322,     0,   274,   283,   284,   286,   288,   289,
     290,   291,   293,   294,   295,   297,   298,     0,   285,   287,
     276,   277,   278,   279,   280,   281,   303,     0,   336,   337,
       0,   117,     0,   155,   154,   130,     0,   110,   128,   127,
     132,     0,     0,    89,    92,    95,    96,    98,   117,    99,
       0,     0,     0,   123,   124,    97,     0,     0,   159,   159,
     159,   159,   142,   153,   153,   153,    46,    61,    58,    64,
      59,    63,    72,    69,   301,   300,   302,   275,   326,     0,
       0,   304,     0,   144,     0,    49,    90,     0,     0,   136,
       0,    54,    94,     0,   105,   106,   107,   108,   109,     0,
       0,     0,   133,   135,     0,     0,   140,    66,     0,     0,
     158,   178,   178,     0,   146,   150,   152,   148,     0,     0,
       0,     0,   299,     0,    44,    93,   129,   138,   139,   131,
     100,     0,   102,   114,   115,     0,   112,   272,   121,   128,
     120,     0,     0,     0,   160,    74,     0,   194,   177,   194,
      86,    60,    62,    71,   323,   305,     0,    91,   137,   117,
       0,   104,   126,   125,   134,   163,   179,     0,   214,   193,
     214,     0,     0,     0,   174,   175,   176,   171,   161,   162,
     165,   166,     0,   182,   195,     0,     0,   213,     0,   306,
       0,   101,   113,     0,   173,   164,   117,   168,     0,     0,
       0,     0,     0,     0,   192,   185,   186,     0,   187,     0,
     188,     0,   189,     0,   190,     0,   191,     0,   180,   181,
     184,   198,     0,   217,    78,    82,     0,   172,     0,     0,
       0,   170,   183,   206,   196,   197,   200,     0,     0,   215,
     220,   307,     0,   271,   167,   169,     0,   207,   199,   201,
     202,     0,   220,     0,     0,   261,   218,   219,   222,   223,
       0,   227,   230,   231,   228,     0,     0,   241,   232,     0,
     111,     0,   212,     0,   216,   270,     0,     0,   247,   242,
     221,   225,     0,     0,   268,   268,   268,     0,   308,     0,
     159,     0,   208,     0,   204,   211,     0,     0,   260,   249,
     248,   228,   229,   224,   261,   234,     0,   251,     0,   262,
     265,   236,     0,   238,     0,   261,   240,     0,     0,     0,
     209,   212,     0,   228,   269,   257,   253,     0,     0,   263,
     266,     0,     0,     0,   244,   309,     0,   341,     0,   205,
       0,   341,   259,   258,   261,   250,   261,   235,   111,     0,
     237,   239,   246,   245,     0,   340,   203,     0,   233,   226,
     254,     0,   267,   310,     0,   210,   256,   255,   264,     0,
     311,     0,     0,   312,     0,     0,   313
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -458,  -458,  -458,  -458,   700,  -458,    -1,  -458,  -458,   611,
    -213,  -458,  -458,  -458,   479,  -458,  -196,  -458,  -178,  -458,
     285,  -175,   391,   401,  -173,  -458,  -172,  -458,   609,  -458,
    -167,  -458,  -165,  -458,  -163,  -458,  -152,  -458,  -151,  -458,
    -148,  -458,  -145,  -458,  -141,  -458,  -174,  -458,   385,  -458,
     496,  -458,  -458,  -458,  -458,  -458,  -458,   397,  -216,  -458,
    -458,  -458,   440,  -458,    63,  -458,     2,  -458,  -458,  -458,
     464,   481,   467,  -101,  -256,  -458,  -458,  -458,  -458,   363,
    -458,  -458,  -458,   417,  -458,  -458,  -458,  -458,   325,   394,
    -458,  -458,  -458,  -458,   312,  -458,  -458,  -458,   238,   228,
     388,  -458,  -458,  -458,   310,   265,  -444,  -458,  -458,   301,
    -458,   287,  -458,  -458,  -458,  -458,  -458,  -458,  -381,  -458,
    -458,  -458,  -457,  -138,  -458,  -458,  -458,  -446,  -369,  -304,
     -10,  -458,  -458,   646,  -458,  -458,  -458,  -458,  -458,  -458,
     240
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    13,    14,    15,    16,    17,   277,    18,    39,    40,
      19,    20,   168,   169,   170,    21,    22,   175,    23,   121,
     197,   278,   280,   281,    24,   177,    25,   125,   202,   283,
      26,   179,    27,   117,    28,   181,    29,   115,    30,   183,
      31,   119,    32,   185,    33,   123,   252,   335,   253,   254,
     255,   256,   257,   258,   259,   309,   260,   345,    89,    90,
     261,   262,   263,   264,   300,   265,   266,    35,   186,   187,
     188,   189,   190,   171,   319,   320,   375,   388,   389,   390,
     406,   391,   392,   357,   358,   393,   428,   429,   430,   378,
     379,   431,   444,   445,   446,   480,   447,   448,   483,   504,
     396,   397,   462,   450,   466,   467,   468,   469,   511,   470,
     471,   472,   473,   474,   475,   476,   526,   477,   515,   516,
     555,   517,   535,   518,   558,   519,   520,   478,   536,   438,
     347,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     566
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    42,    34,   267,   191,   268,   346,   269,   488,   270,
      92,   271,    94,   321,   322,   323,    96,    34,   404,    98,
     100,   102,    91,   490,   463,   294,   282,     1,     2,     3,
       4,     5,     6,     7,     8,     9,   505,   346,   441,   312,
      44,   166,   303,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     3,   408,   409,   410,   411,   412,   413,   509,
     167,   137,   138,   139,   140,   552,   383,   298,   544,    46,
     313,    41,   463,   464,   457,    36,    41,   432,   112,    43,
     299,   314,    37,   315,    45,   505,   133,   245,   465,   490,
     134,    10,   173,   246,   -93,   456,   489,   570,    93,   481,
      95,   456,    85,   247,    97,    11,    38,    99,   101,   103,
      12,   463,   464,    47,   521,   523,   204,   205,   206,   510,
     208,    11,   245,   248,   213,   551,    12,   465,   414,   433,
     249,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   237,   382,   250,   363,   348,   557,   349,   485,
     -93,   560,   561,   562,    12,   249,   553,   251,   104,   576,
     245,  -228,   191,   326,   326,   563,   246,   503,    48,    50,
     415,  -111,  -111,  -111,  -111,  -111,   247,   298,   245,   250,
     439,    52,    54,    86,   246,   279,   245,   416,   243,   456,
     299,   577,   251,   532,   247,   456,   248,  -111,  -111,  -111,
    -111,  -111,   247,   249,   105,   417,   415,   244,   113,   243,
     418,   419,    49,    51,   248,   548,   420,   108,   421,   351,
     422,   249,   248,   416,   109,    53,    55,   250,   244,   249,
     275,   423,   424,    91,   528,   425,   568,    12,   426,   340,
     251,   417,   427,   463,   464,   250,   418,   419,   110,   341,
      91,   -93,   420,   250,   421,    12,   422,    62,   251,   465,
      56,    57,    58,    12,    59,   209,   251,   423,   424,   114,
     332,   425,   333,   116,   426,    60,    61,    62,   427,   118,
      63,    64,    65,   459,    66,    67,  -243,    68,    69,    70,
     456,   460,   384,   385,   386,   487,   500,   120,   534,  -252,
      71,   163,   164,   456,    72,    56,    57,    58,   487,    59,
    -252,   387,   133,  -317,   456,    73,   134,   279,   279,   487,
      60,    61,    62,   122,    74,    63,    64,    65,   437,    66,
      67,   124,    68,    69,    70,   195,   196,   148,   149,   150,
     126,   151,   152,   463,   464,    71,   381,   522,   524,    72,
     156,   157,   158,   159,   160,   161,   158,   159,   160,   161,
      73,    91,    56,    57,    58,  -103,    59,   352,   353,    74,
    -103,   127,   128,   455,   571,  -103,   297,    60,    61,    62,
     436,   129,    63,    64,    65,   130,    66,    67,   131,    68,
      69,    70,   198,   132,   199,   148,   200,   150,    91,   151,
     152,   135,    71,   494,   495,   496,    72,   136,   156,   157,
     158,   159,   160,   161,    88,   162,    12,    73,    56,    57,
      58,   106,    59,   107,   165,   172,    74,   236,   111,    12,
     112,   174,   479,    60,    61,    62,   343,   344,    63,    64,
      65,   176,    66,    67,   193,    68,    69,    70,   178,   180,
     482,   148,   182,   184,   201,   151,   152,   207,    71,   211,
     194,   212,    72,   238,   156,   157,   158,   159,   160,   161,
     239,   241,   240,    73,   151,   152,    56,    57,    58,   527,
      59,   242,    74,   156,   157,   158,   159,   160,   161,   272,
     276,    60,    61,    62,   501,   531,    63,    64,    65,   288,
      66,    67,   273,    68,    69,    70,   161,   274,   293,   540,
     156,   157,   158,   159,   160,   161,    71,   296,   311,   301,
      72,   304,   305,   306,   307,   308,   564,   317,   502,   310,
     316,    73,   318,   112,   328,   331,   334,   329,   330,   336,
      74,   338,   337,   339,   342,   354,   355,   356,   572,   360,
     364,    56,    57,    58,   579,    59,   368,   370,   371,  -122,
     297,   582,   374,   372,   585,   377,    60,    61,    62,   373,
     395,    63,    64,    65,   376,    66,    67,   394,    68,    69,
      70,   401,   402,   403,   407,   440,   434,    45,    47,    49,
     435,    71,    51,   449,    53,    72,    55,   456,   443,   141,
     142,   143,   144,   145,   146,   147,    73,   148,   149,   150,
     454,   151,   152,    93,    95,    74,   153,    97,   154,   155,
     156,   157,   158,   159,   160,   161,    99,   101,   461,   103,
     486,   291,   506,   453,   508,   513,   292,   141,   142,   143,
     144,   145,   146,   147,   491,   148,   149,   150,   492,   151,
     152,   497,   507,   514,   153,   514,   154,   155,   156,   157,
     158,   159,   160,   161,   529,   514,   525,   530,   538,   365,
     537,   539,   542,   487,   366,   141,   142,   143,   144,   145,
     146,   147,   543,   148,   149,   150,   547,   151,   152,   550,
     554,   556,   153,   559,   154,   155,   156,   157,   158,   159,
     160,   161,   567,   575,   565,    87,   578,   399,   192,   361,
     367,   295,   400,   141,   142,   143,   144,   145,   146,   147,
     362,   148,   149,   150,   203,   151,   152,   324,   369,   359,
     153,   325,   154,   155,   156,   157,   158,   159,   160,   161,
     302,   350,   405,   380,   442,   451,   327,   458,   541,   549,
     452,   141,   142,   143,   144,   145,   146,   147,   398,   148,
     149,   150,   484,   151,   152,   493,   533,   210,   153,   512,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,   569,     0,   498,     0,     0,     0,     0,   499,   141,
     142,   143,   144,   145,   146,   147,     0,   148,   149,   150,
       0,   151,   152,     0,     0,     0,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,   545,     0,     0,     0,     0,   546,   141,   142,   143,
     144,   145,   146,   147,     0,   148,   149,   150,     0,   151,
     152,     0,     0,     0,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,   574,   141,   142,   143,   144,   145,
     146,   147,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,   580,     0,     0,
       0,     0,   581,   141,   142,   143,   144,   145,   146,   147,
       0,   148,   149,   150,     0,   151,   152,     0,     0,     0,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
     584,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,     0,   141,
     142,   143,   144,   145,   146,   147,   289,   148,   149,   150,
       0,   151,   152,     0,     0,     0,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,     0,
       0,   214,   141,   142,   143,   144,   145,   146,   147,     0,
     148,   149,   150,     0,   151,   152,     0,     0,     0,   153,
       0,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,     0,     0,     0,   284,   141,   142,   143,   144,   145,
     146,   147,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,   285,   141,   142,
     143,   144,   145,   146,   147,     0,   148,   149,   150,     0,
     151,   152,     0,     0,     0,   153,     0,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
     286,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,     0,     0,   287,   141,   142,   143,   144,   145,   146,
     147,     0,   148,   149,   150,     0,   151,   152,     0,     0,
       0,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,     0,     0,     0,     0,     0,   586,   141,   142,   143,
     144,   145,   146,   147,     0,   148,   149,   150,     0,   151,
     152,     0,     0,     0,   153,   290,   154,   155,   156,   157,
     158,   159,   160,   161,   141,   142,   143,   144,   145,   146,
     147,     0,   148,   149,   150,     0,   151,   152,     0,     0,
       0,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   141,   142,   143,   144,   145,   146,   147,     0,   148,
     149,   150,     0,   151,   152,     0,     0,     0,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   141,   142,
     143,   144,   145,     0,   147,     0,   148,   149,   150,     0,
     151,   152,     0,     0,     0,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   141,   142,   143,   144,   145,
       0,     0,     0,   148,   149,   150,     0,   151,   152,     0,
       0,     0,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   141,   142,   143,   144,     0,     0,     0,     0,
     148,   149,   150,     0,   151,   152,     0,     0,     0,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161
};

static const yytype_int16 yycheck[] =
{
      10,     2,     0,   177,   105,   179,   310,   181,   465,   183,
       1,   185,     1,   269,   270,   271,     1,    15,   387,     1,
       1,     1,    20,   467,    29,   241,   201,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   482,   341,   407,    45,
       1,    49,   258,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     5,     6,     7,     8,     9,    10,    11,    51,
      68,    71,    72,    73,    74,    51,   370,    34,   525,     1,
      76,    45,    29,    30,   443,    45,    45,    19,    83,    86,
      47,    87,    52,    89,    45,   531,    83,     9,    45,   533,
      87,    67,    90,    15,    16,    87,   465,   554,    89,    73,
      89,    87,    46,    25,    89,    81,    76,    89,    89,    89,
      86,    29,    30,    45,   495,   496,   126,   127,   128,   488,
     130,    81,     9,    45,   134,    82,    86,    45,    81,    71,
      52,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   369,    76,   330,    43,   538,    45,   463,
      82,   542,   543,    51,    86,    52,   535,    89,    81,    51,
       9,    89,   273,   274,   275,   544,    15,   481,     1,     1,
     393,    20,    21,    22,    23,    24,    25,    34,     9,    76,
     406,     1,     1,     0,    15,   196,     9,   393,    49,    87,
      47,   570,    89,   507,    25,    87,    45,    20,    21,    22,
      23,    24,    25,    52,    84,   393,   429,    68,    46,    49,
     393,   393,    45,    45,    45,   529,   393,    45,   393,    76,
     393,    52,    45,   429,    52,    45,    45,    76,    68,    52,
      91,   393,   393,   241,   500,   393,   550,    86,   393,    81,
      89,   429,   393,    29,    30,    76,   429,   429,    76,    91,
     258,    82,   429,    76,   429,    86,   429,    37,    89,    45,
      20,    21,    22,    86,    24,    45,    89,   429,   429,    82,
     290,   429,   292,    82,   429,    35,    36,    37,   429,    82,
      40,    41,    42,    81,    44,    45,    83,    47,    48,    49,
      87,    89,    26,    27,    28,    92,   480,    82,    71,    83,
      60,    47,    48,    87,    64,    20,    21,    22,    92,    24,
      83,    45,    83,    84,    87,    75,    87,   328,   329,    92,
      35,    36,    37,    82,    84,    40,    41,    42,    88,    44,
      45,    82,    47,    48,    49,    12,    13,    61,    62,    63,
      84,    65,    66,    29,    30,    60,   366,   495,   496,    64,
      74,    75,    76,    77,    78,    79,    76,    77,    78,    79,
      75,   369,    20,    21,    22,    81,    24,   314,   315,    84,
      86,    84,    84,    88,   558,    91,    92,    35,    36,    37,
     400,    83,    40,    41,    42,    84,    44,    45,    84,    47,
      48,    49,   117,    84,   119,    61,   121,    63,   406,    65,
      66,    45,    60,    31,    32,    33,    64,    45,    74,    75,
      76,    77,    78,    79,    84,    84,    86,    75,    20,    21,
      22,    81,    24,    83,    87,    81,    84,    85,    81,    86,
      83,    82,   452,    35,    36,    37,    38,    39,    40,    41,
      42,    82,    44,    45,    45,    47,    48,    49,    82,    82,
     461,    61,    82,    82,    12,    65,    66,    45,    60,    85,
      87,    45,    64,    45,    74,    75,    76,    77,    78,    79,
      45,    85,    46,    75,    65,    66,    20,    21,    22,   499,
      24,    81,    84,    74,    75,    76,    77,    78,    79,    85,
      88,    35,    36,    37,    38,   506,    40,    41,    42,    85,
      44,    45,    81,    47,    48,    49,    79,    90,    88,   520,
      74,    75,    76,    77,    78,    79,    60,    71,    83,    82,
      64,    20,    21,    22,    23,    24,   546,    82,    72,    91,
      81,    75,    16,    83,    13,    83,    81,    90,    90,    45,
      84,    34,    47,    82,    45,    71,    82,    14,   559,    82,
      45,    20,    21,    22,   574,    24,    47,    84,    81,    83,
      92,   581,    82,    88,   584,    17,    35,    36,    37,    88,
      18,    40,    41,    42,    71,    44,    45,    71,    47,    48,
      49,    81,    85,    87,    45,    87,    82,    45,    45,    45,
      82,    60,    45,    71,    45,    64,    45,    87,    45,    53,
      54,    55,    56,    57,    58,    59,    75,    61,    62,    63,
      81,    65,    66,    89,    89,    84,    70,    89,    72,    73,
      74,    75,    76,    77,    78,    79,    89,    89,    71,    89,
      45,    85,    13,    88,    45,    81,    90,    53,    54,    55,
      56,    57,    58,    59,    89,    61,    62,    63,    90,    65,
      66,    83,    91,    45,    70,    45,    72,    73,    74,    75,
      76,    77,    78,    79,    84,    45,    45,    72,    31,    85,
      83,    89,    32,    92,    90,    53,    54,    55,    56,    57,
      58,    59,    33,    61,    62,    63,    82,    65,    66,    34,
      45,    45,    70,    13,    72,    73,    74,    75,    76,    77,
      78,    79,    85,    72,    81,    15,    82,    85,   107,   328,
     335,   242,    90,    53,    54,    55,    56,    57,    58,    59,
     329,    61,    62,    63,   125,    65,    66,   273,   341,   322,
      70,   274,    72,    73,    74,    75,    76,    77,    78,    79,
     254,   311,   389,   359,   429,    85,   275,   445,   520,   531,
      90,    53,    54,    55,    56,    57,    58,    59,   380,    61,
      62,    63,   462,    65,    66,   474,   511,   131,    70,   492,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,   551,    -1,    85,    -1,    -1,    -1,    -1,    90,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    90,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    90,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    90,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      90,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    53,
      54,    55,    56,    57,    58,    59,    88,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    85,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    85,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    53,    54,
      55,    56,    57,    -1,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      67,    81,    86,    94,    95,    96,    97,    98,   100,   103,
     104,   108,   109,   111,   117,   119,   123,   125,   127,   129,
     131,   133,   135,   137,   159,   160,    45,    52,    76,   101,
     102,    45,    99,    86,     1,    45,     1,    45,     1,    45,
       1,    45,     1,    45,     1,    45,    20,    21,    22,    24,
      35,    36,    37,    40,    41,    42,    44,    45,    47,    48,
      49,    60,    64,    75,    84,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    46,     0,    97,    84,   151,
     152,   159,     1,    89,     1,    89,     1,    89,     1,    89,
       1,    89,     1,    89,    81,    84,    81,    83,    45,    52,
      76,    81,    83,    46,    82,   130,    82,   126,    82,   134,
      82,   112,    82,   138,    82,   120,    84,    84,    84,    83,
      84,    84,    84,    83,    87,    45,    45,   223,   223,   223,
     223,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    65,    66,    70,    72,    73,    74,    75,    76,    77,
      78,    79,    84,    47,    48,    87,    49,    68,   105,   106,
     107,   166,    81,   159,    82,   110,    82,   118,    82,   124,
      82,   128,    82,   132,    82,   136,   161,   162,   163,   164,
     165,   166,   102,    45,    87,    12,    13,   113,   113,   113,
     113,    12,   121,   121,   223,   223,   223,    45,   223,    45,
     226,    85,    45,   223,    85,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,    85,   223,    45,    45,
      46,    85,    81,    49,    68,     9,    15,    25,    45,    52,
      76,    89,   139,   141,   142,   143,   144,   145,   146,   147,
     149,   153,   154,   155,   156,   158,   159,   139,   139,   139,
     139,   139,    85,    81,    90,    91,    88,    99,   114,    99,
     115,   116,   114,   122,    85,    85,    85,    85,    85,    88,
      71,    85,    90,    88,   151,   107,    71,    92,    34,    47,
     157,    82,   143,   151,    20,    21,    22,    23,    24,   148,
      91,    83,    45,    76,    87,    89,    81,    82,    16,   167,
     168,   167,   167,   167,   163,   165,   166,   164,    13,    90,
      90,    83,   223,   223,    81,   140,    45,    47,    34,    82,
      81,    91,    45,    38,    39,   150,   222,   223,    43,    45,
     155,    76,   157,   157,    71,    82,    14,   176,   177,   176,
      82,   115,   116,   114,    45,    85,    90,   141,    47,   150,
      84,    81,    88,    88,    82,   169,    71,    17,   182,   183,
     182,   223,   151,   222,    26,    27,    28,    45,   170,   171,
     172,   174,   175,   178,    71,    18,   193,   194,   193,    85,
      90,    81,    85,    87,   221,   172,   173,    45,     6,     7,
       8,     9,    10,    11,    81,   103,   109,   111,   117,   119,
     123,   125,   127,   129,   131,   133,   135,   137,   179,   180,
     181,   184,    19,    71,    82,    82,   223,    88,   222,   151,
      87,   221,   181,    45,   185,   186,   187,   189,   190,    71,
     196,    85,    90,    88,    81,    88,    87,   221,   187,    81,
      89,    71,   195,    29,    30,    45,   197,   198,   199,   200,
     202,   203,   204,   205,   206,   207,   208,   210,   220,   223,
     188,    73,    99,   191,   197,   222,    45,    92,   215,   221,
     199,    89,    90,   202,    31,    32,    33,    83,    85,    90,
     139,    38,    72,   222,   192,   220,    13,    91,    45,    51,
     221,   201,   204,    81,    45,   211,   212,   214,   216,   218,
     219,   211,   216,   211,   216,    45,   209,   223,   167,    84,
      72,    99,   222,   198,    71,   215,   221,    83,    31,    89,
      99,   191,    32,    33,   215,    85,    90,    82,   222,   192,
      34,    82,    51,   221,    45,   213,    45,   211,   217,    13,
     211,   211,    51,   221,   223,    81,   233,    85,   222,   233,
     215,   139,    99,    85,    90,    72,    51,   221,    82,   223,
      85,    90,   223,    85,    90,   223,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    99,    99,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   110,   109,   112,   111,   113,   113,   113,
     113,   114,   115,   115,   116,   118,   117,   120,   119,   121,
     121,   122,   122,   124,   123,   126,   125,   128,   127,   130,
     129,   132,   131,   134,   133,   136,   135,   138,   137,   139,
     140,   139,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   147,   148,   148,   148,   148,   148,
     149,   149,   150,   150,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   157,   157,   157,
     158,   159,   159,   160,   160,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   166,   166,   167,   167,
     169,   168,   170,   170,   171,   171,   173,   172,   174,   174,
     174,   174,   174,   174,   175,   175,   175,   176,   176,   178,
     177,   179,   179,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   182,   182,   184,   183,   185,   185,   186,
     186,   187,   188,   187,   189,   189,   190,   190,   191,   191,
     191,   192,   192,   193,   193,   195,   194,   196,   194,   197,
     197,   198,   198,   199,   199,   201,   200,   202,   202,   203,
     203,   204,   204,   205,   206,   206,   206,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   210,   210,   210,
     211,   211,   212,   212,   213,   213,   213,   214,   214,   214,
     215,   215,   216,   217,   216,   218,   218,   218,   219,   219,
     220,   221,   222,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   225,   225,   225,
     226,   226,   226,   226,   227,   227,   227,   228,   228,   228,
     229,   230,   230,   231,   231,   231,   232,   232,   232,   232,
     233,   233
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     2,     2,
       1,     1,     1,     3,     6,     3,     5,     1,     0,     3,
       1,     1,     2,     0,     5,     0,     4,     0,     2,     2,
       4,     1,     3,     1,     1,     0,     5,     0,     4,     2,
       0,     3,     1,     0,     6,     0,     4,     0,     9,     0,
       4,     0,     9,     0,     4,     0,     6,     0,     4,     1,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     6,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     0,     1,     4,     1,     1,     1,     0,     2,     1,
       3,     3,     3,     1,     1,     4,     4,     1,     1,     3,
       1,     3,     1,     2,     4,     2,     1,     3,     2,     2,
       2,     1,     4,     2,     5,     1,     3,     1,     3,     1,
       3,     1,     1,     0,     2,     2,     1,     1,     1,     0,
       0,     4,     1,     0,     2,     1,     0,     4,     2,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     0,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     1,     0,     2,
       1,     2,     0,     7,     4,     6,     1,     2,     2,     3,
       6,     1,     0,     1,     0,     0,     5,     0,     4,     1,
       0,     2,     1,     1,     3,     0,     6,     1,     0,     3,
       1,     1,     1,     6,     3,     5,     3,     5,     3,     5,
       3,     1,     2,     1,     2,     3,     3,     2,     3,     3,
       3,     1,     1,     2,     2,     3,     3,     2,     3,     3,
       2,     0,     1,     0,     5,     1,     2,     4,     0,     2,
       2,     3,     1,     1,     3,     4,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     5,
       4,     4,     4,     3,     4,     6,     8,    10,    12,    14,
      16,    18,    20,    22,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     1,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     2,
       1,     0
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   272,     0,   261,     0,   268,     0,   268,     0,   268,
       0,   261,     0,   261,     0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)


YYSTYPE yylval;
YYLTYPE yylloc;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IMPORT", "PACKAGE",
  "PROPERTY", "MODULE", "SIMPLE", "NETWORK", "CHANNEL", "MODULEINTERFACE",
  "CHANNELINTERFACE", "EXTENDS", "LIKE", "TYPES", "PARAMETERS", "GATES",
  "SUBMODULES", "CONNECTIONS", "ALLOWUNCONNECTED", "DOUBLETYPE", "INTTYPE",
  "STRINGTYPE", "BOOLTYPE", "XMLTYPE", "VOLATILE", "INPUT_", "OUTPUT_",
  "INOUT_", "IF", "FOR", "RIGHTARROW", "LEFTARROW", "DBLARROW", "TO",
  "TRUE_", "FALSE_", "THIS_", "DEFAULT", "ASK", "CONST_", "SIZEOF",
  "INDEX_", "TYPENAME", "XMLDOC", "NAME", "PROPNAME", "INTCONSTANT",
  "REALCONSTANT", "STRINGCONSTANT", "CHARCONSTANT", "PLUSPLUS",
  "DOUBLEASTERISK", "EQ", "NE", "GE", "LE", "AND", "OR", "XOR", "NOT",
  "BIN_AND", "BIN_OR", "BIN_XOR", "BIN_COMPL", "SHIFT_LEFT", "SHIFT_RIGHT",
  "EXPRESSION_SELECTOR", "CHAR", "INVALID_CHAR", "'?'", "':'", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMIN", "';'", "'}'",
  "'.'", "'('", "')'", "'@'", "'['", "']'", "'{'", "','", "'='", "'$'",
  "$accept", "startsymbol", "nedfile", "definitions", "definition",
  "packagedeclaration", "dottedname", "import", "importspec", "importname",
  "propertydecl", "propertydecl_header", "opt_propertydecl_keys",
  "propertydecl_keys", "propertydecl_key", "fileproperty",
  "channeldefinition", "$@1", "channelheader", "$@2", "opt_inheritance",
  "extendsname", "likenames", "likename", "channelinterfacedefinition",
  "$@3", "channelinterfaceheader", "$@4", "opt_interfaceinheritance",
  "extendsnames", "simplemoduledefinition", "$@5", "simplemoduleheader",
  "$@6", "compoundmoduledefinition", "$@7", "compoundmoduleheader", "$@8",
  "networkdefinition", "$@9", "networkheader", "$@10",
  "moduleinterfacedefinition", "$@11", "moduleinterfaceheader", "$@12",
  "opt_paramblock", "$@13", "opt_params", "params", "paramsitem", "param",
  "param_typenamevalue", "param_typename", "pattern_value", "paramtype",
  "opt_volatile", "paramvalue", "opt_inline_properties",
  "inline_properties", "pattern", "pattern2", "pattern_elem",
  "pattern_name", "pattern_index", "property", "property_namevalue",
  "property_name", "opt_property_keys", "property_keys", "property_key",
  "property_values", "property_value", "property_literal", "opt_gateblock",
  "gateblock", "$@14", "opt_gates", "gates", "gate", "$@15",
  "gate_typenamesize", "gatetype", "opt_typeblock", "typeblock", "$@16",
  "opt_localtypes", "localtypes", "localtype", "opt_submodblock",
  "submodblock", "$@17", "opt_submodules", "submodules", "submodule",
  "$@18", "submoduleheader", "submodulename", "likeexpr", "opt_condition",
  "opt_connblock", "connblock", "$@19", "$@20", "opt_connections",
  "connections", "connectionsitem", "connectiongroup", "$@21",
  "opt_loops_and_conditions", "loops_and_conditions", "loop_or_condition",
  "loop", "connection", "leftgatespec", "leftmod", "leftgate",
  "parentleftgate", "rightgatespec", "rightmod", "rightgate",
  "parentrightgate", "opt_subgate", "channelspec", "$@22",
  "channelspec_header", "opt_channelname", "condition", "vector",
  "expression", "expr", "simple_expr", "funcname", "identifier",
  "special_expr", "literal", "stringliteral", "boolliteral", "numliteral",
  "quantity", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* startsymbol: EXPRESSION_SELECTOR expr  */
#line 199 "ned2.y"
                { ps.nedfile->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2244 "ned2.tab.cc"
    break;

  case 19: /* definition: channelinterfaceheader error '}'  */
#line 230 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2250 "ned2.tab.cc"
    break;

  case 20: /* definition: CHANNELINTERFACE error '}'  */
#line 232 "ned2.y"
                { restoreGlobalParserState(); }
#line 2256 "ned2.tab.cc"
    break;

  case 21: /* definition: simplemoduleheader error '}'  */
#line 234 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2262 "ned2.tab.cc"
    break;

  case 22: /* definition: SIMPLE error '}'  */
#line 236 "ned2.y"
                { restoreGlobalParserState(); }
#line 2268 "ned2.tab.cc"
    break;

  case 23: /* definition: compoundmoduleheader error '}'  */
#line 238 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2274 "ned2.tab.cc"
    break;

  case 24: /* definition: MODULE error '}'  */
#line 240 "ned2.y"
                { restoreGlobalParserState(); }
#line 2280 "ned2.tab.cc"
    break;

  case 25: /* definition: networkheader error '}'  */
#line 242 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2286 "ned2.tab.cc"
    break;

  case 26: /* definition: NETWORK error '}'  */
#line 244 "ned2.y"
                { restoreGlobalParserState(); }
#line 2292 "ned2.tab.cc"
    break;

  case 27: /* definition: moduleinterfaceheader error '}'  */
#line 246 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2298 "ned2.tab.cc"
    break;

  case 28: /* definition: MODULEINTERFACE error '}'  */
#line 248 "ned2.y"
                { restoreGlobalParserState(); }
#line 2304 "ned2.tab.cc"
    break;

  case 29: /* definition: channelheader error '}'  */
#line 250 "ned2.y"
                { storePos(ps.component, (*yylocp)); restoreGlobalParserState(); }
#line 2310 "ned2.tab.cc"
    break;

  case 30: /* definition: CHANNEL error '}'  */
#line 252 "ned2.y"
                { restoreGlobalParserState(); }
#line 2316 "ned2.tab.cc"
    break;

  case 31: /* packagedeclaration: PACKAGE dottedname ';'  */
#line 257 "ned2.y"
                {
                  ps.package = (PackageElement *)createElementWithTag(NED_PACKAGE, ps.nedfile);
                  ps.package->setName(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)).c_str());
                  storePos(ps.package,(*yylocp));
                  storeBannerAndRightComments(ps.package,(*yylocp));
                }
#line 2327 "ned2.tab.cc"
    break;

  case 34: /* import: IMPORT importspec ';'  */
#line 275 "ned2.y"
                {
                  ps.import = (ImportElement *)createElementWithTag(NED_IMPORT, ps.nedfile);
                  ps.import->setImportSpec(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)).c_str());
                  storePos(ps.import,(*yylocp));
                  storeBannerAndRightComments(ps.import,(*yylocp));
                }
#line 2338 "ned2.tab.cc"
    break;

  case 43: /* propertydecl: propertydecl_header opt_inline_properties ';'  */
#line 302 "ned2.y"
                {
                    storePos(ps.propertydecl, (*yylocp));
                    storeBannerAndRightComments(ps.propertydecl,(*yylocp));
                }
#line 2347 "ned2.tab.cc"
    break;

  case 44: /* propertydecl: propertydecl_header '(' opt_propertydecl_keys ')' opt_inline_properties ';'  */
#line 307 "ned2.y"
                {
                    storePos(ps.propertydecl, (*yylocp));
                    storeBannerAndRightComments(ps.propertydecl,(*yylocp));
                }
#line 2356 "ned2.tab.cc"
    break;

  case 45: /* propertydecl_header: PROPERTY '@' PROPNAME  */
#line 315 "ned2.y"
                {
                  ps.propertydecl = (PropertyDeclElement *)createElementWithTag(NED_PROPERTY_DECL, ps.nedfile);
                  ps.propertydecl->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2365 "ned2.tab.cc"
    break;

  case 46: /* propertydecl_header: PROPERTY '@' PROPNAME '[' ']'  */
#line 320 "ned2.y"
                {
                  ps.propertydecl = (PropertyDeclElement *)createElementWithTag(NED_PROPERTY_DECL, ps.nedfile);
                  ps.propertydecl->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)));
                  ps.propertydecl->setIsArray(true);
                }
#line 2375 "ned2.tab.cc"
    break;

  case 51: /* propertydecl_key: property_literal  */
#line 339 "ned2.y"
                {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.propertydecl);
                  ps.propkey->setName(opp_trim(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc))).c_str());
                  storePos(ps.propkey, (*yylocp));
                }
#line 2385 "ned2.tab.cc"
    break;

  case 52: /* fileproperty: property_namevalue ';'  */
#line 351 "ned2.y"
                {
                  storePos(ps.property, (*yylocp));
                  storeBannerAndRightComments(ps.property,(*yylocp));
                }
#line 2394 "ned2.tab.cc"
    break;

  case 53: /* $@1: %empty  */
#line 362 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2406 "ned2.tab.cc"
    break;

  case 54: /* channeldefinition: channelheader '{' $@1 opt_paramblock '}'  */
#line 371 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2421 "ned2.tab.cc"
    break;

  case 55: /* $@2: %empty  */
#line 385 "ned2.y"
                {
                  ps.component = (ChannelElement *)createElementWithTag(NED_CHANNEL, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ChannelElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2430 "ned2.tab.cc"
    break;

  case 56: /* channelheader: CHANNEL NAME $@2 opt_inheritance  */
#line 390 "ned2.y"
                { storeBannerAndRightComments(ps.component,(*yylocp)); }
#line 2436 "ned2.tab.cc"
    break;

  case 61: /* extendsname: dottedname  */
#line 402 "ned2.y"
                {
                  ps.extends = (ExtendsElement *)createElementWithTag(NED_EXTENDS, ps.component);
                  ps.extends->setName(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)).c_str());
                  storePos(ps.extends, (*yylocp));
                }
#line 2446 "ned2.tab.cc"
    break;

  case 64: /* likename: dottedname  */
#line 416 "ned2.y"
                {
                  ps.interfacename = (InterfaceNameElement *)createElementWithTag(NED_INTERFACE_NAME, ps.component);
                  ps.interfacename->setName(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)).c_str());
                  storePos(ps.interfacename, (*yylocp));
                }
#line 2456 "ned2.tab.cc"
    break;

  case 65: /* $@3: %empty  */
#line 428 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2468 "ned2.tab.cc"
    break;

  case 66: /* channelinterfacedefinition: channelinterfaceheader '{' $@3 opt_paramblock '}'  */
#line 437 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2483 "ned2.tab.cc"
    break;

  case 67: /* $@4: %empty  */
#line 451 "ned2.y"
                {
                  ps.component = (ChannelInterfaceElement *)createElementWithTag(NED_CHANNEL_INTERFACE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ChannelInterfaceElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2492 "ned2.tab.cc"
    break;

  case 68: /* channelinterfaceheader: CHANNELINTERFACE NAME $@4 opt_interfaceinheritance  */
#line 456 "ned2.y"
                { storeBannerAndRightComments(ps.component,(*yylocp)); }
#line 2498 "ned2.tab.cc"
    break;

  case 73: /* $@5: %empty  */
#line 474 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2510 "ned2.tab.cc"
    break;

  case 74: /* simplemoduledefinition: simplemoduleheader '{' $@5 opt_paramblock opt_gateblock '}'  */
#line 484 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2525 "ned2.tab.cc"
    break;

  case 75: /* $@6: %empty  */
#line 498 "ned2.y"
                {
                  ps.component = (SimpleModuleElement *)createElementWithTag(NED_SIMPLE_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((SimpleModuleElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2534 "ned2.tab.cc"
    break;

  case 76: /* simplemoduleheader: SIMPLE NAME $@6 opt_inheritance  */
#line 503 "ned2.y"
                { storeBannerAndRightComments(ps.component,(*yylocp)); }
#line 2540 "ned2.tab.cc"
    break;

  case 77: /* $@7: %empty  */
#line 511 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2552 "ned2.tab.cc"
    break;

  case 78: /* compoundmoduledefinition: compoundmoduleheader '{' $@7 opt_paramblock opt_gateblock opt_typeblock opt_submodblock opt_connblock '}'  */
#line 524 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2567 "ned2.tab.cc"
    break;

  case 79: /* $@8: %empty  */
#line 538 "ned2.y"
                {
                  ps.component = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((CompoundModuleElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2576 "ned2.tab.cc"
    break;

  case 80: /* compoundmoduleheader: MODULE NAME $@8 opt_inheritance  */
#line 543 "ned2.y"
                { storeBannerAndRightComments(ps.component,(*yylocp)); }
#line 2582 "ned2.tab.cc"
    break;

  case 81: /* $@9: %empty  */
#line 551 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)ps.component->getFirstChildWithTag(NED_PARAMETERS); // networkheader already created it for @isNetwork
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2594 "ned2.tab.cc"
    break;

  case 82: /* networkdefinition: networkheader '{' $@9 opt_paramblock opt_gateblock opt_typeblock opt_submodblock opt_connblock '}'  */
#line 564 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2609 "ned2.tab.cc"
    break;

  case 83: /* $@10: %empty  */
#line 578 "ned2.y"
                {
                  ps.component = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile );
                  ((CompoundModuleElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2618 "ned2.tab.cc"
    break;

  case 84: /* networkheader: NETWORK NAME $@10 opt_inheritance  */
#line 583 "ned2.y"
                {
                  setIsNetworkProperty(ps.component);
                  storeBannerAndRightComments(ps.component,(*yylocp));
                }
#line 2627 "ned2.tab.cc"
    break;

  case 85: /* $@11: %empty  */
#line 594 "ned2.y"
                {
                  ps.typescope.push(ps.component);
                  ps.blockscope.push(ps.component);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.component);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 2639 "ned2.tab.cc"
    break;

  case 86: /* moduleinterfacedefinition: moduleinterfaceheader '{' $@11 opt_paramblock opt_gateblock '}'  */
#line 604 "ned2.y"
                {
                  ps.propertyscope.pop();
                  ps.blockscope.pop();
                  ps.component = ps.typescope.top();
                  ps.typescope.pop();
                  if (np->getStoreSourceFlag())
                      storeComponentSourceCode(ps.component, (*yylocp));
                  storePos(ps.component, (*yylocp));
                  storeTrailingComment(ps.component,(*yylocp));
                }
#line 2654 "ned2.tab.cc"
    break;

  case 87: /* $@12: %empty  */
#line 618 "ned2.y"
                {
                  ps.component = (ModuleInterfaceElement *)createElementWithTag(NED_MODULE_INTERFACE, ps.inTypes ? (NEDElement *)ps.types : (NEDElement *)ps.nedfile);
                  ((ModuleInterfaceElement *)ps.component)->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 2663 "ned2.tab.cc"
    break;

  case 88: /* moduleinterfaceheader: MODULEINTERFACE NAME $@12 opt_interfaceinheritance  */
#line 623 "ned2.y"
                { storeBannerAndRightComments(ps.component,(*yylocp)); }
#line 2669 "ned2.tab.cc"
    break;

  case 89: /* opt_paramblock: opt_params  */
#line 631 "ned2.y"
                {
                  storePos(ps.parameters, (*yylocp));
                  if (!ps.parameters->getFirstChild()) { // delete "parameters" element if empty
                      ps.parameters->getParent()->removeChild(ps.parameters);
                      delete ps.parameters;
                  }
                }
#line 2681 "ned2.tab.cc"
    break;

  case 90: /* $@13: %empty  */
#line 639 "ned2.y"
                {
                  ps.parameters->setIsImplicit(false);
                  storeBannerAndRightComments(ps.parameters,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 2690 "ned2.tab.cc"
    break;

  case 91: /* opt_paramblock: PARAMETERS ':' $@13 opt_params  */
#line 644 "ned2.y"
                { storePos(ps.parameters, (*yylocp)); }
#line 2696 "ned2.tab.cc"
    break;

  case 100: /* param_typenamevalue: param_typename opt_inline_properties ';'  */
#line 672 "ned2.y"
                {
                  ps.propertyscope.pop();
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
#line 2706 "ned2.tab.cc"
    break;

  case 101: /* param_typenamevalue: param_typename opt_inline_properties '=' paramvalue opt_inline_properties ';'  */
#line 678 "ned2.y"
                {
                  ps.propertyscope.pop();
                  if (!isEmpty(ps.exprPos))  // note: $4 cannot be checked, as it's always NULL when expression parsing is off
                      addExpression(ps.param, "value",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval);
                  else {
                      // Note: "=default" is currently not accepted in NED files, because
                      // it would be complicated to support in the Inifile Editor.
                      if (ps.isDefault)
                          np->getErrors()->addError(ps.param,"applying the default value (\"=default\" syntax) is not supported in NED files");
                  }
                  ps.param->setIsDefault(ps.isDefault);
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
#line 2725 "ned2.tab.cc"
    break;

  case 102: /* param_typename: opt_volatile paramtype NAME  */
#line 696 "ned2.y"
                {
                  ps.param = addParameter(ps.parameters, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  ps.param->setType(ps.paramType);
                  ps.param->setIsVolatile(ps.isVolatile);
                  ps.propertyscope.push(ps.param);
                }
#line 2736 "ned2.tab.cc"
    break;

  case 103: /* param_typename: NAME  */
#line 703 "ned2.y"
                {
                  ps.param = addParameter(ps.parameters, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  ps.propertyscope.push(ps.param);
                }
#line 2745 "ned2.tab.cc"
    break;

  case 104: /* pattern_value: pattern '=' paramvalue ';'  */
#line 711 "ned2.y"
                {
                  ps.param = addParameter(ps.parameters, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc));
                  ps.param->setIsPattern(true);
                  const char *patt = ps.param->getName();
                  if (strchr(patt,' ') || strchr(patt,'\t') || strchr(patt,'\n'))
                      np->getErrors()->addError(ps.param,"parameter name patterns may not contain whitespace");
                  if (!isEmpty(ps.exprPos))  // note: $3 cannot be checked, as it's always NULL when expression parsing is off
                      addExpression(ps.param, "value",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval);
                  else {
                      // Note: "=default" is currently not accepted in NED files, because
                      // it would be complicated to support in the Inifile Editor.
                      if (ps.isDefault)
                          np->getErrors()->addError(ps.param,"applying the default value (\"=default\" syntax) is not supported in NED files");
                  }
                  ps.param->setIsDefault(ps.isDefault);
                  storePos(ps.param, (*yylocp));
                  storeBannerAndRightComments(ps.param,(*yylocp));
                }
#line 2768 "ned2.tab.cc"
    break;

  case 105: /* paramtype: DOUBLETYPE  */
#line 733 "ned2.y"
                { ps.paramType = NED_PARTYPE_DOUBLE; }
#line 2774 "ned2.tab.cc"
    break;

  case 106: /* paramtype: INTTYPE  */
#line 735 "ned2.y"
                { ps.paramType = NED_PARTYPE_INT; }
#line 2780 "ned2.tab.cc"
    break;

  case 107: /* paramtype: STRINGTYPE  */
#line 737 "ned2.y"
                { ps.paramType = NED_PARTYPE_STRING; }
#line 2786 "ned2.tab.cc"
    break;

  case 108: /* paramtype: BOOLTYPE  */
#line 739 "ned2.y"
                { ps.paramType = NED_PARTYPE_BOOL; }
#line 2792 "ned2.tab.cc"
    break;

  case 109: /* paramtype: XMLTYPE  */
#line 741 "ned2.y"
                { ps.paramType = NED_PARTYPE_XML; }
#line 2798 "ned2.tab.cc"
    break;

  case 110: /* opt_volatile: VOLATILE  */
#line 746 "ned2.y"
                { ps.isVolatile = true; }
#line 2804 "ned2.tab.cc"
    break;

  case 111: /* opt_volatile: %empty  */
#line 748 "ned2.y"
                { ps.isVolatile = false; }
#line 2810 "ned2.tab.cc"
    break;

  case 112: /* paramvalue: expression  */
#line 753 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval; ps.exprPos = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc); ps.isDefault = false; }
#line 2816 "ned2.tab.cc"
    break;

  case 113: /* paramvalue: DEFAULT '(' expression ')'  */
#line 755 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval; ps.exprPos = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc); ps.isDefault = true; }
#line 2822 "ned2.tab.cc"
    break;

  case 114: /* paramvalue: DEFAULT  */
#line 757 "ned2.y"
                {
                  (*yyvalp) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = true;
                }
#line 2830 "ned2.tab.cc"
    break;

  case 115: /* paramvalue: ASK  */
#line 761 "ned2.y"
                {
                  np->getErrors()->addError(ps.parameters,"interactive prompting (\"=ask\" syntax) is not supported in NED files");
                  (*yyvalp) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = false;
                }
#line 2839 "ned2.tab.cc"
    break;

  case 140: /* property: property_namevalue ';'  */
#line 817 "ned2.y"
                {
                  storePos(ps.property, (*yylocp));
                  storeBannerAndRightComments(ps.property,(*yylocp));
                }
#line 2848 "ned2.tab.cc"
    break;

  case 143: /* property_name: '@' PROPNAME  */
#line 830 "ned2.y"
                {
                  assertNonEmpty(ps.propertyscope);
                  ps.property = addProperty(ps.propertyscope.top(), toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                  ps.propvals.clear(); // just to be safe
                }
#line 2858 "ned2.tab.cc"
    break;

  case 144: /* property_name: '@' PROPNAME '[' PROPNAME ']'  */
#line 836 "ned2.y"
                {
                  assertNonEmpty(ps.propertyscope);
                  ps.property = addProperty(ps.propertyscope.top(), toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)));
                  ps.property->setIndex(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)));
                  ps.propvals.clear(); // just to be safe
                }
#line 2869 "ned2.tab.cc"
    break;

  case 148: /* property_key: property_literal '=' property_values  */
#line 855 "ned2.y"
                {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  ps.propkey->setName(opp_trim(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc))).c_str());
                  for (int i=0; i<(int)ps.propvals.size(); i++)
                      ps.propkey->appendChild(ps.propvals[i]);
                  ps.propvals.clear();
                  storePos(ps.propkey, (*yylocp));
                }
#line 2882 "ned2.tab.cc"
    break;

  case 149: /* property_key: property_values  */
#line 864 "ned2.y"
                {
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  ps.propkey->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                  for (int i=0; i<(int)ps.propvals.size(); i++)
                      ps.propkey->appendChild(ps.propvals[i]);
                  ps.propvals.clear();
                  storePos(ps.propkey, (*yylocp));
                }
#line 2895 "ned2.tab.cc"
    break;

  case 150: /* property_values: property_values ',' property_value  */
#line 876 "ned2.y"
                { ps.propvals.push_back(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2901 "ned2.tab.cc"
    break;

  case 151: /* property_values: property_value  */
#line 878 "ned2.y"
                { ps.propvals.push_back(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2907 "ned2.tab.cc"
    break;

  case 152: /* property_value: property_literal  */
#line 883 "ned2.y"
                {
                  (*yyvalp) = createPropertyValue((*yylocp));
                }
#line 2915 "ned2.tab.cc"
    break;

  case 153: /* property_value: %empty  */
#line 887 "ned2.y"
                {
                  LiteralElement *node = (LiteralElement *)createElementWithTag(NED_LITERAL);
                  node->setType(NED_CONST_SPEC); // and leave both value and text at ""
                  (*yyvalp) = node;
                }
#line 2925 "ned2.tab.cc"
    break;

  case 160: /* $@14: %empty  */
#line 911 "ned2.y"
                {
                  assertNonEmpty(ps.blockscope);
                  ps.gates = (GatesElement *)createElementWithTag(NED_GATES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.gates,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 2935 "ned2.tab.cc"
    break;

  case 161: /* gateblock: GATES ':' $@14 opt_gates  */
#line 917 "ned2.y"
                {
                  storePos(ps.gates, (*yylocp));
                }
#line 2943 "ned2.tab.cc"
    break;

  case 164: /* gates: gates gate  */
#line 929 "ned2.y"
                {
                  storeBannerAndRightComments(ps.gate,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 2951 "ned2.tab.cc"
    break;

  case 165: /* gates: gate  */
#line 933 "ned2.y"
                {
                  storeBannerAndRightComments(ps.gate,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 2959 "ned2.tab.cc"
    break;

  case 166: /* $@15: %empty  */
#line 943 "ned2.y"
                {
                  ps.propertyscope.push(ps.gate);
                }
#line 2967 "ned2.tab.cc"
    break;

  case 167: /* gate: gate_typenamesize $@15 opt_inline_properties ';'  */
#line 947 "ned2.y"
                {
                  ps.propertyscope.pop();
                  storePos(ps.gate, (*yylocp));
                }
#line 2976 "ned2.tab.cc"
    break;

  case 168: /* gate_typenamesize: gatetype NAME  */
#line 955 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                }
#line 2985 "ned2.tab.cc"
    break;

  case 169: /* gate_typenamesize: gatetype NAME '[' ']'  */
#line 960 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                  ps.gate->setIsVector(true);
                }
#line 2995 "ned2.tab.cc"
    break;

  case 170: /* gate_typenamesize: gatetype NAME vector  */
#line 966 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc));
                  ps.gate->setType(ps.gateType);
                  ps.gate->setIsVector(true);
                  addExpression(ps.gate, "vector-size",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3006 "ned2.tab.cc"
    break;

  case 171: /* gate_typenamesize: NAME  */
#line 973 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 3014 "ned2.tab.cc"
    break;

  case 172: /* gate_typenamesize: NAME '[' ']'  */
#line 977 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc));
                  ps.gate->setIsVector(true);
                }
#line 3023 "ned2.tab.cc"
    break;

  case 173: /* gate_typenamesize: NAME vector  */
#line 982 "ned2.y"
                {
                  ps.gate = addGate(ps.gates, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc));
                  ps.gate->setIsVector(true);
                  addExpression(ps.gate, "vector-size",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3033 "ned2.tab.cc"
    break;

  case 174: /* gatetype: INPUT_  */
#line 991 "ned2.y"
                { ps.gateType = NED_GATETYPE_INPUT; }
#line 3039 "ned2.tab.cc"
    break;

  case 175: /* gatetype: OUTPUT_  */
#line 993 "ned2.y"
                { ps.gateType = NED_GATETYPE_OUTPUT; }
#line 3045 "ned2.tab.cc"
    break;

  case 176: /* gatetype: INOUT_  */
#line 995 "ned2.y"
                { ps.gateType = NED_GATETYPE_INOUT; }
#line 3051 "ned2.tab.cc"
    break;

  case 179: /* $@16: %empty  */
#line 1008 "ned2.y"
                {
                  assertNonEmpty(ps.blockscope);
                  ps.types = (TypesElement *)createElementWithTag(NED_TYPES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.types,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  if (ps.inTypes)
                     np->getErrors()->addError(ps.types,"more than one level of type nesting is not allowed");
                  ps.inTypes = true;
                }
#line 3064 "ned2.tab.cc"
    break;

  case 180: /* typeblock: TYPES ':' $@16 opt_localtypes  */
#line 1017 "ned2.y"
                {
                  ps.inTypes = false;
                  storePos(ps.types, (*yylocp));
                }
#line 3073 "ned2.tab.cc"
    break;

  case 195: /* $@17: %empty  */
#line 1054 "ned2.y"
                {
                  assertNonEmpty(ps.blockscope);
                  ps.submods = (SubmodulesElement *)createElementWithTag(NED_SUBMODULES, ps.blockscope.top());
                  storeBannerAndRightComments(ps.submods,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 3083 "ned2.tab.cc"
    break;

  case 196: /* submodblock: SUBMODULES ':' $@17 opt_submodules  */
#line 1060 "ned2.y"
                {
                  storePos(ps.submods, (*yylocp));
                }
#line 3091 "ned2.tab.cc"
    break;

  case 201: /* submodule: submoduleheader ';'  */
#line 1077 "ned2.y"
                {
                  storeBannerAndRightComments(ps.submod,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  storePos(ps.submod, (*yylocp));
                }
#line 3100 "ned2.tab.cc"
    break;

  case 202: /* $@18: %empty  */
#line 1082 "ned2.y"
                {
                  ps.blockscope.push(ps.submod);
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.submod);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                  storeBannerAndRightComments(ps.submod,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 3112 "ned2.tab.cc"
    break;

  case 203: /* submodule: submoduleheader '{' $@18 opt_paramblock opt_gateblock '}' opt_semicolon  */
#line 1092 "ned2.y"
                {
                  ps.blockscope.pop();
                  ps.propertyscope.pop();
                  storePos(ps.submod, (*yylocp));
                  storeTrailingComment(ps.submod,(*yylocp));
                }
#line 3123 "ned2.tab.cc"
    break;

  case 204: /* submoduleheader: submodulename ':' dottedname opt_condition  */
#line 1102 "ned2.y"
                {
                  ps.submod->setType(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)).c_str());
                  if (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) ps.submod->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3132 "ned2.tab.cc"
    break;

  case 205: /* submoduleheader: submodulename ':' likeexpr LIKE dottedname opt_condition  */
#line 1107 "ned2.y"
                {
                  addOptionalExpression(ps.submod, "like-expr", ps.exprPos, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval);
                  ps.submod->setLikeType(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)).c_str());
                  ps.submod->setIsDefault(ps.isDefault);
                  if (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) ps.submod->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3143 "ned2.tab.cc"
    break;

  case 206: /* submodulename: NAME  */
#line 1117 "ned2.y"
                {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 3152 "ned2.tab.cc"
    break;

  case 207: /* submodulename: NAME vector  */
#line 1122 "ned2.y"
                {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)));
                  addExpression(ps.submod, "vector-size",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3162 "ned2.tab.cc"
    break;

  case 208: /* likeexpr: '<' '>'  */
#line 1131 "ned2.y"
                { (*yyvalp) = NULL; ps.exprPos = makeEmptyYYLTYPE(); ps.isDefault = false; }
#line 3168 "ned2.tab.cc"
    break;

  case 209: /* likeexpr: '<' expression '>'  */
#line 1133 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval; ps.exprPos = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc); ps.isDefault = false; }
#line 3174 "ned2.tab.cc"
    break;

  case 210: /* likeexpr: '<' DEFAULT '(' expression ')' '>'  */
#line 1135 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval; ps.exprPos = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc); ps.isDefault = true; }
#line 3180 "ned2.tab.cc"
    break;

  case 211: /* opt_condition: condition  */
#line 1140 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval; }
#line 3186 "ned2.tab.cc"
    break;

  case 212: /* opt_condition: %empty  */
#line 1142 "ned2.y"
                { (*yyvalp) = NULL; }
#line 3192 "ned2.tab.cc"
    break;

  case 215: /* $@19: %empty  */
#line 1155 "ned2.y"
                {
                  assertNonEmpty(ps.blockscope);
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.blockscope.top());
                  ps.conns->setAllowUnconnected(true);
                  storeBannerAndRightComments(ps.conns,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 3203 "ned2.tab.cc"
    break;

  case 216: /* connblock: CONNECTIONS ALLOWUNCONNECTED ':' $@19 opt_connections  */
#line 1162 "ned2.y"
                {
                  storePos(ps.conns, (*yylocp));
                }
#line 3211 "ned2.tab.cc"
    break;

  case 217: /* $@20: %empty  */
#line 1166 "ned2.y"
                {
                  assertNonEmpty(ps.blockscope);
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.blockscope.top());
                  storeBannerAndRightComments(ps.conns,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                }
#line 3221 "ned2.tab.cc"
    break;

  case 218: /* connblock: CONNECTIONS ':' $@20 opt_connections  */
#line 1172 "ned2.y"
                {
                  storePos(ps.conns, (*yylocp));
                }
#line 3229 "ned2.tab.cc"
    break;

  case 224: /* connectionsitem: connection opt_loops_and_conditions ';'  */
#line 1190 "ned2.y"
                {
                  if (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval) {
                      transferChildren(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval, ps.conn);
                      delete YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval;
                  }
                  storePos(ps.conn, (*yylocp));
                  storeBannerAndRightComments(ps.conn,(*yylocp));
                }
#line 3242 "ned2.tab.cc"
    break;

  case 225: /* $@21: %empty  */
#line 1202 "ned2.y"
                {
                  if (ps.inConnGroup)
                      np->getErrors()->addError(ps.conngroup,"nested connection groups are not allowed");
                  ps.conngroup = (ConnectionGroupElement *)createElementWithTag(NED_CONNECTION_GROUP, ps.conns);
                  if (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval) {
                      // for's and if's were collected in a temporary UnknownElement, put them under conngroup now
                      transferChildren(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval, ps.conngroup);
                      delete YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval;
                  }
                  ps.inConnGroup = true;
                  storeBannerAndRightComments(ps.conngroup,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc));
                }
#line 3259 "ned2.tab.cc"
    break;

  case 226: /* connectiongroup: opt_loops_and_conditions '{' $@21 connections '}' opt_semicolon  */
#line 1215 "ned2.y"
                {
                  ps.inConnGroup = false;
                  storePos(ps.conngroup,(*yylocp));
                  storeTrailingComment(ps.conngroup,(*yylocp));
                }
#line 3269 "ned2.tab.cc"
    break;

  case 227: /* opt_loops_and_conditions: loops_and_conditions  */
#line 1224 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval; }
#line 3275 "ned2.tab.cc"
    break;

  case 228: /* opt_loops_and_conditions: %empty  */
#line 1226 "ned2.y"
                { (*yyvalp) = NULL; }
#line 3281 "ned2.tab.cc"
    break;

  case 229: /* loops_and_conditions: loops_and_conditions ',' loop_or_condition  */
#line 1231 "ned2.y"
                {
                  YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                  (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval;
                }
#line 3290 "ned2.tab.cc"
    break;

  case 230: /* loops_and_conditions: loop_or_condition  */
#line 1236 "ned2.y"
                {
                  (*yyvalp) = new UnknownElement();
                  (*yyvalp)->appendChild(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3299 "ned2.tab.cc"
    break;

  case 233: /* loop: FOR NAME '=' expression TO expression  */
#line 1249 "ned2.y"
                {
                  ps.loop = (LoopElement *)createElementWithTag(NED_LOOP);
                  ps.loop->setParamName( toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yyloc)) );
                  addExpression(ps.loop, "from-value",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval);
                  addExpression(ps.loop, "to-value",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                  storePos(ps.loop, (*yylocp));
                  (*yyvalp) = ps.loop;
                }
#line 3312 "ned2.tab.cc"
    break;

  case 234: /* connection: leftgatespec RIGHTARROW rightgatespec  */
#line 1264 "ned2.y"
                {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                }
#line 3321 "ned2.tab.cc"
    break;

  case 235: /* connection: leftgatespec RIGHTARROW channelspec RIGHTARROW rightgatespec  */
#line 1269 "ned2.y"
                {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                }
#line 3330 "ned2.tab.cc"
    break;

  case 236: /* connection: leftgatespec LEFTARROW rightgatespec  */
#line 1274 "ned2.y"
                {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                }
#line 3340 "ned2.tab.cc"
    break;

  case 237: /* connection: leftgatespec LEFTARROW channelspec LEFTARROW rightgatespec  */
#line 1280 "ned2.y"
                {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                }
#line 3350 "ned2.tab.cc"
    break;

  case 238: /* connection: leftgatespec DBLARROW rightgatespec  */
#line 1286 "ned2.y"
                {
                  ps.conn->setIsBidirectional(true);
                }
#line 3358 "ned2.tab.cc"
    break;

  case 239: /* connection: leftgatespec DBLARROW channelspec DBLARROW rightgatespec  */
#line 1290 "ned2.y"
                {
                  ps.conn->setIsBidirectional(true);
                }
#line 3366 "ned2.tab.cc"
    break;

  case 242: /* leftmod: NAME vector  */
#line 1302 "ned2.y"
                {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule( toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)) );
                  addExpression(ps.conn, "src-module-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3376 "ned2.tab.cc"
    break;

  case 243: /* leftmod: NAME  */
#line 1308 "ned2.y"
                {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule( toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)) );
                }
#line 3385 "ned2.tab.cc"
    break;

  case 244: /* leftgate: NAME opt_subgate  */
#line 1316 "ned2.y"
                {
                  ps.conn->setSrcGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                }
#line 3394 "ned2.tab.cc"
    break;

  case 245: /* leftgate: NAME opt_subgate vector  */
#line 1321 "ned2.y"
                {
                  ps.conn->setSrcGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3404 "ned2.tab.cc"
    break;

  case 246: /* leftgate: NAME opt_subgate PLUSPLUS  */
#line 1327 "ned2.y"
                {
                  ps.conn->setSrcGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setSrcGateSubg(ps.subgate);
                  ps.conn->setSrcGatePlusplus(true);
                }
#line 3414 "ned2.tab.cc"
    break;

  case 247: /* parentleftgate: NAME opt_subgate  */
#line 1336 "ned2.y"
                {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                }
#line 3425 "ned2.tab.cc"
    break;

  case 248: /* parentleftgate: NAME opt_subgate vector  */
#line 1343 "ned2.y"
                {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3437 "ned2.tab.cc"
    break;

  case 249: /* parentleftgate: NAME opt_subgate PLUSPLUS  */
#line 1351 "ned2.y"
                {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inConnGroup ? (NEDElement*)ps.conngroup : (NEDElement*)ps.conns );
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)));
                  ps.conn->setSrcGateSubg(ps.subgate);
                  ps.conn->setSrcGatePlusplus(true);
                }
#line 3449 "ned2.tab.cc"
    break;

  case 252: /* rightmod: NAME  */
#line 1367 "ned2.y"
                {
                  ps.conn->setDestModule( toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)) );
                }
#line 3457 "ned2.tab.cc"
    break;

  case 253: /* rightmod: NAME vector  */
#line 1371 "ned2.y"
                {
                  ps.conn->setDestModule( toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)) );
                  addExpression(ps.conn, "dest-module-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3466 "ned2.tab.cc"
    break;

  case 254: /* rightgate: NAME opt_subgate  */
#line 1379 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                }
#line 3475 "ned2.tab.cc"
    break;

  case 255: /* rightgate: NAME opt_subgate vector  */
#line 1384 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3485 "ned2.tab.cc"
    break;

  case 256: /* rightgate: NAME opt_subgate PLUSPLUS  */
#line 1390 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  ps.conn->setDestGatePlusplus(true);
                }
#line 3495 "ned2.tab.cc"
    break;

  case 257: /* parentrightgate: NAME opt_subgate  */
#line 1399 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                }
#line 3504 "ned2.tab.cc"
    break;

  case 258: /* parentrightgate: NAME opt_subgate vector  */
#line 1404 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3514 "ned2.tab.cc"
    break;

  case 259: /* parentrightgate: NAME opt_subgate PLUSPLUS  */
#line 1410 "ned2.y"
                {
                  ps.conn->setDestGate( toString( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)) );
                  ps.conn->setDestGateSubg(ps.subgate);
                  ps.conn->setDestGatePlusplus(true);
                }
#line 3524 "ned2.tab.cc"
    break;

  case 260: /* opt_subgate: '$' NAME  */
#line 1419 "ned2.y"
                {
                  const char *s = toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc));
                  if (!strcmp(s,"i"))
                      ps.subgate = NED_SUBGATE_I;
                  else if (!strcmp(s,"o"))
                      ps.subgate = NED_SUBGATE_O;
                  else
                       np->getErrors()->addError(currentLocation(), "invalid subgate spec `%s', must be `i' or `o'", toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)));
                }
#line 3538 "ned2.tab.cc"
    break;

  case 261: /* opt_subgate: %empty  */
#line 1429 "ned2.y"
                { ps.subgate = NED_SUBGATE_NONE; }
#line 3544 "ned2.tab.cc"
    break;

  case 263: /* $@22: %empty  */
#line 1435 "ned2.y"
                {
                  ps.parameters = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.parameters->setIsImplicit(true);
                  ps.propertyscope.push(ps.parameters);
                }
#line 3554 "ned2.tab.cc"
    break;

  case 264: /* channelspec: channelspec_header '{' $@22 opt_paramblock '}'  */
#line 1442 "ned2.y"
                {
                  ps.propertyscope.pop();
                }
#line 3562 "ned2.tab.cc"
    break;

  case 266: /* channelspec_header: opt_channelname dottedname  */
#line 1451 "ned2.y"
                {
                  ps.conn->setType(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)).c_str());
                }
#line 3570 "ned2.tab.cc"
    break;

  case 267: /* channelspec_header: opt_channelname likeexpr LIKE dottedname  */
#line 1455 "ned2.y"
                {
                  addOptionalExpression(ps.conn, "like-expr", ps.exprPos, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval);
                  ps.conn->setLikeType(removeSpaces((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)).c_str());
                  ps.conn->setIsDefault(ps.isDefault);
                }
#line 3580 "ned2.tab.cc"
    break;

  case 269: /* opt_channelname: NAME ':'  */
#line 1465 "ned2.y"
                { ps.conn->setName(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc))); }
#line 3586 "ned2.tab.cc"
    break;

  case 270: /* condition: IF expression  */
#line 1473 "ned2.y"
                {
                  ps.condition = (ConditionElement *)createElementWithTag(NED_CONDITION);
                  addExpression(ps.condition, "condition",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                  storePos(ps.condition, (*yylocp));
                  (*yyvalp) = ps.condition;
                }
#line 3597 "ned2.tab.cc"
    break;

  case 271: /* vector: '[' expression ']'  */
#line 1486 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval; ps.exprPos = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yyloc); }
#line 3603 "ned2.tab.cc"
    break;

  case 272: /* expression: expr  */
#line 1492 "ned2.y"
                {
                  if (np->getParseExpressionsFlag()) (*yyvalp) = createExpression(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval);
                }
#line 3611 "ned2.tab.cc"
    break;

  case 274: /* expr: '(' expr ')'  */
#line 1503 "ned2.y"
                { (*yyvalp) = YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval; }
#line 3617 "ned2.tab.cc"
    break;

  case 275: /* expr: CONST_ '(' expr ')'  */
#line 1505 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction("const", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3623 "ned2.tab.cc"
    break;

  case 276: /* expr: expr '+' expr  */
#line 1508 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("+", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3629 "ned2.tab.cc"
    break;

  case 277: /* expr: expr '-' expr  */
#line 1510 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("-", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3635 "ned2.tab.cc"
    break;

  case 278: /* expr: expr '*' expr  */
#line 1512 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("*", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3641 "ned2.tab.cc"
    break;

  case 279: /* expr: expr '/' expr  */
#line 1514 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("/", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3647 "ned2.tab.cc"
    break;

  case 280: /* expr: expr '%' expr  */
#line 1516 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("%", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3653 "ned2.tab.cc"
    break;

  case 281: /* expr: expr '^' expr  */
#line 1518 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("^", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3659 "ned2.tab.cc"
    break;

  case 282: /* expr: '-' expr  */
#line 1522 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = unaryMinus(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3665 "ned2.tab.cc"
    break;

  case 283: /* expr: expr EQ expr  */
#line 1525 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("==", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3671 "ned2.tab.cc"
    break;

  case 284: /* expr: expr NE expr  */
#line 1527 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("!=", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3677 "ned2.tab.cc"
    break;

  case 285: /* expr: expr '>' expr  */
#line 1529 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator(">", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3683 "ned2.tab.cc"
    break;

  case 286: /* expr: expr GE expr  */
#line 1531 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator(">=", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3689 "ned2.tab.cc"
    break;

  case 287: /* expr: expr '<' expr  */
#line 1533 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("<", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3695 "ned2.tab.cc"
    break;

  case 288: /* expr: expr LE expr  */
#line 1535 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("<=", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3701 "ned2.tab.cc"
    break;

  case 289: /* expr: expr AND expr  */
#line 1538 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("&&", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3707 "ned2.tab.cc"
    break;

  case 290: /* expr: expr OR expr  */
#line 1540 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("||", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3713 "ned2.tab.cc"
    break;

  case 291: /* expr: expr XOR expr  */
#line 1542 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("##", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3719 "ned2.tab.cc"
    break;

  case 292: /* expr: NOT expr  */
#line 1546 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("!", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3725 "ned2.tab.cc"
    break;

  case 293: /* expr: expr BIN_AND expr  */
#line 1549 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("&", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3731 "ned2.tab.cc"
    break;

  case 294: /* expr: expr BIN_OR expr  */
#line 1551 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("|", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3737 "ned2.tab.cc"
    break;

  case 295: /* expr: expr BIN_XOR expr  */
#line 1553 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("#", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3743 "ned2.tab.cc"
    break;

  case 296: /* expr: BIN_COMPL expr  */
#line 1557 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("~", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3749 "ned2.tab.cc"
    break;

  case 297: /* expr: expr SHIFT_LEFT expr  */
#line 1559 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("<<", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3755 "ned2.tab.cc"
    break;

  case 298: /* expr: expr SHIFT_RIGHT expr  */
#line 1561 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator(">>", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3761 "ned2.tab.cc"
    break;

  case 299: /* expr: expr '?' expr ':' expr  */
#line 1563 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createOperator("?:", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 3767 "ned2.tab.cc"
    break;

  case 300: /* expr: INTTYPE '(' expr ')'  */
#line 1566 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3773 "ned2.tab.cc"
    break;

  case 301: /* expr: DOUBLETYPE '(' expr ')'  */
#line 1568 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3779 "ned2.tab.cc"
    break;

  case 302: /* expr: STRINGTYPE '(' expr ')'  */
#line 1570 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3785 "ned2.tab.cc"
    break;

  case 303: /* expr: funcname '(' ')'  */
#line 1573 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc))); }
#line 3791 "ned2.tab.cc"
    break;

  case 304: /* expr: funcname '(' expr ')'  */
#line 1575 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3797 "ned2.tab.cc"
    break;

  case 305: /* expr: funcname '(' expr ',' expr ')'  */
#line 1577 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3803 "ned2.tab.cc"
    break;

  case 306: /* expr: funcname '(' expr ',' expr ',' expr ')'  */
#line 1579 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3809 "ned2.tab.cc"
    break;

  case 307: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ')'  */
#line 1581 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3815 "ned2.tab.cc"
    break;

  case 308: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1583 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3821 "ned2.tab.cc"
    break;

  case 309: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1585 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3827 "ned2.tab.cc"
    break;

  case 310: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1587 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-15)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3833 "ned2.tab.cc"
    break;

  case 311: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1589 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-17)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-15)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3839 "ned2.tab.cc"
    break;

  case 312: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1591 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-19)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-17)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-15)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3845 "ned2.tab.cc"
    break;

  case 313: /* expr: funcname '(' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ',' expr ')'  */
#line 1593 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction(toString((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-21)].yystate.yyloc)), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-19)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-17)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-15)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3851 "ned2.tab.cc"
    break;

  case 320: /* identifier: NAME  */
#line 1611 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createIdent((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3857 "ned2.tab.cc"
    break;

  case 321: /* identifier: THIS_ '.' NAME  */
#line 1613 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createIdent((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)); }
#line 3863 "ned2.tab.cc"
    break;

  case 322: /* identifier: NAME '.' NAME  */
#line 1615 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createIdent((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yyloc)); }
#line 3869 "ned2.tab.cc"
    break;

  case 323: /* identifier: NAME '[' expr ']' '.' NAME  */
#line 1617 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createIdent((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yyloc), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval); }
#line 3875 "ned2.tab.cc"
    break;

  case 324: /* special_expr: INDEX_  */
#line 1622 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction("index"); }
#line 3881 "ned2.tab.cc"
    break;

  case 325: /* special_expr: INDEX_ '(' ')'  */
#line 1624 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction("index"); }
#line 3887 "ned2.tab.cc"
    break;

  case 326: /* special_expr: SIZEOF '(' identifier ')'  */
#line 1626 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createFunction("sizeof", YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); }
#line 3893 "ned2.tab.cc"
    break;

  case 330: /* stringliteral: STRINGCONSTANT  */
#line 1637 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createStringLiteral((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3899 "ned2.tab.cc"
    break;

  case 331: /* boolliteral: TRUE_  */
#line 1642 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createLiteral(NED_CONST_BOOL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3905 "ned2.tab.cc"
    break;

  case 332: /* boolliteral: FALSE_  */
#line 1644 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createLiteral(NED_CONST_BOOL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3911 "ned2.tab.cc"
    break;

  case 333: /* numliteral: INTCONSTANT  */
#line 1649 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createLiteral(NED_CONST_INT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3917 "ned2.tab.cc"
    break;

  case 334: /* numliteral: REALCONSTANT  */
#line 1651 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createLiteral(NED_CONST_DOUBLE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3923 "ned2.tab.cc"
    break;

  case 335: /* numliteral: quantity  */
#line 1653 "ned2.y"
                { if (np->getParseExpressionsFlag()) (*yyvalp) = createQuantityLiteral((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yyloc)); }
#line 3929 "ned2.tab.cc"
    break;


#line 3933 "ned2.tab.cc"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp);
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc

/* Substitute the variable and function names.  */
#define yyparse ned2yyparse
#define yylex   ned2yylex
#define yyerror ned2yyerror
#define yylval  ned2yylval
#define yychar  ned2yychar
#define yydebug ned2yydebug
#define yynerrs ned2yynerrs
#define yylloc  ned2yylloc


#line 1668 "ned2.y"


//----------------------------------------------------------------------
// general bison/flex stuff:
//
int ned2yylex_destroy();  // from lex.XXX.cc file

NEDElement *doParseNED2(NEDParser *p, const char *nedtext)
{
#if YYDEBUG != 0      /* #if added --VA */
    yydebug = YYDEBUGGING_ON;
#endif

    ned2yylex_destroy();

    NONREENTRANT_NED_PARSER(p);

    // reset the lexer
    pos.co = 0;
    pos.li = 1;
    prevpos = pos;

    yyin = NULL;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(nedtext);
    if (!handle)
        {np->getErrors()->addError("", "unable to allocate work memory"); return NULL;}

    // create parser state and NEDFileElement
    resetParserState();
    ps.nedfile = new NedFileElement();

    // store file name with slashes always, even on Windows -- neddoc relies on that
    ps.nedfile->setFilename(slashifyFilename(np->getFileName()).c_str());
    ps.nedfile->setVersion("2");

    // storing the start and end position of the whole file for the NedFileElement
    // NOTE: we cannot use storePos() because it strips off the leading spaces
    // and comments from the element.
    YYLTYPE pos = np->getSource()->getFullTextPos();
    NEDSourceRegion region;
    region.startLine = pos.first_line;
    region.startColumn = pos.first_column;
    region.endLine = pos.last_line;
    region.endColumn = pos.last_column;
    ps.nedfile->setSourceRegion(region);

    // store file comment
    storeFileComment(ps.nedfile);

    ps.propertyscope.push(ps.nedfile);

    globalps = ps; // remember this for error recovery

    if (np->getStoreSourceFlag())
        storeSourceCode(ps.nedfile, np->getSource()->getFullTextPos());

    // parse
    try
    {
        yyparse();
    }
    catch (NEDException& e)
    {
        yyerror((std::string("error during parsing: ")+e.what()).c_str());
        yy_delete_buffer(handle);
        return NULL;
    }

    if (np->getErrors()->empty())
    {
        // more sanity checks
        if (ps.propertyscope.size()!=1 || ps.propertyscope.top()!=ps.nedfile)
            INTERNAL_ERROR0(NULL, "error during parsing: imbalanced propertyscope");
        if (!ps.blockscope.empty() || !ps.typescope.empty())
            INTERNAL_ERROR0(NULL, "error during parsing: imbalanced blockscope or typescope");
    }
    yy_delete_buffer(handle);

    return ps.nedfile;
}

void yyerror(const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    np->error(buf, pos.li);
}

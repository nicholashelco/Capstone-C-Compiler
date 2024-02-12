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

#ifndef YY_YY_TOKENNAMES_TAB_H_INCLUDED
# define YY_YY_TOKENNAMES_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
    IF_TOKEN = 258,                /* IF_TOKEN  */
    ELSE_TOKEN = 259,              /* ELSE_TOKEN  */
    FOR_TOKEN = 260,               /* FOR_TOKEN  */
    DO_TOKEN = 261,                /* DO_TOKEN  */
    WHILE_TOKEN = 262,             /* WHILE_TOKEN  */
    SHORT_INT_TYPE_TOKEN = 263,    /* SHORT_INT_TYPE_TOKEN  */
    UN_SHORT_INT_TYPE_TOKEN = 264, /* UN_SHORT_INT_TYPE_TOKEN  */
    UN_INT_TYPE_TOKEN = 265,       /* UN_INT_TYPE_TOKEN  */
    INT_TYPE_TOKEN = 266,          /* INT_TYPE_TOKEN  */
    LONG_INT_TYPE_TOKEN = 267,     /* LONG_INT_TYPE_TOKEN  */
    UN_LONG_INT_TYPE_TOKEN = 268,  /* UN_LONG_INT_TYPE_TOKEN  */
    LONG_LONG_INT_TYPE_TOKEN = 269, /* LONG_LONG_INT_TYPE_TOKEN  */
    UN_LONG_LONG_INT_TYPE_TOKEN = 270, /* UN_LONG_LONG_INT_TYPE_TOKEN  */
    FLOAT_TYPE_TOKEN = 271,        /* FLOAT_TYPE_TOKEN  */
    DOUBLE_TYPE_TOKEN = 272,       /* DOUBLE_TYPE_TOKEN  */
    CHAR_TYPE_TOKEN = 273,         /* CHAR_TYPE_TOKEN  */
    ID_TOKEN = 274,                /* ID_TOKEN  */
    L_PAREN_TOKEN = 275,           /* L_PAREN_TOKEN  */
    R_PAREN_TOKEN = 276,           /* R_PAREN_TOKEN  */
    L_BRACKET_TOKEN = 277,         /* L_BRACKET_TOKEN  */
    R_BRACKET_TOKEN = 278,         /* R_BRACKET_TOKEN  */
    L_BRACE_TOKEN = 279,           /* L_BRACE_TOKEN  */
    R_BRACE_TOKEN = 280,           /* R_BRACE_TOKEN  */
    PLUS_TOKEN = 281,              /* PLUS_TOKEN  */
    MINUS_TOKEN = 282,             /* MINUS_TOKEN  */
    MULTIPLY_TOKEN = 283,          /* MULTIPLY_TOKEN  */
    DIVIDE_TOKEN = 284,            /* DIVIDE_TOKEN  */
    MODULO_TOKEN = 285,            /* MODULO_TOKEN  */
    INCREMENT_TOKEN = 286,         /* INCREMENT_TOKEN  */
    DECREMENT_TOKEN = 287,         /* DECREMENT_TOKEN  */
    ASSN_TOKEN = 288,              /* ASSN_TOKEN  */
    ADD_ASSN_TOKEN = 289,          /* ADD_ASSN_TOKEN  */
    MINUS_ASSN_TOKEN = 290,        /* MINUS_ASSN_TOKEN  */
    MULTI_ASSN_TOKEN = 291,        /* MULTI_ASSN_TOKEN  */
    DIVIDE_ASSN_TOKEN = 292,       /* DIVIDE_ASSN_TOKEN  */
    MODULO_ASSN_TOKEN = 293,       /* MODULO_ASSN_TOKEN  */
    AND_ASSN_TOKEN = 294,          /* AND_ASSN_TOKEN  */
    OR_ASSN_TOKEN = 295,           /* OR_ASSN_TOKEN  */
    XOR_ASSN_TOKEN = 296,          /* XOR_ASSN_TOKEN  */
    EQUAL_COMP_TOKEN = 297,        /* EQUAL_COMP_TOKEN  */
    NOT_EQUAL_COMP_TOKEN = 298,    /* NOT_EQUAL_COMP_TOKEN  */
    LESS_THAN_COMP_TOKEN = 299,    /* LESS_THAN_COMP_TOKEN  */
    GREATER_THAN_COMP_TOKEN = 300, /* GREATER_THAN_COMP_TOKEN  */
    LESS_THAN_EQUAL_COMP_TOKEN = 301, /* LESS_THAN_EQUAL_COMP_TOKEN  */
    GREATER_THAN_EQUAL_COMP_TOKEN = 302, /* GREATER_THAN_EQUAL_COMP_TOKEN  */
    LOGICAL_AND_TOKEN = 303,       /* LOGICAL_AND_TOKEN  */
    LOGICAL_OR_TOKEN = 304,        /* LOGICAL_OR_TOKEN  */
    LOGICAL_NOT_TOKEN = 305,       /* LOGICAL_NOT_TOKEN  */
    BITWISE_AND_TOKEN = 306,       /* BITWISE_AND_TOKEN  */
    BITWISE_OR_TOKEN = 307,        /* BITWISE_OR_TOKEN  */
    BITWISE_XOR_TOKEN = 308,       /* BITWISE_XOR_TOKEN  */
    BITWISE_LSHIFT_TOKEN = 309,    /* BITWISE_LSHIFT_TOKEN  */
    BITWISE_RSHIFT_TOKEN = 310,    /* BITWISE_RSHIFT_TOKEN  */
    BITWISE_NOT_TOKEN = 311,       /* BITWISE_NOT_TOKEN  */
    NUM_TOKEN = 312                /* NUM_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKENNAMES_TAB_H_INCLUDED  */

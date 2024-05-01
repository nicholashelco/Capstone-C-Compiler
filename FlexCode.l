/* ================================== */
/* Definitions Section */


%{
    #include <cerrno>
    #include <cstdlib>
    #include <cstring>
    #include <string>
    #include "../driver.h"
    #include "YaccCode.tab.hpp"
%}

%option noyywrap nounput noinput batch debug

%{
    yy::parser::symbol_type make_LIT_NUM(yy::location& loc);
    yy::parser::symbol_type make_ID(yy::location& loc);
%}

/* Regular Definitions here */
dlim    [ \t\n]
ws      {dlim}+
letter  [A-Za-z]
digit   [0-9]
id      (_|{letter})({letter}|{digit}|_)*

%{
    #define YY_USER_ACTION  loc.columns(yyleng);
%}



%%

 /* ================================== */
 /* Rules Section */


%{
     yy::location &loc = d.location;
     loc.step();
%}

 /* Consume whitespace */
{ws}+  loc.step();

yy::parser::make_(loc);


 /* Keywords */
if        return yy::parser::make_IF       (loc);
else      return yy::parser::make_ELSE     (loc);
for       return yy::parser::make_FOR      (loc);
do        return yy::parser::make_DO       (loc);
while     return yy::parser::make_WHILE    (loc);
return    return yy::parser::make_RETURN   (loc);
break     return yy::parser::make_BREAK    (loc);
continue  return yy::parser::make_CONTINUE (loc);

short     return yy::parser::make_SHORT_TYPE    (loc);
int       return yy::parser::make_INT_TYPE      (loc);
long      return yy::parser::make_LONG_TYPE     (loc);
unsigned  return yy::parser::make_UNSIGNED_TYPE (loc);
float     return yy::parser::make_FLOAT_TYPE    (loc);
double    return yy::parser::make_DOUBLE_TYPE   (loc);
char      return yy::parser::make_CHAR_TYPE     (loc);
struct    return yy::parser::make_STRUCT_TYPE   (loc);
enum      return yy::parser::make_ENUM_TYPE     (loc);
union     return yy::parser::make_UNION_TYPE    (loc);
void      return yy::parser::make_VOID_TYPE     (loc);


 /* identifiers */
{id}  return make_ID(loc);

 /* parentheses, braces, brackets, punctuation */
"("   return yy::parser::make_L_PAREN   (loc);
")"   return yy::parser::make_R_PAREN   (loc);
"["   return yy::parser::make_L_BRACKET (loc);
"]"   return yy::parser::make_R_BRACKET (loc);
"{"   return yy::parser::make_L_BRACE   (loc);
"}"   return yy::parser::make_R_BRACE   (loc);
","   return yy::parser::make_COMMA     (loc);
"."   return yy::parser::make_DOT       (loc);
";"   return yy::parser::make_SEMICOLON (loc);
":"   return yy::parser::make_COLON     (loc);
"?"   return yy::parser::make_QUESTION  (loc);

 /* arithmetic operators */
"+"   return yy::parser::make_PLUS      (loc);
"-"   return yy::parser::make_MINUS     (loc);
"*"   return yy::parser::make_ASTERISK  (loc);
"/"   return yy::parser::make_DIVIDE    (loc);
"%"   return yy::parser::make_MODULO    (loc);
"++"  return yy::parser::make_INCREMENT (loc);
"--"  return yy::parser::make_DECREMENT (loc);

 /* Assignment operators */
"="    return yy::parser::make_ASSN        (loc);
"+="   return yy::parser::make_ADD_ASSN    (loc);
"-="   return yy::parser::make_MINUS_ASSN  (loc);
"*="   return yy::parser::make_MULTI_ASSN  (loc);
"/="   return yy::parser::make_DIVIDE_ASSN (loc);
"%="   return yy::parser::make_MODULO_ASSN (loc);
"&="   return yy::parser::make_AND_ASSN    (loc);
"\|="  return yy::parser::make_OR_ASSN     (loc);
"^="   return yy::parser::make_XOR_ASSN    (loc);

 /* comparison operators */
"=="  return yy::parser::make_EQUAL_COMP              (loc);
"!="  return yy::parser::make_NOT_EQUAL_COMP          (loc);
"<"   return yy::parser::make_LESS_COMP          (loc);
">"   return yy::parser::make_GREATER_COMP       (loc);
"<="  return yy::parser::make_LESS_EQUAL_COMP    (loc);
">="  return yy::parser::make_GREATER_EQUAL_COMP (loc);

 /* logical operators */
"&&"    return yy::parser::make_LOGICAL_AND (loc);
"\|\|"  return yy::parser::make_LOGICAL_OR  (loc);
"!"     return yy::parser::make_LOGICAL_NOT (loc);

 /* bitwise operators */
"&"   return yy::parser::make_AMP            (loc);
"\|"  return yy::parser::make_BITWISE_OR     (loc);
"\^"  return yy::parser::make_BITWISE_XOR    (loc);
"<<"  return yy::parser::make_BITWISE_LSHIFT (loc);
">>"  return yy::parser::make_BITWISE_RSHIFT (loc);
"~"   return yy::parser::make_BITWISE_NOT    (loc);

 /* Literals: ints, floating-point, chars, strings */
(0x([1-9]|[a-fA-F])({digit}|[a-fA-F])*)|([1-9]{digit}*)|(0x0)|(0)  return yy::parser::make_LIT_NUM    (loc);
([1-9]{digit}*\.{digit}+)([Ee][+-]?[1-9]{digit}*)?                 return yy::parser::make_LIT_NUM    (loc);
\'[^\']?\'                                                         return yy::parser::make_LIT_CHAR   (loc);
\"[^\"]*\"                                                         return yy::parser::make_LIT_STRING (loc);

 /* invalid input */
.   { throw yy::parser::syntax_error(loc,"invalid character: " + std::string(yytext)); }


 /* end of file */
<<EOF>>  { return yy::parser::make_YYEOF(loc); }


%%



/* ================================== */
/* User code */


 /* rewrite this function for make_LIT_NUM? Also write new functions for make_LIT_CHAR, make_LIT_STRING? */
yy::parser::symbol_type make_LIT_NUM(yy::location& loc) {

    errno = 0;

    std::string lexeme = "";
    lexeme.append(yytext, yyleng);

    // int64_t n = stoll(s,NULL,10);
    int64_t n = stoll(lexeme, NULL, 10);

    if (!(-2147483648 <= n && n <= 2147483647 && errno != ERANGE))
        throw yy::parser::syntax_error(loc,"integer is out of range: " + lexeme);

    return yy::parser::make_LIT_NUM(loc);
}


yy::parser::symbol_type make_ID(yy::location& loc) {

    std::string lexeme = "";
    lexeme.append(yytext, yyleng);
    return yy::parser::make_ID(loc);
}


void Driver::scanBegin() {

    yy_flex_debug = traceScanning;

    std::cout << "opening file " << inFileName << std::endl;

    if (inFileName.empty() || inFileName == "-")
        yyin = stdin;
    else if (!(yyin = fopen(inFileName.c_str(),"r"))) {
        std::cerr << "Cannot open " << inFileName << ": " << strerror(errno) << '\n';
        exit(EXIT_FAILURE);
    }
}


void Driver::scanEnd() {

    fclose(yyin);
}
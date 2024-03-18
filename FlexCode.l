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
    yy::parser::symbol_type make_NUM(const std::string &s,const yy::parser::location_type &loc);
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
 // Rules Section */


 %{
     yy::location
         &loc = d.location;

     loc.step();
 %}

 /* Consume whitespace */
{ws}+  loc.step();

 /* Keywords */
if        return(IF);
else      return(ELSE);
for       return(FOR);
do        return(DO);
while     return(WHILE);
return    return(RETURN);
break     return(BREAK);
continue  return(CONTINUE);

short     return(SHORT_TYPE);
int       return(INT_TYPE);
long      return(LONG_TYPE);
unsigned  return(UNSIGNED_TYPE);
float     return(FLOAT_TYPE);
double    return(DOUBLE_TYPE);
char      return(CHAR_TYPE);
struct    return(STRUCT_TYPE);
enum      return(ENUM_TYPE);
union     return(UNION_TYPE);
void      return(VOID_TYPE);


 /* identifiers */
{id}  return yy::parser::make_ID(yytext,loc);

 /* parentheses, braces, brackets, punctuation */
"("   return(L_PAREN);
")"   return(R_PAREN);
"["   return(L_BRACKET);
"]"   return(R_BRACKET);
"{"   return(L_BRACE);
"}"   return(R_BRACE);
","   return(COMMA);
"."   return(DOT);
";"   return(SEMICOLON);
":"   return(COLON);
"?"   return(QUESTION);

 /* arithmetic operators */
"+"   return(PLUS);
"-"   return(MINUS);
"*"   return(ASTERISK);
"/"   return(DIVIDE);
"%"   return(MODULO);
"++"  return(INCREMENT);
"--"  return(DECREMENT);

 /* Assignment operators */
"="    return(ASSN);
"+="   return(ADD_ASSN);
"-="   return(MINUS_ASSN);
"*="   return(MULTI_ASSN);
"/="   return(DIVIDE_ASSN);
"%="   return(MODULO_ASSN);
"&="   return(AND_ASSN);
"\|="  return(OR_ASSN);
"^="   return(XOR_ASSN);

 /* comparison operators */
"=="  return(EQUAL_COMP);
"!="  return(NOT_EQUAL_COMP);
"<"   return(LESS_THAN_COMP);
">"   return(GREATER_THAN_COMP);
"<="  return(LESS_THAN_EQUAL_COMP);
">="  return(GREATER_THAN_EQUAL_COMP);

 /* logical operators */
"&&"    return(LOGICAL_AND);
"\|\|"  return(LOGICAL_OR);
"!"     return(LOGICAL_NOT);

 /* bitwise operators */
"&"   return(AMP);
"\|"  return(BITWISE_OR);
"\^"  return(BITWISE_XOR);
"<<"  return(BITWISE_LSHIFT);
">>"  return(BITWISE_RSHIFT);
"~"   return(BITWISE_NOT);

 /* Literals: ints, floating-point, chars, strings */
(0x([1-9]|[a-fA-F])({digit}|[a-fA-F])*)|([1-9]{digit}*)|(0x0)|(0) {return make_NUM(yytext,loc);    }
([1-9]{digit}*\.{digit}+)([Ee][+-]?[1-9]{digit}*)?                {return make_NUM(yytext,loc);    }
\'[^\']?\'                                                        {   }
\"[^\"]*\"                                                        {   }

 /* invalid input */
.   { throw yy::parser::syntax_error(loc,"invalid character: " + std::string(yytext)); }


 /* end of file */
<<EOF>>  { return yy::parser::make_YYEOF(loc); }


%%



/* ================================== */
/* User code */


yy::parser::symbol_type make_NUM(const std::string &s,const yy::parser::location_type &loc) {

    errno = 0;

    int64_t n = stoll(s,NULL,10);

    if (!(-2147483648 <= n && n <= 2147483647 && errno != ERANGE))
        throw yy::parser::syntax_error(loc,"integer is out of range: " + s);

    return yy::parser::make_NUM((int)n,loc);
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


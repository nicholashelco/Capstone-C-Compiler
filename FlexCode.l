/* ================================== */
/* Definitions Section */


/* Code in %{ %} blocks are copied verbatim to output code */
%{

%}

/* Regular Definitions here */
dlim    [ \t\n]
ws      {dlim}+
letter  [A-Za-z]
digit   [0-9]
id      (_|{letter})({letter}|{digit}|_)*



%%



/* ================================== */
/* Rules Section */

/* Consume whitespace */
{ws}+  { /* do nothing */ }

/* Keywords */
if                      return(IF_TOKEN);
else                    return(ELSE_TOKEN);
for                     return(FOR_TOKEN);
do                      return(DO_TOKEN);
while                   return(WHILE_TOKEN);
short int               return(SHORT_INT_TYPE_TOKEN);
unsigned short int      return(UN_SHORT_INT_TYPE_TOKEN);
unsigned int            return(UN_INT_TYPE_TOKEN);
int                     return(INT_TYPE_TOKEN);
long int                return(LONG_INT_TYPE_TOKEN);
unsigned long int       return(UN_LONG_INT_TYPE_TOKEN);
long long int           return(LONG_LONG_INT_TYPE_TOKEN);
unsigned long long int  return(UN_LONG_LONG_INT_TYPE_TOKEN);
float                   return(FLOAT_TYPE_TOKEN);
double                  return(DOUBLE_TYPE_TOKEN);
char                    return(CHAR_TYPE_TOKEN);

/* identifiers */
{id}  {yylval = installID(); return(ID_TOKEN); }

/* arithmetic operators */
"+"   return(PLUS_TOKEN);
"-"   return(MINUS_TOKEN);
"*"   return(MULTIPLY_TOKEN);
"/"   return(DIVIDE_TOKEN);
"%"   return(MODULO_TOKEN);
"++"  return(INCREMENT_TOKEN);
"--"  return(DECREMENT_TOKEN);

/* Assignment operators */
"="    return(ASSN_TOKEN);
"+="   return(ADD_ASSN_TOKEN);
"-="   return(MINUS_ASSN_TOKEN);
"*="   return(MULTI_ASSN_TOKEN);
"/="   return(DIVIDE_ASSN_TOKEN);
"%="   return(MODULO_ASSN_TOKEN);
"&="   return(AND_ASSN_TOKEN);
"\|="  return(OR_ASSN_TOKEN);
"^="   return(XOR_ASSN_TOKEN);

/* comparison operators */
"=="  return(EQUAL_COMP_TOKEN);
"!="  return(NOT_EQUAL_COMP_TOKEN);
"<"   return(LESS_THAN_COMP_TOKEN);
">"   return(GREATER_THAN_COMP_TOKEN);
"<="  return(LESS_THAN_EQUAL_COMP_TOKEN);
">="  return(GREATER_THAN_EQUAL_COMP_TOKEN);

/* logical operators */
"&&"    return(LOGICAL_AND_TOKEN);
"\|\|"  return(LOGICAL_OR_TOKEN);
"!"     return(LOGICAL_NOT_TOKEN);

/* bitwise operators */
"&"|"\|"|"\^"|"<<"|">>"|"~"
"&"   return(BITWISE_AND_TOKEN);
"\|"  return(BITWISE_OR_TOKEN);
"\^"  return(BITWISE_XOR_TOKEN);
"<<"  return(BITWISE_LSHIFT_TOKEN);
">>"  return(BITWISE_RSHIFT_TOKEN);
"~"   return(BITWISE_NOT_TOKEN);

/* Numbers: ints and floating-point */
({digit}+)|"0x"({digit}|[a-fA-F])+                   {yylval = installNum(); return(NUM_TOKEN); }
({digit}+\.{digit}*|\.{digit}+)([Ee][+-]?{digit}+)?  {yylval = installNum(); return(NUM_TOKEN); }



%%



/* ================================== */
/* User code */


/* function to install the lexeme of an ID,
   whose first char is pointed to by yytext,
   and whose length is yylang, into the symbol
   table and return a pointer to */
int* installID(){}


/* function to install the lexeme of a number,
   whose first char is pointed to by yytext,
   and whose length is yylang, into the symbol
   table and return a pointer to */
int* installNum(){}


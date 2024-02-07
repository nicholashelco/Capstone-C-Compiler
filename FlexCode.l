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


/* Control Structures */
if|else|for|do|while|                                printf("A Control Structure: %s\n", yytext);

/* Data types */
"int"|"float"|"double"|"char"|                       printf("A data type: %s\n", yytext);

/* identifiers */
id                                                   printf("An identifier: %s\n", yytext);

/* arithmetic operators */
"+"|"-"|"*"|"/"|"%"|"++"|"--"                        printf("An arithmetic operator: %s\n", yytext);

/* Assignment operators (includes >> and << ) */
("+"|"-"|"*"|"/"|"%"|"&"|"\|"|"^"|">>"|"<<")?"="     printf("An assignment operator: %s\n", yytext);

/* comparison operators */
"=="|"!="|">"|">="|"<"|"<="|                         printf("A comparison operator: %s\n", yytext);

/* logical operators */
"&&"|"\|\|"|"!"                                      printf("A logical operator: %s\n", yytext);

/* bitwise operators (includes >> and << too) */
"&"|"\|"|"\^"|"<<"|">>"|"~"                          printf("A bitwise operator: %s\n", yytext);

/* How to handle numbers: signs, hex, fp? */






%%

/* ================================== */
/* User code */
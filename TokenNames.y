
%{

%}

/* keywords */
%token IF_TOKEN
%token ELSE_TOKEN
%token FOR_TOKEN
%token DO_TOKEN
%token WHILE_TOKEN

%token SHORT_INT_TYPE_TOKEN
%token UN_SHORT_INT_TYPE_TOKEN
%token UN_INT_TYPE_TOKEN
%token INT_TYPE_TOKEN
%token LONG_INT_TYPE_TOKEN
%token UN_LONG_INT_TYPE_TOKEN
%token LONG_LONG_INT_TYPE_TOKEN
%token UN_LONG_LONG_INT_TYPE_TOKEN
%token FLOAT_TYPE_TOKEN
%token DOUBLE_TYPE_TOKEN
%token CHAR_TYPE_TOKEN

/* identifiers */
%token ID_TOKEN

 /* parentheses, braces, and brackets */
%token L_PAREN_TOKEN
%token R_PAREN_TOKEN
%token L_BRACKET_TOKEN
%token R_BRACKET_TOKEN
%token L_BRACE_TOKEN
%token R_BRACE_TOKEN

 /* arithmetic operators */
%token PLUS_TOKEN
%token MINUS_TOKEN
%token MULTIPLY_TOKEN
%token DIVIDE_TOKEN
%token MODULO_TOKEN
%token INCREMENT_TOKEN
%token DECREMENT_TOKEN

 /* Assignment operators */
%token ASSN_TOKEN
%token ADD_ASSN_TOKEN
%token MINUS_ASSN_TOKEN
%token MULTI_ASSN_TOKEN
%token DIVIDE_ASSN_TOKEN
%token MODULO_ASSN_TOKEN
%token AND_ASSN_TOKEN
%token OR_ASSN_TOKEN
%token XOR_ASSN_TOKEN

 /* comparison operators */
%token EQUAL_COMP_TOKEN
%token NOT_EQUAL_COMP_TOKEN
%token LESS_THAN_COMP_TOKEN
%token GREATER_THAN_COMP_TOKEN
%token LESS_THAN_EQUAL_COMP_TOKEN
%token GREATER_THAN_EQUAL_COMP_TOKEN

 /* logical operators */
%token LOGICAL_AND_TOKEN
%token LOGICAL_OR_TOKEN
%token LOGICAL_NOT_TOKEN

 /* bitwise operators */
%token BITWISE_AND_TOKEN
%token BITWISE_OR_TOKEN
%token BITWISE_XOR_TOKEN
%token BITWISE_LSHIFT_TOKEN
%token BITWISE_RSHIFT_TOKEN
%token BITWISE_NOT_TOKEN

 /* Numbers: ints and floating-point */
%token NUM_TOKEN



%%

filler:
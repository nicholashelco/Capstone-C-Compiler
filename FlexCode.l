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
number  {digit}+(\.{digit}+)?(E[+-]?{digit}+)?


/* Rules Section */
%%


%%



/* User code */
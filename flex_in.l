%{
#include <stdio.h>
#include "y.tab.h"
%}
int             (0[box])?[0-9]+
decimal         [0-9]*\.[0-9]+
%%
{int}           { /* printf("%s: int", yytext);*/ return INTEGER; }
{decimal}       { /* printf("%s: decimal", yytext);*/ return DECIMAL; }
"+"             return ADD;
"-"             return SUB;
"*"             return MUL;
"/"             return DIV;
%%
// int main() {
//     yylex(); /* 进行Lex分析 */
//     return 0;
// }

int yywrap() {
    return 1;
}

// int yyerror(char *s) {
//     fprintf(stderr, "%s\n", s);
//     return 0;       
// }

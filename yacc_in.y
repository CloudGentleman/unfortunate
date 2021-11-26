%{
#include <stdio.h>

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;       
}
%}
%token INTEGER DECIMAL
%token ADD SUB MUL DIV MOD
%%
numeric_expr
        : INTEGER
        {
            $$ = $1;
        }
        | MUL numeric_expr numeric_expr
        {
            $$ = $2 * $3;
        }
        | DIV numeric_expr numeric_expr
        {
            $$ = $2 / $3;
        }
        | ADD numeric_expr numeric_expr
        {
            $$ = $2 + $3;
        }
        | SUB numeric_expr numeric_expr
        {
            $$ = $2 - $3;
        }
        ;
%%
int main(void) {
    yyparse();
    return 0;
}

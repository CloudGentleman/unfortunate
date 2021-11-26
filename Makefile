
uf-both : lex.yy.c y.tab.c
	gcc -o $@ $^

uf-flex-only : lex.yy.c
	gcc -o $@ $^

lex.yy.c : flex_in.l
	flex $^

y.tab.c y.tab.h: yacc_in.y
	yacc -d $^

.PHONY : clean
clean :
	rm -fv -- y.tab.* lex.yy.c uf-flex-only uf-both



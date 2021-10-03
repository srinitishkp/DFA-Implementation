lex:lexImp.o lexApp.o
	cc lexImp.o lexApp.o -o lex
lexApp.o:lexApp.c
	cc -c lexApp.c
lexImp.o:lexImp.c
	cc -c lexImp.c

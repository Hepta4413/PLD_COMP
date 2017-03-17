default:
	flex comp.l
	bison -v --defines=comp.tab.h comp.y
	g++ -DYYDEBUG -o comp *.c

default:
	flex comp.l
	bison -v --defines=comp.tab.h comp.y -Wconflicts-sr
	g++ -DYYDEBUG -o comp *.c

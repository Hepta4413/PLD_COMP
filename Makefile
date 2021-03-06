						#######################
						## MAKEFILE PLD_COMP ##
						##		H4413		 ##
						#######################

#Executable
EXE = Compiler_H4413

# Compilateur et editeur de lien
GPP = @g++
GCC = @gcc
LINK = @g++
FLEX = @flex
BISON = @bison

# Options de compilation et editions de liens
CPPFLAGS = -DYYDEBUG -Wall -std=gnu++11 -DMAP
CFLAGS =
EDLFLAGS =
BISONFLAGS =
FLEXFLAGS =

#Fichiers
##############################################################################

#HEADERS
INCDIR = -I ./include -I ./irs/include


#OBJETS
OBJ = \
		obj/Programme.o \
		obj/Affectation.o \
		obj/AppelFonct.o \
		obj/Bloc.o \
		obj/BlocControle.o \
		obj/BlocFor.o \
		obj/BlocIf.o \
		obj/BlocWhile.o \
		obj/Contenu.o \
		obj/Const.o \
		obj/Declaration.o \
		obj/Expression.o \
		obj/Fonction.o \
		obj/Ligne.o \
		obj/OPUnaire.o \
		obj/OPBinaire.o \
		obj/Return.o \
		obj/Variable.o \
		obj/VarS.o \
		obj/VarTab.o \
		obj/ListeDeclaration.o \
		obj/DeclAffect.o \
		irs/obj/BasicBlock.o \
		irs/obj/CFG.o \
		irs/obj/IRInstr.o

MAINOBJ= irs/obj/main.o

FLEXL = flexbison/comp.l
FLEXC = flexbison/lex.yy.c
FLEXOBJ = obj/lex.yy.o

BISONY = flexbison/comp.y
BISONH = flexbison/comp.tab.h
BISONC = flexbison/comp.tab.c
BISONREPORT = flexbison/comp.output
BISONOBJ = obj/comp.tab.o

COMPOBJ = \
			main.s \
			a.out

BISONFLAGS += --defines=$(BISONH) -r state --report-file=$(BISONREPORT) -o $(BISONC)
CPPFLAGS += $(INCDIR)
CFLAGS += $(INCDIR)

###############################################################################

ECHO = @echo
RM = @rm

###############################################################################

.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	$(RM) -fv $(OBJ) $(EXE) $(FLEXC) $(BISONC) $(BISONH) $(BISONREPORT) $(FLEXOBJ) $(BISONOBJ) $(COMPOBJ)

.PHONY: flexbison
flexbison : $(FLEXOBJ) $(BISONOBJ)

#Règles
###############################################################################

#Edition des liens
$(EXE): $(OBJ) $(FLEXOBJ) $(BISONOBJ)
	$(ECHO) "[link]" $(LINK) $(EDLFLAGS) $(EXE)
	$(LINK) -o $(EXE) $^ $(EDLFLAGS)

#Compilation des objets
obj/%.o:src/%.cpp include/%.h
	$(ECHO) "[comp]" $(GPP) $(CPPFLAGS) $<
	$(GPP) -o $@ -c $(CPPFLAGS) $<

irs/obj/%.o:irs/src/%.cpp irs/include/%.h
	$(ECHO) "[comp]" $(GPP) $(CPPFLAGS) $<
	$(GPP) -o $@ -c $(CPPFLAGS) $<

$(MAINOBJ):irs/src/main.cpp
	$(ECHO) "[comp]" $(GPP) $(CPPFLAGS) $<
	$(GPP) -o $@ -c $(CPPFLAGS) $<

#Génération Flex
$(FLEXC):$(FLEXL)
	$(ECHO) "[flex]" $(FLEX) $(FLEXFLAGS) $<
	$(FLEX) -o $@ $(FLEXFLAGS)$(FLEXL)

#Génération Bison
$(BISONC):$(BISONY)
	$(ECHO) "[bison]" $(BISON) $(BISONFLAGS) $<
	$(BISON) $(BISONFLAGS) $(BISONY)

#Compilation Flex
$(FLEXOBJ):$(FLEXC) $(BISONC)
	$(ECHO) "[comp]" $(GPP) $(CPPFLAGS) $<
	$(GPP) -o $@ -c $(CPPFLAGS) $(FLEXC)

#Compilation Bison
$(BISONOBJ):$(BISONC) $(BISONH)
	$(ECHO) "[comp]" $(GPP) $(CPPFLAGS) $<
	$(GPP) -o $@ -c $(CPPFLAGS) $(BISONC)

						#######################
						## MAKEFILE PLD_COMP ##
						##		H4413		 ##
						#######################

#Executable
EXE = Compiler_H4413

# Compilateur et editeur de lien
COMP = @g++
LINK = @g++
FLEX = @flex
BISON = @bison

# Options de compilation et editions de liens
CPPFLAGS = -DYYDEBUG -Wall -std=gnu++11
CPPFLAGS += $(INCDIR)
EDLFLAGS =
BISONFLAG = -v --defines=comp.tab.h
FLEXFLAG = 

#Fichiers
##############################################################################

#HEADERS
INCDIR = -I ./include

#OBJETS
OBJ = \
		obj/Affectation.o \
		obj/AppelFonct.o \
		obj/Bloc.o \
		obj/BlocControle.o \
		obj/BlocFor.o \
		obj/BlocIf.o \
		obj/BlocWhile.o \
		obj/Contenu.o \
		obj/Declaration.o \
		obj/Expression.o \
		obj/Fonction.o \
		obj/Ligne.o \
		obj/OPUnaire.o \
		obj/OPBinaire.o \
		obj/Programme.o \
		obj/Return.o \
		obj/Variable.o \
		obj/VarS.o \
		obj/VarTab.o \

MAIN = obj/main.o

FLEXSRC = flexbison/comp.l

BISONSRC = flexbison/comp.y

FB = fb

###############################################################################

ECHO = @echo
RM = @rm

###############################################################################

.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	$(RM) -fv ./obj/*.o $(EXE)
	
.PHONY: flexbison
flexbison : $(FB)
	
#Dependances
###############################################################################

#Edition des liens
$(EXE): $(OBJ) $(MAIN) #$(FB)
	$(ECHO) "[link]" $(LINK) $(EDLFLAGS) $@
	$(LINK) -o $(EXE) $^ $(EDLFLAGS)
	
#Compilation des objets
obj/%.o:src/%.cpp include/%.h
	$(ECHO) "[comp]" $(COMP) $(CPPFLAGS) $@
	$(COMP) -o $@ -c $(CPPFLAGS) $<
	
#Compilation du main
$(MAIN):src/main.cpp
	$(ECHO) "[comp]" $(COMP) $(CPPFLAGS) $@
	$(COMP) -o $@ -c $(CPPFLAGS) $<
	
#Compilation Flex-Bison
#$(FB):$(FLEXSRC) $(BISONSRC)
#	$(ECHO) "[flex]" $(FLEX) $(FLEXFLAG) $@
#	$(FLEX) $(FLEXSRC)
#	$(ECHO) "[bison]" $(BISON) $(BISONFLAG) $@
#	$(BISON) $(BISONFLAG) $(BISONSRC)
	

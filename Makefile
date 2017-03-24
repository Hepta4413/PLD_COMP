EXE = B3225

# Compilateur et editeur de lien
COMP = @g++
LINK = @g++

# Options de compilation et editions de liens
CPPFLAGS = -DYYDEBUG -Wall -std=gnu++11
CPPFLAGS += $(INCDIR)
EDLFLAGS =

#Fichiers
INCDIR = -I ./include

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

REAL = $(OBJ:.o=.cpp:obj=src)

###############################################################################

ECHO = @echo
RM = @rm


#Cibles
###############################################################################

.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	$(RM) -fv ./obj/*.o $(EXE)
	
#Dependances
###############################################################################

$(EXE): $(OBJ) $(MAIN)
	$(ECHO) "[link]" $(LINK) $(EDLFLAGS) $@
	$(LINK) -o $(EXE) $^ $(EDLFLAGS)
	
obj/%.o:src/%.cpp include/%.h
	$(ECHO) "[comp]" $(COMP) $(CPPFLAGS) $@
	$(COMP) -o $@ -c $(CPPFLAGS) $<
	
$(MAIN):src/main.cpp
	$(ECHO) "[comp]" $(COMP) $(CPPFLAGS) $@
	$(COMP) -o $@ -c $(CPPFLAGS) $<
	

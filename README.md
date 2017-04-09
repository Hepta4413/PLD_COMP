# PLD_COMP

**Compilateur de language C réalisé dans le cadre du PLD_COMP.**

## Fonctionnalités Front-end

* Prise en charge de l'intégralité de la grammaire décrite dans le sujet excepté les variables globales
* Gestion de la portée des variables
* Gestion du typage des noeuds
* Possibilité de déclarer des variables n'importe où dans le code
* Affichage d'erreurs lors de l'affectation du variable non déclarée ou la déclaration d'une variable non utilisée
* Support des caractères spéciaux

## Fonctionnalités Back-end

* Déclaration et l'affectation des variables
* Déclaration et affectation multiple sur la même ligne
* Opérations d'addition, multiplication et soustraction
* Boucles *for* et *while*
* *If* et *else*
* Opérateurs && et ||
* Appel de fonction avec passage de paramètres et retour
* Gestion de *putchar*
* Appels récursifs fonctionnels

## Compilation

Simplement executer `make` dans le dossier racine

## Execution

Un fichier script est disponible pour compiler simplement un programme. Il suffit de lui donner en paramètre le programme C à compiler.
```
./Compiler_H4413.sh source.c
```

Sinon, voici comment faire pas-à-pas :
Passer le fichier source C à compiler au programme grâce à un pipe
```
./Compiler_H4413 < source.c
```
Un ficher *main.s* est généré dans le même dossier contenant le code assembleur généré. *gcc* peut être utilisé pour l'assembler.
```
gcc main.s
```
L'executable peut ensuite être executé.
```
./a.out
```

## Execution des tests

Le dossier `tests/src/` contient un jeu de 11 tests pour le compilateur.

Pour les compiler et les executer, executer le script dédié à cet usage
```
cd tests
./executeTests.sh
```
Les sorties sont dans le dossier `out`. Le script les affiche, les compare avec les sorties du dossier `expected` et affiche le nombre de tests echoués.

### Liste des tests
* 01-putchar.c : simple utilisation de putchar
* 02-variables.c : déclaration, affectation et affichage de variables de type `char`
* 03-multiDeclaration.c : déclaration et affectation de plusieurs variable sur la même ligne puis affichage de ces variables
* 04-VarConstAddCall.c : Opération sur des variables `char` puis affichage
* 05-IfThenElse.c : Tests de condition et affichage selon le resultat du test
* 06-AndOrOperator.c : Tests de conditions avec des opérateurs && et || et affichage selon le résultat
* 07-While.c : Boucle while simple
* 08-doubleBoucleWhileFor.c : Affichage multiple de l'alphabet à l'aide d'une boucle For dans une boucle While
* 09-testWhileAndVariables.c : Affichage de l'alphabet a l'aide d'une boucle While 
* 10-AlphabetRecursif.c : Affichage de l'alphabet à l'aide d'un appel récursif de fonction
* 11-appelEtRetourFonction : Appel d'une fonction avec plusieurs paramètres et retour de fonction dans une variable

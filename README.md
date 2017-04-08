# PLD_COMP

**Compilateur de language C réalisé dans le cadre du PLD_COMP.**

##Fonctionnalités Front-end

* Prise en charge de l'intégralité de la grammaire décrite dans le sujet excepté les variables globales
* Gestion de la portée des variables
* Gestion du typage des noeuds
* Possibilité de déclarer des variables n'importe où dans le code
* Affichage d'erreurs lors de l'affectation du variable non déclarée ou la déclaration d'une variable non utilisée

##Fonctionnalités Back-end

* Déclaration et l'affectation des variables
* Opérations d'addition, multiplication et soustraction
* Boucles *for* et *while*
* *If* et *else*
* Appel de fonction avec passage de paramètres et retour
* Gestion de *putchar*
* Appels récursifs fonctionnels

##Compilation

Simplement executer `make` dans le dossier racine

##Execution

Un fichier script est disponible pour compiler simplement un programme. Il suffit de lui donner en paramètre le programme C à compiler.
`./Compiler_H4413.sh source.c`

Sinon, voici comment faire pas-à-pas :
Passer le fichier source C à compiler au programme grâce à un pipe
`./Compiler_H4413 < source.c`
Un ficher *main.s* est généré dans le même dossier contenant le code assembleur généré. *gcc* peut être utilisé pour l'assembler.
`gcc main.s`
L'executable peut ensuite être executé.
`./a.out`

##Execution des tests
**TODO**

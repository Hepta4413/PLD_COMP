#!/bin/bash

#TODO tester presence de l'executable ./Compiler_H4413 --> si non --> make clean + mkdir obj et irs/obj + make

#Execution du programme de compilation
echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|        Compilation en assembleur         |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"
if [[ $# -eq 1 ]]; then
  if [[ -f $1 ]]; then  #--> le fichier $1 existe
    echo -e "Fichier utilisé: $1\n"
    ./Compiler_H4413 < $1
  else                  #--> le fichier $1 n'existe pas
    echo -e "Erreur: le fichier $1 n'existe pas.\n"
    exit 1 #TODO  ou proposer reprise sur ./Compiler_H4413 sans paramètre ou lecture nomfichier grace a la cmd read // MEttre en place un do whle poiur la reprise
  fi
elif [[ $# -lt 1 ]]; then #--> trop peu d'argument
  echo -e "Attention aucun fichier C n'a été passé en paramètre. Il faudra donc saisir manuellement sont contenu.\n"
  ./Compiler_H4413
else #--> trop d'arguments
  echo -e "Attention trop trop d'arguments ont été passé en paramètre. Seul le premier argument sera utilisé, les autres seront ignorés."
  echo -e "Fichier utilisé: $1\n"
  ./Compiler_H4413 < $1
fi
echo -e "\nValeur de retour de la compilation du fichier $1: $?\n"

#Compilation du fichier assembleur main.s
echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|        Compilation de assembleur         |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"
if [[ -f main.s ]]; then  #--> le fichier main.s existe
  gcc main.s
  echo -e "Valeur de retour de la compilation du fichier main.s: $?\n"
else                      #--> le fichier main.s n'existe pas
  echo -e "Erreur: le fichier main.s n'existe pas. Impossible de le compiler.\n"
  exit 2
fi

#Execution de l'executable généré à partir du programme passé en paramètre
echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|      Execution du programme compilé      |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"
if [[ -f a.out ]]; then #--> le fichier a.out existe
  ./a.out
  echo -e "\n\nValeur de retour de l'execution du fichier a.out: $?\n"
else                    #--> le fichier a.out n'existe pas
    echo -e "Erreur: le fichier a.out n'existe pas. Impossible de l'executer.\n"
    exit 3
fi

exit 0

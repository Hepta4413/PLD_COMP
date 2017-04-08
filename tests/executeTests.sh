#!/bin/bash

echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|        Execution des tests               |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"

for i in src/*.c

do
	echo -e "\nCompilation et execution de "
	echo $i
	../Compiler_H4413 < $i
	gcc main.s
	./a.out > out/${i:4}.out
done

for i in out/*.out

do
	echo $i
	cat $i
	echo -e "\n"
done

rm main.s
rm a.out

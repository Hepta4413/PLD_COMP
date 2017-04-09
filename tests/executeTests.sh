#!/bin/bash

echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|        Execution des tests               |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"

mkdir out

for i in src/*.c

do
	echo -e "\nCompilation et execution de $i"
	../Compiler_H4413 < $i
	gcc main.s
	./a.out > out/${i:4}.out
done

let "nbTestFailed = 0"

for i in out/*.out

do
	echo $i
	cat $i
	if [[ $(diff $i expected/${i:4}) ]]; then
		echo -e "\n==> TEST FAILED"
		let "nbTestFailed = nbTestFailed+1"
	else
		echo -e "\n==> TEST PASSED"
	fi
	echo -e "\n"
done

echo -e "\n\t\t|******************************************|"
echo -e "\t\t|                                          |"
echo -e "\t\t|            $nbTestFailed test(s) failed              |"
echo -e "\t\t|                                          |"
echo -e "\t\t|******************************************|\n"
echo -e "\n \n"

rm main.s
rm a.out

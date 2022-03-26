#!/bin/bash

if [ ! -f ./adder ]; then
	make
fi

for i in `seq 100`
do
	NB1=$RANDOM
	NB2=$RANDOM
	./adder $NB1 $NB2 > mine
	echo $(($NB1 + $NB2)) > real
	diff mine real >> result.log
done

rm mine real

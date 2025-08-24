#!/bin/bash
read n

for ((i = 0; i < n; i++)) do 
	for((j = 0; j < i; j++)) do
		echo -n "*"
	done
	echo ""
done

for ((i = 0; i < n; i++)) do 
	for((j = 0; j < n-i; j++)) do
		echo -n "*"
	done
	echo ""
done


#!/bin/bash

read -p "Enter the value of n= " n

for ((i = 1; i <= n; i++)) do 
	sum=$(($sum + $i*(-1**i)))
done

echo $sum

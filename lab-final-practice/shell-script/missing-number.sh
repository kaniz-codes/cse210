#!/bin/bash

n=0
read -p "Enter the value of n= " n

sum=0
sum1=0
check(){
	sum1=$(((n-1)*(n)/2))
	for ((i = 0; i < n-1; i++)); do
		read -p "Enter number= " x
		sum2=$(($sum2+$x))
	done
	echo "Missing number=" $(($sum1-$sum2))
}

check



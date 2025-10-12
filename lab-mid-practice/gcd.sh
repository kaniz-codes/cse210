#!/bin/bash

gcd() {
	local a=$1
	local b=$2
	
	while [ $b -ne 0 ]; do
		r=$(($a % $b))
		a=$b
		b=$r
	done
	echo $a
}

gcd 48 18

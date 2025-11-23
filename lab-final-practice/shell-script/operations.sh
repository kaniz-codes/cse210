#!/bin/bash
read -p "Value 1:" x
read -p "Value 2:" y
echo "Value 1:" $x
echo "Value 2:" $y
echo ""
a=$(($x+$y))
echo "Addition of x,y:" $a
echo ""
b=$(($x+$y))
echo "Subtraction of x,y:" $b
echo ""
c=$(($x*$y))
echo "Multiplication of x,y:" $c
echo ""
d=$(($x/$y))
echo "Division of x,y:" $d

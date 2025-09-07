#!/bin/bash

read -p "Enter the value of a= " a
read -p "Enter the value of b= " b

count=0
while (($a%$b !=0)); do

  	a=$(($a+1))
        count=$(($count+1))
done

echo $count

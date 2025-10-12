#!/bin/bash

read -p "Enter a number: " num

if (( num % 2 == 0 ))
    then 
         echo "$num is Even"
else
    echo "$num is Odd"
fi

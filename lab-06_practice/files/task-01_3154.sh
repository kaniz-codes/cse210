#!/bin/bash

read -p "Enter the value of n= " n

if (( n%2 == 0 )); then
    echo "YES"
  
elif (( n%2 != 0 )); then
    echo "NO"
 
fi


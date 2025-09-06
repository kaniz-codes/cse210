#!/bin/bash

n=0
read -p "Enter the value of n= " n

res=1
i=0
factorial(){
for (( i=2; i<=n; i++ )); do
    res=$((res*i))
    
done
echo "factorial=" $res
}

factorial

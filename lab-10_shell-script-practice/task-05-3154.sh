#!/bin/bash

# Kaniz Fatema
# 20245103154

read s1 
read s2

result=""
seen=""

len=${#s1}

for (( i=0; i<len; i++ )); do
    ch="${s1:i:1}"
    
    if [[ "$s2" == *"$ch"* && "$seen" != *"$ch"* ]]; then
        result+="$ch"
        seen+="$ch"
    fi
done

echo "$result"

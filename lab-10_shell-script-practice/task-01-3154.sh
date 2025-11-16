#!/bin/bash

# Kaniz Fatema
# 20245103154

read x
lx=${x,,}
size=${#x}
y=0

for (( i=0; i<size; i++ )); do
    z=${lx:$i:1}
    if [ $z == "a" ] || [ $z == "e" ] || [ $z == "i" ] || [ $z == "o" ] || [ $z == "u" ]; then
        y=$(( y + 1 ))
    fi
done

echo $y

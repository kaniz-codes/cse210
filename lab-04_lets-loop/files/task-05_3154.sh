#!/bin/bash

echo "Input:"
read n

if [ $n -lt 2 ]; then
    echo "$n is not a prime number."
    exit 0
fi

for ((i=2; i<=$n/2; i++)); do
    if (( n % i == 0 )); then
        echo "Output: $n is not a prime number."
        exit 0
    fi
done

echo "Output: $n is a prime number."
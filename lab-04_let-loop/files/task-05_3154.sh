#!/bin/bash

echo "Input:"
read n

if [ "$n" < 2 ]; then
    echo "$n is not a prime number."
    exit 0
fi

for ((i=2; i*i<=$n; i++)); do
    if (( n % i == 0 )); then
        echo "Output: $n is not a prime number."
        exit 0
    fi
done

echo "Output: $n is a prime number."

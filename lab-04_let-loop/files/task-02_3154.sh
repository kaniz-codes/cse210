#!/bin/bash
read -p "Enter the number of Fibonacci series: " n
a=0
b=1
echo "Fibonacci Series up to $n:"

if (( n == 0 )); then
    echo ""
    exit 0
elif (( n == 1 )); then
    echo "1"
    exit 0
fi
echo -n "$b "
for (( i=2; i<=n; i++ )); do
    fn=$((a + b))
    echo -n "$fn "
    a=$b
    b=$fn
done
echo ""

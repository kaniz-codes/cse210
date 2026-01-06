#!/bin/bash

echo "Enter first number: "
read num1

echo "Enter second number: "
read num2

echo "Choose one (+, -, *, /) : "
read op

if [ "$op" == "+" ]; then
    result=$((num1 + num2))
elif [ "$op" == "-"]; then
    result=$((num1 - num2))
elif [ "$op" == "*"]; then
    result=$((num1 * num2))
elif [ "$op" == "/"]; then
    result=$((num1 / num2))

fi 

echo "The result is: $result"
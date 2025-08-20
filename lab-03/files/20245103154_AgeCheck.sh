#!/bin/bash
read -p "Age: " a
echo "Your Age" $a
if [ $a -ge 18 ]; then
echo "Adult"
else
echo "Minor"
fi

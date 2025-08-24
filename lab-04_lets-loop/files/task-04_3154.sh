#!/bin/bash

echo -n "Enter a year: "
read year

y1=$((year + 1))
y2=$((year - 1))

k=1
while [ $k -le 4 ]; do

if (( (y1 % 400 == 0 || y1 % 4 == 0) && y1 % 100 != 0 )); then
    break
fi
((y1++))
((k++))

done

k=4
while [ $k -ge 0 ]; do

if (( (y2 % 400 == 0 || y2 % 4 == 0) && (y2 % 100 != 0) )); then

    break
fi
((y2--))
((k--))


done

forwards=$((y1 - year))
backwards=$((year - y2))

echo -n "Nearest leap year: "
if [ $backwards -lt $forwards ]; then
	echo $y2
else
	echo $y1
fi
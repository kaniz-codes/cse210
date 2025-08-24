#!/bin/bash

is_leap_year() {
    local y=$1
    if (( (y % 400) == 0 )); then
        return 0
    elif (( (y % 100) == 0 )); then
        return 1
    elif (( (y % 4) == 0 )); then
        return 0
    else
        return 1
    fi
}

echo -n "Enter a year: "
read year


if is_leap_year $year; then
    echo "Nearest leap year is $year"
    exit 0
fi


k=1
while true; do
    prev=$((year - k))
    next=$((year + k))
    
    if is_leap_year $prev; then
        echo "Nearest leap year is $prev"
        break
    elif is_leap_year $next; then
        echo "Nearest leap year is $next"
        break
    fi
    
    ((k++))
done


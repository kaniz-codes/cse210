# Lab 4: Let's Loop



# Innitialization

Create directory
```bash
mkdir kaniz0154
cd kaniz0154
touch task-01_3154.sh
touch task-02_3154.sh
touch task-03_3154.sh
touch task-04_3154.sh
touch task-05_3154.sh
touch task-06_3154.sh

chmod +x task-01_3154.sh
chmod +x task-02_3154.sh
chmod +x task-03_3154.sh
chmod +x task-04_3154.sh
chmod +x task-05_3154.sh
chmod +x task-06_3154.sh
```

## Task 1
```1. Print a bash script to generate the following pattern:
Input: 5
Output:
*
**
***
****
*****
****
***
**
*
```

```bash
#!/bin/bash
read n
for ((i = 0; i < n; i++)) do 
	for((j = 0; j < i; j++)) do
		echo -n "*"
	done
	echo ""
done

for ((i = 0; i < n; i++)) do 
	for((j = 0; j < n-i; j++)) do
		echo -n "*"
	done
	echo ""
done
```

```bash
./task-01_3154.sh
```
## Task 2

2. Print the Fibonacci series in terminal with a bash script:
Input: 5
Output: 1 1 2 3 5

```bash
#!/bin/bash
read -p "Enter the number of Fibonacci series: " n
a=0
b=1
echo "Fibonacci Series up to $n:"

if (( n == 0 )); then
    echo ""
    exit 0
elif (( n == 1 )); then
    echo "$a"
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
```
show output
```bash
./task-02_3154.sh
```

## Task 3
Write a bash script to find if a year is a leap year or not
HINT: A leap year is either divisible by 400 or divisible by 4 but not divisible
by 100.
```bash
#!/bin/bash
echo -n "Enter a year: "
read year

if (( year % 400 == 0 )); then
    echo "$year is a leap year."
elif (( year % 4 == 0 )); then
    echo "$year is a leap year."
    
elif (( year % 100 == 0 )); then
    echo "$year is not a leap year."

else
    echo "$year is not a leap year."
fi
```
show output
```bash
./task-03_3154.sh
```

## Task 4

4. Write a bash script to find the nearest leap year from the current year.

For example : If year 2023 is given as the input, then the nearest leap year is 2024.
If 2021 is given the nearest leap year is 2020. If 2022 is given you can either print
2020 or 2024.

```bash
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
```

```bash
./task-04_3154.sh
```
## Task 5
Input: 7
Output: "7 is a prime number"
Input: 10
Output: "10 is not a prime number"

```bash
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
```
```bash
./task-05_3154.sh
```

## Task 6
6. Write a bash script to find and print all prime numbers between two given
numbers (inclusive).
Input: 10 30
Output: 11 13 17 19 23 29
```bash
#!/bin/bash

echo "Input:"
read n
read m

for ((i=$n; i<=$m; i++)); do
   if (( i == 1 || i == 0)); then
     continue
     
   fi
            
    k=1
    for ((j = 2; j <= i/2; j++)); do
 
      if (( i % j == 0)); then
        k=0
      fi
      done
      if (( k==1)); then
        echo "$i "
      fi
done
```
```bash
./task-06_3154.sh
```


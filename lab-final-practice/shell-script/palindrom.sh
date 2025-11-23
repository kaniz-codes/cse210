#!/bin/bash

palindrome(){
  str="$1"
  rev="$(echo "$str" | rev)"

  if [ "$str" = "$rev" ]; then
    echo "\"$str\" is palindrome."
  else
    echo "\"$str\" is NOT palindrome."
  fi
}

read -p "Enter a string: " n
palindrome "$n"


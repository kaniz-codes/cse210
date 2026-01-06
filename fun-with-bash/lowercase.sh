#!/bin/bash
echo -n "Enter String Uppercase: "
read -r input
echo "$input" | tr '[:upper:]' '[:lower]'
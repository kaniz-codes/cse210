#!/bin/bash

# Kaniz Fatema
# 20245103154

read -a nums

result=""

for n in "${nums[@]}"; do
    case " $result " in
        *" $n "*) ;;
        *) result+="$n " ;;
    esac
done

echo "$result"

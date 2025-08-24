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





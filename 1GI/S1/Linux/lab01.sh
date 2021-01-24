#!/bin/bash
 
for i in {1..100}
do 
  echo $i
done 
for ((i=1; i<=10; i++))
do 
  echo $i 
done 
array=("dacia" "mercedes" "ford")
for i in ${arrat[@]}
do 
 echo $i
done 
declare -A assocArray
assocArray["name"]="EHTP"
assocArray["id"]="1234"
for i in "${!assocArray[@]}"
do 
  echo "$i: ${assocArray[$i]}"
done
# command substitution
for i in $(ls)
do 
  echo "$i"
done

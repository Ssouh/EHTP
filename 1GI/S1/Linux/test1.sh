#!/bin/bash

n=$1
ans=0
rest=0
while [  $n  -gt  0 ]; do
	rest=`expr $n % 10`
	ans=`expr $ans \* 10 + $rest`
	n=`expr $n / 10`
done 
	echo "le nombre inversé est : $ans" 




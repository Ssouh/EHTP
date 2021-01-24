#!/bin/bash

n=$1
som=0


while [ $n -gt 0 ]
do
	
	som=`expr $n % 10 + $som`
	n=`expr $n / 10`
done 
	echo " le nombre est : $som"



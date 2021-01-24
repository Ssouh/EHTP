#!/bin/bash


if [$# -e 3 ]
rep=$3
droit=$1
ext=$2

for i in "${rep}"/*"${ext}" ;do
    chmod g$droit $i
done
else 
rep="."
droit=$1
ext=$2

for i in "${rep}"/*"${ext}" ;do
    chmod g$droit $i

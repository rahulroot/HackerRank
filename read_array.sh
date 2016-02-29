#!/bin/bash

<<READ_ARRAY
in=0
while read line
do
	a[in]=$line
	let "in=in+1"
done
echo "${a[@]}"
READ_ARRAY

<<MIDDLE_ARRAY
in=0
while read line
do
	if [ $in -gt 3 ] && [ $in -lt 7 ]; then
		a[$in]=$line;
	fi
	let "i=i+1"
done
echo "${a[@]}"
MIDDLE_ARRAY


<<CAT_ARRAY
in=0
while read line
do
	a[in]=$line
	let "in=in+1"
done
echo "${a[@]}"

newarr=("${a[@]}" "${a[@]}")
echo "${newarr[@]}"
CAT_ARRAY

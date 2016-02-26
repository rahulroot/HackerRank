#!/bin/bash

read n
i=0
sum=0
while [ $i -lt $n ]
do
	read a
	let "sum += $a";
	echo "new sum is $sum"; 
  let "i = i + 1"
done
printf "%0.3f" $(expr "scale = 4; $sum/$n" | bc -l)

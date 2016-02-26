#!/bin/bash
i=0
while [ $i -le 100 ]
do
	let "j= $i % 2"
  if [ $j != 0 ]; then
      echo $i
  fi
  let "i= $i + 1"
done

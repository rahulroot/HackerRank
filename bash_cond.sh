#!/bin/bash

read c

if [ "$c" == "Y" ] || [ "$c" == "y" ]; then
    echo "Yes"
else
  echo "No"
fi

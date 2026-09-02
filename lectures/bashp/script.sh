#!/bin/bash

file="$1"
echo $file
if [ -f "$file" ]; then
	cat "$file" | sort -r
else
	echo "dne"
fi

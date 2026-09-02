#!/bin/bash

read -p "Enter path to directory: " directory

if [ -d "$directory" ]; then
	cd "$directory"
	lines=$(ls -l | wc -l)
	validlines=$((lines - 1))
	echo "All items with sizes:"
	ls -l | tail -n $validlines | tr -s ' ' | cut -d ' ' -f 9 > filenames.txt 
	ls -l | tail -n $validlines | tr -s ' ' | cut -d ' ' -f 5 > bytes.txt
	paste -d ',' filenames.txt bytes.txt
	count=1
	sum=0
	while [ $count -le  $validlines ]
	do
		size=`head -n $count bytes.txt | tail -n 1` 
		sum=$((sum+size))
		count=$((count + 1))
	done
	avg=$((sum/validlines))
	echo "Average size: $avg"
	counter=1
	itemcount=1
	echo "Items larger than average ($avg bytes):"
	while [ $counter -le $validlines ]
	do
		if [ `head -n $counter bytes.txt | tail -n 1` -gt $avg ]; then
			echo "$itemcount. $(head -n $counter filenames.txt | tail -n 1) - $(head -n $counter bytes.txt | tail -n 1) bytes"
			itemcount=$((itemcount + 1))
		fi
		counter=$((counter + 1))
	done
	echo "Total items above average: $((itemcount-1)) out of $validlines."
else
	echo "This is not a directory."
fi

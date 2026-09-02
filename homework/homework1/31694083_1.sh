#!/bin/bash

read -p "Enter path to file: " filename

if [ -f "$filename" ]; then
	sort $filename | uniq -c | sort -k1,1nr -k2,2 | tr -s " " > sorted.txt

	cut -d " " -f 3 sorted.txt > letters.txt
	cut -d " " -f 2 sorted.txt > numbers.txt
	echo 'Word Frequency:'
	echo "--------------------"
	paste -d " " letters.txt numbers.txt
	uniques=`wc -l sorted.txt | cut -d " " -f 1`
	echo "Total unique words: $uniques"
else
	echo "File does not exist."
fi

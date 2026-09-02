#!/bin/bash

file1="$1"
file2="$2"
date=`date "+%Y%m%d"`



if [ $# -lt 2 ]; then
	echo "not enough arguments (<2)"
else
	mkdir "backup_$date"
	for file in "$@"; do
		if [ -f "$file" ]; then
			cp "$file" "backup_$date/$file.bak.$date"
		fi
fi




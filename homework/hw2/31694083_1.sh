#!/bin/bash

arguments=( $@ )
arguments_size=${#arguments[@]}
processed=0
removed=0
if [ $arguments_size -gt 1 ]; then
	echo "Too many arguments."
elif [ $arguments_size -eq  1 ]; then
	if [ -d "$1" ]; then

	queue[0]="$1" # storing command-line argument

	while [ "${#queue[@]}" -ne 0 ]; do # check if length of array is not 0
		if [ -f "${queue[0]}" ]; then
			processed=$((processed + 1))
			if [ ! -s ${queue[0]} ]; then
				echo "${queue[0]} removed."
				rm "${queue[0]}"
				removed=$((removed + 1))
			fi
		fi
       		if [ -d "${queue[0]}" ] && [ `ls "${queue[0]}" | wc -l` -ne 0 ]; then # if index 0 of queue is a directory and it is not empty, execute
               		entries=("${queue[0]}/*") # stores subdirectories in entries

               		queue=("${queue[@]}" "${entries[@]}") # combine arrays
       		fi
       		queue=(${queue[@]:1}) # remove element at position 0
	done

	else
		echo "Invalid directory."
	fi
else
	if [ -d "$(pwd)" ]; then

        	queue[0]="$(pwd)" # storing command-line argument
		echo ${queue[0]}
        	while [ "${#queue[@]}" -ne 0 ]; do # check if length of array is not 0
                	if [ -f "${queue[0]}" ]; then 
                        	processed=$((processed + 1)) 
                        	if [ ! -s ${queue[0]} ]; then
                                	echo "${queue[0]} removed."
                                	rm "${queue[0]}"
                                	removed=$((removed + 1))
                        	fi 
                	fi 
                	if [ -d "${queue[0]}" ] && [ `ls "${queue[0]}" | wc -l` -ne 0 ]; then # if index 0 of queue i>
                        	entries=("${queue[0]}/*") # stores subdirectories in entries

                        	queue=("${queue[@]}" "${entries[@]}") # combine arrays
                	fi
                	queue=(${queue[@]:1}) # remove element at position 0
        	done

	fi
fi
echo "Processed $processed files."
echo "Removed $removed files."

#!/bin/bash

# Directory Traversal
# DFS and BFS

# examples for traversal (of a filesystem)

# DFS (depth-first search)

#function traversal(){
#	echo "$1"
#	# checks if entry is not a directory
#	if [ ! -d "$1" ]; then
#		return
#	fi
#	
#	# checks if directory is empty
#	# use ls | wc -l to check number of lines in directory!
#	if [ `ls "$1" | wc -l` -eq 0 ]; then
#		return
#	fi
#	#recursive
#	entries=("$1"/*) # store all files in this array, the first command line argument will be the directory
#	for entry in "${entries[@]}"; do
#		traversal "$entry"
#	done
#}
#traversal "$1"

# BFS (breadth-first search)

# now non-recursive

#queue[0]="$1" # storing command-line argument

#while [ "${#queue[@]}" -ne 0 ]; do # check if length of array is not 0
#	echo "${queue[0]}"
#	if [ -d "${queue[0]}" ] && [ `ls "${queue[0]}" | wc -l` -ne 0 ]; then # if index 0 of queue is a directory and it is not empty, execute
#		entries=("${queue[0]}/*") # stores subdirectories in entries
#		
#		queue=("${queue[@]}" "${entries[@]}") # combine arrays
#	fi
#	queue=(${queue[@]:1}) # remove element at position 0
#done


# write bash script that traverses a directory and its sub-diretories recursively and searches for a file with a specified name.
# script should accept two command-line arguments: directory path to traverse, filename to search for
DIR="$1"
TARGET="$2"

function traversal(){
	current="$1"
       # checks if entry is not a directory
       if [ ! -d "$current" ]; then
                if [ -f "$current" ] && [ $(basename "$current") = "$TARGET" ]; then
			echo "Found at: "
			echo "$current"
		fi 
		return
       fi
         
       # checks if directory is empty
       # use ls | wc -l to check number of lines in directory!
       if [ `ls "$current" | wc -l` -eq 0 ]; then
               return
       fi
	
       #recursive
       entries=("$current"/*) # store all files in this array, the first command line argume>
       for entry in "${entries[@]}"; do
               traversal "$entry"
       done
}
traversal "$DIR"


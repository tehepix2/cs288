#!/bin/bash

# if condition

#if [ expression ]; then  #write these properly with spaces or else bash will touch you
	#statements
#elif [ expression ]; then
	#statements
#else:
	#statements
#fi

# -eq checks if equal
# -ge checks if number is greater than or equal to
# -le checks if number is less than or equal to
# -gt checks if number is greater than
# -lt checks if number is less than

#read num
#if [ $num -eq 10 ]; then
	#echo "correct"
#else
	#echo "no"
#fi


# comparing strings
# = compare if strings are equal
# != compare if strings are not equal
# -n evaluate if string length > 0
# -z evaluate if string length = 0

#read string
#if [ $string = "hello" ]; then
	#echo "hello there"
#else
#	echo "no manners bro"
#fi
#
#if [ -n "$string" ]; then # put quotes around variable here incase string has spaces
#	echo "length > 0"
#else
#	echo "length is not > 0"
#fi

# working with files, directories and perms
# -e check if file/path name exists
# -d check if path given is directory
# -f check if path given is a file
# -r check if read perms is set for file/directory
# -s check if file has length > 0
# -w check if write permissions exist for file/directory
# -x check if execute permissions exist for file/directory

#read -p "enter filename: " filename
# -p prints the test in the terminal, the 4th argument creates variable filename and stores the input

#if [ -f "$filename" ]; then
#	echo "file exists"
#else
#	echo "file dne"
#fi

#if [ -x "$filename" ]; then # -x checks owner perms by default.
#	echo "can execute."
#else
#	echo "cannot execute."
#fi

#if [ -f "$filename" ] && [ -r "$filename" ]; then # [ -f "$filename" -a -r "$filename" ] is the same
#	echo "exists and can read"
#else
#	echo "cooked"
#fi

# you can also set your own exit status
#if [ -f "$filename" ]; then
#	echo "exists."
#	exit 10
#else
#	echo "dne."
#	exit 1
#fi

# for loops
for x in one two three four; do
	echo $x
done

for y in {1..5}; do
	echo $y
done

# can also write in c-style

for(i=0;i<10;i++){
	echo $i
}

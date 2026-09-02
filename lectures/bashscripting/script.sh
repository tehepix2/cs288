#!/bin/bash

#echo "Hello world!"

var="hello"
var2="hello world!"
#echo $var
#echo $var2

#single and double quotes behave differently

#double quotes allow for any variable resolution/substitution.
#single quotes do not allow any variable resolution/substitution.

#echo "the variables stores $var" # double quotes
#echo 'the variables stores $var' # single quotes

#system variables
#echo $?
#echo $USER
#what about operations using integers or other data types??
#EXPANSIONS!!!!!
# Arithemtic expansion
# Variable expansion
# Command expansion
# Brace expansion
# Tilde Expansion
# Filename expansion

# ARITHMETIC $((expression))
#num1=1
#num2=2
#echo $((num1 + num2))

# VARIABLE (getting length, substring, etc.) use: ${variable}

# get length: ${#variable}
#echo ${#var} # displays length using # before variable

# extract substring: ${var:position:length}
#echo ${var:2:5} # give me the first 5 characters starting from index two.
#echo ${var:3} # give me all characters starting from index 3 
# no negative indexes.

# COMMAND EXPANSION: store output of a command into a variable
# syntax: $() or `` (backticks)

#output=`pwd` # execute pwd and store the output into the variable output.
#echo $output

#output2=`cut -f 1 -d : /etc/passwd` # get the first column of the /etc/passwd file seperated by : and store the output into the output2 variable.
#echo $output2

# BRACE EXPANSION: work with ranges
# syntax: {start..end} (cannot use variables inside the braces :( )
#echo {1..10} # give me a range from 1-10 (inclusive)
#echo {a..g} # give me a range from a-g (inclusive)
#start=1
#end=10
#echo {$start..$end} # prints {1..10} lol

#how to do it:
#seq $start $end

# TILDE EXPANSION: replaces the path to the home directory.
# use ~
# echo ~ # prints home directory

# FILENAME EXPANSION: 
# bash scans each word for certain characters: (*, ?, []). if these
# characters appear in any word, bash treats it as a pattern. (regex)
# replaces all the files.directories matching the pattern
# * replaces any char or any length including null (empty string)
# ? replaces with any single char.
# [] replaces with any single char enclosed within 

echo sc* # displays all files that start with sc (such as script, scramble, etc.)

echo ho* # displays all files that start with ho (such as homes, hoes, hobos, etc.)

echo home?.txt # looks for a single character after home and before .txt

echo home[135].txt  # looks for any single character within braces, so will look for home1, home3, and home5



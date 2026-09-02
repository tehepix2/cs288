#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <number1> <number2> ... <numberN>"
    exit 1
fi

arr=("$@")
n=${#arr[@]}

echo "Original array: ${arr[@]}"

i=0
while [ $i -lt $n ]; do
    j=0
    while [ $j -lt $((n - i - 1)) ]; do
        if [ ${arr[$j]} -gt ${arr[$((j + 1))]} ]; then
            temp=${arr[$j]}
            arr[$j]=${arr[$((j + 1))]}
            arr[$((j + 1))]=$temp
        fi
        j=$((j + 1))
    done
    i=$((i + 1))
done

echo "Sorted array: ${arr[@]}"

#!/bin/bash
count=$1
if ! [[ "$count" =~ ^[0-9]+$ ]] || (( count < 1 || count > 20 )); then
echo "Count must be an integer between 1 and 20." >&2
exit 1
fi
rm -f input your_output standard_output
echo "================== input ======================"
for (( i=0; i<count; i++ )); do
echo $((RANDOM-16384))
done | tee input
echo "============= execution result ================"
# read each line as exactly one argument, then pass on the command line
mapfile -t values < input
./31694083_1.c "${values[@]}" | tee your_output
sort -n input > standard_output
echo "====== differences from correct result ======="
diff your_output standard_output

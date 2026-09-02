#!/bin/bash
count=$1
if ! [[ "$count" =~ ^[0-9]+$ ]] || (( count < 1 || count > 100 )); then
echo "Count must be an integer between 1 and 100." >&2
exit 1
fi
rm -f input your_output standard_output
echo "================== input ======================"
for (( i=0; i<count; i++ )); do
# combine two RANDOMs; bash RANDOM alone only reaches 32767
hundredths=$(( (RANDOM*32768 + RANDOM) % 200001 - 100000 ))
if (( hundredths < 0 )); then
m=$(( -hundredths ))
printf -- "-%d.%02d\n" $(( m/100 )) $(( m%100 ))
else
printf "%d.%02d\n" $(( hundredths/100 )) $(( hundredths%100 ))
fi
done | tee input
echo "============= execution result ================"
mapfile -t values < input
./31694083_2.c "${values[@]}" | tee your_output
sort -g input > standard_output
echo "====== differences from correct result ======="
diff your_output standard_output
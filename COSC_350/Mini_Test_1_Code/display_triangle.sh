#!/usr/bin/bash
# this task displays a triangle

echo -n "Enter base of a triangle shape: "
read base
let even=base%2
if [ $even = 0 ] || [ $base -lt 3 ]; then
	echo "expecting odd number"
	exit 1
fi

let height=($base-1)/2+1
let skip=$height-1

# display upper half of Diamond
for i in $(seq 1 $height);
do
	let star=2*i-1
	for j in $(seq 1 $skip)
	do
		echo -n " "
	done
	for j in $(seq 1 $star)
	do
		echo -n "*"
	done
	echo ""
	let skip--
done
exit 0

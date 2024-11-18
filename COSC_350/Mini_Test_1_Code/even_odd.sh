#!/usr/bin/bash

# Check if any arguments are provided
if [ $# -eq 0 ]; then
	echo "Error: No arguments provided."
	exit 1
fi

# initialize counters for even and odd numbers
evenCount=0
oddCount=0

# Loop through all the command-line arguments

for num in "$@"; do
	# Use the modulo operator with `let` for checking even/odd
	let "remainder = num % 2"
	if [ $remainder -eq 0 ]; then
		let "evenCount++"
	else
		let "oddCount++"
	fi
done

# Display the results
echo "Even numbers: $evenCount"
echo "Odd numbers: $oddCount"
exit 0

#!/bin/bash

fibonacci() {
	if [ $1 -le 0 ]; then
		echo 0
	elif [ $1 -eq 1 ]; then
		echo 1
	else
		a=$(fibonacci $(( $1 - 1)))
		b=$(fibonacci $(( $1 - 2)))
		echo $(( a + b ))
	fi
}

number=10
result=$(fibonacci $number)
echo "Fibonacci of $number is: $result"

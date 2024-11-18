#!/bin/bash

function fibonacci() 
{
	if [ $1 -eq 0 ]; then
		echo 0
	elif [ $1 -eq 1 ]; then 
		echo 1
	else
		a=$(fibonacci $(($1-1)))
		b=$(fibonacci $(($1-2)))
		echo $(( a +  b))
	fi
}

n=5
result=$(fibonacci $n)
echo "result: $result"

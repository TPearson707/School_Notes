#!/bin/bash

factorial()
{
	if [ $1 -le 1 ]; then
		echo 1
	else
		prev=$(factorial$(($1-1)))
		echo $(($1*prev))
	fi
}

sum_factorials()
{
	fact1=$(factorial $1)
	fact2=$(factorial $2)
	let "sum=fact1+fact2"
	echo "$sum"
	
}

num1=5
num2=2

result=$(sum_factorials $num1 $num2)

echo "Sum of factorials of $num1 and $num2 is: $result"

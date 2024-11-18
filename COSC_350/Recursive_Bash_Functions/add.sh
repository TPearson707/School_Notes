#!/bin/bash

function add() {
	local a=`expr $1 + $2`
	return $a
}

function subtract() {
	shift
	local a=`expr $1 - $2`
	return $a
}

subtract 4 2 10
a=$?
echo "$0: $a "



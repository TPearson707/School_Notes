#!/usr/bin/bash
for filename in *; do
	case $filename in
		*.c ) gcc -c "$filename" ;;
		*.cpp ) g++ -c "$filename" ;;
		*.txt ) cat "$filename" ;;
		*) echo "$filename is not c, c++, or text code"
	esac
done
exit 0

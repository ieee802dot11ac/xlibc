#!/usr/bin/sh

for file in $(find src -name "*.c"); do
		gcc -g -c -o $(printf "%s%s%s" "obj/" $(basename $file .c) ".o") $file
done

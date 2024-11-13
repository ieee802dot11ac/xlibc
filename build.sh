#!/usr/bin/sh

mkdir -p obj
mkdir -p bin
for file in $(find src -name "*.c"); do
		gcc -g -c -o $(printf "obj/%s.o" $(basename $file .c)) $file
done

gcc -fPIC -shared -o bin/xlibc.so

#!/usr/bin/env bash

if [ $# -lt 1 ]; then
	echo "file name?"
	exit 1
fi

NAME="$1"

make compile
./build/e ./example/${NAME}.m
cp ./example/${NAME}.s object
cd object
make
./asm ${NAME}.s
./machine ${NAME}.o
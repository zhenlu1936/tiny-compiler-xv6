#!/usr/bin/env bash

if [ $# -lt 1 ]; then
	echo "Please enter file name."
	exit 1
fi

NAME="$1"

make compile TARGET=${NAME}
cp examples/${NAME}.s xv6-riscv/user/test_tinyc.s

cd xv6-riscv
make qemu
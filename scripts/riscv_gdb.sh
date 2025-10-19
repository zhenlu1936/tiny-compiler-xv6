#!/bin/bash

PROGRAM=./examples/test.o

if [[ "$1" == "1" ]]; then
    echo "Starting QEMU for RISC-V program in debug mode..."
    qemu-riscv32 -g 1234 $PROGRAM &
    qemu_pid=$!
    echo "QEMU started in background with PID: $qemu_pid. Waiting for GDB connection on port 1234."
    sleep 1
    gdb-multiarch -x ./scripts/gdb_commands.txt $PROGRAM
    if ps -p $qemu_pid > /dev/null; then
        echo "Killing QEMU with PID $qemu_pid."
        kill $qemu_pid
    fi
else
    echo "Running QEMU for RISC-V program (no debug)..."
    qemu-riscv32 $PROGRAM
fi

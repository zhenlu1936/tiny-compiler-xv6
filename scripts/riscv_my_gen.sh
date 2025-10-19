make compile
riscv-none-elf-gcc -march=rv32im -mabi=ilp32 -O0 ./examples/test.s -o ./examples/test.o
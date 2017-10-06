LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c swap.c
	 gcc -c main.c
	 gcc -o swap.exe swap.o main.o $(LIB)

test_swap: clean
	 gcc -c swap.c
	 gcc -c test_swap.c
	 gcc -o test_swap.exe swap.o test_swap.o
	 ./test_swap.exe

test:	 test_swap

clean:
	 rm *.out *.o *.exe || exit 0

swap: clean
	 gcc -c swap.c
	 gcc -c main.c
	 gcc -o swap.exe swap.o main.o $(LIB)

run: swap
	 ./swap.exe

runtest: swap
	 ./integrationtest.tcl ./swap.exe


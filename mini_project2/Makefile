LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c sum-two-integers.c
	 gcc -c main.c
	 gcc -o sum-two-integers.exe sum-two-integers.o main.o $(LIB)

test_sum-two-integers: clean
	 gcc -c sum-two-integers.c
	 gcc -c test_sum-two-integers.c
	 gcc -o test_sum-two-integers.exe sum-two-integers.o test_sum-two-integers.o
	 ./test_sum-two-integers.exe

test:	 test_sum-two-integers

clean:
	 rm *.out *.o *.exe || exit 0

sum-two-integers: clean
	 gcc -c sum-two-integers.c
	 gcc -c main.c
	 gcc -o sum-two-integers.exe sum-two-integers.o main.o $(LIB)

run: sum-two-integers
	 ./sum-two-integers.exe

runtest: sum-two-integers
	 ./integrationtest.tcl ./sum-two-integers.exe


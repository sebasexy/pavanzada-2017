LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c operations.c
	 gcc -c main.c
	 gcc -o operations.exe operations.o main.o $(LIB)

test_operations: clean
	 gcc -c operations.c
	 gcc -c test_operations.c
	 gcc -o test_operations.exe operations.o test_operations.o
	 ./test_operations.exe

test:	 test_operations

clean:
	 rm *.out *.o *.exe || exit 0

operations: clean
	 gcc -c operations.c
	 gcc -c main.c
	 gcc -o operations.exe operations.o main.o $(LIB)

run: operations
	 ./operations.exe

runtest: operations
	 ./integrationtest.tcl ./operations.exe


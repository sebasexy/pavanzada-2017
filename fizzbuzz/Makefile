LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c kata5.c
	 gcc -c main.c
	 gcc -o kata5.exe kata5.o main.o $(LIB)

test_kata5: clean
	 gcc -c kata5.c
	 gcc -c test_kata5.c
	 gcc -o test_kata5.exe kata5.o test_kata5.o
	 ./test_kata5.exe

test:	 test_kata5

clean:
	 rm *.out *.o *.exe || exit 0

kata5: clean
	 gcc -c kata5.c
	 gcc -c main.c
	 gcc -o kata5.exe kata5.o main.o $(LIB)

run: kata5
	 ./kata5.exe

runtest: kata5
	 ./integrationtest.tcl ./kata5.exe


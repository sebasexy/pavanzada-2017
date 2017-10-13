LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c qsort.c
	 gcc -c main.c
	 gcc -o qsort.exe qsort.o main.o $(LIB)

test_qsort: clean
	 gcc -c qsort.c
	 gcc -c test_qsort.c
	 gcc -o test_qsort.exe qsort.o test_qsort.o
	 ./test_qsort.exe

test:	 test_qsort

clean:
	 rm *.out *.o *.exe || exit 0

qsort: clean
	 gcc -c qsort.c
	 gcc -c main.c
	 gcc -o qsort.exe qsort.o main.o $(LIB)

run: qsort
	 ./qsort.exe

runtest: qsort
	 ./integrationtest.tcl ./qsort.exe


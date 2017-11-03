LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c threads.c
	 gcc -c main.c
	 gcc -o threads.exe threads.o main.o $(LIB)

test_threads: clean
	 gcc -c threads.c
	 gcc -c test_threads.c
	 gcc -o test_threads.exe threads.o test_threads.o
	 ./test_threads.exe

test:	 test_threads

clean:
	 rm *.out *.o *.exe || exit 0

threads: clean
	 gcc -c threads.c
	 gcc -c main.c
	 gcc -o threads.exe threads.o main.o $(LIB)

run: threads
	 ./threads.exe

runtest: threads
	 ./integrationtest.tcl ./threads.exe


LIB := $(shell find ./lib -name '*libpcre2-8.a')
all:
	 gcc -c pcre.c
	 gcc -c main.c
	 gcc -o pcre.exe pcre.o main.o $(LIB)

test_pcre: clean
	 gcc -c pcre.c
	 gcc -c test_pcre.c
	 gcc -o test_pcre.exe pcre.o test_pcre.o
	 ./test_pcre.exe

test:	 test_pcre

clean:
	 rm *.out *.o *.exe || exit 0

pcre: clean
	 gcc -c pcre.c
	 gcc -c main.c
	 gcc -o pcre.exe pcre.o main.o $(LIB)

run: pcre
	 ./pcre.exe

runtest: pcre
	 ./integrationtest.tcl ./pcre.exe

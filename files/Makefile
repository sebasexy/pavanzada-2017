LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c texto.c
	 gcc -c main.c
	 gcc -o texto.exe texto.o main.o $(LIB)

test_texto: clean
	 gcc -c texto.c
	 gcc -c test_texto.c
	 gcc -o test_texto.exe texto.o test_texto.o
	 ./test_texto.exe

test:	 test_texto

clean:
	 rm *.out *.o *.exe || exit 0

texto: clean
	 gcc -c texto.c
	 gcc -c main.c
	 gcc -o texto.exe texto.o main.o $(LIB)

run: texto
	 ./texto.exe

runtest: texto
	 ./integrationtest.tcl ./texto.exe


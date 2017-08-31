all:
	 gcc -c can-compare.c
	 gcc -c main.c
	 gcc -o main can-compare.o main.o

test_can-compare: clean
	 gcc -c can-compare.c
	 gcc -c test_can-compare.c
	 gcc -o test_can-compare.exe can-compare.o test_can-compare.o
	 ./test_can-compare.exe

test:	 test_can-compare

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c can-compare.c
	 gcc -c main.c
	 gcc -o main.exe can-compare.o main.o
	 ./main
#f

all:
	 gcc -c two-sum.c
	 gcc -c main.c
	 gcc -o main two-sum.o main.o

test_two-sum: clean
	 gcc -c two-sum.c
	 gcc -c test_two-sum.c
	 gcc -o test_two-sum.exe two-sum.o test_two-sum.o
	 ./test_two-sum.exe

test:	 test_two-sum

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c two-sum.c
	 gcc -c main.c
	 gcc -o main.exe two-sum.o main.o
	 ./main

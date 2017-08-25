all:
	 gcc -c calculate_days.c
	 gcc -c main.c
	 gcc -o main calculate_days.o main.o

test_calculate_days: clean
	 gcc -c calculate_days.c
	 gcc -c test_calculate_days.c
	 gcc -o test_calculate_days.exe calculate_days.o test_calculate_days.o
	 ./test_calculate_days.exe

test:	 test_calculate_days

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c calculate_days.c
	 gcc -c main.c
	 gcc -o main.exe calculate_days.o main.o
	 ./main

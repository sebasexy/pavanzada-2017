all:
	 gcc -c keyboard.c
	 gcc -c main.c
	 gcc -o main keyboard.o main.o

test_keyboard: clean
	 gcc -c keyboard.c
	 gcc -c test_keyboard.c
	 gcc -o test_keyboard.exe keyboard.o test_keyboard.o
	 ./test_keyboard.exe

test:	 test_keyboard

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c keyboard.c
	 gcc -c main.c
	 gcc -o main.exe keyboard.o main.o
	 ./main

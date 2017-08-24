CC=gcc
CFLAGS=-I.
DEPS = word-len.h
OBJ = word-len.o word-len-main.o
#Sirve porfis
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

word-len.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o *.exe

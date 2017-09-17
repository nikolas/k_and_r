CC=gcc

all: 4-1.exe 4-2.exe

4-1.exe: 4-1.o
	$(CC) 4-1.c -o $@

4-2.exe: 4-2.o
	$(CC) -lm 4-2.c -o $@

.PHONY: clean all
clean:
	rm -f *.o *.exe

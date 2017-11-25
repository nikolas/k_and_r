CC=gcc

all: 5-1.exe 5-2.exe 5-3.exe

5-1.exe: 5-1.o
	$(CC) 5-1.c -o $@

5-2.exe: 5-2.o
	$(CC) 5-2.c -o $@

5-3.exe: 5-3.o
	$(CC) 5-3.c -o $@

.PHONY: clean all
clean:
	rm -f *.o *.exe

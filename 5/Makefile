CC=gcc

all: 5-1.exe 5-2.exe 5-3.exe 5-4.exe 5-5.exe 5-7.exe

5-1.exe: 5-1.o
	$(CC) 5-1.c -o $@

5-2.exe: 5-2.o
	$(CC) 5-2.c -o $@

5-3.exe: 5-3.o
	$(CC) 5-3.c -o $@

5-4.exe: 5-4.o
	$(CC) 5-4.c -o $@

5-5.exe: 5-5.o
	$(CC) 5-5.c -o $@

5-7.exe: 5-7.o alloc.o getlinef.o
	$(CC) 5-7.c -o $@ alloc.o getlinef.o

.PHONY: clean all
clean:
	rm -f *.o *.exe

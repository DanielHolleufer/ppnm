CC = gcc
CFLAGS = -O -Wall -std=gnu17
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: main.o
	$(CC) $(CFLAGS) -o main main.o $(LDLIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean
clean:
	$(RM) *.o main out.txt latex.aux latex.log latex.out
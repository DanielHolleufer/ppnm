CC = gcc
CFLAGS = -Wall -O -std=gnu11
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: epsilon
	./epsilon > out.txt

epsilon: epsilon.o equal.o
	$(CC) -o epsilon epsilon.o equal.o $(LDLIBS)

epsilon.o: epsilon.c
	$(CC) $(CFLAGS) -c -fwrapv epsilon.c

equal.o: equal.c
	$(CC) $(CFLAGS) -c equal.c

.PHONY: clean
clean:
	$(RM) *.o epsilon out.txt


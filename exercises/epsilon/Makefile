CC = gcc
CFLAGS = -O -std=gnu11
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: epsilon
	./epsilon > out.txt

epsilon: epsilon.o
	$(CC) -o epsilon epsilon.o $(LDLIBS)

epsilon.o: epsilon.c
	$(CC) $(CLFAGS) -c -fwrapv epsilon.c

.PHONY: clean
clean:
	$(RM) epsilon.o epsilon out.txt


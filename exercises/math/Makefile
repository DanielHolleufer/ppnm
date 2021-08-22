CC = gcc
CFLAGS = -O -std=gnu11
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: math
	./math > out.txt

math: math.o
	$(CC) -o math math.o $(LDLIBS)

math.o: math.c
	$(CC) $(CFLAGS) -c math.c

.PHONY: clean
clean:
	$(RM) math.o math out.txt


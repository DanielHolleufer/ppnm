CC = gcc
CFLAGS = -Wall -std=gnu17
LDLIBS = -lm

default: out-read-cmdline.txt out-read-stdin.txt out-read-file.txt
	cat $^

out-read-cmdline.txt: read-cmdline
	./$< 1 2 3 4 5 > $@

out-read-stdin.txt: read-stdin
	./$< < input.txt > $@

out-read-file.txt: read-file
	./$< input.txt > $@

read-cmdline: read-cmdline.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

read-stdin: read-stdin.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

read-file: read-file.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

read-cmdline.o: read-cmdline.c
	$(CC) $(CFLAGS) -c $^

read-stdin.o: read-stdin.c
	$(CC) $(CFLAGS) -c $^

read-file.o: read-file.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	$(RM) *.o read-cmdline read-stdin read-file out-read-cmdline.txt out-read-stdin.txt out-read-file.txt


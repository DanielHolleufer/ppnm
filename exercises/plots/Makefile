CC = gcc
CFLAGS = `gsl-config --cflags`
CFLAGS = $(shell gsl-config --cflags)
LDLIBS = $(shell gsl-config --libs)

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: main.o
	$(CC) -o main main.o $(LDLIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean
clean:
	$(RM) *.o main out.txt

# Seperate command to clear data to avoid accidentally deleting it
.PHONY: cleandata
cleandata:
	$(RM) errordata.txt gammadata.txt lngammadata.txt

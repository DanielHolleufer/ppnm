CC = gcc 				# The C compiler
CFLAGS = -O -std=gnu11	# options for the C compiler
LDLIBS = -lm 			# Libraries to link

default: out.txt	# Defualt target is to make out.txt
	cat out.txt		# Show out.txt on screen

out.txt: hello			# out.txt needs hello
	./hello > out.txt	# Run hello, output goes into out.txt

hello: hello.o							# hello needs hello.o
	$(CC) -o hello hello.o $(LDLIBS)	# Link hello.o into hello

hello.o: hello.c				# hello.o needs hello.c
	$(CC) $(CFLAGS) -c hello.c	# Compile hello.c

.PHONY: clean
clean:							# clean is a phoney target
	$(RM) hello.o hello out.txt	# Clean up the directory

.PHONY: test
test:				# test target used for debugging
	echo $(LDLIBS)
	echo $(CC)
	echo $(RM)


CFLAGS = -Wall -std=gnu99
LDLIBS = -lm

.PHONY: all clean
all					: out.txt			; cat $<
out.txt				: main				; ./$< > $@
main				: main.o komplex.o	# Built-in linking rule is used here
main.o komplex.o	: komplex.h			# Built-in compiling rule is used here
clean				:					; $(RM) main main.o komplex.o out.txt


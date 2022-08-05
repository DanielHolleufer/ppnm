CFLAGS = -Wall -O1 -std=gnu11
CFLAGS += $(shell gsl-config --cflags)
LDLIBS += $(shell gsl-config --libs)

default: out.txt
	cat out.txt

out.txt:main
	./$< > $@

.PHONEY: clean
clean:
	$(RM) main out.txt

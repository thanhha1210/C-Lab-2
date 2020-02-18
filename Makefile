#
# Makefile that builds btest and other helper programs for the CS:APP data lab
#
CC = gcc
CFLAGS =  -Wall  -g -I./
LIBS = -lm

ptest: ptest.c pointer.c common.c common.h
	$(CC) $(CFLAGS) -Wno-unused-variable -o ptest ptest.c pointer.c common.c

clean:
	rm -f *.o ptest *~

test: ptest
	./ptest

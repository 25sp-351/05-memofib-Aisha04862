all: fibonacci

CC=clang
CFLAGS=-Wall -g

fibonacci: fibonaci.c cache.o
	$(CC) $(CFLAGS) -o $@ $^

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

clean:
	rm -rf *.o *.dSYM fibonacci
.PHONY: clean

CFLAGS=-Wall -Werror -O3 -g

essai_fap: fap.o essai_fap.c
	$(CC) $(CFLAGS) -o $@ $^

varargs: varargs.c
	$(CC) $(CFLAGS) -o $@ $^

fap.o: fap.h

clean:
	rm -rf varargs *.o

CC=gcc
CFLAGS=-Wall -Werror -O3

essai_pile: $(patsubst %.c, %.o, $(wildcard *.c))
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pile.o: pile.h
pile_io.o: pile_io.h pile.h
essai_pile.o: pile.h

clean:
	rm -rf *.o essai_pile

.PHONY: clean

CC=gcc
CFLAGS=-Wall -Werror -O3

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pile.o: pile.h
pile_io.o: pile_io.h pile.h

essai_pile: essai_pile.c pile_io.o pile.o
	$(CC) $(CFLAGS) $^ -o $@


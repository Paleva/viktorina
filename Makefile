CC=gcc
CFLAGS=-I.
DEPS = lib/questions.h lib/gamelogic.h lib/console.h lib/leader.h lib/inputs.h lib/free.h
OBJ = main.o lib/questions.o lib/gamelogic.o lib/console.o lib/leader.o lib/inputs.o lib/free.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

viktorina: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) viktorina

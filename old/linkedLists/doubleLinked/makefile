CC=gcc
BIN=bin
CFILES=linked.c main.c
OBJS=linked.o main.o
HFILES=linked.h
CFLAGS=-std=c11 -Werror -Wpedantic -Wall -Wunused-variable

all: $(BIN)

$(BIN): $(OBJS) $(HFILES)
	$(CC) -o $(BIN) $(OBJS)

%.o: %.c $(HFILES)
	$(CC) $^ $(CFLAGS) -c

run: $(BIN)
	./$(BIN)

clean:
	@echo "Cleaning objs"
	@rm -rf $(OBJS) $(BIN) *.gch

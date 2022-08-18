CC=gcc
CFLAGS=-Wall -Werror -Wpedantic
OPT=-O0
OBJ=main.o link.o
BIN=run
CFILES=main.c link.c

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $(OBJ)

%.o: %.c
	$(CC) %.c -c $(CFLAGS) $(OPT)

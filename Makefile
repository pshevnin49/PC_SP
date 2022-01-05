CC = gcc

CFLAGS = -Wall -Wextra -pedantic -ansi -g
LDFLAGS = $(CFLAGS)

BIN = PC_SP.exe

all: clean $(BIN)

$(BIN): vector.o edge.o node.o bfs.o algorithm.o out_file.o parameters.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

vector.o: vector.c
	$(CC) -c $(CFLAGS) -o $@ $<

edge.o: edge.c
	$(CC) -c $(CFLAGS) -o $@ $<

node.o: node.c
	$(CC) -c $(CFLAGS) -o $@ $<

bfs.o: bfs.c
	$(CC) -c $(CFLAGS) -o $@ $<

algorithm.o: algorithm.c
	$(CC) -c $(CFLAGS) -o $@ $<

out_file.o: out_file.c
	$(CC) -c $(CFLAGS) -o $@ $<

parameters.o: parameters.c
	$(CC) -c $(CFLAGS) -o $@ $<

main.o: main.c
	$(CC) -c $(CFLAGS) -o $@ $<


# on linux use rm -rf 
clean:
	del /F /Q *.o  

CC = gcc

CFLAGS = -Wall # -Wextra -pedantic -ansi -g
LDFLAGS = $(CFLAGS)

BUILD_DIR = build
BIN = PC_SP.exe

all: clean $(BUILD_DIR) $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN): $(BUILD_DIR)/vector.o $(BUILD_DIR)/edge.o $(BUILD_DIR)/node.o $(BUILD_DIR)/ford_fulkerson.o $(BUILD_DIR)/parameters.o $(BUILD_DIR)/main.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/vector.o: src/vector.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/edge.o: src/edge.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/node.o: src/node.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/ford_fulkerson.o: src/ford_fulkerson.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/parameters.o: src/parameters.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/main.o: src/main.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR):
	mkdir $@

# on linux use rm -rf $(BUILD_DIR)
clean:
	del /F /Q $(BUILD_DIR)  

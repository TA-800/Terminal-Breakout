CC = g++
CFLAGS = -Wall -g -lncurses -DNCURSES_STATIC

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# List of all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Generate corresponding object file names
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Main target
all: $(BIN_DIR)/game

# Rule to build the executable
$(BIN_DIR)/game: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(BUILD_DIR)/*.o $(BIN_DIR)/game

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
EXECUTABLE = $(BIN_DIR)/main

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule to handle .cpp files without corresponding .hpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean target
clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLE)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files go into bin/
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC))

# Output binary name
TARGET = $(BIN_DIR)/clox

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile .c files to .o in bin/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BIN_DIR)/*


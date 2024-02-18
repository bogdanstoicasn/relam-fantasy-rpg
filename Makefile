# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = game/obj
LIB_DIR = game/lib
GAME_DIR = game

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Static library
LIBRARY = $(LIB_DIR)/libgame.a

# Main program
MAIN = $(SRC_DIR)/main.c
# Executable
EXECUTABLE = Relam_RPG

.PHONY: all clean

all: $(GAME_DIR)/$(EXECUTABLE)

# Guard to create directories if they don't exist
$(OBJ_DIR) $(LIB_DIR):
	@mkdir -p $@

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(LIBRARY): $(OBJS) | $(LIB_DIR)
	ar rcs $@ $^

# Compile main program
$(GAME_DIR)/$(EXECUTABLE): $(MAIN) $(LIBRARY)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -lgame -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(EXECUTABLE) $(GAME_DIR)

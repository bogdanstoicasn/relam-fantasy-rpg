# Makefile

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRCDIR = src
OBJDIR = game/obj
LIBDIR = game/lib
BINDIR = game

# Source files
ENTITY_SRCS = $(wildcard $(SRCDIR)/entity/*.c)
PROGRESSION_SRCS = $(wildcard $(SRCDIR)/progression/*.c)
MAIN_SRCS = $(SRCDIR)/main.c

# Object files
ENTITY_OBJS = $(patsubst $(SRCDIR)/entity/%.c,$(OBJDIR)/entity/%.o,$(ENTITY_SRCS))
PROGRESSION_OBJS = $(patsubst $(SRCDIR)/progression/%.c,$(OBJDIR)/progression/%.o,$(PROGRESSION_SRCS))
MAIN_OBJ = $(OBJDIR)/main.o

# Static library
LIB = $(LIBDIR)/libgame.a

# Main target
EXECUTABLE = $(BINDIR)/Relam_RPG

.PHONY: all clean run

all: $(LIB) $(EXECUTABLE)

$(LIB): $(ENTITY_OBJS) $(PROGRESSION_OBJS) | $(LIBDIR)
	ar rcs $(LIB) $^

$(EXECUTABLE): $(MAIN_OBJ) $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lgame -o $@

$(OBJDIR)/entity/%.o: $(SRCDIR)/entity/%.c | $(OBJDIR)/entity
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/progression/%.o: $(SRCDIR)/progression/%.c | $(OBJDIR)/progression
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/entity:
	mkdir -p $@

$(OBJDIR)/progression:
	mkdir -p $@

$(OBJDIR) $(LIBDIR) $(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(LIB) $(BINDIR)

run: all
	./$(EXECUTABLE)

# Makefile

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude -MP -MD

# Directories
SRCDIR = src
OBJDIR = game/obj
LIBDIR = game/lib
BINDIR = game

# Source files
ENTITY_SRCS = $(wildcard $(SRCDIR)/entity/*.c)
LOAD_SRCS = $(wildcard $(SRCDIR)/load/*.c)
PROGRESSION_SRCS = $(wildcard $(SRCDIR)/progression/*.c)
MAIN_SRCS = $(SRCDIR)/main.c

# Object files
ENTITY_OBJS = $(patsubst $(SRCDIR)/entity/%.c,$(OBJDIR)/entity/%.o,$(ENTITY_SRCS))
LOAD_OBJS = $(patsubst $(SRCDIR)/load/%.c,$(OBJDIR)/load/%.o,$(LOAD_SRCS))
PROGRESSION_OBJS = $(patsubst $(SRCDIR)/progression/%.c,$(OBJDIR)/progression/%.o,$(PROGRESSION_SRCS))
MAIN_OBJ = $(OBJDIR)/main.o

# Dependency files
DEP_FILES = $(ENTITY_OBJS:.o=.d) $(LOAD_OBJS:.o=.d) $(PROGRESSION_OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

# Static library
LIB = $(LIBDIR)/libgame.a

# Main target
EXECUTABLE = $(BINDIR)/Relam_RPG

.PHONY: all clean run run_valgrind

all: $(LIB) $(EXECUTABLE)

-include $(DEP_FILES)

$(LIB): $(ENTITY_OBJS) $(LOAD_OBJS) $(PROGRESSION_OBJS) | $(LIBDIR)
	ar rcs $(LIB) $^

$(EXECUTABLE): $(MAIN_OBJ) $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lgame -o $@

$(OBJDIR)/entity/%.o: $(SRCDIR)/entity/%.c | $(OBJDIR)/entity
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/load/%.o: $(SRCDIR)/load/%.c | $(OBJDIR)/load
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/progression/%.o: $(SRCDIR)/progression/%.c | $(OBJDIR)/progression
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/entity:
	mkdir -p $@

$(OBJDIR)/load:
	mkdir -p $@

$(OBJDIR)/progression:
	mkdir -p $@

$(OBJDIR) $(LIBDIR) $(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(LIB) $(BINDIR)

clean_all: clean
	rm -rf $(DEP_FILES)

run: all
	./$(EXECUTABLE)

run_valgrind: all
	valgrind -s ./$(EXECUTABLE)

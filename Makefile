# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude -MP -MD
# SDL2 libraries
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Directories
SRCDIR = src
OBJDIR = game/obj
LIBDIR = game/lib
BINDIR = game

# Source files
ENTITY_SRCS = $(wildcard $(SRCDIR)/entity/*.c)
GRAPHICS_SRCS = $(wildcard $(SRCDIR)/graphics/*.c)
LOAD_SRCS = $(wildcard $(SRCDIR)/load/*.c)
PROGRESSION_SRCS = $(wildcard $(SRCDIR)/progression/*.c)
MAIN_SRCS = $(SRCDIR)/main.c

# Object files
ENTITY_OBJS = $(patsubst $(SRCDIR)/entity/%.c,$(OBJDIR)/entity/%.o,$(ENTITY_SRCS))
GRAPHICS_OBJS = $(patsubst $(SRCDIR)/graphics/%.c,$(OBJDIR)/graphics/%.o,$(GRAPHICS_SRCS))
LOAD_OBJS = $(patsubst $(SRCDIR)/load/%.c,$(OBJDIR)/load/%.o,$(LOAD_SRCS))
PROGRESSION_OBJS = $(patsubst $(SRCDIR)/progression/%.c,$(OBJDIR)/progression/%.o,$(PROGRESSION_SRCS))
MAIN_OBJ = $(OBJDIR)/main.o

# Dependency files
DEP_FILES = $(ENTITY_OBJS:.o=.d) $(GRAPHICS_OBJS:.o=.d) $(LOAD_OBJS:.o=.d) $(PROGRESSION_OBJS:.o=.d) $(MAIN_OBJ:.o=.d)

# Static library
LIB = $(LIBDIR)/libgame.a

# Main target
EXECUTABLE = $(BINDIR)/Relam_RPG

.PHONY: all clean run run_valgrind

all: $(LIB) $(EXECUTABLE)

-include $(DEP_FILES)

$(LIB): $(ENTITY_OBJS) $(GRAPHICS_OBJS) $(LOAD_OBJS) $(PROGRESSION_OBJS) | $(LIBDIR)
	ar rcs $(LIB) $^

$(EXECUTABLE): $(MAIN_OBJ) $(LIB) | $(BINDIR)
	$(CC) $(CFLAGS) $< -L$(LIBDIR) -lgame $(LIBS) -o $@

$(OBJDIR)/entity/%.o: $(SRCDIR)/entity/%.c | $(OBJDIR)/entity
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/graphics/%.o: $(SRCDIR)/graphics/%.c | $(OBJDIR)/graphics
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(OBJDIR)/load/%.o: $(SRCDIR)/load/%.c | $(OBJDIR)/load
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/progression/%.o: $(SRCDIR)/progression/%.c | $(OBJDIR)/progression
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRCS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/entity:
	mkdir -p $@

$(OBJDIR)/graphics:
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
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

run_valgrind_file: all
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=valgrind.log ./$(EXECUTABLE)
# valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --log-file=supdata.log ./prog.out
# Command above for supression of errors

CC = gcc
CFLAGS = -I./structs -I./menus/admin -I./menus/admin/menues -Wall -g

# Source files
SRC = main.c \
      menus/admin/menuadmin.c \
      menus/admin/menues/crudprof.c \
      menus/admin/menues/crudparent.c \
      menus/admin/menues/crudnotes.c \
      menus/prof/menuprof.c

# Object files - automatically create object files based on the source file paths
OBJ = $(SRC:%.c=%.o)

# Output executable name
OUT = main

# Default target (build the project)
all: $(OUT)

# Link object files into the final executable
$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OUT) $(OBJ)

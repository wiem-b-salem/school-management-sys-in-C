# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable name
TARGET = admin_app

# Source files
SRCS = src/main.c \
  src/messages.c \
 src/admin/menuadmin.c \
  src/admin/crudenseignant.c \
  src/admin/crudparent.c \
  src/admin/crudnotes.c \
  src/admin/crudeleve.c \
  src/admin/crudnouveaute.c \
  src/admin/crudemploi.c \
  src/admin/crudclasse.c \
  src/admin/crudevenement.c \
  src/admin/crudcours.c \
  src/admin/crudclub.c\
  src/admin/gererprofile.c\
 src/enseignant/menuenseignant.c \
  src/enseignant/gererprofile.c \
  src/enseignant/crudabsence.c \
  src/enseignant/crudevenementens.c \
  src/enseignant/nouveauteenseignant.c \
 src/parent/menuparent.c \
  src/parent/nouveauteparent.c \
  src/parent/gererprofileetudiant.c \
  src/parent/gererprofileparent.c
# Object files (replace .c with .o for each source file)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to build object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: all
	./$(TARGET)

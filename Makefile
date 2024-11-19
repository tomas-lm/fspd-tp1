# Variables
CC = g++
CFLAGS = -Wall -Wextra -Iinclude -pthread
SRCDIR = src
BUILDDIR = build
INCLUDEDIR = include
TARGET = program

# Source and Object Files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/threads.cpp $(SRCDIR)/passa_tempo.cpp $(SRCDIR)/salas.cpp $(SRCDIR)/utils.cpp $(SRCDIR)/trajeto.cpp
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Default Target
all: $(TARGET)

# Build Target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Ensure Build Directory Exists
$(OBJECTS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Compile Object Files with Dependencies
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(INCLUDEDIR)/threads.hpp $(INCLUDEDIR)/passa_tempo.hpp $(INCLUDEDIR)/salas.hpp $(INCLUDEDIR)/trajeto.hpp $(INCLUDEDIR)/utils.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/threads.o: $(SRCDIR)/threads.cpp $(INCLUDEDIR)/threads.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/passa_tempo.o: $(SRCDIR)/passa_tempo.cpp $(INCLUDEDIR)/passa_tempo.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/salas.o: $(SRCDIR)/salas.cpp $(INCLUDEDIR)/salas.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/trajeto.o: $(SRCDIR)/trajeto.cpp $(INCLUDEDIR)/trajeto.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/utils.o: $(SRCDIR)/utils.cpp $(INCLUDEDIR)/utils.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)

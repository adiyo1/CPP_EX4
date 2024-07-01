# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Executable name
EXEC = tree_example

# Source files
SOURCES = main.cpp Complex.cpp Tree.cpp

# Header files
HEADERS = Tree.hpp Node.hpp Complex.hpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXEC)

# Phony targets
.PHONY: all clean

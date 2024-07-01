# # Compiler
# CXX = g++

# # Compiler flags
# CXXFLAGS = -std=c++17 -Wall

# # SFML libraries
# SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# # Executable name
# EXEC = tree_example

# # Source files
# SOURCES = main.cpp Complex.cpp Tree.cpp

# # Header files
# HEADERS = Tree.hpp Node.hpp Complex.hpp

# # Object files
# OBJECTS = $(SOURCES:.cpp=.o)

# # Default target
# all: $(EXEC)

# # Link object files to create executable
# $(EXEC): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# # Compile source files to object files
# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $<

# # Clean up build files
# clean:
# 	rm -f $(OBJECTS) $(EXEC)

# # Phony targets
# .PHONY: all clean


#id:324207935 email:shbabkoff123@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES = main.cpp Complex.cpp TestCounter.cpp Test.cpp
OBJECTS = $(SOURCES:.cpp=.o)

tree: main
	./$^

main: main.o Complex.o
	$(CXX) $(CXXFLAGS) $^ -o main $(SFML_FLAGS)

test: TestCounter.o Test.o Complex.o
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main test
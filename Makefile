# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = main.cc cli/cli.cc
OBJ = $(SRC:.cc=.o)
TARGET = hazmat

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
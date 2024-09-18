# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++26 -Wall -Wextra -pedantic

# Directories
BUILD_DIR := build
SRC_DIR := .

# Find all .cc files recursively, excluding .git and .vscode directories
SRCS := $(shell find $(SRC_DIR) -type d \( -name .git -o -name .vscode \) -prune -o -name '*.cc' -print)

# Generate object file names
OBJS := $(SRCS:%.cc=$(BUILD_DIR)/%.o)

# Executable name
TARGET := hazmat

# Default target
all: $(TARGET)

# Rule to create build directories
$(BUILD_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run rule
run: $(TARGET)
	./$(TARGET)

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	find . -type f -name '*~' -delete
	find . -type f -name '*.o' -delete

.PHONY: all clean run

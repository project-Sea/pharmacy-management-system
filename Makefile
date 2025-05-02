# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall

# Library for MySQL
LIBS = -lmysqlcppconn

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files and target output
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/pharmacy

# Default target to build the project
all: $(TARGET)

# Create directories if they don't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

# Rule to compile .cpp files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and the target executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# PHONY targets (don't correspond to files)
.PHONY: all clean


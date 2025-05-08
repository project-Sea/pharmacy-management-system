# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Idb -std=c++17

# Linker flags for MySQL Connector/C++
MYSQL_INC = -IC:/mysql-connector-c++-9.3.0-winx64/include
MYSQL_LIB = -LC:/mysql-connector-c++-9.3.0-winx64/lib64
MYSQL_LINK = -lmysqlcppconn8

# Directories
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/pharmacy

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(MYSQL_INC) -o $@ $^ $(MYSQL_LIB) $(MYSQL_LINK)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(MYSQL_INC) -c $< -o $@

run: all
	$(TARGET)

clean:
	del /Q $(OBJ_DIR)\*.o $(TARGET).exe 2>nul || exit 0

.PHONY: all clean run



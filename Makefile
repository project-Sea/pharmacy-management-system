CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -Iinclude/mysql

LDFLAGS := -Llib -lmysql

SRCS := main.cpp src/db_connection.cpp src/src.cpp src/ui.cpp src/sales.cpp src/expiryF.cpp src/medicine.cpp src/expenses.cpp src/reports.cpp
TARGET := main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

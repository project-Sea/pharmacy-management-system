-.RECIPEPREFIX = >
 CXX := g++
 CXXFLAGS := -std=c++17 -Iinclude -Iinclude/mysql
 LDFLAGS := -Llib -lmysql

 all: $(TARGET)

 $(TARGET): $(SRCS)
-    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)
+	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

 clean:
-    rm -f $(TARGET)
+	rm -f $(TARGET)

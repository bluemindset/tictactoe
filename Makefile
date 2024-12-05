# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.

# Source and object files
SRCS = main.cpp utils/utils.cpp tiktak/tik.cpp
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = app

# Build the application
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS)

# Run the application
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: clean

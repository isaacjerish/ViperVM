CXX      := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++17 -g
TARGET   := vipervm
SRC      := $(wildcard *.cpp)
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
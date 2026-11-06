CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Isrc
SRC      := $(shell find src -name '*.cpp')
OBJ      := $(SRC:src/%.cpp=build/%.o)
TARGET   := build/inventory

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean

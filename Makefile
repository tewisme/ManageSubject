#Makefile
CXX = g++
CXXFLAGS = -std=c++20
TARGET = QUAN_LI_MON_HOC
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

all: $(TARGET)

$(OBJ): | obj

#compile and link
obj/%.o: src/%.cpp
	@echo "Compiling $< to $@.."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@echo "Compiling $^ to $@.."
	$(CXX) $(CXXFLAGS) -o $@ $^

#setup command
compile:
	$(OBJ)

link:
	$(TARGET)

run:
	./$(TARGET)

clean:
	del /Q $(TARGET).exe obj\*.o

.PHONY: all compile link run clean

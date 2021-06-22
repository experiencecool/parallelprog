CXX = g++
CXXFLAGS = -O3 -g -std=c++17
PRALLEL = -fopenmp

SRC = main.cpp
EXE_NAME = test.bin
BUILD_FOLDER = ./build/
IMPORTS_AND_LINKS = -lm

.PHONY: build build_parallel

all: clean

clean:
	rm -rf $(BUILD_FOLDER)

build_init: clean
	mkdir $(BUILD_FOLDER)

build:
	$(CXX) $(CXXFLAGS) -o $(BUILD_FOLDER)$(EXE_NAME).seq $(SRC) $(IMPORTS_AND_LINKS)

build_parallel:
	$(CXX) $(CXXFLAGS) $(PRALLEL) -o $(BUILD_FOLDER)$(EXE_NAME).par $(SRC) $(IMPORTS_AND_LINKS)

run: build
	$(BUILD_FOLDER)$(EXE_NAME) 

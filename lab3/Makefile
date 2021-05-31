CXX = g++
CXXFLAGS = -O3 -g -std=c++17
PRALLEL = -fopenmp

SRC = main.cpp
EXE_NAME = test.bin
BUILD_FOLDER = ./build/
# Signal proccesing depends on both: ippcore ippvm
IMPORTS_AND_LINKS = -lm
#-I $IPPROOT/include -L $IPPROOT/lib/intel64 -lippi -lipps -lippcore -lippvm

# BUFFER_EXE_NAME = vector-add-buffers
# BUFFER_SOURCES = src/vector-add-buffers.cpp

# USM_EXE_NAME = vector-add-usm
# USM_SOURCES = src/vector-add-usm.cpp

all: clean
# build_buffers:
# 	$(CXX) $(CXXFLAGS) -o $(BUFFER_EXE_NAME) $(BUFFER_SOURCES)
clean:
	rm -rf $(BUILD_FOLDER)
init_build: clean
	mkdir $(BUILD_FOLDER)
build: init_build
	$(CXX) $(CXXFLAGS) -o $(BUILD_FOLDER)$(EXE_NAME) $(SRC) $(IMPORTS_AND_LINKS)
build_parallel: init_build
	$(CXX) $(CXXFLAGS) $(PRALLEL) -o $(BUILD_FOLDER)$(EXE_NAME) $(SRC) $(IMPORTS_AND_LINKS)
run: build
	$(BUILD_FOLDER)$(EXE_NAME) 
# build_usm:
# 	$(CXX) $(CXXFLAGS) -o $(USM_EXE_NAME) $(USM_SOURCES)

# run: 
# 	./$(BUFFER_EXE_NAME)

# run_usm: 
# 	./$(USM_EXE_NAME)

# clean: 
# 	rm -f $(EXE_NAME) 

# $(USM_EXE_NAME)

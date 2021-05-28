CXX = dpcpp
CXXFLAGS = -O2 -g -std=c++17

SRC = main.cpp ippwrap.cpp
EXE_NAME = ipptest
# Signal proccesing depends on both: ippcore ippvm
IMPORTS_AND_LINKS = -I $IPPROOT/include -L $IPPROOT/lib/intel64 -lippi -lipps -lippcore -lippvm

# BUFFER_EXE_NAME = vector-add-buffers
# BUFFER_SOURCES = src/vector-add-buffers.cpp

# USM_EXE_NAME = vector-add-usm
# USM_SOURCES = src/vector-add-usm.cpp

all: build

# build_buffers:
# 	$(CXX) $(CXXFLAGS) -o $(BUFFER_EXE_NAME) $(BUFFER_SOURCES)
build:
	$(CXX) $(CXXFLAGS) -o $(EXE_NAME) $(SRC) $(IMPORTS_AND_LINKS)

# build_usm:
# 	$(CXX) $(CXXFLAGS) -o $(USM_EXE_NAME) $(USM_SOURCES)

# run: 
# 	./$(BUFFER_EXE_NAME)

# run_usm: 
# 	./$(USM_EXE_NAME)

clean: 
	rm -f $(EXE_NAME) 

# $(USM_EXE_NAME)

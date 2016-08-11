CXX = g++-5
CPPFLAGS = -g -std=c++11 -Wall
SRC = src
INCLUDE = -Iincludes

default: all
all: sorting search tree

sorting:
	@echo "Building Sorting Module"
	$(CXX) $(CPPFLAGS) -o sort $(SRC)/main.cpp $(SRC)/sorting.cpp $(INCLUDE)


search:
	@echo "Building Search Module"
	$(CXX) $(CPPFLAGS) -o search $(SRC)/main.cpp $(SRC)/search.cpp $(INCLUDE)

tree:
	@echo "Building Tree Module"
	$(CXX) $(CPPFLAGS) -o tree $(SRC)/tree.cpp $(INCLUDE)

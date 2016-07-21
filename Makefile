CXX = g++-5
CPPFLAGS = -g -std=c++11 -Wall
LIBS = 

SRC = src
INCLUDE = -Iincludes

default: all


sorting:
	@echo "Building Binary Tree"
	$(CXX) $(CPPFLAGS) -o btree $(SRC)/main.cpp $(SRC)/sorting.cpp $(INCLUDE)


search:
	@echo "Building Binary Tree"
	$(CXX) $(CPPFLAGS) -o btree $(SRC)/main.cpp $(SRC)/search.cpp $(INCLUDE)

btree:
	@echo "Building Binary Tree"
	$(CXX) $(CPPFLAGS) -o btree $(SRC)/btree.cpp $(INCLUDE)

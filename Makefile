CXX := g++-5
CPPFLAGS := -g -std=c++11 -Wall
SRC_DIR := src/
INCLUDE := -Iincludes/

TARGET := dalgo
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=%.o)
RM := $(OBJS) $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -o $@ $^

$(OBJS) : $(SRCS)
	$(CXX) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

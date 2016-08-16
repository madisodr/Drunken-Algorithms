CXX = g++-5
CPPFLAGS = -g -std=c++11 -Wall
SRCDIR = src
BUILDDIR = build

SRCS = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.cpp=.o))

INCLUDE = -I includes

TARGET = dalgo
RM = $(OBJS) $(TARGET)
LIB = 

$(TARGET): $(OBJS)
	@echo "Linking"
	@echo "$(CXX) $^ -o $(TARGET) $(CPPFLAGS) $(LIB)"
	$(CXX) $^ -o $(TARGET) $(CPPFLAGS) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	echo "$(CXX) $(CPPFLAGS) $(INCLUDE) -c -o $@ $^"
	$(CXX) $(CPPFLAGS) $(INCLUDE) -c -o $@ $^

.PHONY: clean
clean:
	echo "Cleaning"
	rm -r $(OBJS) $(BUILDDIR) $(TARGET)

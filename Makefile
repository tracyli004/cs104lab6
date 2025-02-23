# compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp mathfuncs.cpp randfuncs.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = calc

# default i will build the executable
all: $(TARGET)

# then link object files to create the final exec
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
clean:
    rm -f $(OBJS) $(TARGET)


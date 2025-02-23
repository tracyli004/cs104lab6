# compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp mathfuncs.cpp randfuncs.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = calc

# default i will build the executable
all: $(TARGET)



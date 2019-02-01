CXX=g++ -std=c++11
CXXFLAGS=-Wall -pedantic
LDFLAGS=-O3 -ffast-math -Ilib/ -Isrc/include/
LDLIBS=-lm

SRCS=$(shell find src/source/ -name "*.cpp")
OBJS=$(SRCS:.cpp=.o)

#alls:
#	$(CXX) -Wall -pedantic -lm -Ilib/ -Isrc/include/ src/main.cpp src/source/*.cpp -omain && ./main

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) src/main.cpp bin/*.o -omain

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -obin/$(shell basename $< .cpp).o


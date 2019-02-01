CXX=g++ -std=c++11
CXXFLAGS=-Wall -Wreorder -pedantic
LDFLAGS=-ggdb -Ilib/ -Isrc/include/
LDLIBS=-lm

SRCS=$(shell find src/source/ -name "*.cpp")
OBJS=$(SRCS:.cpp=.o)

#alls:
#	$(CXX) -Wall -pedantic -lm -Ilib/ -Isrc/include/ src/main.cpp src/source/*.cpp -omain && ./main

all: main

main: $(OBJS)
	g++ -std=c++11 -Wall -pedantic -lm -Ilib/ -Isrc/include/ src/main.cpp bin/*.o -omain

%.o: %.cpp
	g++ -std=c++11 -Wall -pedantic -Ilib/ -Isrc/include/ -c $< -obin/$(shell basename $< .cpp).o

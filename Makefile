CXX = g++
CXXFLAGS = -std=c++17
PROGRAMS = rrt rrt_debug

all: $(PROGRAMS)

rrt: src/main.cpp src/rrt.cpp src/tree.cpp
	$(CXX) $(CXXFLAGS) -o rrt -I include/ src/main.cpp src/rrt.cpp src/tree.cpp

rrt_debug: src/main.cpp src/rrt.cpp src/tree.cpp
	$(CXX) $(CXXFLAGS) -g -o rrt_debug -I include/ src/main.cpp src/rrt.cpp src/tree.cpp

clean:
	rm -rf $(PROGRAMS) *.dSYM *.map

.PHONY: all clean
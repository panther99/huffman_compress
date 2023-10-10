CXX=g++
INCLUDES=-I includes/
CXXFLAGS=-std=c++20 -O3 -Wall -Wextra -Werror -pedantic $(INCLUDES)
NATIVE=on

test: build/tests.out
	- $<

clean:
	$(RM) build/tests.out build/main.out

build/main.out: src/Main.cpp src/Parser.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

build/tests.out: test/tests.cpp src/Parser.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

src/%.cpp: includes/%.hpp
	touch $@

.DEFAULT_GOAL := build/main.out
.PHONY: clean exec

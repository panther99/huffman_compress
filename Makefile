all:
	$(CXX) -O3 -Os -std=c++20 src/Main.cpp -o build/main

clean:
	$(RM) build/main

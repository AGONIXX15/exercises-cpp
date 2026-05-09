CXX=g++
CFLAG=-std=c++23 -Wall


build:
	@mkdir -p build

compile: build
	$(CXX) $(CFLAG) main.cpp -o build/setcomp

save: compile
	sudo mv build/setcomp ~/.local/bin


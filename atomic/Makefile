CC=g++
CFLAGS= -Wall -Werror -std=c++23
FILES=$(wildcard *.cpp)



run:
	./build/main

build:
	mkdir -p build

compile: build
	$(CC) $(FILES) $(CFLAGS) -o build/main


all: compile run


clear:
	rm -rf build

all:

build:	
	gcc main.c -o simulation
run: build
	./simulation

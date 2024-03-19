all:

build:	
	gcc main.c list.o -o simulation
run: build
	./simulation

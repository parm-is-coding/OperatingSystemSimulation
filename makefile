all:

build:	
	gcc -I HeaderFiles main.c list.o functions.c ipc.c operatingSystem.c scheduler.c semaphore.c pcb.c -o simulation
run: build
	./simulation

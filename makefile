Modules= Modules/helper.c Modules/baseFunctions.c Modules/ipc.c Modules/operatingSystem.c Modules/scheduler.c Modules/semaphore.c Modules/pcb.c

all: build

build:	
	gcc -g -I HeaderFiles main.c $(Modules) list.o -o simulation
run: build
	./simulation

git:
	git add *
	git commit
	git push
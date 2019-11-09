all: randomFile.o
	gcc -o program randomFile.o

randomFile.o: randomFile.c
	gcc -c randomFile.c

run:
	./program

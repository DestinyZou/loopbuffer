main: main.c loopbuffer.o  packages.o
	gcc -o main loopbuffer.o packages.o main.c

loopbuffer.o: loopbuffer.c loopbuffer.h
	gcc -c loopbuffer.c -o loopbuffer.o

packages.o: packages.c packages.h loopbuffer.h
	gcc -c packages.c -o packages.o

clean:
	rm -f packages.o loopbuffer.o

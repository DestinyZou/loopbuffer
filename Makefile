main: main.c loopbuffer.o  packages.o
	gcc -o main  -g loopbuffer.o packages.o main.c

loopbuffer.o: loopbuffer.c loopbuffer.h
	gcc -c -g loopbuffer.c -o loopbuffer.o

packages.o: packages.c packages.h loopbuffer.h
	gcc -c -g packages.c -o packages.o

clean:
	rm -f packages.o loopbuffer.o

CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=exec

all: exec

exec : 	main.o
		gcc -o exec main.o $(CFLAGS)

main.o: main.c 
		gcc -c main.c

clean:
		rm -f *.o

mrproper: clean
		rm -f $(EXEC)
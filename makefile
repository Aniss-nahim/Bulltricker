CC = gcc
CFLAGS = -Wall -O
LDFLAGS =
EXEC = Bulltricker
OBJ =./obj/
TARGETPATH = ./bin/


all: main.o function.o linker

function.o : function.c
			$(CC) -c function.c -o $(OBJ)function.o

main.o : main.c 
			$(CC) -c main.c -o $(OBJ)main.o

mrproper : clear
			rm -f $(TARGETPATH)$(EXEC)

clear : 
		rm -f $(OBJ)*.o 

linker : 
		$(CC) -o $(TARGETPATH)$(EXEC) $(OBJ)main.o $(OBJ)function.o
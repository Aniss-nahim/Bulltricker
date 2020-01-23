#CC specifies which compiler we're using
CC = gcc
#CFLAGS = -Wall -O
LDFLAGS =
EXEC = Bulltricker.exe
OBJECT =./obj/
SOURCE = ./src/
TARGETPATH = ./bin/
MAIN = main.c

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#  # -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl

#Command execution 
all : main.o cli.o action.o queen.o pawn.o king.o bullStack.o linker


action : action.o linker
	
bullStack : bullStack.o linker
	
cli : cli.o linker
	
queen : queen.o linker
	
king : king.o linker
	
main: main.o linker
	
pawn : pawn.o linker
	
action.o :
			$(CC) -c $(SOURCE)action.c -o $(OBJECT)action.o

bullStack.o :
			$(CC) -c $(SOURCE)bullStack.c -o $(OBJECT)bullStack.o

cli.o :
			$(CC) -c $(SOURCE)cli.c -o $(OBJECT)cli.o

queen.o :
			$(CC) -c $(SOURCE)queen.c -o $(OBJECT)queen.o

king.o :
			$(CC) -c $(SOURCE)king.c -o $(OBJECT)king.o

main.o :
			$(CC) -c $(MAIN) -o $(OBJECT)main.o

pawn.o :
			$(CC) -c $(SOURCE)pawn.c -o $(OBJECT)pawn.o

mrproper :
			rm -f $(TARGETPATH)$(EXEC)

clean_o : 
		rm -f $(OBJECT)*.o 

linker : 
		$(CC) -o $(TARGETPATH)$(EXEC) $(OBJECT)*.o

count:
	find src include -name '*.*' | xargs wc -l
	
run :
	$(TARGETPATH)$(EXEC)
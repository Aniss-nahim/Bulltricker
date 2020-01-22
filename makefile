#CC specifies which compiler we're using
CC = gcc
#CFLAGS = -Wall -O
LDFLAGS =
EXEC = Bulltricker.exe
OBJECT =./obj/
SOURCE = ./src/
TARGETPATH = ./bin/
MAIN = main.c

#SDL CONFIG
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#  # -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

#includes for lib SDL2
INCLUDE_PATHS = -IC:\mingwDev\SDL2\include

LIBRARY_PATHS = -LC:\mingwDev\SDL2\lib


#Command execution 
all : main.o cli.o action.o dame.o linker

main: main.o linker
	
cli : cli.o linker
	
action : action.o linker
	
dame : dame.o linker
	
SDLExec :  $(MAIN)
	$(CC) $(MAIN) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

action.o :
			$(CC) -c $(SOURCE)action.c -o $(OBJECT)action.o

dame.o :
			$(CC) -c $(SOURCE)dame.c -o $(OBJECT)dame.o

cli.o :
			$(CC) -c $(SOURCE)cli.c -o $(OBJECT)cli.o

main.o :
			$(CC) -c $(MAIN) -o $(OBJECT)main.o

mrproper : clear
			rm -f $(TARGETPATH)$(EXEC)

clean_o : 
		rm -f $(OBJECT)*.o 

linker : 
		$(CC) -o $(TARGETPATH)$(EXEC) $(OBJECT)*.o

run :
	$(TARGETPATH)$(EXEC)


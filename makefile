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
all: main.o function.o linker

SDLExec :  $(MAIN)
	$(CC) $(MAIN) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

function.o :
			$(CC) -c $(SOURCE)function.c -o $(OBJECT)function.o

main.o :
			$(CC) -c $(MAIN) -o $(OBJECT)main.o

mrproper : clear
			rm -f $(TARGETPATH)$(EXEC)

clear : 
		rm -f $(OBJECT)*.o 

linker : 
		$(CC) -o $(TARGETPATH)$(EXEC) $(OBJECT)main.o $(OBJECT)function.o


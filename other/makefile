#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#  # -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

OBJS = myMain.c
#CC specifies which compiler we're using
CC = gcc

#includes for lib SDL2
INCLUDE_PATHS = -IC:\mingwDev\SDL2\include

LIBRARY_PATHS = -LC:\mingwDev\SDL2\lib

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

SDLExec :  $(MAIN)
	$(CC) $(MAIN) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

clean:
	del game.exe

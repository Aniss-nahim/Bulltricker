#CC specifies which compiler we're using
CC = gcc
#CFLAGS = -Wall -O
LDFLAGS =
EXEC = Bulltricker.exe
OBJECT =./obj/
SOURCE = ./src/
TARGETPATH = ./bin/
MAIN = main.c
OBJS = main.o gui.o router.o controller.o queen.o pawn.o king.o bullStack.o
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#  # -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -w -Wl,-subsystem,windows
COMPILER_FLAGS = -w -Wall

#includes for lib SDL2
INCLUDE_PATHS = -ISDL2\include

LIBRARY_PATHS = -LSDL2\lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

compile = $(CC) -c $(SOURCE)$(1).c $(INCLUDE_PATHS) $(COMPILER_FLAGS) -o $(OBJECT)$(1).o

#Command execution 
all : $(OBJS) linker


controller : controller.o linker
	
bullStack : bullStack.o linker
	
gui : gui.o linker
	
queen : queen.o linker
	
king : king.o linker
	
main: main.o linker
	
pawn : pawn.o linker
	
router : router.o linker
	
main.o :
		$(CC) -c $(MAIN) $(INCLUDE_PATHS) $(COMPILER_FLAGS) -o $(OBJECT)main.o
	
controller.o :
		$(call compile,controller)

bullStack.o :
		$(call compile,bullStack)

gui.o :
		$(call compile,gui)

queen.o :
		$(call compile,queen)

king.o :
		$(call compile,king)

pawn.o :
		$(call compile,pawn)

router.o :
		$(call compile,router)

mrproper :
		rm -f $(TARGETPATH)$(EXEC)

files :
		rm -f ./file/*.*

clean_o : 
		rm -f $(OBJECT)*.o 

linker :
	$(CC) $(OBJECT)main.o $(OBJECT)gui.o $(OBJECT)router.o $(OBJECT)controller.o $(OBJECT)queen.o $(OBJECT)pawn.o $(OBJECT)king.o $(OBJECT)bullStack.o  $(LIBRARY_PATHS)  $(LINKER_FLAGS) $(INCLUDE_PATHS) $(COMPILER_FLAGS) -o $(TARGETPATH)$(EXEC)

count:
	find main.c src include -name '*.*' | xargs wc -l
	
run :
	$(TARGETPATH)$(EXEC)
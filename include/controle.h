#ifndef Controller
#define Controller

#include    "header.h"

//Debug 
void m(Move move);
void l(Location Loc, char *tag);

// board initialisation
void initBoard( int);
void freeBoard( void);
Piece *initCellObject(int row, int col);
char getCellType(int row, int col);
Piece *createPiece(int , char );

// Movment setup
Move getMove(Location Loc_From, Location Loc_To );
bool isValideLocation(Location position);
bool isEmptyCell(Cell cell);
bool isMyPiece(Cell cell);
bool isEmptyLocation(Location Loc);

// return cell if valide and not prohibited
Cell *getCell(Location position);

bool moveBullPiece( Move);
bool isValideMove( Move);
void eatPiece(Cell ** cellOfPieaceToEat);

bool isLegaleMoveForKing( Move);
bool checkMat( int);

bool isLegaleMoveForQueen( Move);

bool isLegaleMoveForPawn( Move);

// stack management
void initStack();
Node * create_element(Piece *p);
void pushToStack(Piece *p);
void makeStackEmpty();
bool isEmptyStack();
void displayStack(Stack *, char []);

#endif
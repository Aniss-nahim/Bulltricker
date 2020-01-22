#include    "../include/header.h"

//Debug
void test(char str[]);

// board initialisation
void initBoard( int);
Piece *initCellObject(int row, int col);
char getCellType(int row, int col);
Piece *createPiece(int , char );

// Movment setup
bool isValideLocation(Location position);
bool isEmptyCell(Cell cell);
bool isMyPiece(Cell cell);

// return cell if valide and not prohibited
Cell *getCell(Location position);
bool isForPawnOrDame(Cell *c);
bool isForKing(Cell *c);

bool moveBullPiece( Move);
bool isValideMove( Move);
void eatPiece(Cell ** cellAssPieaceToEat);

bool isLegaleMoveForKing( Move);
bool checkMat( int);

bool isLegaleMoveForDame( Move);

bool isLegaleMoveForPawn( Move);

// stack management
void initStack();
Node * create_element(Piece *p);
void pushToStack(Piece *p);
void makeStackEmpty();
bool isEmptyStack();
void displayStack(Stack *, char []);
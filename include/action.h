#include    "../include/common.h"

// board initialisation
void initBoard();
Piece *initCellObject(int row, int col);
char getCellType(int row, int col);
Piece *createPiece(int , char );

// Movment setup
bool isValideLocation(Location position);
bool isEmptyCell(Cell cell);

// return cell if valide and not prohibited
Cell *getCell(Location position);
bool isForPawnOrDame(Cell *c);
bool isForKing(Cell *c);

bool moveBullPiece( Move);
bool isValideMove( Move);
bool isLegaleMoveForKing( Move);
bool checkMat( int);
bool isLegaleMoveForDame( Move);
void eatPiece(Cell ** cellAssPieaceToEat);
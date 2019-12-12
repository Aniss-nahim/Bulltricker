#include"header.h"
#define Malloc(type) malloc(sizeof(type))
#define A(i)    2*i-1 // take number gives a row 
#define N(i)    2*i-1 //take number gives a col
#define V(i)    2*(i-1) //take number gives a col
#define H(i)    2*(i-1) // take number gives a row 
#define PLAYER1 1
#define PLAYER2 2
#define PAWN    'P'
#define DAME    'D'
#define KING    'K'
#define PROHIBITED_CELL 'B'
#define VERTICAL_CELL   'V'
#define HORIZONTAL_CELL 'H'
#define ROYAL_CELL      'R'
#define LENGHTBOARD 15
//#define ..

void initBoard();

Piece *initCell(int row, int col);

Piece *creatPiece(int player, char kind);

bool isLegaleMove(Move movement);

bool isValideLocation(Location position);

bool isEmptyCell(Cell cell);

char getCellType(int row, int col);

void DisplayBoard(Board board);


#include "header.h"

#define Malloc(type) malloc(sizeof(type))
#define A(i) (2 * (i) - 1)   // take number gives a row
#define N(i) (2 * (i) - 1)   // take number gives a col
#define V(i) (2 * ((i) - 1)) // take number gives a col
#define H(i) (2 * ((i) - 1)) // take number gives a row

#define PLAYER1 1
#define PLAYER2 -1

#define PAWN 'P'
#define DAME 'D'
#define KING 'K'

#define PROHIBITED_CELL 'B'
#define VERTICAL_CELL 'V'
#define HORIZONTAL_CELL 'H'
#define ROYAL_CELL 'R'
#define LENGHTBOARD 15
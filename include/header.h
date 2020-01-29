#ifndef BullTricker
#define BullTricker
#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>
#include    <string.h>
#include    <time.h>

// #DEFINE
#define Malloc(type) malloc(sizeof(type))
#define A(i) (2 * (i) - 1)   // take number gives a row
#define N(i) (2 * (i) - 1)   // take number gives a col
#define V(i) (2 * ((i) - 1)) // take number gives a col
#define H(i) (2 * ((i) - 1)) // take number gives a row

#define PLAYER1 1
#define PLAYER2 -1

#define PAWN 'P'
#define QUEEN 'Q'
#define KING 'K'

#define LENGHTBOARD 15


//Struct definitions
typedef struct{
    unsigned int  x;
    unsigned int  y;
}Location;

typedef struct{
    Location from;
    Location to;
}Move;

typedef struct{
    int PlayerOwner;
    char kind;
}Piece;

typedef struct{
    char CellType;
    Piece *Object;
}Cell;

typedef struct{
    Cell Matrix[15][15];
    Location kingLocation[2];
}Board;


typedef struct _node{
    Piece *piece;
    struct _node *next;
}Node;

typedef struct{
    Node *head;
}Stack;

//Global Variables
Board   _board;
Stack * _stackPieces;
int     _player;

#endif
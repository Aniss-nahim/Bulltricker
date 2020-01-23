// #INCLUDE
#ifndef BullTricker
#define BullTricker
#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>
#include    <string.h>
#include    <ctype.h>
#include    <windows.h>
#include    <conio.h>
#include    <string.h>

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

#define PROHIBITED_CELL 'B'
#define VERTICAL_CELL 'V'
#define HORIZONTAL_CELL 'H'
#define ROYAL_CELL 'R'
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
    char kind; // Pawn=1, Queen=2, King=3
}Piece;

typedef struct{
    char CellType;
    Piece *Object;
}Cell;

typedef struct{
    Cell Matrix[15][15];
    Location kingLocation[2];
}Board;

typedef struct{
    int id;
    char name[25];
    int role;
}Player;

typedef struct _node{
    Piece *piece;
    struct _node *next;
}Node;

typedef struct{
    Node *head;
}Stack;

//Global Variables
Board   _board;
Stack *_stackPieces; // this stack will contain all captured pieces
int     _player;
char    _namePlayer1[15];
char    _namePlayer2[15];
Stack   *_stackPieces; 

#endif
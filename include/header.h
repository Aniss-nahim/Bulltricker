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


//Struct definitions
typedef struct{
    int  x;
    int  y;
}Location;

typedef struct{
    Location from;
    Location to;
}Move;

typedef struct{
    int PlayerOwner;
    char kind; // Pawn=1, Dame=2, King=3
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

// Stack definition
typedef struct ele{
    Piece p;
    struct ele *next;
}Element;

typedef struct{
    element *head;
}Stack;


//Global Variables
Board   _board;
Stack *_stackPieces; // this stack will contain all captured pieces
int     _player;
char    _namePlayer1[15];
char    _namePlayer2[15];

#endif
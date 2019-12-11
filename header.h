#ifndef BullTricker
#define BullTricker
#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>

extern Board board;
typedef struct{
    int  x;
    int  y;
}Location;

typedef struct{
    Location from;
    Location to;
}Move;

typedef struct{
    int Cell;
    char kind; // Pion=1, Dame=2, Dame=3
}Piece;

typedef struct{
    char CellType;
    Piece *object;
}Cell;

typedef struct{
    Cell Matrix[15][15];
}Board;

typedef struct{
    int id;
    char name[25];
    int role;
}Player;

/*
typedef struct{
    .. ..;
}..;
*/
#endif
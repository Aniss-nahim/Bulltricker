#include    "header.h"

void main(){
    initBoard(bullBoard);

}

void initBoard(Board bullBoard){
    int row, col;
    for(row=0; row<LENGHTBOARD; row++){
        for(col=0; col<LENGHTBOARD; col++){
            bullBoard[row][col].CellType = getCellType(row, col);
            bullBoard[row][col].Object = initCell(row, col);
        }
    }
    
}

Piece *initCell(int row, int col){
    switch(true){
        case A(1) == row && !(col%2):
            return creatPiece(PLAYER2, DAME);
        break;
        
        case A(2) == row && !(col%2):
        case H(2) == row && col%2 :
            return creatPiece(PLAYER2, PAWN);
        break;

        case A(1) == row && col == N(4):
            return creatPiece(PLAYER2, KING);
        break;
        
        case A(7) == row && !(col%2):
            return creatPiece(PLAYER1, DAME);
        break;

        case A(6) == row && !(col%2):
        case H(7) == row && col%2 :
            return creatPiece(PLAYER1, PAWN);
        break;

        case A(7) == row && col == N(4):
            return creatPiece(PLAYER1, KING);
        break;
        default:
            return NULL;
    }
    

}

Piece * creatPiece(int player, char kind ){
    Piece *p = Malloc(Piece);
    p->kind = kind;
    p->ownerPlayer = player;
    return p;
}

char getKind

char getCellType(int row, int col){
    switch(true){
        case !(row % 2) && !(col % 2):
            return  PROHIBITED_CELL;
        break;
        case !(row % 2) && col % 2:
            return  HORIZONTAL_CELL;
        break;
        case row % 2 && !(col % 2):
            return  VERTICAL_CELL;
        break;
        case row % 2 && col % 2:
            return  ROYAL_CELL;
        break;
    }
}

void DisplayBoard(){
    
}
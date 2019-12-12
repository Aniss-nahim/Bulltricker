#include    "function.h"

void initBoard(){
    int row, col;
    for(row=0; row<LENGHTBOARD; row++){
        for(col=0; col<LENGHTBOARD; col++){
            board.Matrix[row][col].CellType = getCellType(row, col);
            board.Matrix[row][col].Object = initCell(row, col);
        }
    }
    
}

Piece *initCell(int row, int col){
    switch(row){
        case A(1):{
            if(col%2 == 0)
                return creatPiece(PLAYER2, DAME);
            else if(col == N(4))
                return creatPiece(PLAYER2, KING);
            break;
        }   
        case H(2):{
            if(col%2)
                return creatPiece(PLAYER2, PAWN);
            break;
        }
        case A(2):{
            if(col%2 == 0)
                return creatPiece(PLAYER2, PAWN);
            break;
        }
        case A(6):{
            if(col%2 == 0)
                return creatPiece(PLAYER1, PAWN);
            break;
        }
        case H(7):{
            if(col%2)
                return creatPiece(PLAYER1, PAWN);
            break;
        }  
        case A(7):{
            if(col%2 == 0)
                return creatPiece(PLAYER1, DAME);
            else if(col == N(4))
                return creatPiece(PLAYER1, KING);
            break;
        } 
    }
    return NULL;
}

Piece *creatPiece(int player, char kind){
    Piece *p = Malloc(Piece);
    p->kind = kind;
    p->PlayerOwner = player;
    return p;
}

char getCellType(int row, int col){
    if(row%2 == 0){
        if(col%2 == 0)
            return  PROHIBITED_CELL; // pair pair
        else
            return  HORIZONTAL_CELL; // pair impair
    }else{
        if(col%2 == 0)
            return  VERTICAL_CELL; // impair pair
        else
            return  ROYAL_CELL; // impair impair
    }
}

void DisplayBoard(Board board){
    int row,col;
    Cell c;
    for(row=0;row<LENGHTBOARD;row++){
        for(col=0;col<LENGHTBOARD;col++){
            c = board.Matrix[row][col];
            if(c.Object){
                printf(" %c(%c-%d) ",c.CellType,c.Object->kind,c.Object->PlayerOwner);
            }else{
                 printf(" %c(---) ",c.CellType);
            }
        }
        printf("\n\n");
    }
}
#include    "function.h"

void initBoard(){
    int row, col;
    for(row=0; row<LENGHTBOARD; row++){
        for(col=0; col<LENGHTBOARD; col++){
            board.Matrix[row][col].CellType = getCellType(row, col);
            board.Matrix[row][col].Object = initCellObject(row, col);
        }
    }
}

Piece *initCellObject(int row, int col){
    switch(row){
        case A(1):{
            if(col%2 == 0)
                return createPiece(PLAYER2, DAME);
            else if(col == N(4))
                return createPiece(PLAYER2, KING);
            break;
        }   
        case H(2):{
            if(col%2)
                return createPiece(PLAYER2, PAWN);
            break;
        }
        case A(2):{
            if(col%2 == 0)
                return createPiece(PLAYER2, PAWN);
            break;
        }
        case A(6):{
            if(col%2 == 0)
                return createPiece(PLAYER1, PAWN);
            break;
        }
        case H(7):{
            if(col%2)
                return createPiece(PLAYER1, PAWN);
            break;
        }  
        case A(7):{
            if(col%2 == 0)
                return createPiece(PLAYER1, DAME);
            else if(col == N(4))
                return createPiece(PLAYER1, KING);
            break;
        } 
    }
    return NULL;
}

Piece *createPiece(int player, char kind){
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

// check the location
bool isValideLocation(Location position){
    if(position.x < LENGHTBOARD && position.y < LENGHTBOARD && position.x >=0 && position.y >=0)
        return true;
    return false;
}

// return NULL if the Cell doesn't exist
Cell *getCell(Location position){
    if(isValideLocation(position) && getCellType(position.x,position.y)!= PROHIBITED_CELL)
        return &board.Matrix[position.x][position.y];
    return NULL;
}

// return true if the Cell is not occupid
bool isEmptyCell(Cell cell){
    if(cell.Object == NULL)
        return true;
    return false;
}

bool isForPawnOrDame(Cell *c){
    if(c->CellType == ROYAL_CELL || c->CellType == PROHIBITED_CELL)
        return false;
    return true;
}

bool isForKing(Cell *c){
    if(c->CellType != ROYAL_CELL)
        return false;
    return true;
}
/*
bool possibleMovePawn(Cell *to){

}

bool playerRoles(Cell *from, Cell *to, int player){
    if(player == PLAYER1){
        switch(from->Object->kind){
            case PAWN : {
                if(isForPawn(to)){
                    return // function that see if the deplacement is valide
                }
            } 
            case DAME : {

            }
            case KING : {

            }
            default : return false;
        }
    }else{

    }
}

//test if the Cell-form exist en the cell-to exist
// and if the cell-to is empty;
// if player one pawn : cell-from position - 
bool isLegaleMove(Move movement, int player){
    Cell *to;
    Cell *from = getCell(movement.from);
    if(isEmptyCell(from.Object)){
        printf("Cellule vide !");
        return false;
    }else if(from->Object->PlayerOwner != player){
         printf("Cette piéce ne vous appartient pas !");
         return false;
    }else{
        Cell *to = getCell(movement.to);
        if(!isEmptyCell(movement.to)){
            printf("cellule pleinne !");
            return false;
        }else
            return playerRoles(from, to, player);
    }
}
*/
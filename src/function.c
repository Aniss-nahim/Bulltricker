#include    "../include/function.h"

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
        printf("%c%d\t",(row%2==0)?'H':'A', row/2+1);
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
    printf("  \t");
    for(col=0;col<LENGHTBOARD;col++){
        printf("   %c%d   ",(col%2==0)?'V':'N', col/2+1);
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

bool isLegaleMove(Move movement, int player){
    Location from ,to;
    from = movement.from;
    to = movement.to;
    Cell *fromCell = getCell(from);
    if(fromCell !=NULL){
        if(!isEmptyCell(*fromCell) && fromCell->Object->PlayerOwner == player){
            Piece *pieceToMove = fromCell->Object;
            Cell *toCell = getCell(to);
            if(toCell == NULL) return false;
            switch(pieceToMove->kind){
                case PAWN :  
                    //return checkPawnRules();
                break;
                case DAME :  
                    //return checkDameRules();
                break;
                case KING :  
                    return checkKingRules(pieceToMove, &fromCell, &toCell, movement, player);
                break;

                default : return false;
            }
        }else{
            printf(" not your piece !");
        }
    }else{
        printf("not valide position !");
    }
}


bool checkKingRules(Piece* king,Cell **cFrom, Cell **cTo, Move move,int ply){
    Location from = move.from, to = move.to;
    if( from.x == to.x && from.y + 2 * ply == to.y ) {
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 2 * ply ; 
        Loc1.y = from.y + 4 * ply;
        Loc2.x = from.x ; 
        Loc2.y = from.y + 4 * ply;
        Loc3.x = from.x + 2 * ply ; 
        Loc3.y = from.y + 4 * ply;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if(isEmptyCell(*c1) && isEmptyCell(*c2) && isEmptyCell(*c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            return true;
        }
        return false;
    }

    else
    if( from.x == to.x && from.x - 2 * ply == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 2 * ply ;
        Loc1.y = from.y - 4 * ply ;
        Loc2.x = from.x ;
        Loc2.y = from.y - 4 * ply ;
        Loc3.x = from.x + 2 * ply ;
        Loc3.y = from.y - 4 * ply ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if(isEmptyCell(*c1) && isEmptyCell(*c2) && isEmptyCell(*c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            return true;
        }
        return false;
    }
    
    else
    if( from.x - 2 * ply == to.x && from.y == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 4 * ply ;
        Loc1.y = from.y - 2 * ply ;
        Loc2.x = from.x - 4 * ply ;
        Loc2.y = from.y ;
        Loc3.x = from.x -4 * ply ;
        Loc3.y = from.y +2 * ply ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if(isEmptyCell(*c1) && isEmptyCell(*c2) && isEmptyCell(*c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            return true;
        }
        return false;
    }
    
    else
    if( from.x + 2 * ply == to.x && from.y == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x + 4 * ply ;
        Loc1.y = from.y - 2 * ply ;
        Loc2.x = from.x + 4 * ply ;
        Loc2.y = from.y ;
        Loc3.x = from.x + 4 * ply ;
        Loc3.y = from.y + 2 * ply ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if(isEmptyCell(*c1) && isEmptyCell(*c2) && isEmptyCell(*c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            return true;
        }
        return false;
    }    
    
}
#include    "../include/action.h"

void initBoard(){
    int row, col;
    _player = PLAYER1;
    for(row=0; row<LENGHTBOARD; row++){
        for(col=0; col<LENGHTBOARD; col++){
            _board.Matrix[row][col].CellType = getCellType(row, col);
            _board.Matrix[row][col].Object = initCellObject(row, col);
        }
    }
    Location LocKK;
    LocKK.y = N(4);
    LocKK.x = A(7);
    _board.kingLocation[0] = LocKK;
    LocKK.x = A(1);
    _board.kingLocation[1] = LocKK;
    
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
                return createPiece(PLAYER1, PAWN); //PAWN
            break;
        }
        case H(7):{
            if(col%2)
                return createPiece(PLAYER1, PAWN); //PAWN
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

Piece *createPiece(int ply,  char kind){
    Piece *p = Malloc(Piece);
    p->kind = kind;
    p->PlayerOwner = ply;
    return p;
}

char getCellType(int row, int col){ //ymken t7yed
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

// check the location
bool isValideLocation(Location position){
    return (position.x < LENGHTBOARD && position.y < LENGHTBOARD && position.x >=0 && position.y >=0);
}

// return NULL if the Cell doesn't exist
Cell *getCell(Location position){
    return ( isValideLocation(position) && getCellType(position.x,position.y)!= PROHIBITED_CELL )
                ?&_board.Matrix[position.x][position.y] 
                :NULL;
}

// return true if the Cell is not occupid
bool isEmptyCell(Cell cell){
    return (cell.Object == NULL);
}

bool isForPawnOrDame(Cell *c){
    return (c->CellType == ROYAL_CELL || c->CellType == PROHIBITED_CELL);
}

bool isForKing(Cell *c){
    return (c->CellType != ROYAL_CELL);
}

bool moveBullPiece(Move movement){
    printf("moveBullPiece ");getch();
    printf(" (%d,%d) > (%d,%d) ", movement.from.x, movement.from.y, movement.to.x, movement.to.y);
    Piece *pieceToMove = getCell(movement.from)->Object;
    bool isLegale = false;
    if(!isValideMove(movement))
        return false;
    switch(pieceToMove->kind){
        case PAWN :  
            //isLegale = isLegaleMoveFroPawn();
        break;
        case DAME :  
            isLegale = isLegaleMoveForDame( movement);
        break;
        case KING :  
            isLegale = isLegaleMoveForKing( movement);
        break;
        default : return false;
    }
    
    if(isLegale){
        getCell(movement.from)->Object  = NULL;
        getCell(movement.to)->Object = pieceToMove;
        if(pieceToMove->kind == KING)
            _board.kingLocation[(_player == PLAYER1)?0:1] =  movement.to;
        return true;
    }

     
}

bool isValideMove(Move movement){
    Cell *fromCell = getCell(movement.from); 
    Cell *toCell = getCell(movement.to);
    return( ( fromCell && ( !isEmptyCell(*fromCell) && fromCell->Object->PlayerOwner == _player ) )
        &&  toCell  );
}

bool isLegaleMoveForKing( Move move){
    Location from = move.from, to = move.to;
    if (!isEmptyCell(*getCell(move.to)))
        return false;
    if( from.x == to.x && from.y + 2 == to.y ) {
        Location Loc0, Loc1, Loc2, Loc3;             
        Loc0.x = from.x ; 
        Loc0.y = from.y + 1 ;

        Loc1.x = from.x - 2 ; 
        Loc1.y = from.y + 4 ;
        
        Loc2.x = from.x ; 
        Loc2.y = from.y + 4 ;
        
        Loc3.x = from.x + 2 ; 
        Loc3.y = from.y + 4 ;
        
        Cell * c0 = getCell(Loc0);
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        return ( (c0 && isEmptyCell(*c0))
        &&    ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) );
    }

    else
    if( from.x == to.x && from.y - 2 == to.y ){
        Location Loc0, Loc1, Loc2, Loc3;             
        Loc0.x = from.x ; 
        Loc0.y = from.y - 1 ;

        Loc1.x = from.x - 2 ;
        Loc1.y = from.y - 4 ;
        
        Loc2.x = from.x ;
        Loc2.y = from.y - 4 ;
        
        Loc3.x = from.x + 2 ;
        Loc3.y = from.y - 4 ;
        
        Cell * c0 = getCell(Loc0);
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        return ( (c0 && isEmptyCell(*c0))
        &&  ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) );
    }
    
    else
    if( from.x - 2 == to.x && from.y == to.y ){
        Location Loc0, Loc1, Loc2, Loc3;             
        Loc0.x = from.x - 1 ; 
        Loc0.y = from.y ;

        Loc1.x = from.x - 4 ;
        Loc1.y = from.y - 2 ;
        
        Loc2.x = from.x - 4 ;
        Loc2.y = from.y ;
        
        Loc3.x = from.x - 4 ;
        Loc3.y = from.y + 2 ;
        
        Cell * c0 = getCell(Loc0);
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        return ( (c0 && isEmptyCell(*c0))
        &&  ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) );
    }
    
    else
    if( from.x + 2 == to.x && from.y == to.y ){
        Location Loc0, Loc1, Loc2, Loc3;             
        Loc0.x = from.x + 1 ; 
        Loc0.y = from.y ;

        Loc1.x = from.x + 4 ;
        Loc1.y = from.y - 2 ;
        
        Loc2.x = from.x + 4 ;
        Loc2.y = from.y ;
        
        Loc3.x = from.x + 4 ;
        Loc3.y = from.y + 2 ;
        
        Cell * c0 = getCell(Loc0);
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        return ( (c0 && isEmptyCell(*c0))
        &&  ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) );
    }    
    
}

bool checkMat(int ply){
    Location king ;
    bool isSurrounded = false ;
    Cell *c1, *c2, *c3, *c4;
    if(ply == PLAYER1){
        king = _board.kingLocation[0];
        ply = PLAYER2;
    }else{
        king = _board.kingLocation[1];
        ply = PLAYER1;
    }
    
    king.x -=1 ;
    c1 = getCell(king);
    
    king.x +=2 ;
    c2 = getCell(king);
    
    king.x -=1; king.y -=1;
    c3 = getCell(king);
    
    king.y +=2;
    c4 = getCell(king);

    isSurrounded = !isEmptyCell(*c1) && !isEmptyCell(*c2) && !isEmptyCell(*c3) && !isEmptyCell(*c4);
    
    
    if( isSurrounded && ( c1->Object->PlayerOwner == ply || c2->Object->PlayerOwner == ply || c3->Object->PlayerOwner == ply || c4->Object->PlayerOwner == ply) )
            return true;
    return false ;
}


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

Piece *createPiece(int ply,  char kind){
    Piece *p = Malloc(Piece);
    p->kind = kind;
    p->PlayerOwner = ply;
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
/* stack management */

void initStack(){
    _stackPieces = Malloc(Stack);
    stack->head = NULL;
}

bool emptyStack(){
    if(_stackPieces->head == NULL){
        return true;
    }
    return false;
}

element * create_element(Piece p){
    Element el;
    el = Malloc(Element);
    el->p = p;
    el->next = NULL;
    return el;
}

void addToStack(Piece p){
    Element * el = create_element(p);
    el->next = _stackPieces->head;
    _stackPieces->head = el;
}

void makeStackEmpty(){
    Element el;
    while(_stackPieces->head != NULL){
        el = _stackPieces->head;
        _stackPieces->head = _stackPieces->head->next;
        free(el);
    }
}

/********************/


// check the location
bool isValideLocation(Location position){
    if(position.x < LENGHTBOARD && position.y < LENGHTBOARD && position.x >=0 && position.y >=0)
        return true;
    return false;
}

// return NULL if the Cell doesn't exist
Cell *getCell(Location position){
    if(isValideLocation(position) && getCellType(position.x,position.y)!= PROHIBITED_CELL)
        return &_board.Matrix[position.x][position.y];
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

bool isLegaleMove(Move movement){
    Location from ,to;
    from = movement.from;
    to = movement.to;
    Cell *fromCell = getCell(from);
    if(fromCell !=NULL){
        if(!isEmptyCell(*fromCell) && fromCell->Object->PlayerOwner == _player){
            Piece *pieceToMove = fromCell->Object;
            Cell *toCell = getCell(to);
            if(toCell == NULL)  return false;
            switch(pieceToMove->kind){
                case PAWN :  
                    return checkPawnRoles(pieceToMove,&toCell, &fromCell,movement);
                break;
                case DAME :  
                    //return checkDameRules();
                break;
                case KING :  
                    return checkKingRules(pieceToMove, &fromCell, &toCell, movement);
                break;

                default : return false;
            }
        }else{
            printf("Not your piece or empty cell!");
            getch();
        }
    }else{
        printf("Not valide position !");
        getch();
    }
}

bool checkPawnRoles(Piece *pawn, Cell **toCell, Cell **fromCell, Move movement){
    Location from,to;
    from = movement.from;
    to = movement.to;
    if(to.x == from.x-1*_player && to.y == from.y + 1){
        if((*toCell)->Object == NULL){
            (*toCell)->Object = pawn;
            (*fromCell)->Object = NULL;
        }
    }else if(to.x== from.x-1*_player && to.y == from.y - 1){
        if((*toCell)->Object == NULL){
            (*toCell)->Object = pawn;
            (*fromCell)->Object = NULL;
        }
    }else if(to.x == from.x-2*_player && to.y == from.y){
        if((*toCell)->Object != NULL){
            if((*toCell)->Object->PlayerOwner != player){
                 addToStack((*toCell)->Object);// piece captured
                 (*toCell)->Object = pawn;
                 (*fromCell)->Object = NULL;
            }
        }else{
            (*toCell)->Object = pawn;
            (*fromCell)->Object = NULL;
        }
        return true;
    }
    return false;
}


bool checkKingRules(Piece* king,Cell **cFrom, Cell **cTo, Move move){
    Location from = move.from, to = move.to;
    if( from.x == to.x && from.y + 2 * _player == to.y ) {
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 2 * _player ; 
        Loc1.y = from.y + 4 * _player;
        Loc2.x = from.x ; 
        Loc2.y = from.y + 4 * _player;
        Loc3.x = from.x + 2 * _player ; 
        Loc3.y = from.y + 4 * _player;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if( ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            _board.kingLocation[(_player == PLAYER1)?0:1];
            return true;
        }
        return false;
    }

    else
    if( from.x == to.x && from.y - 2 * _player == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 2 * _player ;
        Loc1.y = from.y - 4 * _player ;
        Loc2.x = from.x ;
        Loc2.y = from.y - 4 * _player ;
        Loc3.x = from.x + 2 * _player ;
        Loc3.y = from.y - 4 * _player ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if( ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            _board.kingLocation[(_player == PLAYER1)?0:1];
            return true;
        }
        return false;
    }
    
    else
    if( from.x - 2 * _player == to.x && from.y == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x - 4 * _player ;
        Loc1.y = from.y - 2 * _player ;
        Loc2.x = from.x - 4 * _player ;
        Loc2.y = from.y ;
        Loc3.x = from.x -4 * _player ;
        Loc3.y = from.y +2 * _player ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if( ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            _board.kingLocation[(_player == PLAYER1)?0:1];
            return true;
        }
        return false;
    }
    
    else
    if( from.x + 2 * _player == to.x && from.y == to.y ){
        Location Loc1, Loc2, Loc3;             
        Loc1.x = from.x + 4 * _player ;
        Loc1.y = from.y - 2 * _player ;
        Loc2.x = from.x + 4 * _player ;
        Loc2.y = from.y ;
        Loc3.x = from.x + 4 * _player ;
        Loc3.y = from.y + 2 * _player ;
        Cell * c1 = getCell(Loc1);
        Cell * c2 = getCell(Loc2);
        Cell * c3 = getCell(Loc3);
        if( ((c1 && isEmptyCell(*c1)) || !c1)
        &&  ((c2 && isEmptyCell(*c2)) || !c2) 
        &&  ((c3 && isEmptyCell(*c3)) || !c3) ){
            (*cFrom)->Object  = NULL;
            (*cTo)->Object = king;
            _board.kingLocation[(_player == PLAYER1)?0:1];
            return true;
        }
        return false;
    }    
    
}

bool checkMat(int ply){
    Location king ;
    bool isSurrounded ;
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
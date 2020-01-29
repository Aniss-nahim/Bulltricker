#include    "../include/controle.h"

void initBoard(int rolePlayer){
    _player = rolePlayer;
    for(int row=0; row<LENGHTBOARD; row++){
        for(int col=0; col<LENGHTBOARD; col++){
            //_board.Matrix[row][col].CellType = getCellType(row, col);
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
                return createPiece(PLAYER2, QUEEN);
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
                return createPiece(PLAYER1, QUEEN);
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

void freeBoard( void){
     for(int row=0; row<LENGHTBOARD; row++){
        for(int col=0; col<LENGHTBOARD; col++){
            free(_board.Matrix[row][col].Object);
        }
    }
}

// check if it about a valide location [0,14]
bool isValideLocation(Location position){
    return (position.x < LENGHTBOARD && position.y < LENGHTBOARD && position.x >=0 && position.y >=0);
}

// return NULL if the Cell doesn't exist
Cell *getCell(Location position){
    return ( isValideLocation(position) && !(position.x % 2 == 0 && position.y % 2 ==0 ) )
                ?&_board.Matrix[position.x][position.y]
                :NULL;
}

// return true if the Cell is not occupied
bool isEmptyCell(Cell cell){
    return (cell.Object == NULL);
}

bool isEmptyLocation(Location Loc){
    return ( _board.Matrix[Loc.x][Loc.y].Object == NULL);
}

bool isMyPiece(Cell cell){
    return cell.Object->PlayerOwner == _player;
}

// tell the piece to move
bool moveBullPiece(Move movement){
    bool isLegale = false;
    if(!isValideMove(movement))
        return false;
    Piece *pieceToMove = getCell(movement.from)->Object;
    switch(pieceToMove->kind){
        case PAWN :  
            isLegale = isLegaleMoveForPawn( movement);
        break;
        case QUEEN :  
            isLegale = isLegaleMoveForQueen(movement);
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
        else if(pieceToMove->kind == PAWN &&  movement.to.x == -7 * _player +7 )
            getCell(movement.to)->Object->kind = QUEEN ;
        return true;
    }

     
}

/*  check if it's about a valide Move ,
    means if the bornes are valide and the piece to move is yours*/
bool isValideMove(Move movement){
    Cell *fromCell = getCell(movement.from); 
    Cell *toCell = getCell(movement.to);
    return (  fromCell &&  !isEmptyCell(*fromCell) && isMyPiece(*fromCell) &&  toCell  );
}

// eat given Piece
void eatPiece(Cell ** cellOfPieaceToEat){
    pushToStack((*cellOfPieaceToEat)->Object);
    (*cellOfPieaceToEat)->Object = NULL;
}

Move getMove(Location Loc_From, Location Loc_To ){
    Move move;
    move.from.x = Loc_From.x ;
    move.from.y = Loc_From.y ;
    move.to.x = Loc_To.x ;
    move.to.y = Loc_To.y ;
    return move ;
}

bool readBoardFromFile(){
    FILE *file = fopen(FILE_GAME_PART, "rb");
    if(!file)
        return false;
    
    fread(  &_player , sizeof( int ), 1 , file);
    if(feof(file))
        return false;
    
    Location Loc;
    Piece Pce;
    for(int row = 0; row < LENGHTBOARD ; row++ ){
        for(int col = 0; col < LENGHTBOARD ; col++ ){
            _board.Matrix[row][col].Object =  NULL;
        }
    }

    Piece * piece;
    while ( !feof( file ) ){
        fread(  &Loc , sizeof( Location ), 1 , file);
        fread(  &Pce , sizeof( Piece ), 1 , file);
        piece = createPiece( Pce.PlayerOwner, Pce.kind);
        _board.Matrix[Loc.x][Loc.y].Object = piece;
        if(piece->kind == KING ){
            _board.kingLocation[(piece->PlayerOwner == PLAYER1 )? 0: 1] = Loc;
        }
   }

    fclose(file);
    return true;
}

bool  writeBoardIntoFile(){
    FILE *file = fopen(FILE_GAME_PART, "wb");
    
    fwrite(  &_player , sizeof( int ), 1 , file);
    Location Loc;
    for(int row = 0; row < LENGHTBOARD ; row++ ){
        for(int col = 0; col < LENGHTBOARD ; col++ ){
            if(_board.Matrix[row][col].Object !=  NULL ){
                Loc.x = row;
                Loc.y = col;
                fwrite(  &Loc , sizeof( Location ), 1 , file);
                fwrite(  _board.Matrix[row][col].Object , sizeof( Piece ), 1 , file);
            }
        }
    }
    fclose(file);
    return true;
}


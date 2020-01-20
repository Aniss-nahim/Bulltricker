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

Move readMovement(){
    Move m;
    printf("donner le movment : \n");
    printf("Form : ");
    scanf("%d,%d",&m.from.x,&m.from.y);
    printf("To : ");
    scanf("%d,%d",&m.to.x,&m.to.y);
    return m;
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

bool checkPawnRolls(Piece *pawn, Cell **toCell, Cell **fromCell, Move movement, int player){
    Location from,to;
    from = movement.from;
    to = movement.to;
    if(to.x == from.x-1*player && to.y == from.y + 1){
        if((*toCell)->Object == NULL){
            (*toCell)->Object = pawn;
            (*fromCell)->Object = NULL;
        }
    }else if(to.x== from.x-1*player && to.y == from.y - 1){
        if((*toCell)->Object == NULL){
            (*toCell)->Object = pawn;
            (*fromCell)->Object = NULL;
        }
    }else if(to.x == from.x-2*player && to.y == from.y){
        if((*toCell)->Object != NULL){
            if((*toCell)->Object->PlayerOwner != player){
                 // empiler piece manger
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

bool isLegaleMove(Move movement, int player){
    Location from ,to;
    from = movement.from;
    to = movement.to;
    Cell *fromCell = getCell(from); // check if is valide and isn't prohibited
    if(fromCell !=NULL){
        if(!isEmptyCell(*fromCell) && fromCell->Object->PlayerOwner == player){
            Piece *pieceToMove = fromCell->Object;
            Cell *toCell = getCell(to); // check if is valide and isn't prohibited
            if(toCell == NULL) return false;
            switch(pieceToMove->kind){
                case PAWN :  
                    return checkPawnRolls(pieceToMove,&toCell, &fromCell,movement,player);
                break;
                /*case DAME :  break;
                case KING :  break;*/
                default : return false;
            }
        }else{
            printf(" not your piece !");
            return false;
        }
    }else{
        printf("not valide position !");
        return false;
    }
}
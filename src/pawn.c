#include    "../include/action.h"

bool isLegaleMoveForPawn( Move move){
    Location from = move.from , to = move.to;
    if( ( ( to.x == from.x - 1 * _player && to.y == from.y + 1 * _player ) || 
          ( to.x == from.x - 1 * _player && to.y == from.y - 1 * _player ) ) 
            && isEmptyCell(*getCell(to)) )
        return true;

    if(to.y != from.y) return false;

    if(to.x == from.x - 2 * _player){
        if(isEmptyCell(*getCell(to))) // mouvement en colonne
            return true;
        else
        if( !isEmptyCell(*getCell(to)) && from.x % 2 != 0 ){ // prise en colonne
            Cell * toCell = getCell(to);
            eatPiece(&toCell);
            return true;
        }
        return false;
    }

    if(!isEmptyCell(*getCell(to))) return false;
   
    if( (from.x - to.x) % 4 == 0  && from.x * _player > to.x * _player ){
        
        Location  kingLoc0,pieceLoc0, kingLoc1, pieceLoc1;
        pieceLoc0.y = kingLoc0.y = kingLoc1.y = pieceLoc1.y = from.y;
        kingLoc0.x = from.x - 1 * _player ;
        pieceLoc0.x = from.x - 2 * _player ;
        kingLoc1.x = from.x - 3 * _player ;
        pieceLoc1.x = from.x - 4 * _player ;
        
        if( isEmptyCell(*getCell(kingLoc0)) && isEmptyCell(*getCell(kingLoc1)) ){
            if( isEmptyCell(*getCell(pieceLoc0)) ) {
                if( pieceLoc1.x == to.x && from.x == 5 * _player + 7 /* f(x) = 5 * x + 7 ; (1)>12,(-1)>2) */ ) {
                    return true; // avancer de 2 cases d'un coup, lors de leur premier coup}
                }
                return false; //else
            }else{
                int i ;
                
                pieceLoc1.x = pieceLoc0.x - 2 * _player;
                Cell *pieceLocCell;
                if( isEmptyCell(*getCell(pieceLoc1)) ){
                    pieceLocCell= getCell(pieceLoc0);
                    if(!isMyPiece(*pieceLocCell))
                        eatPiece(&pieceLocCell);
                    else return false;
                }
                else return false;
                while(pieceLoc1.x * _player > to.x * _player){
                    kingLoc0.x = pieceLoc1.x - 1 * _player ;
                    pieceLoc0.x = pieceLoc1.x - 2 * _player ;
                    kingLoc1.x = pieceLoc1.x - 3 * _player ;
                    pieceLoc1.x = pieceLoc1.x - 4 * _player ;
                    if( isEmptyCell(*getCell(kingLoc0)) 
                    &&  !isEmptyCell(*getCell(pieceLoc0))  
                    &&  isEmptyCell(*getCell(kingLoc1))  
                    &&  isEmptyCell(*getCell(pieceLoc1)) ){
                        pieceLocCell = getCell(pieceLoc0);
                        if(!isMyPiece(*pieceLocCell))
                        eatPiece(&pieceLocCell);
                        else return false;
                    }
                    else return false;
                }
                return true;
            }
        }
    }
    return false;
}
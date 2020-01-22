#include    "../include/action.h"

bool isLegaleMoveForDame(Move move){
    Location from = move.from , to = move.to;
    printf("isLegaleMoveForDame ");getch();
    if( ( from.x - 1 * _player == to.x && from.y + 1 * _player == to.y) ||
        ( from.x - 1 * _player == to.x && from.y - 1 * _player == to.y) ||
        ( from.x + 1 * _player == to.x && from.y - 1 * _player == to.y) ||
        ( from.x + 1 * _player == to.x && from.y + 1 * _player == to.y) )
        return true;
    if( from.x % 2 == 0 ){
        
        if( from.y == to.y && from.x != to.x ){  // mouvement Verticale en range
            if(!isEmptyCell(*getCell(to)))
                return false;

            if( from.x - 2 == to.x ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.x = from.x - 1;
                tempKing.y = from.y;
                Cell *cKK = getCell(tempKing);
                return ( isEmptyCell(*cKK) ) ;
            }

            if( from.x + 2 == to.x ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.x = from.x + 1;
                tempKing.y = from.y;
                Cell *cKK = getCell(tempKing);
                return ( isEmptyCell(*cKK) ) ;
                    
            } 

            if( (from.x - to.x) %2 == 0){ // mouvement verticale en range  avec/sans prise
                printf(" n9zz");
                if(from.x < to.x){
                    printf(" foo9");
                    int i;
                    Location parcPceLoc, tempKingLoc ; 
                    parcPceLoc.y = tempKingLoc.y = from.y; 
                    for(i=from.x + 2 ; i < to.x ; i+=2){
                        parcPceLoc.x = i;
                        tempKingLoc.x = i - 1;
                        if(!isEmptyCell(*getCell(tempKingLoc)))
                            return false;
                        Cell *parCell = getCell(parcPceLoc);
                        if( isEmptyCell( *parCell ) )
                            continue;
                        else{
                            parcPceLoc.x = i + 2;
                            tempKingLoc.x = i + 3;
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) )){
                                eatPiece(&parCell);
                                i+=2;
                                continue;
                            }
                        }
                        return false;
                    }
                    return true;
                }else{ // (from.x > to.x)
                    printf(" ta7t ");
                    int i;
                    Location parcPceLoc, tempKingLoc ; 
                    parcPceLoc.y = tempKingLoc.y = from.y; 
                    for(i=from.x - 2 ; i > to.x ; i-=2){
                        parcPceLoc.x = i;
                        tempKingLoc.x = i + 1;
                        if(!isEmptyCell(*getCell(tempKingLoc)))
                            return false;
                        Cell *parCell = getCell(parcPceLoc);
                        if( isEmptyCell( *parCell ) )
                            continue;
                        else{
                            parcPceLoc.x = i - 2;
                            tempKingLoc.x = i - 3;
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) )){
                                eatPiece(&parCell);
                                i-=2;
                                continue;
                            }
                        }
                        return false;
                    }
                    return true;
                }
                
            }


        }else 
        if( from.x == to.x && from.y != to.y ){ // mouvement horizontale en colonne
            if( (from.y - to.y)  == 2 || (from.y - to.y)  == -2  ){ 
                Cell * cTo = getCell(to);
                if(!isEmptyCell(*cTo) && cTo->Object->PlayerOwner == -_player ){// prise en colone 
                    eatPiece(&cTo);
                }//sinon mouvement simple d'un pas

            }else
            if ( (from.y - to.y) % 2 == 0 ){ // mouvement simple
                int i;
                Location parcourLoc;
                parcourLoc.x = from.x ;
                if(from.y < to.y){
                    for(i = from.y + 2 ; i < to.y ; i += 2){
                         parcourLoc.y = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }else{ //(from.y > to.y)
                    for(i = from.y - 2 ; i < to.y ; i += 2){
                         parcourLoc.y = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }
                
            }
            return true;
        }
    }else{ //( from.x % 2 == 0 ) 
        
    }

    return false;


}
void eatPiece(Cell ** cellAssPieaceToEat){
    /*
        empiler
    (*cellAssPieaceToEat)->Object */
    (*cellAssPieaceToEat)->Object = NULL;
}
#include    "../include/controle.h"

bool isLegaleMoveForQueen(Move move){
    Location from = move.from , to = move.to;
    
    if((( from.x - 1 == to.x && from.y + 1 == to.y) ||
        ( from.x - 1 == to.x && from.y - 1 == to.y) ||
        ( from.x + 1 == to.x && from.y - 1 == to.y) ||
        ( from.x + 1 == to.x && from.y + 1 == to.y) ) && isEmptyCell(*getCell(to)) )
        return true;
    if( from.x % 2 == 0 ){
        
        if( from.y == to.y && from.x != to.x ){  // mouvement Verticale en range
            if(!isEmptyCell(*getCell(to)))
                return false;

            if( from.x - 2 == to.x ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.x = from.x - 1;
                tempKing.y = from.y;
                return ( isEmptyCell(*getCell(tempKing))) ;
            }

            if( from.x + 2 == to.x ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.x = from.x + 1;
                tempKing.y = from.y;
                return ( isEmptyCell(*getCell(tempKing)) ) ;
                    
            } 

            if( (from.x - to.x) %2 == 0){ // mouvement verticale en range  avec/sans prise
                
                if(from.x < to.x){
                    
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
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) ) && !isMyPiece(*parCell) ){
                                eatPiece(&parCell);
                                i+=2;
                                continue;
                            }
                        }
                        return false;
                    }
                    return true;
                }else{ // (from.x > to.x)
                    
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
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) ) && !isMyPiece(*parCell)){
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
            Cell * cTo = getCell(to);
            if( (from.y - to.y)  == 2 || (from.y - to.y)  == -2  ){
                
                if( isEmptyCell(*cTo))
                    return true;
                if( !isMyPiece(*cTo) ){// prise en colone 
                    eatPiece(&cTo);
                    return true;
                }//sinon mouvement simple d'un pas
                return false;

            }else
            if ( (from.y - to.y) % 2 == 0 ){ // mouvement simple
                int i;
                Location parcourLoc;
                parcourLoc.x = from.x ;
                if( !isEmptyCell(*cTo)) 
                    return false;
                if(from.y < to.y){
                    for(i = from.y + 2 ; i < to.y ; i += 2){
                         parcourLoc.y = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }else{ //(from.y > to.y)
                    for(i = from.y - 2 ; i > to.y ; i -= 2){
                         parcourLoc.y = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }
                
            }
            return true;
        }
    }else{ //( from.x % 2 != 0 ) 
        
        if( from.x == to.x && from.y != to.y ){  // mouvement Verthorizontale en range
            if(!isEmptyCell(*getCell(to)))
                return false;

            if( from.y - 2 == to.y ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.y = from.y - 1;
                tempKing.x = from.x;
                Cell *cKK = getCell(tempKing);
                return ( isEmptyCell(*cKK) ) ;
            }

            if( from.y + 2 == to.y ){   // mouvement simple en range d'un seule pas
                Location tempKing ;
                tempKing.y = from.y + 1;
                tempKing.x = from.x;
                Cell *cKK = getCell(tempKing);
                return ( isEmptyCell(*cKK) ) ;
                    
            } 

            if( (from.y - to.y) %2 == 0){ // mouvement verticale en range  avec/sans prise
                
                if(from.y < to.y){
                    
                    int i;
                    Location parcPceLoc, tempKingLoc ; 
                    parcPceLoc.x = tempKingLoc.x = from.x; 
                    for(i=from.y + 2 ; i < to.y ; i+=2){
                        parcPceLoc.y = i;
                        tempKingLoc.y = i - 1;
                        if(!isEmptyCell(*getCell(tempKingLoc)))
                            return false;
                        Cell *parCell = getCell(parcPceLoc);
                        if( isEmptyCell( *parCell ) )
                            continue;
                        else{
                            parcPceLoc.y = i + 2;
                            tempKingLoc.y = i + 3;
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) ) && !isMyPiece(*parCell) ){
                                eatPiece(&parCell);
                                i+=2;
                                continue;
                            }
                        }
                        return false;
                    }
                    return true;
                }else{ // (from.y > to.y)
                    
                    int i;
                    Location parcPceLoc, tempKingLoc ; 
                    parcPceLoc.x = tempKingLoc.x = from.x; 
                    for(i=from.y - 2 ; i > to.y ; i-=2){
                        parcPceLoc.y = i;
                        tempKingLoc.y = i + 1;
                        if(!isEmptyCell(*getCell(tempKingLoc)))
                            return false;
                        Cell *parCell = getCell(parcPceLoc);
                        if( isEmptyCell( *parCell ) )
                            continue;
                        else{
                            parcPceLoc.y = i - 2;
                            tempKingLoc.y = i - 3;
                            
                            if(isEmptyCell( *getCell(parcPceLoc) ) && isEmptyCell( *getCell(tempKingLoc) ) && !isMyPiece(*parCell)){
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
        if( from.y == to.y && from.x != to.x ){ // mouvement horizontale en colonne
            Cell * cTo = getCell(to);
            if( (from.x - to.x)  == 2 || (from.x - to.x)  == -2  ){ 
                if( isEmptyCell(*cTo))
                    return true;
                if( !isMyPiece(*cTo)  ){// prise en colone 
                    eatPiece(&cTo);
                    return true;
                }
                return false;//sinon mouvement simple d'un pas
            }else
            if ( (from.x - to.x) % 2 == 0 ){ // mouvement simple
                if(!isEmptyCell(*cTo))
                    return false;
                int i;
                Location parcourLoc;
                parcourLoc.y = from.y ;
                if(from.x < to.x){
                    for(i = from.x + 2 ; i < to.x ; i += 2){
                         parcourLoc.x = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }else{ //(from.x > to.x)
                    for(i = from.x - 2 ; i > to.x ; i -= 2){
                         parcourLoc.x = i  ; 
                        if (!isEmptyCell(*getCell(parcourLoc))) 
                            return false;
                    }
                }
                
            }
            return true;
        }
    }
    return false;
}

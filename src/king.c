#include    "../include/controle.h"

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
    return false;
    
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


/**
    ************* Welcome to the Bulltricker game *****************
                        copy right 2019
**/

#include    "./include/action.h"
#include    "./include/cli.h"


void main(){
    initBoard(PLAYER2);
    Move lasteMove;
    lasteMove.from.x = 0;
    lasteMove.from.y = 0;
    lasteMove.to.x = 14;
    lasteMove.to.y = 14;
    
    //splash();
    strcpy(_namePlayer1, "Ayoub");strcpy(_namePlayer2, "Aniss");
    //readPlayersName(_namePlayer1, _namePlayer2);
    while(1){
        //system("cls");
        __displayBoard();
        printf("\n\t%s's turn",(_player == PLAYER1 )?_namePlayer1:_namePlayer2);
        printf("\t\t\t%s","00:00");
        printf("\t\t\tlast move %c%d,%c%d > %c%d,%c%d",
            (lasteMove.from.x%2)?'A':'H',
                lasteMove.from.x/2+1,
                    (lasteMove.from.y%2)?'N':'V',
                        lasteMove.from.y/2+1,            
                            (lasteMove.to.x%2)?'A':'H',
                                lasteMove.to.x/2+1,
                                    (lasteMove.to.y%2)?'N':'V',
                                        lasteMove.to.y/2+1);
       
        readMove(&lasteMove);
        
        //gameController
        if(moveBullPiece(lasteMove))
            _player *= -1; //_player = (_player == PLAYER1)? PLAYER2: PLAYER1;
        
        if ( checkMat(PLAYER1) ){
            printf(" %s, you Win !!!", _namePlayer2 );
            return ;
        }else 
        if ( checkMat(PLAYER2) ){
            printf(" %s, you Win !!!", _namePlayer1 );
            return ;
        }
    
    }
}

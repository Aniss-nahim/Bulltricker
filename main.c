/**
    ************* Welcome to the BULLTRICKER game *****************
                         ©opyRight 2019
**/

#include    "./include/action.h"
#include    "./include/cli.h"


void main(){
    
    initStack();
    initBoard(PLAYER1);
    Move lastMove;
    lastMove.from.x = lastMove.from.y = 0;  lastMove.to.x = lastMove.to.y = 14;
    
    splash();
    strcpy(_namePlayer1, "Ayoub");/*VS*/strcpy(_namePlayer2, "Aniss");
    //readPlayersName( _namePlayer1, _namePlayer2);
    while(true){ //loop game
        system("cls");
        displayBoard();
        displayBar(lastMove);
        displayStack(_stackPieces,"stack");
       
        readMove(&lastMove);
        
        ///gameController
        if(moveBullPiece(lastMove))
            _player *= -1; //_player = (_player == PLAYER1)? PLAYER2: PLAYER1;
        
        if ( checkMat(PLAYER1) ){
            printf(" %s, you Win !!!", _namePlayer2 );  getch();
            return ;
        }else 
        if ( checkMat(PLAYER2) ){
            printf(" %s, you Win !!!", _namePlayer1 );  getch();
            return ;
        }
    }
}

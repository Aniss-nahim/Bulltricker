/**
    ************* Welcome to the BULLTRICKER game *****************
                         ©opyRight 2019
**/

#include    "./include/action.h"
#include    "./include/cli.h"


void main(){
    Move *lastMove = NULL;
    bool checkMatPlayer1,checkMatPlayer2;
    initBoard(PLAYER1);
    initStack();
    splash();
    strcpy(_namePlayer1, "Ayoub");strcpy(_namePlayer2, "Aniss");
    //readPlayersName(_namePlayer1, _namePlayer2);
    checkMatPlayer1 = checkMatPlayer2 = false;
    while(!checkMatPlayer1 && !checkMatPlayer2){
        system("cls");

        //UI
        displayBoard();
        displayBar(lastMove);
        displayStack(_stackPieces,"stack");
         if(getch() == 27)
            exit(-1);
        //gameController
        do{
            //readMove
            lastMove = readMove(lastMove);
        }while(!moveBullPiece(lastMove));
        //checkMat test
        checkMatPlayer1 = checkMat(PLAYER1);
        checkMatPlayer2 = checkMat(PLAYER2);
        //switch turn
        _player *= -1;
    }
    // show board state for the winier
    system("cls");
    displayBoard();
    displayBar(lastMove);
    displayStack(_stackPieces,"stack");
    if(checkMatPlayer1){
        printf(" %s, you Win !!!", _namePlayer2 );
    }else{
        printf(" %s, you Win !!!", _namePlayer1 );
    }
}

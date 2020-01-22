/**
    ************* Welcome to the Bulltricker game *****************
                        opyright 2020
**/

#include    "./include/action.h"
#include    "./include/cli.h"


void main(){
    Move *lasteMove = NULL;
    bool checkMatPlayer1,checkMatPlayer2;
    initBoard();
    initStack();
    splash();
    strcpy(_namePlayer1, "Ayoub");strcpy(_namePlayer2, "Aniss");
    //readPlayersName(_namePlayer1, _namePlayer2);
    checkMatPlayer1 = checkMatPlayer2 = false;
    _player = PLAYER1;
    while(!checkMatPlayer1 || !checkMatPlayer2){
        system("cls");

        //UI
        __displayBoard();
        __displayDashboard(lasteMove);
        printf("player : %d",_player);
        //gameController
        do{
            //readMove
            lasteMove = readMove(lasteMove);
        }while(!isLegaleMove(*lasteMove));
        //checkMat test
        checkMatPlayer1 = checkMat(PLAYER1);
        checkMatPlayer2 = checkMat(PLAYER2);
        //switch turn
        _player = (_player == PLAYER1) ?  PLAYER2 : PLAYER1;
    }
    if(checkMatPlayer1){
        printf(" %s, you Win !!!", _namePlayer2 );
    }else{
        printf(" %s, you Win !!!", _namePlayer1 );
    }
}

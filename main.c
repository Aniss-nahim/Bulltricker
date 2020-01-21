/**
    ************* Welcome to the Bulltricker game *****************
                        opyright 2020
**/

#include    "./include/action.h"
#include    "./include/cli.h"


void main(){
    Move *lasteMove = NULL;
    initBoard();
    initStack();
    //splash();
    strcpy(_namePlayer1, "Ayoub");strcpy(_namePlayer2, "Aniss");
    //readPlayersName(_namePlayer1, _namePlayer2);
    while(1){
        //system("cls");
        __displayBoard();
        __displayDashboard(lasteMove);
       
        lasteMove = readMove(lasteMove);
        printf("here \n");
        //gameController
        isLegaleMove(*lasteMove);
        if ( checkMat(PLAYER1) ){
            printf(" %s, you Win !!!", _namePlayer2 );
        }else 
        if ( checkMat(PLAYER2) ){
            printf(" %s, you Win !!!", _namePlayer1 );
        }
    
    }
}

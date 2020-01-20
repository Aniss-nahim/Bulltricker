/**
    ************* Welcome to the Bulltricker game *****************
                        opyright 2020
**/

#include    "./include/function.h"


void main(){
    Move m; int turn = PLAYER1; bool next;
    printf("\n\t\t--------- Welcome to the BULLTRICKER GAME ------------\n");
    initBoard();
    do{
        DisplayBoard(board);
        if(turn){
            printf("PLAYER 1");
            m = readMovement();
            do{
                 next = isLegaleMove(m, turn);
            }while(!next);
            turn = PLAYER2;
        }else{
            printf("Plaier 2");
            m = readMovement();
            do{
                next = isLegaleMove(m,turn);
            }while(!next);
            turn = PLAYER1;
        }
        system("cls");
    }while(true);    
}
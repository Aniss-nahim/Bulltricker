/**
    ************* Welcome to the Bulltricker game *****************
                        opyright 2020
**/

#include    "./include/function.h"


void main(){
    Move m;
    initBoard();
    DisplayBoard(board);
    printf("donner le movment : \n");
    printf("Form : ");
    scanf("%d,%d",&m.from.x,&m.from.y);
    printf("To : ");
    scanf("%d,%d",&m.to.x,&m.to.y);
    printf("checking movement...... \n");
    if(isLegaleMove(m,1)){
        printf("Movement done !\n");
    }else{
        printf("movement not Done !\n");
    }
    DisplayBoard(board);
}
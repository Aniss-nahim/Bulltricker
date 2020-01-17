#include    "../include/function.h"

int inputPos(char str[2]){
    switch(str[0]){
		case 'A':
			return A(str[1]-'0') ;
			break;
		case 'N':
			return  N(str[1]-'0') ;
			break;
		case 'V':
			return  V(str[1]-'0') ;
			break;
		case 'H':
			return  H(str[1]-'0') ;
			break;
	}
}

Move readMove(char player){
	Move move;
	char Loc1[2], Loc2[2];
	Location fromLoc, toLoc;
	printf("Player  ::  %s\n",player);
	printf("from\t?>\t");
	scanf("%s",Loc1,Loc2);
	if(strlen(Loc1) == 2 && strlen(Loc2) == 2 && isalpha(Loc1[0]) && isdigit(Loc1[1]) && isalpha(Loc2[0]) && isdigit(Loc2[1] )  ){
        fromLoc.x = inputPos(Loc1);
        fromLoc.y = inputPos(Loc2);
    }else{
		return move;
	}
	
    printf("to\t?>\t");
	scanf("%s",Loc1,Loc2);
    if(strlen(Loc1) == 2 && strlen(Loc2) == 2 && isalpha(Loc1[0]) && isdigit(Loc1[1]) && isalpha(Loc2[0]) && isdigit(Loc2[1] )  ){
        fromLoc.x = inputPos(Loc1);
        fromLoc.y = inputPos(Loc2);
    }else{
		printf("error");
		return move;
	}
	move.from = fromLoc;
	move.from = toLoc;
	
}
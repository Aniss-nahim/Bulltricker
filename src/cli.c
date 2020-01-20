#include    "../include/cli.h"

void splash(){
	puts("\t\t ____                   __    _____                     _     ");
	puts("\t\t(  _`\\                 (_ )  (_   _)        _          ( )    ");
	puts("\t\t| (_) )  _   _   _   _  | |    | |   _ __  (_)    ___  | |/')     __    _ __  ");
	puts("\t\t|  _ <' ( ) ( ) ( ) ( ) | |    | |  ( '__) | |  /'___) | , <    /'__`\\ ( '__) ");
	puts("\t\t| (_) ) | \\_/ | | \\_/ | | |    | |   | |   | | ( (___  | |\\`\\  (  ___/ | |    ");
	puts("\t\t(____/' `\\___/' `\\___/'(___)   (_)   (_)   (_)  \\____) (_) (_) `\\____) (_)    ");

	getch();

}

void readPlayersName(char str1[],char str2[]){
	printf("? Name of first plyer  :\t");
		scanf("%s",str1);
	printf("? Name of second plyer :\t");
		scanf("%s",str2);

	puts("\n\n\tTape any key to start your game ;)");
	getch();
}

void displayBoard(){
    int row,col;
    Cell c;
    for(row=0;row<LENGHTBOARD;row++){
        printf("%c%d\t",(row%2==0)?'H':'A', row/2+1);
        for(col=0;col<LENGHTBOARD;col++){
            c = _board.Matrix[row][col];
            if(c.Object){
                printf(" %c(%c-%d) ",c.CellType,c.Object->kind,c.Object->PlayerOwner);
            }else{
                 printf(" %c(---) ",c.CellType);
            }
        }
        printf("\n\n");
    }
    printf("  \t");
    for(col=0;col<LENGHTBOARD;col++){
        printf("   %c%d   ",(col%2==0)?'V':'N', col/2+1);
    }
}

char shape(int i, int j){
	char r;
	Cell C = _board.Matrix[i][j];
	if(C.Object){
		if(C.Object->PlayerOwner == PLAYER1 )
			return toupper(C.Object->kind);
		else
			return tolower(C.Object->kind);
	}else return ' ';
	
}

void __displayBoard(){
		int row,col;
		char c[15];
		
		puts("      +---------------------------------------------------------------------------------------+");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 0, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H1",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 1, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A1",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 2, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H2",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 3, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A2",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 4, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H3",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 5, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A3",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 6, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H4",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 7, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A4",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 8, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H5",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 9, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A5",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 10, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H6",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 11, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A6",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 12, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H7",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		for(col=0 ; col<LENGHTBOARD ; col++) c[col] = shape( 13, col);
	printf("  %2s  | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |   %c   | %c |\n","A7",c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9], c[10], c[11], c[12], c[13], c[14]);
		puts("      |   |       |   |       |   |       |   |       |   |       |   |       |   |       |   |");
		puts("      |---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---+-------+---|");
		for(col=1 ; col<LENGHTBOARD ; col+=2){c[col] = shape( 14, col);}
	printf("  %2s  | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |   %c   | . |\n","H8",c[1], c[3], c[5], c[7], c[9], c[11], c[13]);
		puts("      +---------------------------------------------------------------------------------------+");
		printf("       %s    %s     %s   %s     %s    %s    %s    %s    %s    %s    %s    %s    %s    %s     %s","V1","N1","V2","N2","V3","N3","V4","N4","V5","N5","V6","N6","V7","N7","V8");

			printf("\n\n");
}

static int inputPos(char Str[]){
    switch(Str[0]){
		case 'A': case 'a':
			return A(Str[1]-'0') ;
			break;
		case 'N': case 'n':
			return  N(Str[1]-'0') ;
			break;
		case 'V': case 'v':
			return  V(Str[1]-'0') ;
			break;
		case 'H': case 'h':
			return  H(Str[1]-'0') ;
			break;
	}
}

static bool inputValid(char Str1[], char Str2[]){
	
	return (	strlen(Str1) == 2	&& 	strlen(Str2) == 2	
				&&(
					((Str1[0]=='A' || Str1[0]=='a') && ('1'<=Str1[1] && Str1[1]<='7') )	
					||((Str1[0]=='H' || Str1[0]=='h') && ('1'<=Str1[1] && Str1[1]<='8') )
				)&&(
					((Str2[0]=='N' || Str2[0]=='n') && ('1'<=Str2[1] && Str2[1]<='7') )	
					||((Str2[0]=='V' || Str2[0]=='v') && ('1'<=Str2[1] && Str2[1]<='8') )
				)
			);
}

bool readMove(Move *mv){
	char Loc1[3], Loc2[3];
	Location fromLoc, toLoc;
	start:
	printf("\n\nfrom (x,y)\t?>\t");
	fflush(stdin);
	scanf("%s %s",Loc1, Loc2);
	if ( inputValid(Loc1, Loc2) ){
        fromLoc.x = inputPos(Loc1);
        fromLoc.y = inputPos(Loc2);
    }else{
		puts("      error!!");
		goto start;
	}
	
    printf("to (x,y)\t?>\t");
	scanf("%s%s",Loc1,Loc2);
    if( inputValid(Loc1, Loc2) ){
        toLoc.x = inputPos(Loc1);
        toLoc.y = inputPos(Loc2);
    }else{
		puts("      error!!");
		goto start;
	}

	mv->from = fromLoc;
	mv->to = toLoc;
	return true;
}
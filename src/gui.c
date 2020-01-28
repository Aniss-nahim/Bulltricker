#include    "../include/gui.h"

bool onKeyDown(SDL_Keycode code, SDL_Rect * cursor, SDL_Rect * cursor_ghost ){
    int pxl_X, pxl_Y ;
    switch (code) {

        case SDLK_ESCAPE:
            _isGridSelected_To = _isGridSelected_From = false;
            break;
        case SDLK_KP_5:
        case SDLK_SPACE:
            *cursor = *cursor_ghost ;
            cursor->x -= 3;
            cursor->y -= 3;
            cursor->w += 6;
            cursor->h += 6;
            return true;
            break;

        case SDLK_u:
        case SDLK_KP_8 :
        case SDLK_UP:
            pxl_Y = cursor_ghost->y/GRID_CELL_SIZE;
            if( pxl_Y  == 0 )
                break;
            if( pxl_Y % 3 == 0){
                if( pxl_Y  == 0 )
                    break;
                cursor_ghost->y -= GRID_CELL_SIZE * 2;
                cursor_ghost->h = GRID_CELL_SIZE * 2;
            }
            else if( pxl_Y % 3 == 1){
                if( cursor_ghost->x/GRID_CELL_SIZE % 3 == 0 ){
                    if( pxl_Y  == 1 )
                        break;
                    cursor_ghost->y -= GRID_CELL_SIZE * 3;
                    cursor_ghost->h = GRID_CELL_SIZE * 2;
                    break;
                }
                cursor_ghost->y -= GRID_CELL_SIZE;
                cursor_ghost->h = GRID_CELL_SIZE;
            }
            break;
        
        case SDLK_d:
        case SDLK_KP_2:
        case SDLK_DOWN:
            pxl_Y = cursor_ghost->y/GRID_CELL_SIZE;
            if( pxl_Y + 1 == GRIDS ) 
                break;
            if( pxl_Y % 3 == 0){
                if( pxl_Y + 1 == GRIDS ) 
                    break;
                cursor_ghost->y += GRID_CELL_SIZE;
                cursor_ghost->h = GRID_CELL_SIZE * 2;
            }
            else if( pxl_Y % 3 == 1){
                if( cursor_ghost->x/GRID_CELL_SIZE % 3 == 0 ){
                    if( pxl_Y + 3 == GRIDS ) 
                        break;
                    cursor_ghost->y += GRID_CELL_SIZE * 3;
                    cursor_ghost->h = GRID_CELL_SIZE * 2;
                    break;
                }
                cursor_ghost->y += GRID_CELL_SIZE * 2;
                cursor_ghost->h = GRID_CELL_SIZE;
            }
            break;
        
        case SDLK_l:
        case SDLK_KP_4:
        case SDLK_LEFT:
            pxl_X = cursor_ghost->x/GRID_CELL_SIZE;
            
            if( pxl_X % 3 == 0 && pxl_X  != 0){
                if( pxl_X  == 0 )
                    break;
                cursor_ghost->x -= GRID_CELL_SIZE * 2;
                cursor_ghost->w = GRID_CELL_SIZE * 2;
            }
            else if( pxl_X % 3 == 1){
                if( cursor_ghost->y/GRID_CELL_SIZE % 3 == 0 ){
                    if( pxl_X  == 1 )
                        break;
                    cursor_ghost->x -= GRID_CELL_SIZE * 3;
                    cursor_ghost->w = GRID_CELL_SIZE * 2;
                    break;
                }
                cursor_ghost->x -= GRID_CELL_SIZE;
                cursor_ghost->w = GRID_CELL_SIZE;
            }
            break;
        
        case SDLK_r:
        case SDLK_KP_6:
        case SDLK_RIGHT:
            pxl_X = cursor_ghost->x/GRID_CELL_SIZE;
            
            if( pxl_X % 3 == 0){
                if( pxl_X + 1 == GRIDS ) 
                    break;
                cursor_ghost->x += GRID_CELL_SIZE;
                cursor_ghost->w = GRID_CELL_SIZE * 2;
            }
            else if( pxl_X % 3 == 1){
                if( cursor_ghost->y/GRID_CELL_SIZE % 3 == 0 ){
                    if( pxl_X + 3 == GRIDS ) 
                        break;
                    cursor_ghost->x += GRID_CELL_SIZE * 3;
                    cursor_ghost->w = GRID_CELL_SIZE * 2;
                    break;
                }
                cursor_ghost->x += GRID_CELL_SIZE * 2;
                cursor_ghost->w = GRID_CELL_SIZE;
            }
            break;

        case SDLK_HOME:
            pxl_Y = cursor_ghost->y/GRID_CELL_SIZE;
            if(pxl_Y % 3 == 0){
                cursor_ghost->x = GRID_CELL_SIZE;
                cursor_ghost->w = GRID_CELL_SIZE * 2;
            }
            else{
                cursor_ghost->x = 0;
                cursor_ghost->w = GRID_CELL_SIZE;
            }
            break;

        case SDLK_END:
            pxl_Y = cursor_ghost->y/GRID_CELL_SIZE;
            if(pxl_Y % 3 == 0){
                cursor_ghost->x = GRID_CELL_SIZE * (GRIDS - 3);
                cursor_ghost->w = GRID_CELL_SIZE * 2;
            }
            else{
                cursor_ghost->x = GRID_CELL_SIZE * (GRIDS - 1) ;
                cursor_ghost->w = GRID_CELL_SIZE;
            }
            break;

        case SDLK_PAGEUP:
            pxl_X = cursor_ghost->x/GRID_CELL_SIZE;
            if(pxl_X % 3 == 0){
                cursor_ghost->y = GRID_CELL_SIZE ;
                cursor_ghost->h = GRID_CELL_SIZE * 2;
            }
            else{
                cursor_ghost->y = 0;
                cursor_ghost->h = GRID_CELL_SIZE;
            }
            break;
            
        case SDLK_PAGEDOWN:
            pxl_X = cursor_ghost->x/GRID_CELL_SIZE;
            if(pxl_X % 3 == 0){
                cursor_ghost->y = GRID_CELL_SIZE * (GRIDS - 3);
                cursor_ghost->h = GRID_CELL_SIZE * 2;
            }
            else{
                cursor_ghost->y = GRID_CELL_SIZE * (GRIDS - 1) ;
                cursor_ghost->h = GRID_CELL_SIZE;
            }
            break;

        }
    return false;
}

bool onMouseEvent(SDL_MouseMotionEvent currentPos, SDL_Rect * cursor){
    int pxl_X =  currentPos.x / GRID_CELL_SIZE, pxl_Y = currentPos.y / GRID_CELL_SIZE;
    
    if( pxl_X >= GRIDS || pxl_Y >= GRIDS )
        return false;
    if( pxl_X % 3 == 0  && pxl_Y % 3 == 0   ){
        return false;
    }
    else if( pxl_X % 3 == 1  && pxl_Y % 3 == 0  ){
        cursor->x = pxl_X * GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 1;
    }
    else if( pxl_X % 3 == 2  && pxl_Y % 3 == 0  ){
        cursor->x = pxl_X * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 1;
    }
    if( pxl_X % 3 == 0  && pxl_Y % 3 == 1   ){
        cursor->x = pxl_X * GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 1;
        cursor->y = pxl_Y * GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    else if( pxl_X % 3 == 1  && pxl_Y % 3 == 1  ){
        cursor->x = pxl_X * GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    else if( pxl_X % 3 == 2  && pxl_Y % 3 == 1  ){
        cursor->x = pxl_X * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    if( pxl_X % 3 == 0  && pxl_Y % 3 == 2   ){
        cursor->x = pxl_X * GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 1;
        cursor->y = pxl_Y * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    else if( pxl_X % 3 == 1  && pxl_Y % 3 == 2  ){
        cursor->x = pxl_X * GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    else if( pxl_X % 3 == 2  && pxl_Y % 3 == 2  ){
        cursor->x = pxl_X * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->w = GRID_CELL_SIZE * 2;
        cursor->y = pxl_Y * GRID_CELL_SIZE - GRID_CELL_SIZE;
        cursor->h = GRID_CELL_SIZE * 2;
    }
    printf(">>pixel hover(%d,%d)\n",pxl_X, pxl_Y);
    return true;
}
    
void drawImage(SDL_Renderer *rend, Shape Shp ){
    
    // player rectangle
    SDL_Rect rectplayer;
    SDL_QueryTexture(Texture[Shp.source], NULL, NULL, &rectplayer.w, &rectplayer.h);
    

    // change player size
    rectplayer.w = GRID_CELL_SIZE * Shp.w;
    rectplayer.h = GRID_CELL_SIZE * Shp.h;

    // player initial  position
    rectplayer.x = Shp.pixel.x * GRID_CELL_SIZE ; 
    rectplayer.y = Shp.pixel.y * GRID_CELL_SIZE ;


    // draw the image to the window
    SDL_RenderCopy(rend, Texture[Shp.source], NULL, &rectplayer);
}

void drawImageDefault(SDL_Renderer *rend, int  imgTag, int _X, int _Y, int _W, int _H ){
    
    // player rectangle
    SDL_Rect rectplayer;
    SDL_QueryTexture(Texture[imgTag], NULL, NULL, &rectplayer.w, &rectplayer.h);
    
    // change player size
    rectplayer.w =  _W;
    rectplayer.h =  _H;

    // player initial  position
    rectplayer.x = _X  ; 
    rectplayer.y = _Y  ;



    // draw the image to the window
    SDL_RenderCopy(rend, Texture[imgTag], NULL, &rectplayer);/**/
}

Shape newShape(int source, int row, int col, int w, int h){
    Shape Sh;
    Sh.source = source;
    Sh.pixel.x = col;
    Sh.pixel.y = row;
    Sh.w = w;
    Sh.h = h;
    return Sh;
}

Shape initShape(int row, int col){
    switch(row){
        case A(1):{
            if(col%2 == 0) // pair
                return newShape(QUEEN_2_V, INDEX(row), INDEX(col), 1, 2);
            else if(col == N(4))
                return newShape(KING_2, INDEX(row), INDEX(col), 2, 2);
            break;
        } 
        case H(2):{
            if(col%2) // impair
                return newShape(PAWN_2_H, INDEX(row), INDEX(col), 2, 1);
            break;
        }
        case A(2):{
            if(col%2 == 0) // pair
                return newShape(PAWN_2_V, INDEX(row), INDEX(col), 1, 2);
            break;
        }
        case A(6):{
            if(col%2 == 0) //pair
            return newShape(PAWN_1_V, INDEX(row), INDEX(col) , 1, 2); 
            break;
        }
        case H(7):{
            if(col%2) // impaire
                return newShape(PAWN_1_H, INDEX(row), INDEX(col) , 2, 1); 
            break;
        }  
        case A(7):{
            if(col%2 == 0)
                return newShape(QUEEN_1_V, INDEX(row), INDEX(col), 1, 2);
            else if(col == N(4))
                return newShape(KING_1, INDEX(row), INDEX(col), 2, 2);
            break;
        } 
    }
}

Shape getShape(int row, int col, int ply, int kind){
    switch(kind){
        case PAWN:
            if(PLAYER1 == ply){
                if( row % 2 != 0 && col % 2 == 0 )
                    return newShape(PAWN_1_V, INDEX(row), INDEX(col), 1, 2);
                if( row % 2 == 0 && col % 2 != 0)
                    return newShape(PAWN_1_H, INDEX(row), INDEX(col), 2, 1);
            }
            else{
                if( row % 2 != 0 && col % 2 == 0 )
                    return newShape(PAWN_2_V, INDEX(row), INDEX(col), 1, 2);
                if( row % 2 == 0 && col % 2 != 0 )
                    return newShape(PAWN_2_H, INDEX(row), INDEX(col), 2, 1);
            }
            break;
        case QUEEN:
            if(PLAYER1 == ply){
                if( row % 2 != 0 && col % 2 == 0 )
                    return newShape(QUEEN_1_V, INDEX(row), INDEX(col), 1, 2);
                if( row % 2 == 0 && col % 2 != 0)
                    return newShape(QUEEN_1_H, INDEX(row), INDEX(col), 2, 1);
            }
            else{
                if( row % 2 != 0 && col % 2 == 0 )
                    return newShape(QUEEN_2_V, INDEX(row), INDEX(col), 1, 2);
                if( row % 2 == 0 && col % 2 != 0 )
                    return newShape(QUEEN_2_H, INDEX(row), INDEX(col), 2, 1);
            }
            break;
        case KING:
            if(PLAYER1 == ply)
                return newShape(KING_1, INDEX(row), INDEX(col), 2, 2);
            else
                return newShape(KING_2, INDEX(row), INDEX(col), 2, 2);
            break;
    }
}

void draw_grid_cursor(SDL_Renderer * rend, SDL_Color color, SDL_Rect * cursor ){
    SDL_SetRenderDrawColor(rend, color.r, color.g, color.b, color.a);                           
    SDL_RenderFillRect(rend, cursor);
}

Location getLocation_Cursor(SDL_Rect cursor ){
    Location Loc;
    Loc.x = INDEX_1((cursor.y + GRID_CELL_SIZE ) / GRID_CELL_SIZE) ;
    Loc.y = INDEX_1((cursor.x + GRID_CELL_SIZE ) / GRID_CELL_SIZE) ;/**/////////////////////////////
    return Loc;
}


void displayBoard(SDL_Renderer *rend){
    for(int row = 0; row < LENGHTBOARD ; row++ ){
        for(int col = 0; col < LENGHTBOARD ; col++ ){
            Cell C = _board.Matrix[row][col];
            
            if(C.Object){
                drawImage(rend, getShape( row, col, C.Object->PlayerOwner, C.Object->kind) );
            }
        }
    }
}

bool alert(SDL_Renderer * rend,char * Text ,int daley, int ply){
        TTF_Init();
        TTF_Font *font = TTF_OpenFont("../public/font.ttf",70);
        SDL_Color white = {255,255,255};
        SDL_Surface * surface = TTF_RenderText_Solid(font,Text,white);
        SDL_Rect dest;
        SDL_Texture* Tture;
        Tture = SDL_CreateTextureFromSurface(rend, surface);
        SDL_QueryTexture(Tture, NULL, NULL, &dest.w, &dest.h);
        dest.x = 180;
        dest.y = 240;


        // draw the image to the window
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, Tture, NULL, &dest);
        drawImage(rend,newShape((ply == PLAYER1)? WIN_KING_1 : WIN_KING_2, INDEX(9), INDEX(6), 4, 4) );
        
        SDL_RenderPresent(rend);
        SDL_FreeSurface(surface);

        // wait a few seconds
        SDL_Delay(daley);
        
        TTF_CloseFont(font);
        SDL_Event event;
        while (1)
        while (SDL_PollEvent(&event)) {
            if((event.type== SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
            ||( SDL_MOUSEBUTTONDOWN && event.motion.x / (4*GRID_CELL_SIZE) == INDEX(9) && event.motion.y / (4*GRID_CELL_SIZE) == INDEX(6) ))
            return true;
            else 
            if (event.type == SDL_QUIT)
                return false;
        }
        return false;
}

void displaySideBar(SDL_Renderer *rend, Move lastMove){ // Time_t time
    drawImageDefault(rend,(_player == PLAYER1 )? BLACK1_TURN :WHITE2_TURN, BOARD_LENGTH + 5, 0, 339, 220 );
    int countp1, countq1, countp2, countq2;
    drawImageDefault(rend, PAWN1_STACK, BOARD_LENGTH + 5 , 230 , GRID_CELL_SIZE, GRID_CELL_SIZE);
    drawImageDefault(rend, QUEEN1_STACK, BOARD_LENGTH + 5  , 230 + GRID_CELL_SIZE + 10, GRID_CELL_SIZE, GRID_CELL_SIZE );
    
    drawImageDefault(rend, PAWN2_STACK, BOARD_LENGTH + 5+ 20 + GRID_CELL_SIZE + 10 , 230 , GRID_CELL_SIZE, GRID_CELL_SIZE );
    drawImageDefault(rend, QUEEN2_STACK, BOARD_LENGTH + 5+ 20 + GRID_CELL_SIZE + 10 , 230 + GRID_CELL_SIZE + 10 , GRID_CELL_SIZE, GRID_CELL_SIZE);
}

void IMGS_PREPARE(SDL_Renderer* rend){
    SDL_Surface* surface;
    // load the image data into the graphics hardware's memory
    surface = IMG_Load("../public/king1.png");
    Texture[KING_1] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn1_V.png");
    Texture[PAWN_1_V] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn1_H.png");
    Texture[PAWN_1_H] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen1_V.png");
    Texture[QUEEN_1_V] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen1_H.png");
    Texture[QUEEN_1_H] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/king2.png");
    Texture[KING_2] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn2_V.png");
    Texture[PAWN_2_V] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn2_H.png");
    Texture[PAWN_2_H] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen2_V.png");
    Texture[QUEEN_2_V] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen2_H.png");
    Texture[QUEEN_2_H] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/KING_1.png");
    Texture[WIN_KING_1] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/KING_2.png");
    Texture[WIN_KING_2] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/background.png");
    Texture[BACKGOUND_IMG] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/black_turn.png");
    Texture[BLACK1_TURN] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/white_turn.png");
    Texture[WHITE2_TURN] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn1_stack.png");
    Texture[PAWN1_STACK] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen1_stack.png");
    Texture[QUEEN1_STACK] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/pawn2_stack.png");
    Texture[PAWN2_STACK] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);
    surface = IMG_Load("../public/queen2_stack.png");
    Texture[QUEEN2_STACK] = SDL_CreateTextureFromSurface(rend , surface);
    SDL_FreeSurface(surface);

}
/*
void displayStack(Stack *stkPc, char *tag){
    if(isEmptyStack())
        return;
	int count = 0;
    Node * node = stkPc->head;
    printf("\n\t%s  : ",tag);
    while(node){
        count++;
        printf("(%c)%d, ", (stkPc->head->piece->PlayerOwner == PLAYER1)? toupper(stkPc->head->piece->kind) : tolower(stkPc->head->piece->kind), count);
        node = node->next;
    }
	
}
*/
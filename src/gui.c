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

void displaySideBar(SDL_Renderer *rend, Move lastMove){ // Time_t time
    drawImageDefault(rend,(_player == PLAYER1 )? BLACK1_TURN :WHITE2_TURN, BOARD_LENGTH + 5, 0, 335, 220 );
    
    int countRows = 0, countCols = 0, index;
    Node * node = _stackPieces->head;
    while(node){
    
        if( BOARD_LENGTH + 20 + (countCols+1)*(GRID_CELL_SIZE + 5) > WINDOW_WEIGHT ){
            countCols = 0;
            countRows++;
        }
        
        if( node->piece->PlayerOwner == PLAYER1 ){
            if(node->piece->kind == PAWN)
                index = PAWN1_STACK;
            else   
                index = QUEEN1_STACK;
        }else{
            if(node->piece->kind == PAWN)
                index = PAWN2_STACK;
            else   
                index = QUEEN2_STACK;
        }
        
        drawImageDefault(rend, index, BOARD_LENGTH + 20 + countCols*(GRID_CELL_SIZE + 5) , 230 + countRows * (GRID_CELL_SIZE + 10), GRID_CELL_SIZE, GRID_CELL_SIZE);   
        
        countCols ++;
      node = node->next;
    }
    drawImageDefault(rend, SAVE_QUIT, BOARD_LENGTH + 5, 570 , 335,100);
}


void IMGS_PREPARE(SDL_Renderer* rend){
    SDL_Surface* surface;
    char fileSource[25][30]={
                            "../public/king1.png",
                            "../public/pawn1_V.png",
                            "../public/pawn1_H.png",
                            "../public/queen1_V.png",
                            "../public/queen1_H.png",
                            "../public/king2.png",
                            "../public/pawn2_V.png",
                            "../public/pawn2_H.png",
                            "../public/queen2_V.png",
                            "../public/queen2_H.png",
                            "../public/KING_1.png",
                            "../public/KING_2.png",
                            "../public/background.png",
                            "../public/black_turn.png",
                            "../public/white_turn.png",
                            "../public/pawn1_stack.png",
                            "../public/queen1_stack.png",
                            "../public/pawn2_stack.png",
                            "../public/queen2_stack.png",
                            "../public/King1Winner.png",
                            "../public/King2Winner.png",
                            "../public/save_quit.png"
                        };
    for (int  i = 0; i < 25; i++){
        surface = IMG_Load(fileSource[i]);
        Texture[i] = SDL_CreateTextureFromSurface(rend , surface);
        SDL_FreeSurface(surface);
    }
    
    // load the image data into the graphics hardware's memory

}
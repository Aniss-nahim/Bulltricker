#include    "../include/route.h"


int __Route(SDL_Renderer * rend ){
    IMGS_PREPARE(rend);
    SDL_Rect grid_cursor;
    SDL_bool quit_menu = SDL_FALSE;
    SDL_bool mouse_active = SDL_FALSE;
    SDL_bool mouse_hover = SDL_FALSE;
    while (!quit_menu) { // menu loop

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN:
                //routing
                    printf("(%d, %d) :: \n",event.motion.x, event.motion.y);
                    if( 520 < event.motion.y && event.motion.y < 575 ){
                        switch(event.motion.x){
                            case 287 ... 450:   //Continue
                                /*restoreBoard(PLAYER1);
                                restoreStack();*/
                                printf(" | CONTINUE | ");
                            break;
                            case 545 ... 710:   // New game
                                initBoard(PLAYER1);
                                initStack();
                                PlayGame(rend);
                            break;
                            /*case y3 ... y3 + 385:
                                //call something
                            break;*/
                        }
                    }
                    
                case SDL_MOUSEMOTION:
                
                if (!mouse_active)
                    mouse_active = SDL_TRUE;
                break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_ENTER && !mouse_hover)
                        mouse_hover = SDL_TRUE;
                    else if (event.window.event == SDL_WINDOWEVENT_LEAVE && mouse_hover)
                        mouse_hover = SDL_FALSE;
                    break;
                case SDL_QUIT:
                    quit_menu = SDL_TRUE;
                    break;
            }
        SDL_RenderClear(rend);
        drawImageDefault(rend,BACKGOUND_IMG, 0 ,0, WINDOW_WEIGHT, WINDOW_LENGTH );
        SDL_RenderPresent(rend);
        }
    }
}

int PlayGame(SDL_Renderer * rend ){
    Move lastMove;
    bool gameOver ;
    int Winner;
    _isGridSelected_From = _isGridSelected_To = false ;
    // Place the grid cursor in the middle of the screen.
    SDL_Rect grid_cursor_From, grid_cursor_To;

    // The cursor ghost is a cursor that always shows in the cell below the
    // mouse cursor.
    SDL_Rect grid_cursor_ghost = {
        .x = (GRIDS - 1) / 2 * GRID_CELL_SIZE,
        .y = (GRIDS - 1) / 2 * GRID_CELL_SIZE,
        .w = GRID_CELL_SIZE * 2,
        .h = GRID_CELL_SIZE * 2,
    };

    // Light Theme.
    SDL_Color grid_background = {233, 233, 233, 255}; // Barely_white
    SDL_Color grid_line_color = {200, 200, 200, 255}; // Very_light_grey
    
    SDL_Color ghost_color_blue = {172, 220, 246, 1}; // ghost_Blue
    SDL_Color ghost_color_yellow = {245, 210, 100, 1}; // ghost_Green
    
    SDL_Color color_Blue = {35, 167, 240, 1}; // Green
    SDL_Color color_Yellow = {235, 190, 90, 1}; // Green
    SDL_bool quit = SDL_FALSE;
    SDL_bool mouse_active = SDL_FALSE;
    SDL_bool mouse_hover = SDL_FALSE;
    while (!quit) { // game loop
    
        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            switch (event.type) {
                case SDL_KEYDOWN:
                    if( event.key.keysym.sym == SDLK_RETURN  && _isGridSelected_To && _isGridSelected_From ){
                            Location l1, l2;
                            /*l(getLocation_Cursor(grid_cursor_From), "clicked");
                            l(getLocation_Cursor(grid_cursor_To), "clicked");*/
                            l1 = getLocation_Cursor(grid_cursor_From);
                            l2 = getLocation_Cursor(grid_cursor_To);
                            l(l1,"clicked1"); l(l2,"clicked2");
                            //lastMove = getMove( getLocation_Cursor(grid_cursor_From), getLocation_Cursor(grid_cursor_To));
                            lastMove = getMove( l1, l2);

                            m(lastMove);
                            
                            if(moveBullPiece(lastMove)){ // mouvement effectuer
                                _player *= -1;
                                _isGridSelected_To = _isGridSelected_From = false;
                                
                                if(checkMat(PLAYER1)){
                                    gameOver = true;
                                    Winner = PLAYER2;
                                }
                                else if(checkMat(PLAYER2)){
                                    gameOver = true;
                                    Winner = PLAYER1;
                                }
                            }
                    }
                    else if( !_isGridSelected_From ){
                        if( onKeyDown(event.key.keysym.sym , &grid_cursor_From , &grid_cursor_ghost ) ){
                            _isGridSelected_From = true;
                        }
                    }
                    else{
                        if ( onKeyDown(event.key.keysym.sym , &grid_cursor_To , &grid_cursor_ghost ) ){
                            _isGridSelected_To = true;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                        if( !_isGridSelected_From ){
                            
                            if(onMouseEvent( event.motion, &grid_cursor_From)){
                                l(getLocation_Cursor(grid_cursor_From), "click1");
                                /*if(isEmptyLocation(getLocation_Cursor(grid_cursor_From)))
                                    break;*/
                                grid_cursor_From.x -= 3;
                                grid_cursor_From.y -= 3;
                                grid_cursor_From.w += 6;
                                grid_cursor_From.h += 6;
                                _isGridSelected_From = true;
                            }    
                        }
                        else{
                            if(onMouseEvent( event.motion, &grid_cursor_To)){
                                l(getLocation_Cursor(grid_cursor_To), "click2");
                                grid_cursor_To.x -= 3;
                                grid_cursor_To.y -= 3;
                                grid_cursor_To.w += 6;
                                grid_cursor_To.h += 6;
                                _isGridSelected_To = true;
                            }
                        }
                    break;
                case SDL_MOUSEMOTION:
                    onMouseEvent( event.motion, &grid_cursor_ghost);
                    //l(getLocation_Cursor(grid_cursor_ghost), "hover");
                    
                    if (!mouse_active)
                        mouse_active = SDL_TRUE;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_ENTER && !mouse_hover)
                        mouse_hover = SDL_TRUE;
                    else if (event.window.event == SDL_WINDOWEVENT_LEAVE && mouse_hover)
                        mouse_hover = SDL_FALSE;
                    break;
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
            }
            if(grid_cursor_From.x == grid_cursor_To.x && grid_cursor_From.y == grid_cursor_To.y){
                _isGridSelected_From = _isGridSelected_To = false;
            }
            
        }

        {   //Draw background
            // Draw grid background.
            SDL_SetRenderDrawColor(rend, grid_background.r, grid_background.g,
                                grid_background.b, grid_background.a);
            SDL_RenderClear(rend);

            // Draw grid lines.
            SDL_SetRenderDrawColor(rend, grid_line_color.r, grid_line_color.g,
                                grid_line_color.b, grid_line_color.a);
            
            for (int x = 0, i = 2; x < 1 + BOARD_LENGTH; 
                        i = (i==1)? 2 : 1 ,  x += GRID_CELL_SIZE * i) {
                SDL_RenderDrawLine(rend, x, 0, x, BOARD_LENGTH);
            }

            for (int y = 0, i = 2; y < 1 + BOARD_LENGTH; 
                        i = (i==1)? 2 : 1 ,  y += GRID_CELL_SIZE*i) {
                SDL_RenderDrawLine(rend, 0, y, BOARD_LENGTH, y);
            }
                
        }

        // Draw grid ghost cursor.
        if (mouse_active && mouse_hover) {

            if(!_isGridSelected_From)
                draw_grid_cursor(rend, ghost_color_blue, &grid_cursor_ghost );
                
            else
                draw_grid_cursor(rend, ghost_color_yellow, &grid_cursor_ghost );
        }

        // Draw grid cursor.
        if(_isGridSelected_From){
            draw_grid_cursor(rend, color_Blue, &grid_cursor_From );
            if(_isGridSelected_To)
                draw_grid_cursor(rend, color_Yellow, &grid_cursor_To);
        }

        //alert(SDL_Renderer * rend,char * Text ,int daley)
        displayBoard(rend);
        displaySideBar(rend, lastMove);
        SDL_RenderPresent(rend);
        if(gameOver){
            
            freeBoard();
            makeStackEmpty();
            
            if(alert(rend,"Game over" ,5000, Winner)){
                initBoard(PLAYER1);
                initStack();
                _isGridSelected_From = _isGridSelected_To = false ;
                quit = SDL_FALSE;
            }
            
            else 
                quit = SDL_TRUE;
        } 
    }
}
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
                    if( 520 < event.motion.y && event.motion.y < 575 ){
                        switch(event.motion.x){
                            case 287 ... 450:   //Continue
                                if(!readBoardFromFile() || !readStackFromFile()){
                                    initBoard(PLAYER1);
                                    initStack();
                                }
                                    
                                    PlayGame(rend); 
                            break;
                            case 545 ... 710:   // New game
                                initBoard(PLAYER1);
                                initStack();
                                PlayGame(rend);
                            break;
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
    bool gameOver = false;
    int Winner;
    _isGridSelected_From = _isGridSelected_To = false ;
    // Place the grid cursor in the middle of the screen.
    SDL_Rect cursor_From, cursor_To;

    // The cursor ghost is a cursor that always shows in the cell below the
    // mouse cursor.
    SDL_Rect cursor_ghost = {
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
                          
                            lastMove = getMove( getLocation_Cursor(cursor_From), getLocation_Cursor(cursor_To));

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
                        if( onKeyDown(event.key.keysym.sym , &cursor_From , &cursor_ghost ) ){
                            _isGridSelected_From = true;
                        }
                    }
                    else{
                        if ( onKeyDown(event.key.keysym.sym , &cursor_To , &cursor_ghost ) ){
                            _isGridSelected_To = true;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                        if( (event.motion.x / GRID_CELL_SIZE) >= GRIDS || (event.motion.y / GRID_CELL_SIZE) >= GRIDS ){
                            if( 600 < event.motion.y && event.motion.y < 630 ){
                                switch(event.motion.x){
                                    case 720 ... 800:   //Quit
                                        quit = SDL_TRUE;
                                    break;
                                    case 855 ... 935:   // Save            
                                        writeBoardIntoFile();
                                        writeStackdIntoFile();
                                    break;
                                }
                            }
                        }
                        else
                        if( !_isGridSelected_From ){
                                cursor_From = cursor_ghost;
                                cursor_From.x -= 3;
                                cursor_From.y -= 3;
                                cursor_From.w += 6;
                                cursor_From.h += 6;
                                _isGridSelected_From = true;
                        }
                        else{
                                cursor_To = cursor_ghost;
                                cursor_To.x -= 3;
                                cursor_To.y -= 3;
                                cursor_To.w += 6;
                                cursor_To.h += 6;
                                _isGridSelected_To = true;
                        }
                    break;
                case SDL_MOUSEMOTION:
                    onMouseEvent( event.motion, &cursor_ghost);
                    
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
            if(_isGridSelected_From &&  _isGridSelected_To)
                if(cursor_From.x == cursor_To.x && cursor_From.y == cursor_To.y){
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
        //if (mouse_active && mouse_hover) {
            if(!_isGridSelected_From)
                draw_grid_cursor(rend, ghost_color_blue, &cursor_ghost );
                
            else
                draw_grid_cursor(rend, ghost_color_yellow, &cursor_ghost );
       // }

        // Draw grid cursor.
        if(_isGridSelected_From){
            draw_grid_cursor(rend, color_Blue, &cursor_From );
            if(_isGridSelected_To)
                draw_grid_cursor(rend, color_Yellow, &cursor_To);
        }

        displayBoard(rend);
        displaySideBar(rend, lastMove);
        SDL_RenderPresent(rend);
        if(gameOver){
            
            freeBoard();
            makeStackEmpty();
            
            drawImageDefault(rend,(Winner == PLAYER1)? KING1_WINNER : KING2_WINNER,65, 166,530, 337 );
            SDL_RenderPresent(rend);
            SDL_Delay(20000);
            quit = SDL_TRUE;
            
        } 
    }
}
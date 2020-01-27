#ifndef GUI
#define GUI

#include "../SDL2/include/SDL.h"
#include "../SDL2/include/SDL_ttf.h"
#include "../SDL2/include/SDL_timer.h"
#include "header.h"


#define GAME_NAME "BullTricker game"
#define GRIDS 22
#define GRID_CELL_SIZE  30

#define BOARD_LENGTH  (GRIDS * GRID_CELL_SIZE)

#define WINDOW_WEIGHT 1000
#define WINDOW_LENGTH 670

#define INDEX(i) (2 * (i) - ((i) + 1) / 2) // take number gives a row
#define INDEX_1(i) ((i) - ((i) + 1) / 3)  // take number gives a row

enum{ 
    BULL_MENU ,
    BULL_NEW_GAME ,
    BULL_RESTORE_GAME ,
    BULL_SAVE_GAME
};
enum{ 
    KING_1 ,
    PAWN_1_V ,
    PAWN_1_H ,
    QUEEN_1_V ,
    QUEEN_1_H ,
    KING_2 ,
    PAWN_2_V ,
    PAWN_2_H ,
    QUEEN_2_V ,
    QUEEN_2_H ,
    WIN_KING_1,
    WIN_KING_2,
    BACKGOUND_IMG,
    FONT_TEXT
};

typedef struct {
    unsigned int x;
    unsigned int y;
}Pixel;

typedef struct {
    Pixel pixel;
    unsigned w; //weidth
    unsigned h; //height
    int source;
}Shape;

bool _isGridSelected_From ;
bool _isGridSelected_To ;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *Texture[15]; 


Location getLocation_Cursor(SDL_Rect cursor );
bool onKeyDown(SDL_Keycode code, SDL_Rect * cursor, SDL_Rect * cursor_ghost );
bool onMouseEvent(SDL_MouseMotionEvent currentPos, SDL_Rect * cursor);
void drawImageDefault(SDL_Renderer *rend, int imgSrc, int _X, int _Y, int _W, int _H );
void drawImage(SDL_Renderer *rend, Shape Shp );
Shape initShape(int row, int col);
Shape getShape(int row, int col, int ply, int kind);
Shape newShape(int source, int x, int y, int w, int h);
void draw_grid_cursor(SDL_Renderer * rend, SDL_Color color, SDL_Rect * cursor );
void displayBoard(SDL_Renderer *rend);
bool alert(SDL_Renderer * rend,char * Text ,int daley, int ply);
void displaySideBar(SDL_Renderer *rend, int ply,time_t time, Move last);

#endif
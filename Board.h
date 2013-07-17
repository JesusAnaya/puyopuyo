//
//  Board.h
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#ifndef __puyopuyo__Board__
#define __puyopuyo__Board__

#include "Commons.h"
#include "Piece.h"

class Board
{
private:
    Piece* pieces[BOARD_ROWS][BOARD_COLS];
    
public:
    Board();
    ~Board();
    
    void set_piece(Piece *piece);
    void render(SDL_Renderer *renderer);
    void update();
    bool is_used(int x, int y);
};

#endif

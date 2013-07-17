//
//  Piece.cpp
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#include "Commons.h"
#include "Piece.h"

Piece::Piece(int start_x, int start_y, int color)
{
    this->color = color;
    
    pos_x = start_x;
    pos_y = start_y;
    
    offset_x = PIECE_WIDTH;
    offset_y = PIECE_WIDTH;
    
    move_counter = 0;
    can_down = true;
}

Piece::~Piece()
{
    std::cout << "Delete Piece" << std::endl;
}

//move down

void Piece::move_down()
{
    if(can_move_down())
    {
        if(pos_y <= 0)
            offset_y = PIECE_WIDTH;
        
        pos_y += offset_y;
    }
}

// move piece to left
bool Piece::can_move_to_left()
{
    if(pos_x - PIECE_WIDTH < 0)
        return false;
    return true;
}

void Piece::move_left()
{
    pos_x -= PIECE_WIDTH;
}

// move piece to right
void Piece::move_right()
{
    pos_x += PIECE_WIDTH;
}

bool Piece::can_move_to_right()
{
    if(pos_x + PIECE_WIDTH > SCREEN_WIDTH - 1 - PIECE_WIDTH)
        return false;
    return true;
}

// can move down
bool Piece::can_move_down()
{
    if(move_counter++ >= PIECE_MOVE_COUNTER)
    {
        move_counter = 0;
        return true;
    }
    return false;
}

// renderer object
void Piece::render(SDL_Renderer *renderer)
{
    /*  Come up with a rectangle */
    SDL_Rect rect;
    rect.w = PIECE_WIDTH;
    rect.h = PIECE_WIDTH;
    rect.x = pos_x;
    rect.y = pos_y;
    
    /* Come up with a color example: 0xff0000*/
    SDL_SetRenderDrawColor(renderer, color >> 16 & 0xFF,
                           color >> 8 & 0xFF, color & 0xFF, 0xFF);
    /*  Fill the rectangle in the color */
    SDL_RenderFillRect(renderer, &rect);
}
//
//  Board.cpp
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#include "Board.h"
#include <cstring>
#include <cstdlib>

Board::Board()
{
    std::cout << BOARD_ROWS << std::endl;
    for(int i = 0; i < BOARD_COLS; i++)
    {
        for (int j = 0; j < BOARD_ROWS; j++)
        {
            pieces[j][i] = NULL;
        }
    }
}

Board::~Board()
{
    for(int i = 0; i < BOARD_COLS; i++)
    {
        for (int j = 0; j < BOARD_ROWS; j++)
        {
            if(pieces[j][i])
                delete pieces[j][i];
        }
    }
}

void Board::set_piece(Piece *piece)
{
    int x = piece->get_pos_x() / PIECE_WIDTH - 1;
    int y = piece->get_pos_y() / PIECE_WIDTH - 1;
    
    pieces[y][x] = piece;
    std::cout << "Add priece to board" << std::endl;
}

void Board::update()
{
    
}

void Board::render(SDL_Renderer *renderer)
{
    for(int i = 0; i < BOARD_COLS; i++)
    {
        for (int j = 0; j < BOARD_ROWS; j++)
        {
            if(pieces[j][i] != NULL)
                pieces[j][i]->render(renderer);
        }
    }
}

bool Board::is_used(int x, int y)
{
    int pos_x = x / PIECE_WIDTH - 1;
    int pos_y = y / PIECE_WIDTH - 1;
    
    return (pieces[pos_y][pos_x] != NULL);
}

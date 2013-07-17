//
//  PiecesManager.cpp
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#include "PiecesManager.h"
#include "Game.h"
#include "Board.h"

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

int colors[] = {
    /* RED */       0xff0000,
    /* YELLOW */    0xffff00,
    /* GREEN */     0x008000,
    /* ORANGE */    0xCC3232,
    /* Aluminium */ 0xA9ACB6,
    /* sandstone */ 0xA78D84
};

// PairPieces declarations //

PairPieces::PairPieces(){
    this->first = NULL;
    this->second = NULL;
    
    std::srand (std::time(0));
}

PairPieces::~PairPieces(){
    if(this->first)
        delete first;
    
    if(this->second)
        delete second;
}

void PairPieces::push_first(Piece *piece){
    first = piece;
    pieces_array[0] = piece;
}

void PairPieces::push_second(Piece *piece){
    second = piece;
    pieces_array[1] = piece;
}

void PairPieces::clear()
{
    if(this->first)
    {
        delete first;
        first = NULL;
        pieces_array[0] = NULL;
    }
    
    if(this->second)
    {
        delete second;
        second = NULL;
        pieces_array[1] = NULL;
    }
}

bool PairPieces::exists()
{
    return (this->first != NULL || this->second != NULL);
}

Piece* PairPieces::at(int index)
{
    if(index == 0 || index == 1)
        return pieces_array[index];
    
    return NULL;
}


// PiecesManager declaration //

PiecesManager::PiecesManager()
{
    board = new Board();
    pieces = new PairPieces();
    create_pieces();
}

PiecesManager::~PiecesManager()
{
    delete board;
    delete pieces;
}

void PiecesManager::create_pieces()
{
    //if(pieces->exists())
    //    pieces->clear();
    
    pieces->push_first(new Piece(PIECE_START_X_LEFT, PIECE_START_Y, colors[(int)(std::rand() % (sizeof(colors) / sizeof(int)))]));
    pieces->push_second(new Piece(PIECE_START_X_RIGHT, PIECE_START_Y, colors[(int)(std::rand() %(sizeof(colors) / sizeof(int)))]));
}

bool PiecesManager::touch_buttom(Piece* piece)
{
    if(board->is_used(piece->get_pos_x(), piece->get_pos_y() + PIECE_WIDTH))
        return true;
    else if(piece->get_pos_y() >= BOARD_ROWS * PIECE_WIDTH)
        return true;

    return false;
}

void PiecesManager::update()
{
    Touch touch;
    bool need_new_pieces = false;
    
    if (Game::getInstance()->touch_pressed(&touch))
    {
        if (touch.pos_x < SCREEN_WIDTH / 2)
        {
            move_pieces_horizontal(MOVE_LEFT);
        }
        else if (touch.pos_x >= SCREEN_WIDTH / 2)
        {
            move_pieces_horizontal(MOVE_RIGHT);
        }
    }
    
    // pieces
    for(int x = 0; x < pieces->size(); x++)
    {
        if(!touch_buttom(pieces->at(x)))
        {
            pieces->at(x)->move_down();
        }
        else
        {
            board->set_piece(pieces->at(x));
            need_new_pieces = true;
        }
    }
        
    //create new pieces if the pieces touch the button
    if(need_new_pieces)
        create_pieces();
}

void PiecesManager::move_pieces_horizontal(int position)
{
    switch(position)
    {
        case MOVE_LEFT:
            //validate that the piece can be moved to left
            for (int x = 0; x < pieces->size(); ++x)
                if(!pieces->at(x)->can_move_to_left())
                    return;
            
            // move piece
            for (int x = 0; x < pieces->size(); ++x)
                pieces->at(x)->move_left();
            break;
            
        case MOVE_RIGHT:
            //validate that the piece can be moved to right
            for (int x = 0; x < pieces->size(); ++x)
                if(!pieces->at(x)->can_move_to_right())
                    return;
            
            // move piece
            for (int x = 0; x < pieces->size(); ++x)
                pieces->at(x)->move_right();
            break;
    }
}

void PiecesManager::render_all_pieces(SDL_Renderer *renderer)
{
    board->render(renderer);
    
    for (int x = 0; x < pieces->size(); ++x)
    {
        pieces->at(x)->render(renderer);
    }
}

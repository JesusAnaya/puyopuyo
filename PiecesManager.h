//
//  PiecesManager.h
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#ifndef __puyopuyo__PiecesManager__
#define __puyopuyo__PiecesManager__

#include "Commons.h"
#include "Piece.h"

#define MOVE_LEFT 0
#define MOVE_RIGHT 1

class Board;

class PairPieces
{
private:
    Piece *pieces_array[2];
  
public:
    Piece *first;
    Piece *second;
    PairPieces();
    ~PairPieces();
    
    void clear();
    bool exists();
    Piece* at(int index);
    
    void push_first(Piece *piece);
    void push_second(Piece *piece);
    
    inline size_t size() {
        return 2;
    }
};

class PiecesManager
{
private:
    PairPieces *pieces;
    Board *board;
    
public:
    PiecesManager();
    ~PiecesManager();
    
    void render_all_pieces(SDL_Renderer*);
    void update();
    
private:
    void move_pieces_horizontal(int position);
    void create_pieces();
    bool touch_buttom(Piece* piece);
};

#endif

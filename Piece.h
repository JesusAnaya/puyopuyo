//
//  Piece.h
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#ifndef __puyopuyo__Piece__
#define __puyopuyo__Piece__

class Piece
{
private:
    int pos_x;
    int pos_y;
    int offset_x;
    int offset_y;
    int color;
    int move_counter;
    bool can_down;
    
public:
    Piece(int start_x, int start_y = PIECE_START_Y, int color = 0x000000);
    ~Piece();
    
    void render(SDL_Renderer*);
    void move_down();
    void move_left();
    void move_right();
    bool can_move_to_left();
    bool can_move_to_right();
    
    inline int get_pos_x(){return pos_x;}
    inline int get_pos_y(){return pos_y;}
    
private:
    bool can_move_down();
};
#endif

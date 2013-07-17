//
//  Commons.h
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#ifndef puyopuyo_Commons_h
#define puyopuyo_Commons_h

#include <iostream>
#include <list>
#include <vector>
#include "SDL.h"

// Game config
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 960

#define TICK_INTERVAL 80

// User config
#define START_LIFE_POINTS 3

// Pieces config
#define PIECE_WIDTH 40 //pixels
#define PIECE_START_X_LEFT ((SCREEN_WIDTH / 2) - (PIECE_WIDTH))
#define PIECE_START_X_RIGHT (SCREEN_WIDTH / 2)
#define PIECE_START_Y 0
#define PIECE_MOVE_COUNTER 5

#define BOARD_ROWS ((SCREEN_HEIGHT / PIECE_WIDTH) - 1)
#define BOARD_COLS (SCREEN_WIDTH / PIECE_WIDTH)

#endif

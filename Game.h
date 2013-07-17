//
//  Game.h
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#ifndef __puyopuyo__Game__
#define __puyopuyo__Game__

#include "Commons.h"

class User;
class PiecesManager;

typedef struct Touch
{
    int pos_x;
    int pos_y;
}Touch;

class Game
{
private:
    static Game *instance;
    
    User *user;
    PiecesManager *pieces_manager;
    Touch touch;
    bool is_touch_pressed;
    bool is_run;
    
    //SDL Objects
    SDL_Window *window;
    SDL_Renderer *renderer;
    
public:
    Game();
    ~Game();
    
    static Game* getInstance();
    static void deleteInstance();
    
    void handler_event();
    void run();
    void render();
    void update();
    void start();
    void stop();
    bool is_running();
    
    bool touch_pressed(Touch *touch);
    
private:
    void window_initialization();
    void set_touch_pressed(Touch touch);
    bool time_delay();
};

#endif

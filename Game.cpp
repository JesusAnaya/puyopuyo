//
//  Game.cpp
//  puyopuyo
//
//  Created by Jesus Anaya Orozco on 3/23/13.
//
//

#include "Game.h"
#include "User.h"
#include "PiecesManager.h"

Game* Game::instance = NULL;

Game* Game::getInstance()
{
    if(instance == NULL)
        instance = new Game();
    return instance;
}

void Game::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = NULL;
    }
}


Game::Game()
{
    is_run = false;
    window_initialization();
}

Game::~Game()
{
    delete user;
    delete pieces_manager;
}

void Game::start()
{
    is_run = true;
    user = new User();
    pieces_manager = new PiecesManager();
}

bool Game::time_delay()
{
    static int last_time = 0;
    int now = SDL_GetTicks();
    
    if ( last_time == 0)
        last_time = SDL_GetTicks();
    
    if(now - last_time >= TICK_INTERVAL)
    {
        last_time = SDL_GetTicks();
        return true;
    }
    return false;
}

void Game::window_initialization()
{
    /* initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL" << std::endl;
    }
    
    /* create window and renderer */
    window = SDL_CreateWindow(NULL, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN |
                              SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cout << "Could not initialize Window" << std::endl;
    }
    
    renderer = SDL_CreateRenderer(window, 0, 0);
    if (!renderer)
    {
        std::cout << "Could not create renderer" << std::endl;
    }
}

void Game::set_touch_pressed(Touch touch)
{
    this->touch.pos_x = touch.pos_x;
    this->touch.pos_y = touch.pos_y;
    is_touch_pressed = true;
}

bool Game::touch_pressed(Touch *touch)
{
    if(is_touch_pressed)
    {
        touch->pos_x = this->touch.pos_x;
        touch->pos_y = this->touch.pos_y;
        is_touch_pressed = false;
        return true;
    }
    else
    {
        return false;
    }
}

bool Game::is_running()
{
    return is_run;
}

void Game::stop()
{
    is_run = false;
}

void Game::handler_event()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                stop();
                std::cout << "Event quit" << std::endl;
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                Touch touch;
                SDL_GetMouseState(&touch.pos_x, &touch.pos_y);  /* get its location */
                set_touch_pressed(touch);
                std::cout << "Event touch" << std::endl;
                break;
        }
    }
}

void Game::update()
{
    pieces_manager->update();
}

void Game::render()
{
    /* Clear the screen */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    pieces_manager->render_all_pieces(renderer);
    
    /* update screen */
    SDL_RenderPresent(renderer);
}

void Game::run()
{
    while (is_running())
    {
        handler_event();
        
        if(time_delay())
        {
            // update all objects
            update();
            
            // render rendereables objects x'D
            render();
            
            // Delay timer
        }
        //SDL_Delay(10);
    }
    
    /* shutdown SDL */
    SDL_Quit();
}
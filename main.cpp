/*
 *	rectangles.c
 *	written by Holmes Futrell
 *	use however you want
 */

#include "Commons.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    Game* game = Game::getInstance();
    game->start();
    game->run();
    game->deleteInstance();
    
    return 0;
}

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "types.h"
#include "player.h"

typedef struct {
    Player player;
    GameState state;
} GameController;

GameController GameController_create(void);
void GameController_startGame(GameController* game);

#endif

#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <stdbool.h>
#include "player.h"

bool SaveManager_saveGame(const Player* player);
bool SaveManager_loadGame(Player* player);
bool SaveManager_hasSaveFile(void);

#endif

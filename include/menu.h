#ifndef MENU_H
#define MENU_H

#include "types.h"
#include "player.h"
#include "inventory.h"

int Menu_showMainMenu(void);
int Menu_showRestMenu(void);
ActionType Menu_readBattleAction(void);
void Menu_showHowToPlay(void);
void Menu_showStatus(const Player* player);
void Menu_showInventory(const Inventory* inventory);

#endif

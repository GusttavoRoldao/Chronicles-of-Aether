#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "types.h"
#include "stats.h"
#include "inventory.h"

typedef struct {
    char name[NAME_LEN];
    CharacterClass classe;
    Stats stats;
    ItemID weapon;
    ItemID helmet;
    ItemID armor;
    Inventory inventory;
    int coins;
    int currentPhase;
    int chests[CHEST_TYPE_COUNT];
} Player;

Player Player_create(const char* name, CharacterClass classe);
int Player_getTotalAttack(const Player* player);
int Player_getTotalDefense(const Player* player);
bool Player_equipItem(Player* player, int itemIndex);
bool Player_useItem(Player* player, int itemIndex);
void Player_addChest(Player* player, ChestType type);
bool Player_openChest(Player* player, ChestType type);

#endif

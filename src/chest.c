#include "chest.h"
#include "itemtable.h"
#include <stdlib.h>

static const ItemID COMMON_LOOT_TABLE[4] =
{

    ITEM_POTION_HP_SMALL,
    ITEM_POTION_HP_SMALL,
    ITEM_POTION_MANA_SMALL,
    ITEM_HELMET_BASIC

};

static const ItemID BOSS_LOOT_TABLE[3] =
{

    ITEM_ARMOR_BASIC,
    ITEM_HELMET_BASIC,
    ITEM_POTION_HP_SMALL

};

static int Chest_rollIndex(int tableSize);

bool Chest_shouldDrop(bool isBoss)
{

    if (isBoss)
        return true;

    return rand() % 100 < 30;

}

ChestType Chest_getDropType(bool isBoss)
{

    if (isBoss)
        return CHEST_BOSS;

    return CHEST_COMMON;

}

Item Chest_generateItem(ChestType type)
{

    int index;

    if (type == CHEST_BOSS)
    {

        index = Chest_rollIndex(3);
        return ItemTable_getItem(BOSS_LOOT_TABLE[index]);

    }

    index = Chest_rollIndex(4);
    return ItemTable_getItem(COMMON_LOOT_TABLE[index]);

}

static int Chest_rollIndex(int tableSize)
{

    return rand() % tableSize;

}

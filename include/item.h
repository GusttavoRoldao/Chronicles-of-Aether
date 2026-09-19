#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include "types.h"

typedef struct {
    ItemType type;
    char name[NAME_LEN];
    int tier;
    int value;
    ItemID id;
} Item;

bool Item_isConsumable(const Item* item);
bool Item_isEquipment(const Item* item);

#endif

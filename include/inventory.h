#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdbool.h>
#include "types.h"

typedef struct {
    ItemID items[INVENTORY_MAX];
    int itemCount;
} Inventory;

void Inventory_init(Inventory* inventory);
bool Inventory_addItem(Inventory* inventory, ItemID id);
bool Inventory_removeItem(Inventory* inventory, int index);
ItemID Inventory_getItem(const Inventory* inventory, int index);
bool Inventory_isFull(const Inventory* inventory);
bool Inventory_isEmpty(const Inventory* inventory);

#endif

#ifndef CHEST_H
#define CHEST_H

#include <stdbool.h>
#include "types.h"
#include "item.h"

bool Chest_shouldDrop(bool isBoss);
ChestType Chest_getDropType(bool isBoss);
Item Chest_generateItem(ChestType type);

#endif

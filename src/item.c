#include <stddef.h>
#include "item.h"

bool Item_isConsumable(const Item* item) {
    if (item == NULL) {
        return false;
    }

    return item->type == ITEM_POTION_HP || item->type == ITEM_POTION_MANA;
}

bool Item_isEquipment(const Item* item) {
    if (item == NULL) {
        return false;
    }

    return item->type == ITEM_WEAPON ||
           item->type == ITEM_HELMET ||
           item->type == ITEM_ARMOR;
}

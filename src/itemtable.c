#include "itemtable.h"

static const Item itemTable[ITEM_ID_COUNT] = {
    {ITEM_WEAPON,     "Espada Basica",       1,  5, ITEM_SWORD_BASIC},
    {ITEM_WEAPON,     "Arco Basico",         1,  5, ITEM_BOW_BASIC},
    {ITEM_WEAPON,     "Cajado Basico",       1,  5, ITEM_STAFF_BASIC},
    {ITEM_ARMOR,      "Armadura Basica",     1,  4, ITEM_ARMOR_BASIC},
    {ITEM_HELMET,     "Capacete Basico",     1,  2, ITEM_HELMET_BASIC},
    {ITEM_POTION_HP,  "Pocao de Vida",       1, 20, ITEM_POTION_HP_SMALL},
    {ITEM_POTION_MANA,"Pocao de Mana",       1, 20, ITEM_POTION_MANA_SMALL}
};

Item ItemTable_getItem(ItemID id) {
    Item emptyItem = {0};

    if (id < 0 || id >= ITEM_ID_COUNT) {
        return emptyItem;
    }

    return itemTable[id];
}

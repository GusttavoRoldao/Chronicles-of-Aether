#ifndef ITEM_TABLE_DEF_H
#define ITEM_TABLE_DEF_H

typedef struct 
{
    Item item[ALL_GAME_ITEMS];
} ItemTable;

void ItemTable_Init();
Item* ItemTable_GetItem(ItemID itemID);

#endif //ITEM_TABLE_DEF_H
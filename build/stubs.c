#include <string.h>
#include "player.h"
#include "itemtable.h"

bool Stats_isDead(const Stats* stats)
{

    return stats->life <= 0;

}

void Stats_takeDamage(Stats* stats, int damage)
{

    stats->life -= damage;

    if (stats->life < 0)
        stats->life = 0;

}

int Player_getTotalAttack(const Player* player)
{

    return player->stats.attack + 5;

}

int Player_getTotalDefense(const Player* player)
{

    return player->stats.defense + 3;

}

Item ItemTable_getItem(ItemID id)
{

    Item item;

    item.type = ITEM_POTION_HP;
    strcpy(item.name, "Item falso");
    item.tier = 1;
    item.value = 0;
    item.id = id;

    return item;

}

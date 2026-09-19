#ifndef STATS_H
#define STATS_H

#include <stdbool.h>
#include "types.h"

typedef struct {
    int level;
    int xp;
    int xpToNextLevel;
    int life;
    int maxLife;
    int mana;
    int maxMana;
    int attack;
    int defense;
} Stats;

Stats Stats_create(CharacterClass classe);
bool Stats_isDead(const Stats* stats);
void Stats_takeDamage(Stats* stats, int damage);
bool Stats_addXp(Stats* stats, int amount);

#endif

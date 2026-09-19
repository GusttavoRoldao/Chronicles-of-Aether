#ifndef ENEMY_H
#define ENEMY_H

#include <stdbool.h>
#include "types.h"

typedef struct {
    char name[NAME_LEN];
    int life;
    int maxLife;
    int attack;
    int defense;
    int xpReward;
    int coinReward;
    bool isBoss;
} Enemy;

Enemy Enemy_create(int phase);
void Enemy_takeDamage(Enemy* enemy, int damage);
bool Enemy_isDead(const Enemy* enemy);

#endif

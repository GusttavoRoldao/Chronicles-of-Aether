#ifndef BATTLE_H
#define BATTLE_H

#include <stdbool.h>
#include "player.h"
#include "enemy.h"

int Battle_calculateDamage(int attack, int defense);
void Battle_playerAttack(Player* player, Enemy* enemy);
void Battle_enemyAttack(Enemy* enemy, Player* player);
void Battle_useSkill(Player* player, Enemy* enemy);
bool Battle_isOver(const Player* player, const Enemy* enemy);
bool Battle_playerWon(const Player* player, const Enemy* enemy);

#endif

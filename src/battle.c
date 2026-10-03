#include "battle.h"

int Battle_calculateDamage(int attack, int defense)
{

    int damage = attack - defense;

    if (damage < 1)
        damage = 1;

    return damage;

}

void Battle_playerAttack(Player* player, Enemy* enemy)
{

    int damage = Battle_calculateDamage(Player_getTotalAttack(player), enemy->defense);
    Enemy_takeDamage(enemy, damage);

}

void Battle_enemyAttack(Enemy* enemy, Player* player)
{

    int damage = Battle_calculateDamage(enemy->attack, Player_getTotalDefense(player));
    Stats_takeDamage(&player->stats, damage);

}

void Battle_useSkill(Player* player, Enemy* enemy)
{

    if (player->stats.mana < 10)
    {

        Battle_playerAttack(player, enemy);
        return;

    }

    player->stats.mana -= 10;

    int damage = Battle_calculateDamage(Player_getTotalAttack(player) * 2, enemy->defense);
    Enemy_takeDamage(enemy, damage);

}

bool Battle_isOver(const Player* player, const Enemy* enemy)
{

    return Stats_isDead(&player->stats) || Enemy_isDead(enemy);

}

bool Battle_playerWon(const Player* player, const Enemy* enemy)
{

    return Enemy_isDead(enemy) && !Stats_isDead(&player->stats);

}

#include "enemy.h"

static const Enemy ENEMY_TABLE[6] =
{

        //vida  vidaMax  ataque  defesa  xp  moedas  éChefe
    { "Slime", 20, 20, 3, 0, 10, 5, false },
    { "Goblin", 30, 30, 4, 1, 15, 8, false },
    { "Lobo", 40, 40, 5, 2, 20, 10, false },
    { "Skeleton", 55, 55, 6, 3, 28, 14, false },
    { "Orc de sinb", 70, 70, 7, 4, 35, 18, false },
    { "REI ORC BK Segundo", 120, 120, 10, 5, 100, 60, true }

};

static int Enemy_getIndexForPhase(int phase);

Enemy Enemy_create(int phase)
{

    int index = Enemy_getIndexForPhase(phase);
    Enemy enemy = ENEMY_TABLE[index];

    enemy.maxLife += phase * 2;
    enemy.life = enemy.maxLife;
    enemy.attack += phase;

    return enemy;

}

void Enemy_takeDamage(Enemy* enemy, int damage)
{

    enemy->life -= damage;

    if (enemy->life < 0)
        enemy->life = 0;

}

bool Enemy_isDead(const Enemy* enemy)
{

    return enemy->life <= 0;

}

static int Enemy_getIndexForPhase(int phase)
{

    if (phase < 1)
        return 0;

    if (phase >= MAX_PHASE)
        return 5;

    return (phase - 1) / 2;

}

#include <stddef.h>
#include "stats.h"

static void Stats_levelUp(Stats* stats) {   //upar level
    stats->level++;
    stats->xpToNextLevel = stats->level * 100;

    stats->maxLife += 10;
    stats->life = stats->maxLife;
    stats->maxMana += 5;
    stats->mana = stats->maxMana;
    stats->attack += 2;
    stats->defense += 2;
}

Stats Stats_create(CharacterClass classe) {   //status de acordo com a classe
    Stats stats;

    stats.level = 1;
    stats.xp = 0;
    stats.xpToNextLevel = 100;

    switch (classe) {
        case CLASS_WARRIOR:
            stats.maxLife = 120;
            stats.maxMana = 30;
            stats.attack = 15;
            stats.defense = 10;
            break;

        case CLASS_ARCHER:
            stats.maxLife = 90;
            stats.maxMana = 50;
            stats.attack = 18;
            stats.defense = 6;
            break;

        case CLASS_MAGE:
            stats.maxLife = 70;
            stats.maxMana = 100;
            stats.attack = 22;
            stats.defense = 4;
            break;

        default:
            stats.maxLife = 100;
            stats.maxMana = 50;
            stats.attack = 10;
            stats.defense = 5;
            break;
    }

    stats.life = stats.maxLife;
    stats.mana = stats.maxMana;

    return stats;
}

bool Stats_isDead(const Stats* stats) {  //verificação de dano, morte e levelUP
    return stats == NULL || stats->life <= 0;
}

void Stats_takeDamage(Stats* stats, int damage) {
    if (stats == NULL || damage <= 0) {
        return;
    }

    stats->life -= damage;

    if (stats->life < 0) {
        stats->life = 0;
    }
}

bool Stats_addXp(Stats* stats, int amount) {
    bool leveledUp = false;

    if (stats == NULL || amount <= 0) {
        return false;
    }

    stats->xp += amount;

    while (stats->xp >= stats->xpToNextLevel) {
        stats->xp -= stats->xpToNextLevel;
        Stats_levelUp(stats);
        leveledUp = true;
    }

    return leveledUp;
}

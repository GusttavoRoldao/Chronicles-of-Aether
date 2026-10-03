#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "battle.h"
#include "chest.h"

int main()
{

    srand(time(NULL));

    Player player;
    player.stats.life = 100;
    player.stats.maxLife = 100;
    player.stats.attack = 10;
    player.stats.defense = 2;
    player.stats.mana = 20;
    player.stats.maxMana = 20;

    for (int phase = 1; phase <= MAX_PHASE; phase++)
    {

        Enemy enemy = Enemy_create(phase);

        char title[NAME_LEN];
        strcpy(title, enemy.name);

        for (int i = 0; title[i] != '\0'; i++)
        {

            title[i] = toupper(title[i]);

        }

        printf("\nFASE %d: %s\n", phase, title);

        while (!Battle_isOver(&player, &enemy))
        {

            printf("\nSUA VEZ\n");
            printf("%s: vida %d/%d\n", enemy.name, enemy.life, enemy.maxLife);
            printf("Voce: vida %d/%d | mana %d/%d\n", player.stats.life, player.stats.maxLife, player.stats.mana, player.stats.maxMana);
            printf("1 - Atacar\n");
            printf("2 - Habilidade (10 mana)\n");
            printf("0 - Sair\n");
            printf("Escolha: ");

            int option;

            if (scanf("%d", &option) != 1)
                return 0;

            if (option == 0)
                return 0;

            int enemyLife = enemy.life;
            int manaBefore = player.stats.mana;

            if (option == 1)
                Battle_playerAttack(&player, &enemy);
            else if (option == 2)
                Battle_useSkill(&player, &enemy);
            else
            {

                printf("Opcao invalida\n");
                continue;

            }

            printf("Voce causou %d de dano\n", enemyLife - enemy.life);

            if (option == 2 && player.stats.mana == manaBefore)
                printf("Sem mana, deu um ataque normal\n");
            else if (option == 2)
                printf("Mana agora: %d/%d\n", player.stats.mana, player.stats.maxMana);

            if (!Battle_isOver(&player, &enemy))
            {

                printf("\nVEZ DO %s\n", enemy.name);

                int playerLife = player.stats.life;
                Battle_enemyAttack(&enemy, &player);
                printf("%s causou %d de dano em voce\n", enemy.name, playerLife - player.stats.life);

            }

        }

        if (!Battle_playerWon(&player, &enemy))
        {

            printf("\nVoce perdeu na fase %d\n", phase);
            return 0;

        }

        printf("\nVoce venceu! +%d xp | +%d moedas\n", enemy.xpReward, enemy.coinReward);

        if (Chest_shouldDrop(enemy.isBoss))
        {

            ChestType type = Chest_getDropType(enemy.isBoss);
            Item item = Chest_generateItem(type);

            if (type == CHEST_BOSS)
                printf("Dropou um bau de chefe: %s\n", item.name);
            else
                printf("Dropou um bau comum: %s\n", item.name);

        }
        else
            printf("Nao dropou bau\n");

        player.stats.life = player.stats.maxLife;
        player.stats.mana = player.stats.maxMana;
        printf("(teste: vida e mana restauradas)\n");

    }

    printf("\nVoce zerou as %d fases!\n", MAX_PHASE);

    return 0;

}

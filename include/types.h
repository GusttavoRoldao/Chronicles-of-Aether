#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#define INVENTORY_MAX 20
#define MAX_PHASE 10
#define NAME_LEN 32

typedef enum {
    STATE_MAIN_MENU,
    STATE_PLAYER_CREATION,
    STATE_PLAYING,
    STATE_GAME_OVER
} GameState;

typedef enum {
    CLASS_WARRIOR,
    CLASS_ARCHER,
    CLASS_MAGE
} CharacterClass;

typedef enum {
    ACT_ATTACK,
    ACT_SKILL,
    ACT_ITEM,
    ACT_INFO
} ActionType;

typedef enum {
    ITEM_WEAPON,
    ITEM_HELMET,
    ITEM_ARMOR,
    ITEM_POTION_HP,
    ITEM_POTION_MANA
} ItemType;

typedef enum {
    CHEST_COMMON,
    CHEST_RARE,
    CHEST_EPIC,
    CHEST_BOSS,
    CHEST_TYPE_COUNT
} ChestType;

typedef enum {
    ITEM_SWORD_BASIC,
    ITEM_BOW_BASIC,
    ITEM_STAFF_BASIC,
    ITEM_ARMOR_BASIC,
    ITEM_HELMET_BASIC,
    ITEM_POTION_HP_SMALL,
    ITEM_POTION_MANA_SMALL,
    ITEM_ID_COUNT
} ItemID;

#endif

#include <stdlib.h>
#include "inventory.h"

void Inventory_init(Inventory* inventory) {
    if (inventory == NULL) {
        return;
    }

    inventory->head = NULL;
    inventory->itemCount = 0;
}

bool Inventory_addItem(Inventory* inventory, ItemID id) {
    InventoryNode* newNode;
    InventoryNode* current;

    if (inventory == NULL || Inventory_isFull(inventory)) {
        return false;
    }

    newNode = malloc(sizeof(InventoryNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->id = id;
    newNode->next = NULL;

    if (inventory->head == NULL) {
        inventory->head = newNode;
    } else {
        current = inventory->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    inventory->itemCount++;
    return true;
}

bool Inventory_removeItem(Inventory* inventory, int index) {
    InventoryNode* current;
    InventoryNode* previous;
    int i;

    if (inventory == NULL || index < 0 || index >= inventory->itemCount) {
        return false;
    }

    current = inventory->head;
    previous = NULL;

    for (i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        inventory->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    inventory->itemCount--;

    return true;
}

ItemID Inventory_getItem(const Inventory* inventory, int index) {
    const InventoryNode* current;
    int i;

    if (inventory == NULL || index < 0 || index >= inventory->itemCount) {
        return ITEM_ID_COUNT;
    }

    current = inventory->head;

    for (i = 0; i < index; i++) {
        current = current->next;
    }

    return current->id;
}

bool Inventory_isFull(const Inventory* inventory) {
    if (inventory == NULL) {
        return false;
    }

    return inventory->itemCount >= INVENTORY_MAX;
}

bool Inventory_isEmpty(const Inventory* inventory) {
    if (inventory == NULL) {
        return true;
    }

    return inventory->itemCount == 0;
}

void Inventory_destroy(Inventory* inventory) {
    InventoryNode* current;
    InventoryNode* next;

    if (inventory == NULL) {
        return;
    }

    current = inventory->head;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    inventory->head = NULL;
    inventory->itemCount = 0;
}

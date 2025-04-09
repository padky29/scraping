#include "listing.h"
#include "scrape.h"
#include <stdio.h>

#define TRESHOLD 1
#define MAX_TRANSACTIONS 200

User createBot(char name[], Skin bSkins[], List bLists[], double balance){
    User bot = createUser(name, bSkins, bLists, balance);
    return bot;
}

void buySkin(User *user, List listB){
    printf("SKIN BOUGHT: ");
    printList(listB);
    user->skins[user->skinCount++] = listB.skin;
    user->balance -= listB.price;
}

void listSkin(User *userB, Skin skinB){
    if (userB->skinCount > 0) {
        createList(*userB, skinB, skinB.marketPrice);
        // Remover a skin do array
        int indexToRemove = -1;

        for (int i = 0; i < userB->skinCount; i++) {
            if (strcmp(userB->skins[i].skinName, skinB.skinName) == 0) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove != -1) {
            for (int i = indexToRemove; i < userB->skinCount - 1; i++) {
                userB->skins[i] = userB->skins[i + 1]; // Shift
            }
            userB->skinCount--;
        }
    } else {
        printf("No more skins to list.\n");
    }
}

void updateB(List listB, User user){
    if(listB.price > listB.skin.marketPrice + TRESHOLD){
        buySkin(&user, listB);
    }
}